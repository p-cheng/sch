#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


int main()
{
    int fd;//打开已经存在的文件

    /*fd= open("wang.txt",O_RDWR);
    if(fd == -1)
    {
        perror("open file ");
        exit(1);
    }*/

    //创建新文件
     fd = open("hello",O_RDWR|O_CREAT);

     printf("fd = %d\n",fd);
    int ret = close(fd);
    printf(" ret = %d \t close file\n",ret);
}
