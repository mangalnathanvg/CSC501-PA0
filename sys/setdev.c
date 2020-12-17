/* setdev.c - setdev */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <lab0.h>
/*------------------------------------------------------------------------
 *  setdev  -  set the two device entries in the process table entry
 *------------------------------------------------------------------------
 */
SYSCALL	setdev(int pid, int dev1, int dev2)
{
	
        int funcId = 13;

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

	short	*nxtdev;

	if (isbadpid(pid))
	{       
		if(trackFlag == 1 && startTrackFlag == 1)
	        {
                	endTime = ctr1000;
                	procsyslist[currpid][funcId].exectime += (endTime - startTime);
        	}

		return(SYSERR);
	}
	nxtdev = (short *) proctab[pid].pdevs;
	*nxtdev++ = dev1;
	*nxtdev = dev2;

        if(trackFlag == 1 && startTrackFlag == 1)
        {
		endTime = ctr1000;
                procsyslist[currpid][funcId].exectime += (endTime - startTime);
        }

	return(OK);
}
