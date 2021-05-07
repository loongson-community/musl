.global	__clone
.hidden __clone
.type	__clone,@function
__clone:
	# Save function pointer and argument pointer on new thread stack
	addi.d	$a1, $a1, -16	# aligning stack to double word
	st.d	$a0, $a1, 0		# save function pointer
	st.d	$a3, $a1, 8		# save argument pointer

	# Shuffle (fn,sp,fl,arg,ptid,tls,ctid) to (fl,sp,ptid,tls,ctid)
	# sys_clone(u64 flags, u64 ustack_base, u64 parent_tidptr, u64 child_tidptr, u64 tls)
	or	$a0, $a2, $zero
	or	$a2, $a4, $zero
	or	$a3, $a6, $zero
	or	$a4, $a5, $zero
	ori	$a7, $zero, 220
	syscall 0				# call clone

	beqz	$a0, 1f			# whether child process
	jirl	$zero, $ra, 0	# parent process return
1:
	ld.d	$t8, $sp, 0     # function pointer
	ld.d	$a0, $sp, 8     # argument pointer
	jirl	$ra, $t8, 0     # call the user's function
	ori	$a7, $zero, 93
	syscall	0				# child process exit

