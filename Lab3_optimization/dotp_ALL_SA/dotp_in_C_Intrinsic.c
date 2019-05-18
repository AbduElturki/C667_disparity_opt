int dotpC_intrinsic(short *m, short *n, int count)

{
    _nassert((int) m % 8 == 0);
        _nassert((int) n % 8 == 0);
	  int  sum = 0, sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
	  int i;
#pragma MUST_ITERATE(62,62, 2)
for (i=0; i < count;i+=4)
//		sum += coef[i]* filtbuff1[i];

		{

sum1 += _mpy (_lo(_memd8_const(&n[i])), _lo(_memd8_const(&m[i])));
sum2 += _mpyh(_lo(_memd8_const(&n[i])), _lo(_memd8_const(&m[i])));
sum3 += _mpy (_hi(_memd8_const(&n[i])), _hi(_memd8_const(&m[i])));
sum4 += _mpyh(_hi(_memd8_const(&n[i])), _hi(_memd8_const(&m[i])));

	}

		sum = sum1 + sum2 + sum3 + sum4;
		sum = sum;
		return sum;

		}
