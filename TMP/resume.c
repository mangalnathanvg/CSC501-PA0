/* resume.c - resume */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>
#include <lab0.h>
/*------------------------------------------------------------------------
 * resume  --  unsuspend a process, making it ready; return the priority
 *------------------------------------------------------------------------
 */
SYSCALL resume(int pid)
{
        int funcId = 9;

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
	struct	pentry	*pptr;		/* pointer to proc. tab. entry	*/
	int	prio;			/* priority to return		*/

	disable(ps);
	if (isbadpid(pid) || (pptr= &proctab[pid])->pstate!=PRSUSP) {
		restore(ps);

	        if(trackFlag == 1 && startTrackFlag == 1)
	        {
                	endTime = ctr1000;
        	        procsyslist[currpid][funcId].exectime += (endTime - startTime);
	        }


		return(SYSERR);
	}
	prio = pptr->pprio;
	ready(pid, RESCHYES);
	restore(ps);

        if(trackFlag == 1 && startTrackFlag == 1)
        {
                endTime = ctr1000;
                procsyslist[currpid][funcId].exectime += (endTime - startTime);
        }


	return(prio);
}
