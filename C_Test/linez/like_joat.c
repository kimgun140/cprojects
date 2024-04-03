//포인터를 사용하기;
#include<stdio.h>
void interchange(int * u, int * v);
int main(void){
    int x = 5, y = 10;


    printf("교환 전 x =%d, y = %d\n", x,y);
    interchange(&x, &y);
    printf("교환후 x = %d, y = %d\n", x, y);

    return 0;
}

void interchange(int * u, int * v)
{
    int temp;
    temp = *u;
    *u = *v;
    *v = temp;
}
/*
x와 y의 값을 맞교환하는 함수르 작성한다. 함수에 x와 y의 주소를 전달함으로써, interchange()가 그 변수에 접근할 수 있게 한다. 포인터와 *연산자를 사용함으로써, 함수는 
각각의주소에 저장되어 있는 값들을 구하고 변경할 수 있다. 
void interchange(int* , int *);



*/