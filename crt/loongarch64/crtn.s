.section .init
	ld.d	$r31,$r3,16
	ld.d	$r1,$r3,24
	addi.d	$r3,$r3,32
	jirl	$r0,$r1,0


.section .fini
	ld.d	$r31,$r3,16
	ld.d	$r1,$r3,24
	addi.d	$r3,$r3,32
	jirl	$r0,$r1,0
