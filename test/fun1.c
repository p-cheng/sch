#include<stdio.h>
#define TEXT(x) #x
#define f(x)  x()
#define g()   TEXT(1+f(g))


int main()
{
    printf("%s\n",f(g));
    return  0;
}
