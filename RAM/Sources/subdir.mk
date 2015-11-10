################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/capacitivepads.c" \
"../Sources/capacitivepadsdriver.c" \
"../Sources/common.c" \
"../Sources/delay.c" \
"../Sources/io.c" \
"../Sources/lcdc.c" \
"../Sources/lcdcConsole.c" \
"../Sources/lcdcdriver.c" \
"../Sources/led.c" \
"../Sources/leddriver.c" \
"../Sources/main.c" \
"../Sources/mcg.c" \
"../Sources/mymalloc.c" \
"../Sources/potentiometer.c" \
"../Sources/potentiometerdriver.c" \
"../Sources/profont.c" \
"../Sources/pushbutton.c" \
"../Sources/pushbuttondriver.c" \
"../Sources/sdram.c" \
"../Sources/stringutils.c" \
"../Sources/svc.c" \
"../Sources/thermistor.c" \
"../Sources/thermistordriver.c" \
"../Sources/uart.c" \
"../Sources/uartdriver.c" \

C_SRCS += \
../Sources/capacitivepads.c \
../Sources/capacitivepadsdriver.c \
../Sources/common.c \
../Sources/delay.c \
../Sources/io.c \
../Sources/lcdc.c \
../Sources/lcdcConsole.c \
../Sources/lcdcdriver.c \
../Sources/led.c \
../Sources/leddriver.c \
../Sources/main.c \
../Sources/mcg.c \
../Sources/mymalloc.c \
../Sources/potentiometer.c \
../Sources/potentiometerdriver.c \
../Sources/profont.c \
../Sources/pushbutton.c \
../Sources/pushbuttondriver.c \
../Sources/sdram.c \
../Sources/stringutils.c \
../Sources/svc.c \
../Sources/thermistor.c \
../Sources/thermistordriver.c \
../Sources/uart.c \
../Sources/uartdriver.c \

OBJS += \
./Sources/capacitivepads.o \
./Sources/capacitivepadsdriver.o \
./Sources/common.o \
./Sources/delay.o \
./Sources/io.o \
./Sources/lcdc.o \
./Sources/lcdcConsole.o \
./Sources/lcdcdriver.o \
./Sources/led.o \
./Sources/leddriver.o \
./Sources/main.o \
./Sources/mcg.o \
./Sources/mymalloc.o \
./Sources/potentiometer.o \
./Sources/potentiometerdriver.o \
./Sources/profont.o \
./Sources/pushbutton.o \
./Sources/pushbuttondriver.o \
./Sources/sdram.o \
./Sources/stringutils.o \
./Sources/svc.o \
./Sources/thermistor.o \
./Sources/thermistordriver.o \
./Sources/uart.o \
./Sources/uartdriver.o \

C_DEPS += \
./Sources/capacitivepads.d \
./Sources/capacitivepadsdriver.d \
./Sources/common.d \
./Sources/delay.d \
./Sources/io.d \
./Sources/lcdc.d \
./Sources/lcdcConsole.d \
./Sources/lcdcdriver.d \
./Sources/led.d \
./Sources/leddriver.d \
./Sources/main.d \
./Sources/mcg.d \
./Sources/mymalloc.d \
./Sources/potentiometer.d \
./Sources/potentiometerdriver.d \
./Sources/profont.d \
./Sources/pushbutton.d \
./Sources/pushbuttondriver.d \
./Sources/sdram.d \
./Sources/stringutils.d \
./Sources/svc.d \
./Sources/thermistor.d \
./Sources/thermistordriver.d \
./Sources/uart.d \
./Sources/uartdriver.d \

OBJS_QUOTED += \
"./Sources/capacitivepads.o" \
"./Sources/capacitivepadsdriver.o" \
"./Sources/common.o" \
"./Sources/delay.o" \
"./Sources/io.o" \
"./Sources/lcdc.o" \
"./Sources/lcdcConsole.o" \
"./Sources/lcdcdriver.o" \
"./Sources/led.o" \
"./Sources/leddriver.o" \
"./Sources/main.o" \
"./Sources/mcg.o" \
"./Sources/mymalloc.o" \
"./Sources/potentiometer.o" \
"./Sources/potentiometerdriver.o" \
"./Sources/profont.o" \
"./Sources/pushbutton.o" \
"./Sources/pushbuttondriver.o" \
"./Sources/sdram.o" \
"./Sources/stringutils.o" \
"./Sources/svc.o" \
"./Sources/thermistor.o" \
"./Sources/thermistordriver.o" \
"./Sources/uart.o" \
"./Sources/uartdriver.o" \

C_DEPS_QUOTED += \
"./Sources/capacitivepads.d" \
"./Sources/capacitivepadsdriver.d" \
"./Sources/common.d" \
"./Sources/delay.d" \
"./Sources/io.d" \
"./Sources/lcdc.d" \
"./Sources/lcdcConsole.d" \
"./Sources/lcdcdriver.d" \
"./Sources/led.d" \
"./Sources/leddriver.d" \
"./Sources/main.d" \
"./Sources/mcg.d" \
"./Sources/mymalloc.d" \
"./Sources/potentiometer.d" \
"./Sources/potentiometerdriver.d" \
"./Sources/profont.d" \
"./Sources/pushbutton.d" \
"./Sources/pushbuttondriver.d" \
"./Sources/sdram.d" \
"./Sources/stringutils.d" \
"./Sources/svc.d" \
"./Sources/thermistor.d" \
"./Sources/thermistordriver.d" \
"./Sources/uart.d" \
"./Sources/uartdriver.d" \

OBJS_OS_FORMAT += \
./Sources/capacitivepads.o \
./Sources/capacitivepadsdriver.o \
./Sources/common.o \
./Sources/delay.o \
./Sources/io.o \
./Sources/lcdc.o \
./Sources/lcdcConsole.o \
./Sources/lcdcdriver.o \
./Sources/led.o \
./Sources/leddriver.o \
./Sources/main.o \
./Sources/mcg.o \
./Sources/mymalloc.o \
./Sources/potentiometer.o \
./Sources/potentiometerdriver.o \
./Sources/profont.o \
./Sources/pushbutton.o \
./Sources/pushbuttondriver.o \
./Sources/sdram.o \
./Sources/stringutils.o \
./Sources/svc.o \
./Sources/thermistor.o \
./Sources/thermistordriver.o \
./Sources/uart.o \
./Sources/uartdriver.o \


# Each subdirectory must supply rules for building sources it contributes
Sources/capacitivepads.o: ../Sources/capacitivepads.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/capacitivepads.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/capacitivepads.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/capacitivepadsdriver.o: ../Sources/capacitivepadsdriver.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/capacitivepadsdriver.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/capacitivepadsdriver.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/common.o: ../Sources/common.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/common.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/common.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/delay.o: ../Sources/delay.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/delay.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/delay.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/io.o: ../Sources/io.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/io.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/io.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/lcdc.o: ../Sources/lcdc.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/lcdc.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/lcdc.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/lcdcConsole.o: ../Sources/lcdcConsole.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/lcdcConsole.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/lcdcConsole.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/lcdcdriver.o: ../Sources/lcdcdriver.c
	@echo 'Building file: $<'
	@echo 'Executing target #8 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/lcdcdriver.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/lcdcdriver.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/led.o: ../Sources/led.c
	@echo 'Building file: $<'
	@echo 'Executing target #9 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/led.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/led.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/leddriver.o: ../Sources/leddriver.c
	@echo 'Building file: $<'
	@echo 'Executing target #10 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/leddriver.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/leddriver.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/main.o: ../Sources/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #11 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/main.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/main.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/mcg.o: ../Sources/mcg.c
	@echo 'Building file: $<'
	@echo 'Executing target #12 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/mcg.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/mcg.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/mymalloc.o: ../Sources/mymalloc.c
	@echo 'Building file: $<'
	@echo 'Executing target #13 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/mymalloc.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/mymalloc.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/potentiometer.o: ../Sources/potentiometer.c
	@echo 'Building file: $<'
	@echo 'Executing target #14 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/potentiometer.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/potentiometer.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/potentiometerdriver.o: ../Sources/potentiometerdriver.c
	@echo 'Building file: $<'
	@echo 'Executing target #15 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/potentiometerdriver.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/potentiometerdriver.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/profont.o: ../Sources/profont.c
	@echo 'Building file: $<'
	@echo 'Executing target #16 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/profont.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/profont.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/pushbutton.o: ../Sources/pushbutton.c
	@echo 'Building file: $<'
	@echo 'Executing target #17 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/pushbutton.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/pushbutton.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/pushbuttondriver.o: ../Sources/pushbuttondriver.c
	@echo 'Building file: $<'
	@echo 'Executing target #18 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/pushbuttondriver.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/pushbuttondriver.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/sdram.o: ../Sources/sdram.c
	@echo 'Building file: $<'
	@echo 'Executing target #19 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/sdram.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/sdram.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/stringutils.o: ../Sources/stringutils.c
	@echo 'Building file: $<'
	@echo 'Executing target #20 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/stringutils.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/stringutils.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/svc.o: ../Sources/svc.c
	@echo 'Building file: $<'
	@echo 'Executing target #21 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/svc.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/svc.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/thermistor.o: ../Sources/thermistor.c
	@echo 'Building file: $<'
	@echo 'Executing target #22 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/thermistor.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/thermistor.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/thermistordriver.o: ../Sources/thermistordriver.c
	@echo 'Building file: $<'
	@echo 'Executing target #23 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/thermistordriver.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/thermistordriver.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/uart.o: ../Sources/uart.c
	@echo 'Building file: $<'
	@echo 'Executing target #24 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/uart.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/uart.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/uartdriver.o: ../Sources/uartdriver.c
	@echo 'Building file: $<'
	@echo 'Executing target #25 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/uartdriver.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/uartdriver.o"
	@echo 'Finished building: $<'
	@echo ' '


