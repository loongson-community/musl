.global dlsym
.hidden __dlsym
.type   dlsym,@function
dlsym:
	move	$r6, $ra
	la.global	$r16, __dlsym
	addi.d 	$sp, $sp, -32
	st.d	$ra, $sp, 24
	jirl	$ra, $r16, 0
	ld.d	$ra, $sp, 24
	addi.d	$sp, $sp, 32
	jr	$ra
