.global sigsetjmp
.global __sigsetjmp
.type   sigsetjmp,@function
.type   __sigsetjmp,@function
sigsetjmp:
__sigsetjmp:
        or $t5, $a0, $zero
        or $t6, $a1, $zero

        # comparing save mask with 0, if equals to 0 then
        # sigsetjmp is equal to setjmp.
        beq     $t6, $zero, 1f
        st.d    $ra, $t5, 160
        st.d    $s0, $t5, 168

        # save base of got so that we can use it later
        # once we return from 'longjmp'
        la.global       $t8, setjmp
        or      $s0, $a0, $zero
        jirl    $ra, $t8, 0

        or      $v1, $v0, $zero         # Return from 'setjmp' or 'longjmp'
        ld.d    $ra, $t5, 160   # Restore ra of sigsetjmp
        ld.d    $s0, $t5, 168   # Restore $s0 of sigsetjmp
        or      $a0, $t5, $zero

.hidden __sigsetjmp_tail
        la.global       $t8, __sigsetjmp_tail
        jr      $t8
1:
        la.global       $t8, setjmp
        jr      $t8

