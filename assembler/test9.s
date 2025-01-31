main:

addi sp sp -4

li x12 5
sw x12 0(sp)

addi sp sp -4
lw x12 4(sp)
sw x12 0(sp)
call factorial
addi sp sp 4

addi sp sp -4

sw x10 0(sp)

li x10 11
li x11 10
ecall

li x10 1
lw x11 0(sp)
ecall

li x10 11
li x11 10
ecall

addi sp sp 8

li x10 10
ecall

factorial:

lw x12 0(sp)

bne x12 x0 else
addi x10 x0 1 
ret

else:
addi sp sp -8
addi x13 x12 -1
sw x13 0(sp)
sw ra 4(sp)
call factorial
lw ra 4(sp)
addi sp sp 8

lw x12 0(sp)

mul x10 x10 x12
ret