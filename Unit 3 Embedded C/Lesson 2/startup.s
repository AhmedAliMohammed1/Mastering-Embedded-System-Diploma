.global ahmed
ahmed:
	ldr sp, =stack_top
	bl not_main
stop: b stop