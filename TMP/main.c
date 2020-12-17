/* user.c - main */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>
#include <lab0.h>
/*------------------------------------------------------------------------
 *  main  --  user main program
 *------------------------------------------------------------------------
	Commented Code was used to display the call stack for this function
 */
/*
static unsigned long *ebp;
static unsigned long *esp;
*/
int prX;
void newprocess(char c)
{
	int i;
	sleep(1);
}

int main()
{
	kprintf("\n\nHello World, Xinu lives\n\n");
	long res = zfunction(0xaabbccdd);
	kprintf("\nZfunction(0xaabbccdd) = 0x%08x\n", res);
/*
	asm("movl %ebp, ebp");
	asm("movl %esp, esp");
*/
	syscallsummary_start();
	printsegaddress();

	long int var0 = 200285591;
	int var1 = 10;
      //kprintf("\n%d", var0);
      //kprintf("\n%d", var1);
/*
        kprintf("\n******************Before PrintTOS() Call -  Main Function***********************\n");
	
	kprintf("\nebp      : 0x%08x --- 0x%08x", ebp, *ebp);

        int i = 1;

        while(i<=10){
        kprintf("\nebp - %d :  0x%08x --- 0x%08x",i, ebp-i, *(ebp-i));
        i++;
        }

        kprintf("\nesp      : 0x%08x --- 0x%08x", esp, *esp);
*/
	printtos();	
	sleep(1);
	sleep(1);	

	// Create new processes to check entry in proctab.
	resume(prX = create(newprocess, 1024, 30, "MVG Process 1", 1, 'A'));
        //resume(create(newprocess, 1024, 31, "MVG Process 2", 1,14114));
	//resume(create(newprocess, 1024, 9, "Low Priority MVG Process", 1, 2000));
	
	int priority = 10;
	
	printprocstks(priority);
	syscallsummary_stop();
	printsyscallsummary();
	return 0;
}
