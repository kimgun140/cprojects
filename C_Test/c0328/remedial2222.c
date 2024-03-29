#include<stdio.h>
#include<stdlib.h>


// 주소는 가리키는 자료형이 일치하는 포인터에만 대입이가능합니다. 따라서 다리키는 자료형이 다른 주소를
// 저장한는 경우라면 void 포인터를 사용합니다.
// void 포인터는 가리키는 자료형이 정해지지 않은 포인터입니다.
/*
os는 자리를 줄 뿐이다. 주소만 담겨 있는 void포인터로 주소를 준다.
malloc을 사용할 때 타입을 주지는 않았으니까


*/
void InputScores(int *base,int asize); //asize 명의 성적을 입력받는 함수
void ViewScores(int *base,int asize); //asize 명의 성적을 출력하는 함수
int InputScore(int num); //num 번의 학생 성적을 입력받는 함수


int main(void){
//1.
    // int a = 10; //int형변수
    // double b = 3.5; //double형 변ㄴ수
    // void * vp; // void포인터

    // vp = &a; //int 형 변수의 주소 저장
    // printf("a : %d\n", *(int *)vp);

    // vp = &b; // double형 변수의 주소 저장
    // printf("b : %.1f\n", *(double*)vp);


// // 2.
// int *pi; //동적 할당 영역을 연결할 포인터
// int i, sum = 0; // 반복 제어 변수와 누적 변수

// pi = (int*)malloc(5* sizeof(int)); // 저장 공간 20 바이트 할당
// if (pi == NULL){
//     printf("메모리가 부족합니다\n");
//     exit(1);
// }
// printf("다섯명의 나이를 입력하세요 : ");
// for( i = 0; i< 5; i++){ // i는 0부터 4까지 5번 반복

//     scanf("%d", &pi[i]); //배열 요소에 입력
//     sum += pi[i]; // 배열 요소의 값 누적
// }
// printf("다섯 명의 평균 나이 : %.1lf\n", (sum/5.0)); // 평균 나이 출력
// free(pi); // 할당한 메모리 영역 반환

// 3.


    // int *base = 0;  //동적으로 할당받아 학생들의 성적을 관리할 메모리의 시작 주소
    // int max_stu= 0;   //관리할 학생 수
    // printf("최대 관리할 학생 수를 입력하세요.\n");
    // scanf("%d",&max_stu);
    // base = (int *)malloc(sizeof(int) * max_stu); //성적을 보관할 메모리를 할당
    // InputScores(base,max_stu); //학생들의 성적 입력 요청
    // ViewScores(base,max_stu); //학생들의 성적 출력
    // free(base); //동적으로 할당한 메모리 해제

//4.

    int *pi;
    int size = 5;
    int cnt = 0;
    int num;
    int i ;
    pi = (int *)calloc(size, sizeof(int));
    while(1)
    {
        printf("양수를 입력하세여ㅛ =>");

        scanf("%d", &num);
        if(num <=0)break;
        if(cnt < size){
            pi[cnt++] = num;
        }
        else{
            size += 5;
            pi = (int*)realloc(pi, size*sizeof(int));
            pi[cnt++] = num;
        }
    }
    for (i =0; i < cnt; i++){
        printf("%5d", pi[i]);
    }
    free(pi);









    return 0;
}
//3
void InputScores(int *base,int asize)
{
    int i = 0;
    for(i = 0;  i<asize; i++)
    {
        base[i] = InputScore(i+1); //i+1 번의 학생 성적을 입력받아 base[i]에 대입
    }
}
void ViewScores(int *base,int asize) //asize 명의 성적을 출력하는 함수
{
    for(int i = 0; i<asize; i++){
        printf("%d\n", base[i]);

    }
}

int InputScore(int num) //num 번의 학생 성적을 입력받는 함수
{
    int score;
    printf("%d 번의 성적ㅇ르 입력하세요ㅕ.\n", num);
scanf("%d", &score);
return score;
}


