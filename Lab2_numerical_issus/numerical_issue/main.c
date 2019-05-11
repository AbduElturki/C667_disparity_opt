/*
 * main.c
 */
#include <c6x.h>

short as=0x4000;        // 16-bit 2's complement
short bs=0x2000;
int a = 0x40000000;
int b = 0x20000000;
float af = 0.5;
float bf = 0.25;

long long c = 0;
int cs =0;
float d = 0;
float df=0;
long long c_ll=0;

//to be completed


int main(void) {

	cs = as* bs; 	//16-bit *16-bit ---> 32-bit
	cs = cs <<1;
	c= a *b ;    // C = 0 as only the lower 32-bit of the 64-bit resukts are shown
	a= a>>16;     // get the number smaller
	b=b>>16;	  // get the number smaller
	c=a*b;
	c= c >>15;
	d= (float) c;
	df = af *bf;
	a = 0x40000000;
	b = 0x20000000;



	// This stores only the least 16  significant bits of the result in a_b
	// the results in this case will be WRONG
	c_ll = a *b;
	// This works
	c_ll= (long long) a * (long long) b;	   //32-bit *32-bit ---> least significant 16-bit
	c_ll = c_ll <<1;

	//long long _mpy32ll (int src1, int src2);

	c_ll= _mpy32ll(a,b);  // 32-bit int *32-bit int ---> 64-bit int

	c_ll = c_ll <<1;

	// double_mpysp2dp (float src1, float src2);

	df = _mpysp2dp(af,bf);   //32-bit float *32-bit float ---> 64-bit float


	for(;;);

	return 0;
}
