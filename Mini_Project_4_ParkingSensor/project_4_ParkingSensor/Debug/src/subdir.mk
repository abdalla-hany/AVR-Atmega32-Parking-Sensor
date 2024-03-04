################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/buzzer.c \
../src/gpio.c \
../src/icu.c \
../src/lcd.c \
../src/main.c \
../src/pwm.c \
../src/ultrasonic.c 

OBJS += \
./src/buzzer.o \
./src/gpio.o \
./src/icu.o \
./src/lcd.o \
./src/main.o \
./src/pwm.o \
./src/ultrasonic.o 

C_DEPS += \
./src/buzzer.d \
./src/gpio.d \
./src/icu.d \
./src/lcd.d \
./src/main.d \
./src/pwm.d \
./src/ultrasonic.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


