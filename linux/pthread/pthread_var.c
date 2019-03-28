#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

int var = 100;

void *thrd_fun(void *arg)
{
    int i = (int)arg;
    var+=i;

    printf("thread var = %d\n",var);
    sleep(i);
    return NULL;
}

int main()
{
    printf("At frist var = %d\n",var);
    int ret ,i;
    pthread_t tid;
    for(i=0;i<5;i++)
    {
        ret =pthread_create(&tid,NULL,thrd_fun,(void *)i);

            if(ret != 0)
            {
                fprintf(stderr, "pthread_create error %s\n",strerror(ret));
                exit(0);
            }

    }
    printf("after pthread_creat  var= %d\n",var);
    sleep(i);
    return 0;
}
