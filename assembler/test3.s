.text


main:

#if(6 == 6) 1 else 0
li x12 6
li x13 6
beq x12 x13 if1
li x11 0
li x10 1
ecall
j else1
if1:
li x11 1
li x10 1
ecall
else1:

#if(156 != 478) 1 else 0
li x12 156
li x13 478
bne x12 x13 if2
li x11 0
li x10 1
ecall
j else2
if2:
li x11 1
li x10 1
ecall
else2:

#if(598 < 478) 1 else 0
li x12 598
li x13 478
blt x12 x13 if3
li x11 0
li x10 1
ecall
j else3
if3:
li x11 1
li x10 1
ecall
else3:

#if(300 >= 300) 1 else 0
li x12 300
li x13 300
bge x12 x13 if4
li x11 0
li x10 1
ecall
j else4
if4:
li x11 1
li x10 1
ecall
else4:

#if(1200 <= 54) 1 else 0
li x12 1200
li x13 54
ble x12 x13 if5
li x11 0
li x10 1
ecall
j else5
if5:
li x11 1
li x10 1
ecall
else5:

#if(300 > 700) 1 else 0
li x12 300
li x13 700
bgt x12 x13 if6
li x11 0
li x10 1
ecall
j else6
if6:
li x11 1
li x10 1
ecall
else6:

li x10 10
ecall