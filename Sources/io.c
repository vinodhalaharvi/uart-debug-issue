#include <stdio.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "io.h"
#include "uart.h"
#include "lcdc.h"
#include "stringutils.h"
#include "common.h"
#include "assert.h"

typedef unsigned long uintptr_t; 

//fdtable_t fdtable[MAX_FILE_DESCRIPTORS]; 
static filepath_to_device_t file_properties[PREDEFINED_DEVICE_MAP] = { 
    {"/dev/uart/1", UART, UART1},
    {"/dev/lcdc/1", LCDC, LCDC1}, 
}; 
static fdtable_t fdtable[MAX_FILE_DESCRIPTORS]; 

void init_devices_fdtable(){ 
    unsigned i;
    for (i = 0; i < PREDEFINED_DEVICE_MAP; ++i) {
       fdtable[i].major_num = file_properties[i].major_num; 
       fdtable[i].minor_num = file_properties[i].minor_num; 
    }
    for (i = PREDEFINED_DEVICE_MAP; i < MAX_FILE_DESCRIPTORS; ++i) {
       fdtable[i].major_num = -1; 
       fdtable[i].minor_num = -1; 
    }
}

const char * get_device_path(unsigned major_num, unsigned minor_num){ 
    unsigned i; 
    for (i = 0; i < PREDEFINED_DEVICE_MAP; ++i) {
        if (file_properties[i].major_num == major_num &&
                file_properties[i].minor_num == minor_num){ 
            return file_properties[i].filepath; 
        }
    }
    return  NULL;
}
int is_fd_inuse(int fd){ 
    return (fdtable[fd].major_num != -1 && fdtable[fd].minor_num != -1); 
}

void print_fdtable(){ 
    unsigned i; 
    for (i = 0; i < MAX_FILE_DESCRIPTORS; ++i) {
        if (is_fd_inuse(get_fd(fdtable[i].major_num, fdtable[i].minor_num))){ 
            printf("%d) %s -> Major: %d, Minor: %d\n", i, 
                    get_device_path(fdtable[i].major_num, fdtable[i].minor_num), 
                    fdtable[i].major_num, 
                    fdtable[i].minor_num);
        }
    }
}

void init_fdtable(){ 
    unsigned i; 
    for (i = 0; i < MAX_FILE_DESCRIPTORS; ++i) {
        fdtable[i].major_num = -1; 
        fdtable[i].minor_num = -1; 
    }
    init_devices_fdtable();
}

static struct device {
    int (*init)(void * minor_num); 
    int (*release)(void * minor_num); 
    int (*write)(int ch, void *minor_num); 
    int (*read)(void * minor_num); 
} devices[MAX_DEVICES] = {
    {lcdc_init, NULL, lcdc_write, NULL}, 
    {uart_init, NULL, uart_write, uart_read}, 
}; 

//static map
int isdevice(int major_num) { 
    return (major_num == UART) 
        ||  (major_num == LCDC); 
}

int isfile(int major_num){ 
    return !isdevice(major_num); 
}

int get_minor_num(const char * filepath){ 
    unsigned i; 
    unsigned major_num = get_major_num(filepath); 
    if(isdevice(major_num)){ 
        for (i = 0; i < MAX_FILE_DESCRIPTORS; ++i) {
            if (strcompare(filepath, file_properties[i].filepath) == 0){ 
                return file_properties[i].minor_num; 
            }
        }
    } else { 
        //for file
    }
    return -1; 
}

int get_major_num(const char * filepath){ 
    if (strstr(filepath, "/dev/uart")){ 
        return UART; 
    } else if (strstr(filepath, "/dev/lcdc")){ 
        return LCDC; 
    } else { 
        return -1; 
    }
}


int close_fd(int fd){
    if (is_fd_inuse(fd)){ 
        fdtable[fd].major_num = -1; 
        fdtable[fd].minor_num = -1; 
        return 0; 
    } else { 
        return -1; 
    }
}

int create_fd(int major_num, int minor_num){ 
    unsigned i; 
    assert(!isdevice(major_num)); 
    for (i = PREDEFINED_DEVICE_MAP; i < MAX_FILE_DESCRIPTORS; ++i) {
        if (!is_fd_inuse(i)){ 
            fdtable[i].major_num = major_num; 
            fdtable[i].minor_num = minor_num; 
            return i;
        }
    } 
    return -1; 
}

int get_fd(int major_num, int minor_num){ 
    unsigned i; 
    for (i = 0; i < MAX_FILE_DESCRIPTORS; ++i) {
        if (fdtable[i].major_num == major_num &&
                fdtable[i].minor_num == minor_num){ 
            return i; 
        }
    }
    return -1;
}


int myopen(const char * filepath, unsigned mode){ 
    int major_num, minor_num; 
    int fd; 
    major_num = get_major_num(filepath); 
    minor_num = get_minor_num(filepath); 
    if (isdevice(major_num)){ 
        fd = get_fd(major_num, minor_num); 
        devices[major_num].init((void *) (uintptr_t) minor_num); 
        return fd; 
    } /*else { 
        if (!isfileexists(filepath)){ 
            if (mode == FILE_CREATE){ 
                create_file(filepath); 
                minor_num = get_file_inode(filepath); 
                myassert(minor_num != -1, "", "minor_num != -1"); 
                devices[major_num].init((void *) (uintptr_t) minor_num); 
                fd = create_fd(major_num, minor_num); 
                return fd; 
            } 
        } else { 
            minor_num = get_file_inode(filepath); 
            fd = get_fd(major_num, minor_num); 
            myassert(fd != -1, "", "fd != -1"); 
            return fd; 
            //file does not exists
        } 
    }*/
    return -1; 
}

int myclose(int fd){ 
    int major_num; 
    int minor_num; 
    major_num = fdtable[fd].major_num; 
    minor_num = fdtable[fd].minor_num; 
    if (devices[major_num].release){ 
        devices[major_num].release((void *) (uintptr_t) minor_num); 
    }
    return close_fd(fd); 
}

int mywrite(int fd, int ch){ 
    int major_num; 
    int minor_num; 
    major_num = fdtable[fd].major_num; 
    minor_num = fdtable[fd].minor_num; 
    devices[major_num].write(ch, (void *) (uintptr_t) minor_num); 
    return 0; 
}

int myread(int fd){ 
    int major_num; 
    int minor_num; 
    int ch; 
    major_num = fdtable[fd].major_num; 
    minor_num = fdtable[fd].minor_num; 
    ch = devices[major_num].read((void *) (uintptr_t) minor_num); 
    return ch; 
}

void cat(unsigned fd){ 
    int  ch; 
    while((ch = myread(fd)) != EOF){ 
        mywrite(ch, mystdout); 
    }
}


void verify_io(){
    init_devices_fdtable(); 
    print_fdtable(); 
    create_fd(2, 0); 
    print_fdtable(); 
    print_fdtable(); 
    unsigned fd = myopen("/dev/uart/1", 0); 
    fd = myopen("/dev/lcdc/1", 0); 
    printf("fd of %s is %d\n", "/dev/lcdc/1", fd);
    printf("fd of %s (0, 0) is: %d\n", get_device_path(0, 0), get_fd(0, 0));
    myclose(0); 
    myclose(1); 
    print_fdtable(); 
}



/*void verify_device_independent_file_operations(){ 
    int fd; 
    int ch; 
    unsigned i; 
    const char * filename = "/tmp/test.txt"; 
    if (!is_memory_initialized()){ 
        initmemory(); 
    }
    init_fdtable(); 
    fd = myopen(filename, FILE_CREATE); 
    fd = myopen("/tmp/test1.txt", FILE_CREATE); 
    fd = myopen("/tmp/test2.txt", FILE_CREATE); 
    fd = myopen("/tmp/test3.txt", FILE_CREATE); 
    myassert(fd != -1, "", "fd != -1"); 
    i = 0; 
    const char * string = "hello world!"; 
    char * print_string = (char *) mymalloc(1000);  
    sprintf(print_string, "Writing string '%s %s' to the file\n", string, filename); 
    write_string(print_string, mystdout); 
    do {
        mywrite(fd, string[i]); 
    } while(string[i++]);
    print_string = (char *) mymalloc(1000);  
    sprintf(print_string, "Reading from file %s\n", filename);
    write_string(print_string, mystdout); 
    while((ch = myread(fd)) != EOF){ 
        mywrite(ch, mystdout); 
    }
    sprintf(print_string, "\n%s\n", "Files before ..");
    write_string(print_string, mystdout); 
    ls(); 
    delete_file(filename); 
    sprintf(print_string, "Files after deleting file %s:\n", filename);
    write_string(print_string, mystdout); 
    ls(); 
    sprintf(print_string, "\n");
    write_string(print_string, mystdout); 
}*/
