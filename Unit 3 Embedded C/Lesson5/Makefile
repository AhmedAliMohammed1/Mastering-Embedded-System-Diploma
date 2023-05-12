CC=arm-none-eabi-
CFLAGS=-mcpu=cortex-m3 -gdwarf-2  -mthumb
INCS= -I .
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
LIB=
As=$(wildcard *.s)
AsOBJ=$(As:.s=.o)
ProjectName=app
all: $(ProjectName).bin $(ProjectName).hex
		@echo "===============$(ProjectName) Build is done ================" 
%.o:%.s
	$(CC)as.exe $(CFLAGS) $< -o $@ 
%.o:%.c
	$(CC)gcc.exe $(CFLAGS) $(INCS) -c $< -o $@
$(ProjectName).elf:$(OBJ) $(AsOBJ) 
	$(CC)ld.exe -T linker.ld $(OBJ) $(AsOBJ) $(LIB) -o $@ -Map=Map_file.map
$(ProjectName).bin:$(ProjectName).elf
	$(CC)objcopy.exe -O binary $< $@
$(ProjectName).hex:$(ProjectName).elf
	$(CC)objcopy.exe -O ihex $< $@
clean :
	rm *.elf *.bin *.hex
	
clean_all:
	rm *.elf *.o *.bin *.hex
	@echo "===============$(ProjectName) clean is done ================" 