#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>

static unsigned long *esp;
void printprocstks(int priority)
{
	printf("\n\nvoid printprocstks(int priority)\n");
	int i=0;
	while( i < NPROC) // The constant NPROC specifies the number of processes and the process identifiers range from 0 through NPROC - 1 
	{
		// Checking the priority for every process entry (pentry) in proctab array.	
		if(proctab[i].pprio > priority)
		{
			printf("\nProcess [%s]", proctab[i].pname);                
			printf("\n\tpid: %d", getpid());
			printf("\n\tpriority: %d", proctab[i].pprio);
			printf("\n\tbase: 0x%08x", proctab[i].pbase);
			printf("\n\tlen: %d", proctab[i].pstklen);
		
			//Since processes that are currently running will always have updated esp, we must always display the updated esp for those processes instead of saved stack pointer pesp.
			if(proctab[i].pstate == PRCURR)
			{
				asm("movl %esp, esp");
				printf("\n\tpointer: 0x%08x", esp);
			}
			else
			{
				printf("\n\tpointer: 0x%08x", proctab[i].pesp);
			}
			
		}
		i++;
	}	

}
// Reference: Operating System Design: The XINU Approach by Douglas Comer
