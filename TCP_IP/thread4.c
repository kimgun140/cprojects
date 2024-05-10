//thread4.c

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#define NUM_THREAD 100
// 하나의 데이터에 여러 쓰레드가 접근하면 문제가 생긴다 순서가 어떻게 될지 모르기 때문에  순차적으로 진행되지 않을 수 있으니까
//크리티컬 섹션 / 임계영역의 문제
void * thread_inc(void * arg);
void * thread_des(void * arg);
long long num = 0;

int main(int argc, char argv[]){
    pthread_t thread_id[NUM_THREAD];
    int i;

    printf("sizeof long long: %ld \n", sizeof(long long));
    for ( i = 0; i < NUM_THREAD; i++)
    {
        if(i%2)
            pthread_create(&(thread_id[i]), NULL, thread_inc, NULL);
        else
            pthread_create(&(thread_id[i]), NULL, thread_des, NULL);
    }

    for ( i = 0; i < NUM_THREAD; i++)
    {
        pthread_join(thread_id[i], NULL);
    }

    printf("result: %lld \n",num);
    return 0;
}

void * thread_inc(void * arg)
// void * thread_inc(void * arg)
{
    int i;
    for(i=0; i<50000000; i++)
        num += 1;
    return NULL;
}
void * thread_des(void * arg)
{
    int i;
    for(i=0; i<50000000; i++)
        num -= 1;
    return NULL;
}