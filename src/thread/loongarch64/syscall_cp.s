.global	__cp_begin
.hidden	__cp_begin
.type	__cp_begin,@function
.global	__cp_end
.hidden	__cp_end
.type	__cp_end,@function
.global	__cp_cancel
.hidden	__cp_cancel
.type	__cp_cancel,@function
.hidden	__cancel
.global	__syscall_cp_asm
.hidden	__syscall_cp_asm
.type	__syscall_cp_asm,@function

__syscall_cp_asm:
__cp_begin:
	ld.w	$a0, $a0, 0
	bnez	$a0, __cp_cancel
	or	$t8, $a1, $zero     # reserve system call number
	or	$a0, $a2, $zero
	or	$a1, $a3, $zero
	or	$a2, $a4, $zero
	or	$a3, $a5, $zero
	or	$a4, $a6, $zero
	or	$a5, $a7, $zero
	ld.d	$a6, $sp, 0
	or	$a7, $t8, $zero
	syscall	0
__cp_end:
	jirl	$zero, $ra, 0
__cp_cancel:
	la.local $t8, __cancel
	jirl	$zero, $t8, 0

