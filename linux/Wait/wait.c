#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    pid_t pc,pr;
    pc = fork();

    if(pc<0)
        perror("fork error");
    else if(pc==0)
    {
        sleep(10);
        exit(0);
    }
    do{
        pr = waitpid(pc,NULL,WNOHANG);
        if(pr == 0)
            printf("no child exited\n");
        sleep(1);
    }while(pr==0);
    if(pr == pc)
        printf("successfully get child %d\n",pr);
    else
        printf("some error occured\n");
}

