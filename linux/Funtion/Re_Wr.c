#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

#include <fcntl.h>
#include <unistd.h>

int main()
{
    //打开一个已经存在的文件
    int fd = open("english.txt",O_RDONLY);
    if(fd == -1)
    {
        perror("open");
        exit(1);
    }
    //创建一个新文件  --写操作
    int fdw = open("newfile",O_CREAT|O_RDWR,777);
    if(fdw == -1)
    {
        perror("open1");
        exit(1);
    }
    char *buf[100] = {0};
    int numbytes = read(fd,buf,sizeof(buf));
    if(numbytes == -1)
    {
        perror("read");
        exit(1);
    }
    int ret =0;
    while(numbytes)
    {

         ret = write(fdw,buf,numbytes);
        printf("write bytes %d\n",ret);
        numbytes = read(fd,buf,sizeof(buf));
    }
    close(fd);
    close(fdw);
}
