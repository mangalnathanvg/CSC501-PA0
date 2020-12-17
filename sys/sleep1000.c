/* sleep1000.c - sleep1000 */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <q.h>
#include <sleep.h>
#include <stdio.h>
#include <lab0.h>
/*------------------------------------------------------------------------
 * sleep1000 --  delay the caller for a time specified in 1/100 of seconds
 *------------------------------------------------------------------------
 */
SYSCALL sleep1000(int n)
{
        int funcId = 21;

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

	if (n < 0  || clkruns==0)
	{
		if(trackFlag == 1 && startTrackFlag == 1)
        	{
                	endTime = ctr1000;
        	        procsyslist[currpid][funcId].exectime += (endTime - startTime);
	        }

	         return(SYSERR);
	}
	disable(ps);
	if (n == 0) {		/* sleep1000(0) -> end time slice */
	        ;
	} else {
		insertd(currpid,clockq,n);
		slnempty = TRUE;
		sltop = &q[q[clockq].qnext].qkey;
		proctab[currpid].pstate = PRSLEEP;
	}
	resched();
        restore(ps);
        if(trackFlag == 1 && startTrackFlag == 1)
        {
                endTime = ctr1000;
                procsyslist[currpid][funcId].exectime += (endTime - startTime);
        }


	return(OK);
}
