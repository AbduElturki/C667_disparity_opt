
#include <xdc/std.h>
#include "c6x.h"   // add this if you want o use intrinsics

#include <xdc/runtime/System.h>
#include <ti/sysbios/BIOS.h>

#include <ti/sysbios/knl/Clock.h>
#include <xdc/runtime/Timestamp.h>   //add this for the timestamp

#include "data_fix_float.h"

#define COUNT	256


extern __x128_t dotpsa2(short *m, short  *n, int count,__x128_t    myquad);


/* Declarations                                */



float c[COUNT]= {A_ARRAY};			// a and x are declare in floating point
float d[COUNT]= {X_ARRAY};

short a[COUNT]= {c_ARRAY};				// c and d are declare in fixed point
short x[COUNT]= {d_ARRAY};




long double mydouble = 0x100;
__x128_t    myquad,y3;
int a1= 0x00000000;
int b1= 0x11111111;
int c1= 0x22222222;
int d1= 0x33333333;
float f1 = 0.5;
float f2 = 0.25;
float f3 = 0;
float f4 = 0;

__float2_t  myfloat; //




Void main(){
   myfloat =_ftof2(f1, f2);
    f3=_hif(myfloat);
    f4 =_lof(myfloat);

	__x128_t myquad = _ito128(a1, b1, c1, d1); // Pack values into a __x128_t



	y3 =  dotpsa2(a, x, COUNT,myquad);


    System_printf("y   = %d \n",  y3);
    System_printf("I finished!\n");



  BIOS_exit(0);  /* terminates program and dumps SysMin output */

}



