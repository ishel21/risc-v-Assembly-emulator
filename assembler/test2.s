.text

sum:
lw x11 0(sp)
lw x12 4(sp)
add x13 x11 x12
ret

diff:
lw x11 0(sp)
lw x12 4(sp)
sub x13 x11 x12
ret

mult:
lw x11 0(sp)
lw x12 4(sp)
mul x13 x11 x12
ret

deva:
lw x11 0(sp)
lw x12 4(sp)
dev x13 x11 x12
ret

main:

li x14 25
li x12 5

addi sp sp -8
sw x14 0(sp)
sw x12 4(sp)
call sum
addi sp sp 8
mv x11 x13
li x10 1
ecall

addi sp sp -8
sw x14 0(sp)
sw x12 4(sp)
call diff
addi sp sp 8
mv x11 x13
li x10 1
ecall

addi sp sp -8
sw x14 0(sp)
sw x12 4(sp)
call mult
addi sp sp 8
mv x11 x13
li x10 1
ecall

addi sp sp -8
sw x14 0(sp)
sw x12 4(sp)
call deva
addi sp sp 8
mv x11 x13
li x10 1
ecall

li x10 10
ecall