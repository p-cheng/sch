#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
    pid_t pid;
    pid = fork();
    if(pid == -1)
    {
        perror("fork error");
        exit(1);
    }
    else if(pid >0)
    {
        sleep(1);
        printf("parent\n");
    }else
    {
        //execl("/bin/ls","ls","-l","-a",NULL);
        execl("./while","while",NULL);
    }
    return 0;

}
