
Allocating common symbols
Common symbol       size              file

arr                 0x1               main.o

Memory Configuration

Name             Origin             Length             Attributes
Mem              0x00000000         0x04000000         xrw
*default*        0x00000000         0xffffffff

Linker script and memory map

                0x00010000                . = 0x10000

.startup        0x00010000       0x10
 startup.o(.text)
 .text          0x00010000       0x10 startup.o
                0x00010000                ahmed

.text           0x00010010       0xcc
 *(.text)
 .text          0x00010010       0x18 main.o
                0x00010010                main
 .text          0x00010028       0x50 uart.o
                0x00010028                UART_sendString
 *(.rodata)
 .rodata        0x00010078       0x64 main.o
                0x00010078                str1

.glue_7         0x000100dc        0x0
 .glue_7        0x00000000        0x0 linker stubs

.glue_7t        0x000100dc        0x0
 .glue_7t       0x00000000        0x0 linker stubs

.vfp11_veneer   0x000100dc        0x0
 .vfp11_veneer  0x00000000        0x0 linker stubs

.v4_bx          0x000100dc        0x0
 .v4_bx         0x00000000        0x0 linker stubs

.iplt           0x000100dc        0x0
 .iplt          0x00000000        0x0 startup.o

.rel.dyn        0x000100dc        0x0
 .rel.iplt      0x00000000        0x0 startup.o

.data           0x000100dc       0x64
 *(.data)
 .data          0x000100dc        0x0 startup.o
 .data          0x000100dc       0x64 main.o
                0x000100dc                str
 .data          0x00010140        0x0 uart.o

.igot.plt       0x00010140        0x0
 .igot.plt      0x00000000        0x0 startup.o

.bss            0x00010140        0x1
 *(.bss)
 .bss           0x00010140        0x0 startup.o
 .bss           0x00010140        0x0 main.o
 .bss           0x00010140        0x0 uart.o
 *(.COMMON)
 COMMON         0x00010140        0x1 main.o
                0x00010140                arr
                0x00011141                . = (. + 0x1000)
                0x00011141                stack_top = .
LOAD startup.o
LOAD main.o
LOAD uart.o
OUTPUT(app.elf elf32-littlearm)

.ARM.attributes
                0x00000000       0x2e
 .ARM.attributes
                0x00000000       0x22 startup.o
 .ARM.attributes
                0x00000022       0x32 main.o
 .ARM.attributes
                0x00000054       0x32 uart.o

.comment        0x00000000       0x11
 .comment       0x00000000       0x11 main.o
                                 0x12 (size before relaxing)
 .comment       0x00000000       0x12 uart.o

.debug_line     0x00000000       0x3a
 .debug_line    0x00000000       0x3a startup.o

.debug_info     0x00000000       0x9d
 .debug_info    0x00000000       0x9d startup.o

.debug_abbrev   0x00000000       0x14
 .debug_abbrev  0x00000000       0x14 startup.o

.debug_aranges  0x00000000       0x20
 .debug_aranges
                0x00000000       0x20 startup.o
