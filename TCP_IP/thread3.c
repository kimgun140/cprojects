#include<stdio.h>
#include<pthread.h>
void * thread_summation(void * arg);
int sum = 0;
int main( int argc, char * argv[]){

    pthread_t id_t1, id_t2;
    int range1[] = {1,5};
    int range2[] = {6,10};

    pthread_create(&id_t1, NULL, thread_summation, (void*) range1);
    pthread_create(&id_t2, NULL, thread_summation, (void*) range2);
//쓰레드 2개를 만들어서 같은 함수에 매개변수를 다르게 준다 

    pthread_join(id_t1, NULL);
    pthread_join(id_t2, NULL);
    printf("result: %d \n", sum);
    return 0;
}

void * thread_summation(void * arg){
    int start = ((int*)arg)[0];
    int end=((int*)arg)[1];

    while(start <= end){
        sum +=start;
        start++;
    }
    return NULL;
}
//두쓰레드가 하나의 전역변수 sum에 접근한다.