#ifndef IO_H
#define IO_H value
#define MAX_DEVICES 100
#define MAX_FILE_DESCRIPTORS 1000
#define PREDEFINED_DEVICE_MAP 2

typedef struct _fdtable_t {
    int major_num; 
    int minor_num; 
} fdtable_t;

typedef struct _stream_t {
    int minorno; 
    int majorno; 
} stream_t;

typedef enum {LCDC, UART} major_device; 
typedef enum {LCDC1} lcdc_minor_device; 
typedef enum {UART1} uart_minor_device; 


typedef struct _filepath_to_device_t {
    const char * filepath; 
    unsigned major_num; 
    unsigned minor_num; 
} filepath_to_device_t;

int get_minor_num(const char * filepath); 
int get_major_num(const char * filepath); 
int create_fd(int major_num, int minor_num); 
int get_fd(int major_num, int minor_num); 

int myopen(const char * filepath, unsigned mode); 
int myclose(int fd); 
int mywrite(int fd, int ch); 
int myread(int fd); 
void delete_file(const char * filename); 
void create_file(const char * filename); 

int isdevice(int major_num); 
int isfile(int major_num); 
void assert_memory_is_initialized(); 
void verify_device_independent_file_operations(); 
void init_fdtable(); 
void cat(unsigned fd); 
#endif
