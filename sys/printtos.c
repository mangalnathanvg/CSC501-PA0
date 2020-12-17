#include<stdio.h>

//static unsigned long *esp;
static unsigned long *ebp;
static unsigned long *esp;

void printtos()
{
		
	printf("\n\nvoid printtos()");	
//	printprocstks(2);
	asm("movl %esp, esp");
	asm("movl %ebp, ebp");

// Commented code was used for investigating the runtime stack to understand how ESP and EBP worked.

	int M = 14113;
	int N = 14114;
/*        
	printf("%d", M);
	printf("%d", N);

	printf("\n**************************PrintTOS Function Call************************\n");
	
	int j=18;
	
	while(j>0)
	{
	        printf("\nebp + %d :  0x%08x --- 0x%08x",j, ebp+j, *(ebp+j));
		j--;
	}

	printf("\nebp      : 0x%08x --- 0x%08x", ebp, *ebp);
	
	int i = 1;

	while(i<=10){
        printf("\nebp - %d :  0x%08x --- 0x%08x",i, ebp-i, *(ebp-i));
	i++;
	}
	
	unsigned long **p;
	p = *ebp;
*/
	// EBP is the Base pointer that points to the base of the stack frame. EBP is populated after printtos function is called in main.c
	// EBP + 1 stores the return address to main.c. This is populated right when printtos is called in main.c
	// EBP + 2 is the location right before printtos() is called in main.c

	//printf("\n**************************Top of Stack Runtime Stack right before printtos()**************************\n");
	printf("\nBefore[0x%08x]: 0x%08x", ebp+2, *(ebp+2));
	

      	//printf("\n**************************Top of Stack Runtime Stack right after printtos()**************************\n");
       	printf("\nAfter[0x%08x]: 0x%08x", ebp, *ebp);


	// Printing the address and their contents of upto four stack locations below the top of the stack.
	// Top of the stack is pointed by ESP - Stack Pointer. So the 4 locations below ESP are directly printed as shown below.
	// ESP should be less than EBP for the current stack frame. If ESP crosses EBP then we begin to access the stack frame for the function that called printtos().

	int k = 1;

	while(esp + k < ebp && k<=4)
	{
		printf("\n\telement[0x%08x]: 0x%08x", esp+k, *(esp+k));
		k++; 
	}

}
