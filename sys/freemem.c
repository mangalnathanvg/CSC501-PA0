/* freemem.c - freemem */

#include <conf.h>
#include <kernel.h>
#include <mem.h>
#include <stdio.h>
#include <proc.h>
#include <lab0.h>
/*------------------------------------------------------------------------
 *  freemem  --  free a memory block, returning it to memlist
 *------------------------------------------------------------------------
 */
SYSCALL	freemem(struct mblock *block, unsigned size)
{
	int funcId = 0;
	
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
	struct	mblock	*p, *q;
	unsigned top;

	if (size==0 || (unsigned)block>(unsigned)maxaddr
	    || ((unsigned)block)<((unsigned) &end))
	{	

	        if(trackFlag == 1 && startTrackFlag == 1)
	        {
                	endTime = ctr1000;
        	        procsyslist[currpid][funcId].exectime += (endTime - startTime);
	        }

		return(SYSERR);
	}
	size = (unsigned)roundmb(size);
	disable(ps);
	for( p=memlist.mnext,q= &memlist;
	     p != (struct mblock *) NULL && p < block ;
	     q=p,p=p->mnext )
		;
	if (((top=q->mlen+(unsigned)q)>(unsigned)block && q!= &memlist) ||
	    (p!=NULL && (size+(unsigned)block) > (unsigned)p )) {
		restore(ps);


      	 	 if(trackFlag == 1 && startTrackFlag == 1)
        	{
                	endTime = ctr1000;
        	        procsyslist[currpid][funcId].exectime += (endTime - startTime);
	        }


		return(SYSERR);
	}
	if ( q!= &memlist && top == (unsigned)block )
			q->mlen += size;
	else {
		block->mlen = size;
		block->mnext = p;
		q->mnext = block;
		q = block;
	}
	if ( (unsigned)( q->mlen + (unsigned)q ) == (unsigned)p) {
		q->mlen += p->mlen;
		q->mnext = p->mnext;
	}
	restore(ps);

        if(trackFlag == 1 && startTrackFlag == 1)
        {
                endTime = ctr1000;
                procsyslist[currpid][funcId].exectime += (endTime - startTime);
        }

	return(OK);
}
