//输入一个整数，转化为二进制输出1的个数；
#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace  std;

int fun(int val)
{
    int i  =32,num = 0;
    while(i--)
    {
        if(val&1<<i)
            ++num;
    }
    return num;
}



int main()
{
    int n = 0;
    int m = 0;
    char str[20];
    cin>>n;
     m=fun(n);

    sprintf(str,"%d",m);
    cout << str <<endl;
}
