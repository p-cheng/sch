#include <iostream>
#include <cstdio>
using namespace std;

bool Duplicate(int data[],int length,int *duplicate)
{
    //判断不符合条件的数 空指针
    if(data == NULL|| length <=0)
    {
        return false;
    }
    for(int i =0;i<length;i++)
    {
        if(data[i]<0||data[i]>length-1)
        {
            return false;
        }
    }
    for(int i=0;i<length;++i)
    {
        while(data[i] != i)
        {
            if(data[i] == data[data[i]])
            {

                *duplicate = data[i];
                  return true;
            }
        int temp = data[i];
            data[i] = data[temp];
            data[temp] = temp;
            for(int j=0;j<length;j++)
            {
                cout<<data[j]<<' ';
            }
            putchar(10);
        }
        //交换swap
    }
    return false;
}



int main()
{
    int n= 0;
    int i =0;
    int duplicate(0);
    int data[n];
    cout<<"please enter the size of the array"<<endl;
    cin >>n;
    cout<<"please enter a set of data"<<endl;
    for(int j=0;j<n;j++)
    {
        cin>>data[j];
    }
    Duplicate(data,n,&duplicate);
    cout<<duplicate<<endl;

}
