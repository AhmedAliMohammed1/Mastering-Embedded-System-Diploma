/*LINKER script FOR STM32F103C6*/
/*ENG : Ahmed Ali Mohammed*/


MEMORY
{
FLASH (RX) : ORIGIN = 0x08000000 ,LENGTH = 128K
SRAM (RWX) : ORIGIN = 0x20000000 , LENGTH = 20K

}

SECTIONS
{
	.text :
	{
	*(.vector*)
	*(.text*)
	*(.rodata)

	}> FLASH
	.data :
	{
	*(.data)
	
	}> FLASH
	
	.bss :
	{
	*(.bss*)
	}> SRAM
}