#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// char * ReadUserName(void);
// void SimpleFunc(void){
//     static int num1 = 0; //초기화하지 않으면 0초기화
//     int num2 = 0; //초기화하지 않으면 쓰레기 값 초기화
//     num1++, num2++;
//     printf("static: %d, local: %d \n",num1, num2);
// }
// static이 붙으면 누적이되네, num2는 지웠다 사라졌다 하니까 없어진다.
//글로벌이랑 비슷하네; 전역변수 보다는 안전하다. 하지만 너무 남발하면 좋다고는 말못함

    int static_store = 30;
    const char * pcg = "String Literal"; //data
int main (void){

    // // int i;
    // // for(i=0; i<3; i++)
    // // SimpleFunc();
    //             // (int*) 형변환을 해준다. 타입을 정해줌 사용할 수 있게 
    // int * ptr1 = (int *)malloc(sizeof(int)); // 동적 메모리 할당
    // int * ptr2 = (int *)malloc(sizeof(int)*7);
    // int i;

    // *ptr1 = 20;
    // for(i=0; i<7; i++){
    //     ptr2[i] = i+1;
    // }

    // printf("%d \n", *ptr1);
    // for(i=0; i<7; i++)
    //     printf("%d ", ptr2[i]);

    // free(ptr1); //할당된 메모리 해제
    // free(ptr2);
    
//

// char * name1;
// char * name2;
// name1 = ReadUserName();
// printf("name1: %s \n", name1);
// name2 = ReadUserName();
// printf("name2: %s \n", name2);

// printf("again name1: %s \n", name1);
// printf("again name2: %s \n", name2);

// free(name1);
// free(name2);

    int auto_store = 40; //stack
    char auto_string[] = "Auto char Array"; 
    int * pi;
    char* pcl;

    pi = (int *)malloc(sizeof(int)); //heap
    *pi = 35;
    pcl = (char *) malloc(strlen("Dynamoc String") + 1); //heap
    strcpy(pcl, "Dynamic string");

    printf("static_store: %d at %p\n", static_store, &static_store );

    printf(" auto_store: %d at %p\n", auto_store, &auto_store);
    printf("   *pi: %d at %p\n", *pi, pi);
    printf("    %s at %p\n", pcg, pcg);
    printf("    %s at %p\n", auto_string, auto_string);
    printf("    %s at %p\n", pcl,pcl);
    printf("    %s at %p\n", "Quoted String", "Quoted String");
    free(pi);
    free(pcl);





    return 0;
}
// char * ReadUserName(void){
//     char * name = (char*)malloc(sizeof(char)*30);
//     printf("What's your name? ");
//     gets(name);
//     return name;
// }