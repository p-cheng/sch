#include<iostream>

using namespace std;

bool fun(int n[],int l,int *p)
{
    if(n==NULL||l<=0)
    {
        return false;
    }
    for(int i=0;i<l;++i)
    {
        if(n[i]<0||n[i]>l-1)
            return false;
    }
    for(int i=0;i<l;++i)
    {
        while(n[i]!=i)
        {
            if(n[i]==n[n[i]]);
            *p = n[i];
            return true;
        }
        int temp = n[i];
        n[i] = n[temp];
        n[temp]  = temp;
        cout << n[i]<<endl;
    }
    return false;
}

int main()
{
    int n[6] = {2,4,2,4,5,0};
    int s = 0;
    fun(n,6,&s);
    cout << s <<endl;
    return 0;

}
