/* sleep.c - sleep */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <q.h>
#include <sleep.h>
#include <stdio.h>
#include <lab0.h>
/*------------------------------------------------------------------------
 * sleep  --  delay the calling process n seconds
 *------------------------------------------------------------------------
 */
SYSCALL	sleep(int n)
{	
	// Function Identifier
	int funcId = 18;

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
	if (n<0 || clkruns==0)
        {	
	 	if(trackFlag == 1 && startTrackFlag == 1)
        	{
                	endTime = ctr1000;
               	 	procsyslist[currpid][funcId].exectime += (endTime - startTime);
        	}
		return(SYSERR);
	}
	if (n == 0) {
	        disable(ps);
		resched();
		restore(ps);

       		 if(trackFlag == 1 && startTrackFlag == 1)
        	{
                	endTime = ctr1000;
        	        procsyslist[currpid][funcId].exectime += (endTime - startTime);
	        }


		return(OK);
	}
	while (n >= 1000) {
		sleep10(10000);
		n -= 1000;
	}
	if (n > 0)
		sleep10(10*n);


	if(trackFlag == 1 && startTrackFlag == 1)
	{
		endTime = ctr1000;
		procsyslist[currpid][funcId].exectime += (endTime - startTime);
	}	
	return(OK);
}
