#include <stdio.h>

union A
{
    short c;
    char buf[4];

}x;
int main()
{
    union A x;
    //x.buf={'0x02','0x01','0x03','0x04'};
    x.buf[0] = 0x02;
    x.buf[1] = 0x01;
    x.buf[2] = 0x03;
    x.buf[3] = 0x04;
    printf("%p\n",x.c);
    return 0;
}
