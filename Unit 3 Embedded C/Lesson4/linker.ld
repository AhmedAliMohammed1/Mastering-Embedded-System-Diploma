/*LINKER script FOR STM32F103C6*/
/*ENG : Ahmed Ali Mohammed*/


MEMORY
{
FLASH (RX) : ORIGIN = 0x00000000 ,LENGTH = 512M
SRAM (RWX) : ORIGIN = 0x20000000 , LENGTH = 512M

}

SECTIONS
{
	.text :
	{
	*(.vectors*)
	*(.text*)
	*(.rodata)
	_E_text = . ;
	}> FLASH
	.data :
	{
	_S_DATA = .;
	*(.data)
	_E_DATA = .;
	. = ALIGN(4);
	}> SRAM AT> FLASH
	
	.bss :
	{
	_S_BSS = .;
	*(.bss*)
	. = ALIGN(4);
	_E_BSS = .;
	. = ALIGN(4);

	}> SRAM
}