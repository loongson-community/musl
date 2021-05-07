#ifndef __loongarch_soft_float

.global	feclearexcept
.type	feclearexcept,@function
feclearexcept:
	//andi	$a0, $a0, 0x1f0000 // la: exception bits in 16-20 bit of fcsr0.
        li      $a1, 0x1f0000
        and     $a0, $a0, $a1
	movfcsr2gr $a1, $r0 // r0 is fpu control status register 0(fcsr0), r0 -> fcsr0, r1 -> fcsr1, r2 -> fcsr2, r3 - fcsr3
	or	$a1, $a1, $a0
	xor	$a1, $a1, $a0
	movgr2fcsr $r0, $a1
        li      $v0, 0
	jr	$ra

.global	feraiseexcept
.type	feraiseexcept,@function
feraiseexcept:
	//andi	$a0, $a0, 0x1f0000
        li      $a1, 0x1f0000
        and     $a0, $a0, $a1
	movfcsr2gr $a1, $r0
	or	$a1, $a1, $a0
	movgr2fcsr $r0, $a1
        li      $v0, 0
	jr	$ra

.global	fetestexcept
.type	fetestexcept,@function
fetestexcept:
	//andi	$a0, $a0, 0x1f0000
        li      $a1, 0x1f0000
        and     $a0, $a0, $a1
	movfcsr2gr $a1, $r0
        and     $v0, $a1, $a0
	jr	$ra

.global	fegetround
.type	fegetround,@function
fegetround:
	movfcsr2gr $v0, $r0
        andi    $v0, $v0, 0x300 // RM
	jr	$ra

.global	__fesetround
.hidden __fesetround
.type	__fesetround,@function
__fesetround:
	movfcsr2gr $a1, $r0
	li	$a2, -769
	and	$a1, $a1, $a2
	or	$a1, $a1, $a0
	movgr2fcsr $r0, $a1
        li      $v0, 0
	jr	$ra

.global	fegetenv
.type	fegetenv,@function
fegetenv:
	movfcsr2gr $a1, $r0
	st.w	$a1, $a0, 0
        li      $v0, 0
	jr	$ra

.global	fesetenv
.type	fesetenv,@function
fesetenv:
	addi.d	$a1, $a0, 1
	beq	$a1, $r0, 1f
	ld.w	$a1, $a0, 0
1:	movgr2fcsr $r0, $a1
        li      $v0, 0
	jr	$ra

#endif
