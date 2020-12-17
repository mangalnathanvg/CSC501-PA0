#include<stdio.h>

// End of program segments as specified in MAN Page of etext
extern int  etext, edata, end;

// Print the addresses and contents indicating the end of text, data and BSS Segments of current process
void printsegaddress()
{
	printf("\n\nvoid printsegaddress()\n\n");
	printf("Current: etext[0x%08lx]=0x%08lx,edata[0x%08lx]=0x%08lx, ebss[0x%08lx]=0x%08lx", &etext, etext, &edata, edata, &end, end);
	printf("\nPreceding: etext[0x%08lx]=0x%08lx, edata[0x%08lx]=0x%08lx, ebss[0x%08lx]=0x%08lx", &etext - 1, *(&etext - 1), &edata - 1, *(&edata - 1), &end - 1, *(&end - 1));
	printf("\nAfter:  etext[0x%08lx]=0x%08lx, edata[0x%08lx]=0x%08lx, ebss[0x%08lx]=0x%08lx", &etext + 1, *(&etext + 1), &edata + 1, *(&edata + 1), &end + 1, *(&end + 1));
}
