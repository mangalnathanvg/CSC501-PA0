/* chprio.c - chprio */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <q.h>
#include <stdio.h>
#include <lab0.h>
/*------------------------------------------------------------------------
 * chprio  --  change the scheduling priority of a process
 *------------------------------------------------------------------------
 */
SYSCALL chprio(int pid, int newprio)
{	
	int funcId = 1;

	unsigned long startTime, endTime;

	int startTrackFlag = 0;

        if(trackFlag==1)
        {
                procsyslist[currpid][funcId].syscallName = __func__;
                procsyslist[currpid][funcId].pid = currpid;
                procsyslist[currpid][funcId].freq += 1;
                startTime = ctr1000;
                startTrackFlag = 1;
        }

	STATWORD ps;    
	struct	pentry	*pptr;

	disable(ps);
	if (isbadpid(pid) || newprio<=0 ||
	    (pptr = &proctab[pid])->pstate == PRFREE) {
		restore(ps);
		

        	if(trackFlag == 1 && startTrackFlag == 1)
        	{
                	endTime = ctr1000;
        	        procsyslist[currpid][funcId].exectime += (endTime - startTime);
	        }

		return(SYSERR);
	}
	pptr->pprio = newprio;
	restore(ps);

        if(trackFlag == 1 && startTrackFlag == 1)
        {
                endTime = ctr1000;
                procsyslist[currpid][funcId].exectime += (endTime - startTime);
        }

	return(newprio);
}
