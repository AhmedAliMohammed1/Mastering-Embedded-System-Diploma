################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/MCAL/GPIO_Driver.c \
../Drivers/MCAL/KEYPAD.c \
../Drivers/MCAL/LCD.c 

OBJS += \
./Drivers/MCAL/GPIO_Driver.o \
./Drivers/MCAL/KEYPAD.o \
./Drivers/MCAL/LCD.o 

C_DEPS += \
./Drivers/MCAL/GPIO_Driver.d \
./Drivers/MCAL/KEYPAD.d \
./Drivers/MCAL/LCD.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/MCAL/GPIO_Driver.o: ../Drivers/MCAL/GPIO_Driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/medoo/Desktop/Mastering-Embedded-System-Diploma/Unit7/Lesson 3/Section/LCD_KEYPAD/Drivers/inc" -I"C:/Users/medoo/Desktop/Mastering-Embedded-System-Diploma/Unit7/Lesson 3/Section/LCD_KEYPAD/Drivers/inc" -I"C:/Users/medoo/Desktop/Mastering-Embedded-System-Diploma/Unit7/Lesson 3/Section/LCD_KEYPAD/Drivers" -I"C:/Users/medoo/Desktop/Mastering-Embedded-System-Diploma/Unit7/Lesson 3/Section/LCD_KEYPAD/Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/MCAL/GPIO_Driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/MCAL/KEYPAD.o: ../Drivers/MCAL/KEYPAD.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/medoo/Desktop/Mastering-Embedded-System-Diploma/Unit7/Lesson 3/Section/LCD_KEYPAD/Drivers/inc" -I"C:/Users/medoo/Desktop/Mastering-Embedded-System-Diploma/Unit7/Lesson 3/Section/LCD_KEYPAD/Drivers/inc" -I"C:/Users/medoo/Desktop/Mastering-Embedded-System-Diploma/Unit7/Lesson 3/Section/LCD_KEYPAD/Drivers" -I"C:/Users/medoo/Desktop/Mastering-Embedded-System-Diploma/Unit7/Lesson 3/Section/LCD_KEYPAD/Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/MCAL/KEYPAD.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/MCAL/LCD.o: ../Drivers/MCAL/LCD.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/medoo/Desktop/Mastering-Embedded-System-Diploma/Unit7/Lesson 3/Section/LCD_KEYPAD/Drivers/inc" -I"C:/Users/medoo/Desktop/Mastering-Embedded-System-Diploma/Unit7/Lesson 3/Section/LCD_KEYPAD/Drivers/inc" -I"C:/Users/medoo/Desktop/Mastering-Embedded-System-Diploma/Unit7/Lesson 3/Section/LCD_KEYPAD/Drivers" -I"C:/Users/medoo/Desktop/Mastering-Embedded-System-Diploma/Unit7/Lesson 3/Section/LCD_KEYPAD/Drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/MCAL/LCD.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

