.text

main:

li x12 1
addi sp sp -4
sw x12 0(sp)
jal fibonachy
addi sp sp 4
li x10 1
ecall

li x12 2
addi sp sp -4
sw x12 0(sp)
jal fibonachy
addi sp sp 4
li x10 1
ecall

li x12 3
addi sp sp -4
sw x12 0(sp)
jal fibonachy
addi sp sp 4
li x10 1
ecall

li x12 4
addi sp sp -4
sw x12 0(sp)
jal fibonachy
addi sp sp 4
li x10 1
ecall

li x12 5
addi sp sp -4
sw x12 0(sp)
jal fibonachy
addi sp sp 4
li x10 1
ecall

li x12 6
addi sp sp -4
sw x12 0(sp)
jal fibonachy
addi sp sp 4
li x10 1
ecall

li x12 7
addi sp sp -4
sw x12 0(sp)
jal fibonachy
addi sp sp 4
li x10 1
ecall

li x10 10
ecall


fibonachy:
li x11 1
li x10 1
lw x13 0(sp)
addi x13 x13 -2
rec:
ble x13 x0 end
addi x13 x13 -1
mv x12 x11
add x11 x11 x10
mv x10 x12
j rec
end:
ret