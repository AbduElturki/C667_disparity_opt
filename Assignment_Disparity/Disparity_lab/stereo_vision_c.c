#define Height 223
#define Width 280

#define RADIUS 2
#define SEARCH 60

// TODO: optimise this function for better performance
void stereo_vision_c(unsigned char * restrict L, unsigned char * restrict R, unsigned char * restrict Disparity_Map, int Search_Range, int Radius)
{

    int i,j,k;
    int ii, jj;
    int Sum,Distance,Minimize;
    int ones = 0x01010101;
    int left_word,right_word;
    int diff;
    int pos;
    unsigned char left_buf[28];
    unsigned char right_buf[28];
    int it;
    int p,s;
    int ks[Search_Range];


    //left_buf = calloc(28,1);
    //right_buf[25] = 0;
    //throw into a thingy

    _nassert(((int)L& 0x3) == 0);


    #pragma MUST_ITERATE(Height-5,,2)
    for (i=(Height-1)-Radius;i>=Radius;i--)
    {
        for (j=(Width-1)-Radius;j>=Radius;j--)
        {
            Minimize=100000;

            pos = 0;
            #pragma MUST_ITERATE(4,,4)
            for (ii=-Radius;ii<=Radius;ii++) //loop through the rows
            {
                memcpy(&left_buf[5*pos],&L[(i+ii)*Width+j-Radius],5);
                pos++;
            }


            p=0;
            #pragma MUST_ITERATE(60,60)
            //#pragma UNROLL(60)
            for (k=0;k<Search_Range;k++)
            {
                if (j-Radius-k>=0)
                {
                    ks[p++]=k;
                }
            }

            #pragma MUST_ITERATE(1,60)
            for (s=0;s<p;s++)
            {
                pos = 0;
                #pragma MUST_ITERATE(4,,4)
                for (ii=-Radius;ii<=Radius;ii++) //loop through the rows
                {
                    //grab the row of 5 values and place in a buffer
                    memcpy(&right_buf[5*pos],&R[(i+ii)*Width+j-Radius-ks[s]],5);
                    pos++;
                }

                //now that all of the values have been placed into memory
                //5x5 kernel for 25 values
                //28 is the nearest multiple of 4 with a remainder of 3

                //process in batches of 4 and add to the sum
                Sum=0;
                //#pragma MUST_ITERATE(7,,7)
                //#pragma UNROLL(60)
                for(it=0;it<28;it+=4){
                    left_word = _amem4(&left_buf[it]);
                    right_word = _amem4(&right_buf[it]);
                    diff = _subabs4(left_word,right_word);
                    Sum +=  _dotpu4(diff,ones);
                }

                if (Sum<Minimize)
                {
                    Minimize=Sum;
                    Distance=ks[s];
                }
            }
            Disparity_Map[i*Width+j]= Distance;
        }
    }
}
