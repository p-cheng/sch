#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void * tfn1(void *arg)
{
    printf("thread 1 returning\n");

    return (void *)111;
}

void *tfn2(void *arg)
{
    printf("threaad 2 exiting\n");
    pthread_exit((void *)222);
}

void *tfn3(void *arg)
{
    while(1)
    {
        pthread_testcancel();  //自己加取消点
    }
    return (void*)666;
}

int main(void)
{

    pthread_t tid;
    void *tret = NULL;

    pthread_create(&tid, NULL,tfn1,NULL);
    pthread_join(tid,&tret);
    printf("threead 1 exit code = %d\n\n",(int)tret);

    pthread_create(&tid,NULL,tfn2,NULL);
    pthread_join(tid, &tret);
    printf("thread 2 exit code = %d\n\n",(int)tret);

    pthread_create(&tid,NULL,tfn3,NULL);
    sleep(3);
    pthread_cancel(tid);
    pthread_join(tid,&tret);
    printf("thread 3 exit code = %d\n\n",(int)tret);

    return 0;
}
