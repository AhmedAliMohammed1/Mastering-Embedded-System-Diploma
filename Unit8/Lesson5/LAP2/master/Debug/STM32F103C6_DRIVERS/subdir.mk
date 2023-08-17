################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32F103C6_DRIVERS/EXTI_Driver.c \
../STM32F103C6_DRIVERS/GPIO_Driver.c \
../STM32F103C6_DRIVERS/RCC.c \
../STM32F103C6_DRIVERS/SPI.c \
../STM32F103C6_DRIVERS/USART_Driver.c 

OBJS += \
./STM32F103C6_DRIVERS/EXTI_Driver.o \
./STM32F103C6_DRIVERS/GPIO_Driver.o \
./STM32F103C6_DRIVERS/RCC.o \
./STM32F103C6_DRIVERS/SPI.o \
./STM32F103C6_DRIVERS/USART_Driver.o 

C_DEPS += \
./STM32F103C6_DRIVERS/EXTI_Driver.d \
./STM32F103C6_DRIVERS/GPIO_Driver.d \
./STM32F103C6_DRIVERS/RCC.d \
./STM32F103C6_DRIVERS/SPI.d \
./STM32F103C6_DRIVERS/USART_Driver.d 


# Each subdirectory must supply rules for building sources it contributes
STM32F103C6_DRIVERS/EXTI_Driver.o: ../STM32F103C6_DRIVERS/EXTI_Driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/Ahmed/Desktop/SPI_WORK/master/STM32F103C6_DRIVERS/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32F103C6_DRIVERS/EXTI_Driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32F103C6_DRIVERS/GPIO_Driver.o: ../STM32F103C6_DRIVERS/GPIO_Driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/Ahmed/Desktop/SPI_WORK/master/STM32F103C6_DRIVERS/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32F103C6_DRIVERS/GPIO_Driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32F103C6_DRIVERS/RCC.o: ../STM32F103C6_DRIVERS/RCC.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/Ahmed/Desktop/SPI_WORK/master/STM32F103C6_DRIVERS/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32F103C6_DRIVERS/RCC.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32F103C6_DRIVERS/SPI.o: ../STM32F103C6_DRIVERS/SPI.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/Ahmed/Desktop/SPI_WORK/master/STM32F103C6_DRIVERS/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32F103C6_DRIVERS/SPI.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
STM32F103C6_DRIVERS/USART_Driver.o: ../STM32F103C6_DRIVERS/USART_Driver.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/Ahmed/Desktop/SPI_WORK/master/STM32F103C6_DRIVERS/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32F103C6_DRIVERS/USART_Driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

