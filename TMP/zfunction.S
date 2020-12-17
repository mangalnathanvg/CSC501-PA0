;Reference:  http://flint.cs.yale.edu/cs421/papers/x86-asm/asm.html
;	     https://en.wikibooks.org/wiki/X86_Assembly/GAS_Syntax	
.globl zfunction

zfunction:
 	/* Following callee rules, by maintaining the base pointer as a point of reference for finding parameters
	and local variables on the stack*/
	pushl %ebp
	movl %esp, %ebp
	
	/* Get the value of the parameter passed to zfunction which is always stored at EBP + 8.
	The function parameter is stored into EAX which is a general purpose register (like a variable, but also important at the same time)*/
	movl 8(%ebp), %eax

	/* AND operation to clear 9th to 17th bits from the right*/
	andl $0xfffc01ff, %eax
	
	/* Shift right by 8 bits*/
	shr $8, %eax
	
	/* Filling leftmost 8 bits by 1*/
	orl $0xff000000, %eax
	
	/* Deallocate the local variable space*/
	movl %ebp, %esp

	/* Restore the caller's base pointer value*/
	popl %ebp

	/* Return the value of EAX register to the caller*/
	ret
