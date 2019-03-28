#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

int *thrd_fun(void * arg)
{
    while(1)
    {
        sleep(1);
        printf("thread 1 runing !\n");
    }
    printf("leave thread1!\n");
    return NULL;
}


int main()
{
    pthread_t tid;
    int ret = pthread_create(&tid,NULL,(void *)thrd_fun,NULL);
    {
        if(ret != 0)
        {
            fprintf(stderr,"pthread_creat error %s\n",strerror(ret));
            exit(1);
        }
    }
    sleep(5);
    printf("leave main thread!\n");
    return 0;
}
