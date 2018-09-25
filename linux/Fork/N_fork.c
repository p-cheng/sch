#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc,char *argv[])
{
    int n =5 ;
    int i;
    if(argc == 2)
    {
        n = atoi(argv[1]);
    }
    for(i=0;i<n;i++)
        if(fork()==0)
            break;

    if(n==i)
    {
        sleep(n);
        printf("i am parent,pid = %d\n",getpid());

    }else
    {
        sleep(i);
        printf("i am %dth child,pid = %d\n",i+1,getpid());
    }
    return 0;
}
