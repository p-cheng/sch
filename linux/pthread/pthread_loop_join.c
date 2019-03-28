#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

int var = 100;

void *tfn(void *arg)
{
    int i;
    i  = (int)arg;
    if(i == 1)
    {
        var = 333;
        printf("var = %d\n",var);
        return var;
    }else if(i == 3)
    {
        var = 777;
        printf("i'm %dth pthread,pthread_id = %lu\n var = %d\n",i+1,pthread_self(),var);
        pthread_exit((void *)var);

    }
    else
    {
        printf("i'm %dth pthread, pthread_id = %lu\n var = %d\n",i+1,pthread_self(),var);
        pthread_exit((void *)var);
    }
    return NULL;
}

int main()
{
    pthread_t tid[5];
    int i;
    int *ret[5];

    for(i=0;i<5;i++)
    {
        pthread_create(&tid[i],NULL,tfn,(void *)i);
    }
    for(i=0;i<5;i++)
    {
        pthread_join(tid[i],(void **)&ret[i]);
        printf("------------%d 's ret = %d\n",i,(int)ret[i]);

    }
    printf("i'm main pthread tid = %lu\t var =%d\n",pthread_self(),var);
    sleep(i);
    return 0;
}
