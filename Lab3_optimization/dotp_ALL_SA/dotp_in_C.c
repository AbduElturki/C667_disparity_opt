int dotp1(short* m, short* n, int count) {
 
 
    int i;
    int sum = 0;
 
    _nassert((int) m % 8 == 0);
    _nassert((int) n % 8 == 0);
 
#pragma MUST_ITERATE(250,250, 4);
#pragma UNROLL(4);
 
    for (i = 0; i < count; i++) {
        sum += m[i] * n[i];
    }
 

//__asm (“		MVC	B2, AMR”);
    return sum;
}
