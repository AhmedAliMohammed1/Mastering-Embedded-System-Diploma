################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/KEYPAD.c \
../HAL/LCD.c \
../HAL/LCD2.c \
../HAL/SPI_EEPROM.c \
../HAL/Servo_Motor.c 

OBJS += \
./HAL/KEYPAD.o \
./HAL/LCD.o \
./HAL/LCD2.o \
./HAL/SPI_EEPROM.o \
./HAL/Servo_Motor.o 

C_DEPS += \
./HAL/KEYPAD.d \
./HAL/LCD.d \
./HAL/LCD2.d \
./HAL/SPI_EEPROM.d \
./HAL/Servo_Motor.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/KEYPAD.o: ../HAL/KEYPAD.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/medoo/Desktop/WorkSpace/SecondTerm_FINAL_PROJECT/MCAL/inc" -I"C:/Users/medoo/Desktop/WorkSpace/SecondTerm_FINAL_PROJECT/HAL/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/KEYPAD.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
HAL/LCD.o: ../HAL/LCD.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/medoo/Desktop/WorkSpace/SecondTerm_FINAL_PROJECT/MCAL/inc" -I"C:/Users/medoo/Desktop/WorkSpace/SecondTerm_FINAL_PROJECT/HAL/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/LCD.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
HAL/LCD2.o: ../HAL/LCD2.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/medoo/Desktop/WorkSpace/SecondTerm_FINAL_PROJECT/MCAL/inc" -I"C:/Users/medoo/Desktop/WorkSpace/SecondTerm_FINAL_PROJECT/HAL/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/LCD2.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
HAL/SPI_EEPROM.o: ../HAL/SPI_EEPROM.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/medoo/Desktop/WorkSpace/SecondTerm_FINAL_PROJECT/MCAL/inc" -I"C:/Users/medoo/Desktop/WorkSpace/SecondTerm_FINAL_PROJECT/HAL/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/SPI_EEPROM.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
HAL/Servo_Motor.o: ../HAL/Servo_Motor.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/medoo/Desktop/WorkSpace/SecondTerm_FINAL_PROJECT/MCAL/inc" -I"C:/Users/medoo/Desktop/WorkSpace/SecondTerm_FINAL_PROJECT/HAL/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/Servo_Motor.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

