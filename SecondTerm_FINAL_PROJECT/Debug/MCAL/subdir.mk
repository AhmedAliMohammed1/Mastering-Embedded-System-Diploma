################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/EEPROM.c \
../MCAL/EXTI_Driver.c \
../MCAL/GPIO_Driver.c \
../MCAL/I2C.c \
../MCAL/RCC.c \
../MCAL/SPI.c \
../MCAL/Timer.c \
../MCAL/USART_Driver.c 

OBJS += \
./MCAL/EEPROM.o \
./MCAL/EXTI_Driver.o \
./MCAL/GPIO_Driver.o \
./MCAL/I2C.o \
./MCAL/RCC.o \
./MCAL/SPI.o \
./MCAL/Timer.o \
./MCAL/USART_Driver.o 

C_DEPS += \
./MCAL/EEPROM.d \
./MCAL/EXTI_Driver.d \
./MCAL/GPIO_Driver.d \
./MCAL/I2C.d \
./MCAL/RCC.d \
./MCAL/SPI.d \
./MCAL/Timer.d \
./MCAL/USART_Driver.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/EEPROM.o: ../MCAL/EEPROM.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/medoo/Desktop/WorkSpace/SecondTerm_FINAL_PROJECT/MCAL/inc" -I"C:/Users/medoo/Desktop/WorkSpace/SecondTerm_FINAL_PROJECT/HAL/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MCAL/EEPROM.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
MCAL/EXTI_Driver.o: ../MCAL/EXTI_Driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/medoo/Desktop/WorkSpace/SecondTerm_FINAL_PROJECT/MCAL/inc" -I"C:/Users/medoo/Desktop/WorkSpace/SecondTerm_FINAL_PROJECT/HAL/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MCAL/EXTI_Driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
MCAL/GPIO_Driver.o: ../MCAL/GPIO_Driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/medoo/Desktop/WorkSpace/SecondTerm_FINAL_PROJECT/MCAL/inc" -I"C:/Users/medoo/Desktop/WorkSpace/SecondTerm_FINAL_PROJECT/HAL/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MCAL/GPIO_Driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
MCAL/I2C.o: ../MCAL/I2C.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/medoo/Desktop/WorkSpace/SecondTerm_FINAL_PROJECT/MCAL/inc" -I"C:/Users/medoo/Desktop/WorkSpace/SecondTerm_FINAL_PROJECT/HAL/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MCAL/I2C.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
MCAL/RCC.o: ../MCAL/RCC.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/medoo/Desktop/WorkSpace/SecondTerm_FINAL_PROJECT/MCAL/inc" -I"C:/Users/medoo/Desktop/WorkSpace/SecondTerm_FINAL_PROJECT/HAL/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MCAL/RCC.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
MCAL/SPI.o: ../MCAL/SPI.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/medoo/Desktop/WorkSpace/SecondTerm_FINAL_PROJECT/MCAL/inc" -I"C:/Users/medoo/Desktop/WorkSpace/SecondTerm_FINAL_PROJECT/HAL/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MCAL/SPI.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
MCAL/Timer.o: ../MCAL/Timer.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/medoo/Desktop/WorkSpace/SecondTerm_FINAL_PROJECT/MCAL/inc" -I"C:/Users/medoo/Desktop/WorkSpace/SecondTerm_FINAL_PROJECT/HAL/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MCAL/Timer.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
MCAL/USART_Driver.o: ../MCAL/USART_Driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/medoo/Desktop/WorkSpace/SecondTerm_FINAL_PROJECT/MCAL/inc" -I"C:/Users/medoo/Desktop/WorkSpace/SecondTerm_FINAL_PROJECT/HAL/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"MCAL/USART_Driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

