//const 변수를 변경하지못하게 할 수 있다. 
// double rates[5] = {}
// const double *pd = rates;
//pd가 가리키는 double형이 값이 const라고 선언한다. 이것은
// 가리키는 값을 변경할 목적으로 pd를 사용할 수 없다는 것을 의미한다.
//포인터 주소안에 값을 변경하지 못하게 하겠다. 원본값으 변경하지 못한다.
//그러면 변경할수 있는건  rates[]이다. 
//*pd = 23.90; 불가능하다.
//pd[2] = 22.22; 불가능하다.
//rates[0] = 99.99; rates는 const가 아니기 때문에 허용된다.
//포인터 표기 배열 표기 어느것을 사용하더라도,가리키는 값을 변경하기 위해 
//pd를 사용하는 것은 허용되지 않는다. 그러나 rates는 상수로 선언되지 않기 때문에
//값을 변경할 목적으로 rates를 사용할 수 있다. 
//상수를 가르키는 포인터는 데이터를 변경하는데 포인터를 사용하지 않는 함수에 함수 매개변수로 사용된다.
//void show_array(const double *ar, int n);


//포인터 대입과 const를 사용할 때 지켜야할 규칙
//1. 상수 데이터의 주소나 상수 데티어의 주소를 상수를 가리키는 포인터에 대입하는것은 유효하다.
//double rates[5] = {}
//const doouble locked[4] = {}
// const double *pc = rates;    유효하다
// pc = locked;                 유효하다
// pc = &rates[3];              유효하다

//array2d.c -- 2차원 배열을 처리하는 함수
#include<stdio.h>
#define ROWS 3
#define COLS 4
void sum_rows(int ar[][COLS], int rows);
void sum_cols(int [][COLS], int);
int sum2d(int (*ar)[COLS], int rows);
int main(void){
    int junk[ROWS][COLS] = {
        {2,4,6,8},
        {3,5,7,9,},
        {12,10,8,6}
    };

    sum_rows(junk, ROWS);
    sum_cols(junk, ROWS);
    printf("모든 원소들의 합계 = %d\n", sum2d(junk, ROWS));

    return 0;
}

void sum_rows (int ar[][COLS], int rows){
    int r;
    int c;
    int tot;

    for (r = 0; r< rows; r++){
        tot = 0;
        for ( c=0; c< COLS; c++){
            tot += ar[r][c];
        }
        printf("%d행 : 소계 = %d\n", r, tot);
    }
}

void sum_cols(int ar[][COLS], int rows){
    int r;
    int c;
    int tot;

    for (c =0; c <COLS; c++){
        tot = 0;
        for (r = 0; r<rows; r++)
                tot += ar[r][c];
        printf("%d열 : 소계 = %d\n", c, tot);
    }
}

int sum2d(int ar[][COLS], int rows){
    int r;
    int c;
    int tot = 0;

    for (r = 0; r< rows; r++)
        for ( c = 0; c < COLS; c++)
            tot += ar[r][c];

    return tot;
}