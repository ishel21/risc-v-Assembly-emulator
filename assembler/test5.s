main:
		
addi sp sp -8

li x10 11
li x11 10
ecall

li x10 1
sw x10 4(sp)

li x10 1
sw x10 0(sp)

enter_for:

lw x10 0(sp)
li x11 5
bgt x10 x11 past_for

lw x10 0(sp)
lw x11 4(sp)
beq x10 x11 past_if

li x10 1
lw x11 0(sp)
lw x12 0(sp)
mul x11 x11 x11
sub x11 x11 x12
ecall

li x10 11
li x11 32
ecall

past_if:

lw x10 0(sp)
addi x10 x10 1
sw x10 0(sp)

j enter_for

past_for:

li x10 11
li x11 10
ecall

addi sp sp 8

li x10 10
ecall

