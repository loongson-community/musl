.section .init
.global _init
.align 3
_init:
	addi.d	$r3,$r3,-32
	st.d	$r31,$r3,16
	st.d	$r1,$r3,24

.section .fini
.global _fini
.align 3
_fini:
	addi.d	$r3,$r3,-32
	st.d	$r31,$r3,16
	st.d	$r1,$r3,24
