#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
    int fd = open("aa",O_RDWR);
    if(fd == -1)
    {
        perror("open");
        exit(1);
    }
    int ret = lseek(fd,0,SEEK_END);
    printf("file length = %d \n",ret);
    // 文件拓展
    ret = lseek(fd,1000,SEEK_END);
    printf("file length = %d \n",ret);

    write(fd,"adada",5);
    close(fd);
    return 0;

}


