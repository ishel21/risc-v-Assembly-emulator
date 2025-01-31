.text
main:
	
addi sp sp -12

li x10 45
sw x10 8(sp)

li x10 30
sw x10 4(sp)

li x10 32
sw x10 0(sp)

li x10 1
lw x11 8(sp)
ecall

li x10 1
lw x11 4(sp)
ecall

li x10 1
lw x11 0(sp)
ecall

addi sp sp 12

li x10 10
ecall