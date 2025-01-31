main:
		
addi sp sp -4

li x10 -43
sh x10 2(sp)

li x10 -38
sh x10 0(sp)

li x10 1
lh x11 2(sp)
ecall

li x10 11
li x11 10
ecall

li x10 1
lh x11 0(sp)
ecall

li x10 11
li x11 10
ecall

lh x10 2(sp)

lh x11 0(sp)
sh x11 2(sp)

sh x10 0(sp)

li x10 1
lh x11 2(sp)
ecall

li x10 11
li x11 10
ecall

li x10 1
lh x11 0(sp)
ecall

li x10 11
li x11 10
ecall

addi sp sp 4

li x10 10
ecall