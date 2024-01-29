################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/KEYPAD.c \
../HAL/LCD.c \
../HAL/SPI_EEPROM.c \
../HAL/Servo.c 

OBJS += \
./HAL/KEYPAD.o \
./HAL/LCD.o \
./HAL/SPI_EEPROM.o \
./HAL/Servo.o 

C_DEPS += \
./HAL/KEYPAD.d \
./HAL/LCD.d \
./HAL/SPI_EEPROM.d \
./HAL/Servo.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/KEYPAD.o: ../HAL/KEYPAD.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -I"C:/Users/Ahmed/STM32CubeIDE/workspace_1.4.0/GRAD_Project/uart_bug/MCAL/inc" -I"C:/Users/Ahmed/STM32CubeIDE/workspace_1.4.0/GRAD_Project/uart_bug/HAL/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/KEYPAD.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
HAL/LCD.o: ../HAL/LCD.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -I"C:/Users/Ahmed/STM32CubeIDE/workspace_1.4.0/GRAD_Project/uart_bug/MCAL/inc" -I"C:/Users/Ahmed/STM32CubeIDE/workspace_1.4.0/GRAD_Project/uart_bug/HAL/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/LCD.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
HAL/SPI_EEPROM.o: ../HAL/SPI_EEPROM.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -I"C:/Users/Ahmed/STM32CubeIDE/workspace_1.4.0/GRAD_Project/uart_bug/MCAL/inc" -I"C:/Users/Ahmed/STM32CubeIDE/workspace_1.4.0/GRAD_Project/uart_bug/HAL/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/SPI_EEPROM.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
HAL/Servo.o: ../HAL/Servo.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -I"C:/Users/Ahmed/STM32CubeIDE/workspace_1.4.0/GRAD_Project/uart_bug/MCAL/inc" -I"C:/Users/Ahmed/STM32CubeIDE/workspace_1.4.0/GRAD_Project/uart_bug/HAL/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL/Servo.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

