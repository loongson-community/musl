.global	__set_thread_area
.type	__set_thread_area, @function
__set_thread_area:
	or	$tp, $a0, $zero
	ori	$a0, $zero, 0
	jirl	$zero, $ra, 0

