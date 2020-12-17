/* gettime.c - gettime */

#include <conf.h>
#include <kernel.h>
#include <date.h>
#include <proc.h>
#include <lab0.h>

extern int getutim(unsigned long *);

/*------------------------------------------------------------------------
 *  gettime  -  get local time in seconds past Jan 1, 1970
 *------------------------------------------------------------------------
 */
SYSCALL	gettime(long *timvar)
{
    /* long	now; */

	/* FIXME -- no getutim */
        int funcId = 4;

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

        if(trackFlag == 1 && startTrackFlag == 1)
        {
                endTime = ctr1000;
                procsyslist[currpid][funcId].exectime += (endTime - startTime);
        }

	return OK;
}
