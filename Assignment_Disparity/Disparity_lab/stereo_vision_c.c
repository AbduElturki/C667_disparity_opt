#define Height 223
#define Width 280

#define RADIUS 2
#define SEARCH 60

// TODO: optimise this function for better performance
void stereo_vision_c(unsigned char * restrict L, unsigned char * restrict R, unsigned char * restrict Disparity_Map, int Search_Range, int Radius)
{

    int i,j;
    int Sum, Distance,Minimize;
    int ones = 0x01010101;
    long long mask = 0xFFFFFFFFFF;
    long long left_buf[5];
    long long right_buf[5];
    int flag;
    int s;

    _nassert(((int)L & 0x7F) == 0);
    _nassert(((int)R & 0x7F) == 0);
    _nassert(((int)Disparity_Map & 0x7F) == 0);

    #pragma MUST_ITERATE(Height-5,,2)
    for (i=(Height-1)-Radius;i>=Radius;i--)
    {
#pragma MUST_ITERATE(Width-5,,2)
        for (j=(Width-1)-Radius;j>=Radius;j--)
        {
            Minimize=100000;
            Sum = 100000;

            left_buf[0] = _mem8_const(&L[(i-2)*Width+j-Radius]) & mask;
            left_buf[1] = _mem8_const(&L[(i-1)*Width+j-Radius]) & mask;
            left_buf[2] = _mem8_const(&L[(i)*Width+j-Radius]) & mask;
            left_buf[3] = _mem8_const(&L[(i+1)*Width+j-Radius]) & mask;
            left_buf[4] = _mem8_const(&L[(i+2)*Width+j-Radius]) & mask;

            flag = (j-Radius-Search_Range < 0);
            int search = !flag * Search_Range + flag * (j-Radius+1);

            #pragma MUST_ITERATE(2,,2)
            for (s=0; s<search; s++)
            {
                right_buf[0] = _mem8_const(&R[(i-2)*Width+j-Radius-s]) & mask;
                right_buf[1] = _mem8_const(&R[(i-1)*Width+j-Radius-s]) & mask;
                right_buf[2] = _mem8_const(&R[(i)*Width+j-Radius-s]) & mask;
                right_buf[3] = _mem8_const(&R[(i+1)*Width+j-Radius-s]) & mask;
                right_buf[4] = _mem8_const(&R[(i+2)*Width+j-Radius-s]) & mask;

                flag = (Sum<Minimize);
                Distance = ((!(flag)) * Distance) + (flag * (s-1));
                Minimize = ((!(flag)) * Minimize) + (flag * Sum);

                Sum = _dotpu4(_subabs4(_hill(left_buf[0]),_hill(right_buf[0])),ones);
                Sum += _dotpu4(_subabs4(_loll(left_buf[0]),_loll(right_buf[0])),ones);
                Sum += _dotpu4(_subabs4(_hill(left_buf[1]),_hill(right_buf[1])),ones);
                Sum += _dotpu4(_subabs4(_loll(left_buf[1]),_loll(right_buf[1])),ones);
                Sum += _dotpu4(_subabs4(_hill(left_buf[2]),_hill(right_buf[2])),ones);
                Sum += _dotpu4(_subabs4(_loll(left_buf[2]),_loll(right_buf[2])),ones);
                Sum += _dotpu4(_subabs4(_hill(left_buf[3]),_hill(right_buf[3])),ones);
                Sum += _dotpu4(_subabs4(_loll(left_buf[3]),_loll(right_buf[3])),ones);
                Sum += _dotpu4(_subabs4(_hill(left_buf[4]),_hill(right_buf[4])),ones);
                Sum += _dotpu4(_subabs4(_loll(left_buf[4]),_loll(right_buf[4])),ones);

            }
            flag = (Sum<Minimize);
            Distance = ((!(flag)) * Distance) + (flag * (search-1));
            Minimize = ((!(flag)) * Minimize) + (flag * Sum);

            Disparity_Map[i*Width+j]= Distance;
        }
    }
}
