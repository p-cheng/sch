//创建线
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void * thrd_func(void *arg)
{
    printf("thread id = %lu,pid = %lu\n",pthread_self(),getpid());
    return NULL;
}
int main()
{
    pthread_t tid;
    int ret;
    printf("In main: thread id = %lu, pid = %lu\n",pthread_self(),getpid());
    ret = pthread_create(&tid,NULL,thrd_func,NULL);
    sleep(1);
    if(ret != 0)
    {
        fprintf(stderr,"pthread_creat error %d\n",strerror(ret));
        printf("pthread_create error\n");
        exit(0);
    }
    printf("In main2: thread id = %lu, pid = %lu\n",pthread_self(),getpid());
    return 0;
}
