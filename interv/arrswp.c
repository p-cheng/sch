#include <stdio.h>
#include <stdlib.h>
void swp(int *arr,int a,int b)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int main()
{
    int n ,x, y;
    int i =0;
    scanf("%d",&n);
    int arr[100] = {0};
    for(i=0 ;i <n;i++)
    {
        scanf("%d",&arr[i]);
    }
    scanf("%d %d",&x,&y);

    swp(arr,x,y);
    for(i =0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }


    return  0;
}
