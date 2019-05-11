

#include <xdc/std.h>
#include <xdc/runtime/System.h>

#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Clock.h>
#include <xdc/runtime/Timestamp.h>

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
			y = dotp(a, x, COUNT);


		    System_printf("y   = %d \n",  y);


}


int dotp(short *m, short *n, int count)
{

	int acc,i;
	acc = 0;
	for(i=0; i < count; i++){
	    acc += m[i] * n[i];
	}
	return acc;



}

