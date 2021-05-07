.global pipe
.type   pipe,@function
pipe:
	move	$a1, $r0
	li	$a7, 59
	syscall	0
	li	$t0, -4096
	bgeu	$t0, $v0, 1f
	la.global	$t1, __syscall_ret
	jr	$t1
1:	move	$v0, $r0
	jr	$ra
