#ifndef _LAB0_H_
#define _LAB0_H_

// Function declarations for zfunction, printtos, printsegaddress, printprocstks

long zfunction(long);
void printsegaddress();
void printtos();
void printsegaddress();
void printprocstks(int);


// Function declarations used for tracing system calls

void syscallsummary_start(void);
void syscallsummary_stop(void);
void printsyscallsummary(void);

// Data Structure for process monitor which stores details about each system call

struct procsyscallmonitor
{
	char* syscallName;   // Name of System Call
	int pid;            // Process ID which last called the system call
	int freq; 	    // The number of times the system call was called
	unsigned long exectime;  // The execution time of the system call
};


// We must monitor 27 system calls for each of the process separately

extern struct procsyscallmonitor procsyslist[][27];

// Track flag declared to indicate whether tracking is to be started

extern int trackFlag;

// Time Counter to get Current Time

extern unsigned long ctr1000;

#endif
