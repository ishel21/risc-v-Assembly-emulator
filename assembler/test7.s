.text

xarisx:
lw x10 0(sp)
lw x12 4(sp)
lw x11 0(sp)
addi x12 x12 -1
rec:
bge x0 x12 end
mul x11 x11 x10
addi x12 x12 -1
j rec
end:
ret


main:
#test 5^3
li x13 5
li x14 3
addi sp sp -8
sw x13 0(sp)
sw x14 4(sp)
jal xarisx
addi sp sp 8

li x10 1
ecall

#test 6^2
li x13 6
li x14 2
addi sp sp -8
sw x13 0(sp)
sw x14 4(sp)
jal xarisx
addi sp sp 8

li x10 1
ecall

#test 2^10
li x13 2
li x14 10
addi sp sp -8
sw x13 0(sp)
sw x14 4(sp)
jal xarisx
addi sp sp 8

li x10 1
ecall

li x10 10
ecall


