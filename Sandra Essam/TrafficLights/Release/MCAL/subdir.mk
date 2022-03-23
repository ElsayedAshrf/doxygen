################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/DIO.c 

OBJS += \
./MCAL/DIO.o 

C_DEPS += \
./MCAL/DIO.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/%.o: ../MCAL/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\Copy Center\Desktop\embedded systems\Embedded systems\eclipse source\eclipse\ITI_Embedded_Projects\TrafficLights\STD" -I"C:\Users\Copy Center\Desktop\embedded systems\Embedded systems\eclipse source\eclipse\ITI_Embedded_Projects\TrafficLights\MCAL" -I"C:\Users\Copy Center\Desktop\embedded systems\Embedded systems\eclipse source\eclipse\ITI_Embedded_Projects\TrafficLights\HAL" -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


