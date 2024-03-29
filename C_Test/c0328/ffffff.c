/*
문제 1 
프로그램 사용자부로부터 문자열을 입력 받아서 입력 받은 만자열의 단어르 역으로 출력하는 프로그램을 작성해보자

i am a boy => boy a am i
단 문자열의 입력에 앞서 프로그램 사용자가 입력할 문자열의 최대길이 정보를 먼저 입력받기로하자 그리고 그 글이만큼 메모리 공간을 동적으로 할당해서
문자열을 입력받기로 하자.
참고로 이문제에서는 메모리의 동적할당 이외에 문자열의 단어를 역으로 출력하라는 비교적 어려윤 주제를 여러분에게 제시하고 있다. 이 문제를 해결하는 방법은 여러가지이다.
따라서 여유를 가지고 여러분 나람의 방법을 찾아서 구현해보기를 바란다ㅣ.



*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){

    // void* ptr1 = malloc(sizeof(int));
    // void* ptr1 = 4;
    // int* ptr1 = (int*)malloc(sizeof(int));
    // printf("%p\n",ptr1);
    // free(ptr1);
    // printf("ptr1:%p", &ptr1); //왜 프리해서 메모리 할당 해제 했는데 메모리 주소가 나오지?



    char * str = (char *)malloc(sizeof(char)*30);


    return 0 ;
}