

#include <xdc/std.h>
#include <xdc/runtime/System.h>

#include <ti/sysbios/BIOS.h>


Void clk0Fxn(UArg arg0);
int dotp(short *m, short *n, int count);

/* Include Files */
#include "data.h"

/* Definitions */
#define COUNT	256

short a[COUNT] = {A_ARRAY};
short x[COUNT] = {X_ARRAY};
volatile int y = 0;

        
/*
 *  ======== main ========
 */
Void main()
{
	char buf1[30];
	char buf2[30];
	char s1[30] = "Hello";
	char s2[30] = "Print";
// To be completed
	System_sprintf(buf1, "First output : %s\n", s1);
	System_sprintf(buf2, "Second output: %s\n", s2);


	y = dotp(a, x, COUNT);

	System_printf(buf1);
    System_printf(buf2);

	System_printf("y   = %d \n",  y);



}


int dotp(short *m, short *n, int count)
{

	int acc,i;
	acc = 0;
	for (i = 0; i<count; i++)
		acc += m[i]*n[i];
	return acc;



}

