.global	__unmapself
.type	__unmapself, @function
__unmapself:
	ori	$a7, $zero, 215
	syscall	0				# call munmap
	ori	$a0, $zero, 0
	ori	$a7, $zero, 93
	syscall	0				# call exit
