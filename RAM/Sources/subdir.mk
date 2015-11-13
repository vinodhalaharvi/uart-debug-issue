################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/lcdc.c" \
"../Sources/lcdcConsole.c" \
"../Sources/main.c" \
"../Sources/mcg.c" \
"../Sources/profont.c" \
"../Sources/sdram.c" \
"../Sources/uart.c" \

C_SRCS += \
../Sources/lcdc.c \
../Sources/lcdcConsole.c \
../Sources/main.c \
../Sources/mcg.c \
../Sources/profont.c \
../Sources/sdram.c \
../Sources/uart.c \

OBJS += \
./Sources/lcdc.o \
./Sources/lcdcConsole.o \
./Sources/main.o \
./Sources/mcg.o \
./Sources/profont.o \
./Sources/sdram.o \
./Sources/uart.o \

C_DEPS += \
./Sources/lcdc.d \
./Sources/lcdcConsole.d \
./Sources/main.d \
./Sources/mcg.d \
./Sources/profont.d \
./Sources/sdram.d \
./Sources/uart.d \

OBJS_QUOTED += \
"./Sources/lcdc.o" \
"./Sources/lcdcConsole.o" \
"./Sources/main.o" \
"./Sources/mcg.o" \
"./Sources/profont.o" \
"./Sources/sdram.o" \
"./Sources/uart.o" \

C_DEPS_QUOTED += \
"./Sources/lcdc.d" \
"./Sources/lcdcConsole.d" \
"./Sources/main.d" \
"./Sources/mcg.d" \
"./Sources/profont.d" \
"./Sources/sdram.d" \
"./Sources/uart.d" \

OBJS_OS_FORMAT += \
./Sources/lcdc.o \
./Sources/lcdcConsole.o \
./Sources/main.o \
./Sources/mcg.o \
./Sources/profont.o \
./Sources/sdram.o \
./Sources/uart.o \


# Each subdirectory must supply rules for building sources it contributes
Sources/lcdc.o: ../Sources/lcdc.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/lcdc.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/lcdc.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/lcdcConsole.o: ../Sources/lcdcConsole.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/lcdcConsole.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/lcdcConsole.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/main.o: ../Sources/main.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/main.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/main.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/mcg.o: ../Sources/mcg.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/mcg.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/mcg.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/profont.o: ../Sources/profont.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/profont.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/profont.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/sdram.o: ../Sources/sdram.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/sdram.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/sdram.o"
	@echo 'Finished building: $<'
	@echo ' '

Sources/uart.o: ../Sources/uart.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/uart.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/uart.o"
	@echo 'Finished building: $<'
	@echo ' '


