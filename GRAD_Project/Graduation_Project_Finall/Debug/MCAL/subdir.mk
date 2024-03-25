################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/ADC.c \
../MCAL/CAN.c \
../MCAL/EEPROM.c \
../MCAL/EXTI_Driver.c \
../MCAL/GPIO_Driver.c \
../MCAL/GP_Timers.c \
../MCAL/I2C.c \
../MCAL/RCC.c \
../MCAL/SPI.c \
../MCAL/Timer.c \
../MCAL/Timer1_8.c \
../MCAL/USART_Driver.c 

OBJS += \
./MCAL/ADC.o \
./MCAL/CAN.o \
./MCAL/EEPROM.o \
./MCAL/EXTI_Driver.o \
./MCAL/GPIO_Driver.o \
./MCAL/GP_Timers.o \
./MCAL/I2C.o \
./MCAL/RCC.o \
./MCAL/SPI.o \
./MCAL/Timer.o \
./MCAL/Timer1_8.o \
./MCAL/USART_Driver.o 

C_DEPS += \
./MCAL/ADC.d \
./MCAL/CAN.d \
./MCAL/EEPROM.d \
./MCAL/EXTI_Driver.d \
./MCAL/GPIO_Driver.d \
./MCAL/GP_Timers.d \
./MCAL/I2C.d \
./MCAL/RCC.d \
./MCAL/SPI.d \
./MCAL/Timer.d \
./MCAL/Timer1_8.d \
./MCAL/USART_Driver.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/%.o MCAL/%.su MCAL/%.cyclo: ../MCAL/%.c MCAL/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F103CBTx -DSTM32F1 -c -I../Inc -I"C:/Users/medoo/Desktop/Mastering-Embedded-System-Diploma/GRAD_Project/Graduation_Project_Finall/FreeRTOS/include" -I"C:/Users/medoo/Desktop/Mastering-Embedded-System-Diploma/GRAD_Project/Graduation_Project_Finall/FreeRTOS/portable/ARM_CM3" -I"C:/Users/medoo/Desktop/Mastering-Embedded-System-Diploma/GRAD_Project/Graduation_Project_Finall/FreeRTOS/portable/MemMang" -I"C:/Users/medoo/Desktop/Mastering-Embedded-System-Diploma/GRAD_Project/Graduation_Project_Finall/HAL/inc" -I"C:/Users/medoo/Desktop/Mastering-Embedded-System-Diploma/GRAD_Project/Graduation_Project_Finall/MCAL/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-MCAL

clean-MCAL:
	-$(RM) ./MCAL/ADC.cyclo ./MCAL/ADC.d ./MCAL/ADC.o ./MCAL/ADC.su ./MCAL/CAN.cyclo ./MCAL/CAN.d ./MCAL/CAN.o ./MCAL/CAN.su ./MCAL/EEPROM.cyclo ./MCAL/EEPROM.d ./MCAL/EEPROM.o ./MCAL/EEPROM.su ./MCAL/EXTI_Driver.cyclo ./MCAL/EXTI_Driver.d ./MCAL/EXTI_Driver.o ./MCAL/EXTI_Driver.su ./MCAL/GPIO_Driver.cyclo ./MCAL/GPIO_Driver.d ./MCAL/GPIO_Driver.o ./MCAL/GPIO_Driver.su ./MCAL/GP_Timers.cyclo ./MCAL/GP_Timers.d ./MCAL/GP_Timers.o ./MCAL/GP_Timers.su ./MCAL/I2C.cyclo ./MCAL/I2C.d ./MCAL/I2C.o ./MCAL/I2C.su ./MCAL/RCC.cyclo ./MCAL/RCC.d ./MCAL/RCC.o ./MCAL/RCC.su ./MCAL/SPI.cyclo ./MCAL/SPI.d ./MCAL/SPI.o ./MCAL/SPI.su ./MCAL/Timer.cyclo ./MCAL/Timer.d ./MCAL/Timer.o ./MCAL/Timer.su ./MCAL/Timer1_8.cyclo ./MCAL/Timer1_8.d ./MCAL/Timer1_8.o ./MCAL/Timer1_8.su ./MCAL/USART_Driver.cyclo ./MCAL/USART_Driver.d ./MCAL/USART_Driver.o ./MCAL/USART_Driver.su

.PHONY: clean-MCAL

