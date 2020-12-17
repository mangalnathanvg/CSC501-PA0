/* setnok.c - setnok */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>
#include <lab0.h>
/*------------------------------------------------------------------------
 *  setnok  -  set next-of-kin (notified at death) for a given process
 *------------------------------------------------------------------------
 */
SYSCALL	setnok(int nok, int pid)
{	
        int funcId = 14;

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
	if (isbadpid(pid)) {
		restore(ps);

	        if(trackFlag == 1 && startTrackFlag == 1)
	        {
	                endTime = ctr1000;
                	procsyslist[currpid][funcId].exectime += (endTime - startTime);
        	}

		return(SYSERR);
	}
	pptr = &proctab[pid];
	pptr->pnxtkin = nok;
	restore(ps);

        if(trackFlag == 1 && startTrackFlag == 1)
        {
                endTime = ctr1000;
                procsyslist[currpid][funcId].exectime += (endTime - startTime);
        }


	return(OK);
}
