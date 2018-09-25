#include <stdio.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stdlib.h>

int var  =9;

int main()
{
    int fd = open("/dev/zero",O_RDWR);
    int *p;
    pid_t pid;
     p = mmap(NULL,6,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
     if(p == MAP_FAILED)// 不是p == NULL
     {
         perror("mmap error");
         exit(1);
     }

     pid = fork();
     if(pid < 0 )
     {
         perror("fork error");
         exit(1);
     }
     else if(pid == 0)
     {
         var = 100;
         *p= 200;
         printf("var = %d  *p = %d\n",var,*p);
     }
     else
     {
         sleep(1);
         printf("var = %d *p = %d",var,*p);
        wait(NULL);
        int ret = munmap(p,6);
        if(ret  == -1)
        {
            perror("munmap eror");
            exit(1);
        }
     }

}
