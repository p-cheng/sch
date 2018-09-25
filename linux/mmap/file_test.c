#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    int fd1,fd2;
    pid_t pid;
    char buf[1024];
    char *str = "---test for shared fd in parent child process--";

    pid = fork();
    if(pid < 0)
    {
        perror("fork error");
        exit(1);
    }
    else if(pid == 0)
    {
        fd1 = open("test.txt",O_RDWR);
        if(fd1 < 0)
        {
            perror("open error");
            exit(1);
        }
        write(fd1,str,strlen(str));
        printf("child is write over\n");
    }
    else
    {
        fd2 = open("test.txt",O_RDWR);
        if(fd2 < 0)
        {
            perror("open error");
            exit(1);
        }
        sleep(1);
        int len = read(fd2,buf,sizeof(buf));
        write(STDOUT_FILENO,buf,len);
        wait(NULL);
    }
    return 0;
}
