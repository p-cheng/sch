#include <stdio.h>

int main()
{
    int peach = 0;
    int rest = 2;
    int child = 9;
    int i = 0;
    int n = 0;
    for(child = 9;child>0;child--)
    {
        peach = (rest +1)*2;
        rest = peach;
    }
    printf("%d\n",rest);
    scanf("%d",&n);
    for(child = 0;child <n;child++)
    {
        rest  = rest/2 -1;

    }
    printf("rest %d\n",rest);
    return 0;
}
