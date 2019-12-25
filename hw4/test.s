	.text
	.section .rodata  
	.align 3 
.LC0:  
	.string "z=%d\n"  
	.text  
	.align 1
	.globl main  
	.type main, @function 
main:  
	addi sp,sp,-1024  
	sd ra,1016(sp)  
	sd s0,1008(sp)  
	sd s1,1000(sp)  
	addi s0,sp,40 #stack point(240 stack entries)  
	addi s1,sp,0  #define 12 local variable 
 
 	#load 1 into local variable_0  
	li t1,1     
	addi s0,s0,4     
	sw  t1,0(s0) #push constant 1 onto the stack     

	lw  t1,0(s0) #pop from the top of the stack     
	addi s0,s0,-4  
	sw t1,0(s1) #store the value into local variable_1 
 
 	#load 2 into local variable_1  
	li t1,2 
	addi s0,s0,4     
	sw  t1,0(s0)          
	lw  t1,0(s0)     
	addi s0,s0,-4  
	sw t1,4(s1) 
 
 	#push 2 local variable onto the stack  
	lw t1,0(s1)  
	addi s0,s0,4  
	sw t1,0(s0) 
 
 	lw t1,4(s1) 
 	addi s0,s0,4  
	sw t1,0(s0) 
 
 	#add the top 2 numbers of the stack  
	lw t1,0(s0)  
	addi s0,s0,-4  
	lw t2,0(s0)  
	addi s0,s0,-4  
	add t3,t1,t2 
 
 	#store the result into local variable_2  
	sw t3,8(s0) 
 
 	#push local variable_2 onto the stack  
	lw t1,8(s0)  
	addi s0,s0,4  
	sw t1,0(s0) 
 
 	# "jump" if the top value on the stack is smaller then zero  
	lw t1,0(s0)  
	addi s0,s0,-4  
	blt t1,zero,.L2 
 
 	#if didn't jump, the print the local variable_2  
	lw a5,8(s0)  
	mv a1,a5  
	lui a5,%hi(.LC0)  
	addi a0,a5,%lo(.LC0)  
	call printf 
 
.L2:  #recover some register setting  
	li a5,0  
	mv a0,a5  
	ld ra,1016(sp)  
	ld s0,1008(sp)  
	ld s1,1000(sp)  
	addi sp,sp,1024  
	jr ra  
	.size main, .-main 
