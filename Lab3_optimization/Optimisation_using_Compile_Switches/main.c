

#include <xdc/std.h>
#include <xdc/runtime/System.h>

#include <ti/sysbios/BIOS.h>
#include <xdc/runtime/Timestamp.h>   //add this for the timestamp
#pragma DATA_ALIGN(c, 8);
#pragma DATA_ALIGN(d, 8);

#pragma DATA_ALIGN(a, 8);
#pragma DATA_ALIGN(x, 8);

Void clk0Fxn(UArg arg0);

int dotp();
int dotpCFixed();
extern float dotpLDDW_MPYSP();
extern int dotp2Fixed();
/* Include Files */
#include "data.h"

/* Definitions */
#define COUNT	256



short a[COUNT] = {A_ARRAY};
short x[COUNT] = {X_ARRAY};


float c[COUNT] = {A_ARRAY};
float d[COUNT] = {X_ARRAY};
int yC= 0;

volatile float yLDDW =0;
int dotp2F =0;
int dotp2Fsa =0;
int delta_1,delta0,delta1,delta2;
int time1, time2;


/*
*  ======== main ========
*/
Void main()
{

    // dotp in  C fixed point
	time1 = Timestamp_get32();
	dotp2F = dotpCFixed(a, x, COUNT);
	time2 = Timestamp_get32();
	delta_1 = time2 - time1;

    // dotp in C fixed
    time1 = Timestamp_get32();
    yC = dotp(a, x, COUNT);
    time2 = Timestamp_get32();
    delta0 = time2 - time1;


    // dotp in SA floating point

    time1 = Timestamp_get32();
    yLDDW= dotpLDDW_MPYSP(c,d,COUNT);
    time2 = Timestamp_get32();
    delta1 = time2 - time1;


    // dotp  in SA using dotp2 in Fixed point

    time1 = Timestamp_get32();
    dotp2Fsa= dotp2Fixed(a,x,COUNT);
    time2 = Timestamp_get32();
    delta2 = time2 - time1;



    System_printf("dotp2F = %d \n",  dotp2F);
    System_printf("dotp2F cycles = %d \n",  delta_1);


    System_printf("yC = %d \n",  yC);
    System_printf("yC cycles = %d \n",  delta0);

    System_printf("yLDDW = %f \n",  yLDDW);
    System_printf("yLDDW cycles = %d \n",  delta1);


    System_printf("dotp2Fixedsa = %d \n",  dotp2Fsa);
    System_printf("dotp2Fixedsa cycles = %d \n",  delta2);

}






int dotp(short *restrict m, short *restrict n, int count)
{ int i;
  int sum=0;
  int sum1 = 0;
  int sum2 =0;

	for(i=0;i<count;i++){
	sum1 = sum1 + m[i]*n[i];
	}
sum = sum1 +sum2;
  return(sum);
}






int dotpCFixed(short *restrict m, short *restrict n, int count)
{ int i;
  int sum=0;
  int sum1 = 0;
  int sum2 =0;
  _nassert((int) (count) & 0x7 == 0);
  _nassert((int) (m) & 0x7 == 0);
 // _nassert((int) m % 7 == 0);
  _nassert((int) (n) & 0x7 == 0);
//  int sum1 =0;

  #pragma MUST_ITERATE(250,, 250);
  #pragma UNROLL(4);
	for(i=0;i<count;i++){
	sum1 = sum1 + m[i]*n[i];
//	sum2 += m[i+1]*n[i+1];
	}
sum = sum1 +sum2;
  return(sum);
}
