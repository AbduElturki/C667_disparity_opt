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
    unsigned char left_buf[32];
    unsigned char right_buf[32];
    int flag;
    int s;

    _nassert(((int)L & 0x7F) == 0);
    _nassert(((int)R & 0x7F) == 0);
    _nassert(((int)Disparity_Map & 0x7F) == 0);

    #pragma MUST_ITERATE(Height-5,,2)
    for (i=(Height-1)-Radius;i>=Radius;i--)
    {
        for (j=(Width-1)-Radius;j>=Radius;j--)
        {
            Minimize=100000;
            Sum = 100000;

            memcpy(&left_buf[0],&L[(i-2)*Width+j-Radius],5);
            memcpy(&left_buf[5],&L[(i-1)*Width+j-Radius],5);
            memcpy(&left_buf[10],&L[(i)*Width+j-Radius],5);
            memcpy(&left_buf[15],&L[(i+1)*Width+j-Radius],5);
            memcpy(&left_buf[20],&L[(i+2)*Width+j-Radius],5);
            memcpy(&left_buf[25],&L[(i+3)*Width+j-Radius],5);

            flag = (j-Radius-Search_Range < 0);
            int search = !flag * Search_Range + flag * (j-Radius+1);

            #pragma MUST_ITERATE(2,,2)
            for (s=0; s<search; s++)
            {
                memcpy(&right_buf[0],&R[(i-2)*Width+j-Radius-s],5);
                memcpy(&right_buf[5],&R[(i-1)*Width+j-Radius-s],5);
                memcpy(&right_buf[10],&R[(i)*Width+j-Radius-s],5);
                memcpy(&right_buf[15],&R[(i+1)*Width+j-Radius-s],5);
                memcpy(&right_buf[20],&R[(i+2)*Width+j-Radius-s],5);

                flag = (Sum<Minimize);
                Distance = ((!(flag)) * Distance) + (flag * (s-1));
                Minimize = ((!(flag)) * Minimize) + (flag * Sum);

                Sum = _dotpu4(_subabs4(_hill(_amem8(&left_buf[0])),_hill(_amem8(&right_buf[0]))),ones);
                Sum += _dotpu4(_subabs4(_loll(_amem8(&left_buf[0])),_loll(_amem8(&right_buf[0]))),ones);
                Sum += _dotpu4(_subabs4(_hill(_amem8(&left_buf[8])),_hill(_amem8(&right_buf[8]))),ones);
                Sum += _dotpu4(_subabs4(_loll(_amem8(&left_buf[8])),_loll(_amem8(&right_buf[8]))),ones);
                Sum += _dotpu4(_subabs4(_hill(_amem8(&left_buf[16])),_hill(_amem8(&right_buf[16]))),ones);
                Sum += _dotpu4(_subabs4(_loll(_amem8(&left_buf[16])),_loll(_amem8(&right_buf[16]))),ones);
                Sum += _dotpu4(_subabs4(_amem4(&left_buf[24]),_amem4(&right_buf[24])),ones);

            }
            flag = (Sum<Minimize);
            Distance = ((!(flag)) * Distance) + (flag * (search-1));
            Minimize = ((!(flag)) * Minimize) + (flag * Sum);

            Disparity_Map[i*Width+j]= Distance;
        }
    }
}
