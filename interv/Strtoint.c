#include <stdio.h>

int Strtoint(char * str)
{
    int flag = 1;
    int s = 0;
    if(str==NULL)
    {
        printf("pointer is NULL\n");
        return 0;
    }
    while(*str == ' ')
    {
        str++;
    }
    if(*str == '-'||*str=='+')
    {
        if(*str=='-')
            flag = -1;
        str++;
    }
    while(*str>='0'&&*str<='9')
    {
        s = s*10+(*str-'0');
        str++;
    }
    return s*flag;
}
int main()
{
    char str[100]={"\0"};
    int number= 0;
    printf("push string\n");
    scanf("%s",str);
    number = Strtoint(str);
    printf("%d\n",number);
    return 0;
}
