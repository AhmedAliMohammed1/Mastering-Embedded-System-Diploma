################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HALL/DMS.c \
../HALL/KEYPAD.c \
../HALL/LCD.c \
../HALL/LUNA_LIDAR.c \
../HALL/SPI_EEPROM.c \
../HALL/Servo.c \
../HALL/TFT.c 

OBJS += \
./HALL/DMS.o \
./HALL/KEYPAD.o \
./HALL/LCD.o \
./HALL/LUNA_LIDAR.o \
./HALL/SPI_EEPROM.o \
./HALL/Servo.o \
./HALL/TFT.o 

C_DEPS += \
./HALL/DMS.d \
./HALL/KEYPAD.d \
./HALL/LCD.d \
./HALL/LUNA_LIDAR.d \
./HALL/SPI_EEPROM.d \
./HALL/Servo.d \
./HALL/TFT.d 


# Each subdirectory must supply rules for building sources it contributes
HALL/%.o HALL/%.su HALL/%.cyclo: ../HALL/%.c HALL/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F103CBTx -DSTM32F1 -c -I../Inc -I"C:/Users/medoo/Desktop/WorkSpace/DR_SOLIMAN_ELNGAR/MCAL/inc" -I"C:/Users/medoo/Desktop/WorkSpace/DR_SOLIMAN_ELNGAR/HALL/inc" -I"C:/Users/medoo/Desktop/WorkSpace/DR_SOLIMAN_ELNGAR/FreeRTOS/include" -I"C:/Users/medoo/Desktop/WorkSpace/DR_SOLIMAN_ELNGAR/FreeRTOS/portable/ARM_CM3" -I"C:/Users/medoo/Desktop/WorkSpace/DR_SOLIMAN_ELNGAR/FreeRTOS/portable/MemMang" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-HALL

clean-HALL:
	-$(RM) ./HALL/DMS.cyclo ./HALL/DMS.d ./HALL/DMS.o ./HALL/DMS.su ./HALL/KEYPAD.cyclo ./HALL/KEYPAD.d ./HALL/KEYPAD.o ./HALL/KEYPAD.su ./HALL/LCD.cyclo ./HALL/LCD.d ./HALL/LCD.o ./HALL/LCD.su ./HALL/LUNA_LIDAR.cyclo ./HALL/LUNA_LIDAR.d ./HALL/LUNA_LIDAR.o ./HALL/LUNA_LIDAR.su ./HALL/SPI_EEPROM.cyclo ./HALL/SPI_EEPROM.d ./HALL/SPI_EEPROM.o ./HALL/SPI_EEPROM.su ./HALL/Servo.cyclo ./HALL/Servo.d ./HALL/Servo.o ./HALL/Servo.su ./HALL/TFT.cyclo ./HALL/TFT.d ./HALL/TFT.o ./HALL/TFT.su

.PHONY: clean-HALL

