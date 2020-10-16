LOAD_ADDRESS = 0x8000;

SECTIONS
{
	. = LOAD_ADDRESS;
    .text : { KEEP(*(.text.boot)) *(.text .text.* .gnu.linkonce.t*) }
    .rodata : { *(.rodata .rodata.* .gnu.linkonce.r*) }
    .data : { *(.data .data.* .gnu.linkonce.d*) }
    _end = .;
}
