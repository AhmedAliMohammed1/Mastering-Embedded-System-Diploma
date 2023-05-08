CC=arm-none-eabi-
CFLAGS= -mcpu=cortex-m3 -gdwarf-2 
INCS=-I .
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
LIB=
As=$(wildcard *.s)
AsOBJ=$(As:.s=.o)
ProjectName=app
all: $(ProjectName).bin
		@echo "===============$(ProjectName) Build is done ================" 
%.o:%.s
	$(CC)as.exe $(CFLAGS) $< -o $@ 
%.o:%.c
	$(CC)gcc.exe $(CFLAGS) $(INCS) -c $< -o $@
$(ProjectName).elf:$(OBJ) $(AsOBJ) 
	$(CC)ld.exe -T linker.ld $(OBJ) $(AsOBJ) $(LIB) -o $@ -Map=Map_file.map
$(ProjectName).bin:$(ProjectName).elf
	$(CC)objcopy.exe -O binary $< $@

clean :
	rm *.elf *.bin
	
clean_all:
	rm *.elf *.o *.bin