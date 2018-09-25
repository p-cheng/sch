#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/mman.h>
int main()
{
    char *p  = NULL;
    int fd = open("mytest.txt",O_CREAT|O_RDWR,06440);
    if(fd < 0)
    {
        perror("open error");
        exit(1);
    }
    int len = ftruncate(fd,4);
    if(len == -1)
    {
        perror("ftruncate eror:");
        exit(1);
    }
    p = mmap(NULL,4,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
    if(p == MAP_FAILED)
    {
        perror("mmap error");
    }
    strcpy(p,"abc");//写数据
int  ret = munmap(p,4);
    if( ret == -1 )
    {
        perror("munmap error");
        exit(1);
    }
    close(fd);
}
