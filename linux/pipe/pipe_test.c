#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>


int main()
{
    int fd[2];
    pid_t pid;
    int ret = pipe(fd);
    if(ret ==-1)
    {
        perror("pipe error");
        exit(1);
    }
    pid = fork();
    if(pid == -1 )
    {
        perror("pipe error:");
        exit(1);
    }
    else if(pid == 0)
    {
        close(fd[1]);
        char buff[1024];
        ret = read(fd[0],buff,sizeof(buff));
        if(ret == 0)
        {
            printf("-----\n");
        }
        write(STDOUT_FILENO, buff, ret);

    }else{
        close(fd[0]);
        write(fd[1],"hello pipe\n",strlen("hello pipe"));
    }
    return 0;
}
