#include <iostream>

//用位运算实现加法功能：
using namespace std;

int add(int &a,int &b)
{
    int s = 0;
    if(a==0||b==0)
    {
        if(a==0)
            return b;
        if(b==0)
            return a;
    }
    while( b!= 0)
    {
        s = a ^ b;
        b = (a & b)<<1;
        a = s;
    }
    return a;
}

int main()
{
    int x(0);
    int y(0);
    cout<<"please enter two addends:"<<endl;
    cin>>x>>y;
    int s =add(x,y);

    cout<<"x+y = "<<s<<endl;
    return 0;

}
