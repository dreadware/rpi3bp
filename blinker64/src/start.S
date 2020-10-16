
_start:
	mrs	x0, mpidr_el1
	and	x0, x0, #3
	cmp	x0, #0
	beq	_entry

_sleep:
	b	  _sleep

_entry:
	mov	sp, #0x800000
	bl 	main
