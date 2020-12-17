/* scount.c - scount */

#include <conf.h>
#include <kernel.h>
#include <sem.h>
#include <proc.h>
#include <lab0.h>
/*------------------------------------------------------------------------
 *  scount  --  return a semaphore count
 *------------------------------------------------------------------------
 */
SYSCALL scount(int sem)
{
        int funcId = 10;

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


extern	struct	sentry	semaph[];

        if(trackFlag == 1 && startTrackFlag == 1)
        {
                endTime = ctr1000;
                procsyslist[currpid][funcId].exectime += (endTime - startTime);
        }

	if (isbadsem(sem) || semaph[sem].sstate==SFREE)
		return(SYSERR);
	return(semaph[sem].semcnt);
}
