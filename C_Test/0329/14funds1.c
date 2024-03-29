#include<stdio.h>
#define FUNDLEN 50

struct funds{
    char bank[FUNDLEN];
    double bankfund;
    char save[FUNDLEN];
    double savefund;
};

double sum(const struct funds*); //전달인자가 구조체다. 복사를해서 새로운 구조체를 만들어서 돌아간다

int main(void){


    struct  funds stan = {
        "국민은행",
        3024.72,
        "동아상호신용금고",
        9237.11
    };

    printf("Stan 씨의 총 잔고는 $%.2f입니다.\n",
    sum(&stan));
    return 0 ;
    
}

/*두 개의 double형의 값을 더한다.*/

double sum(const struct funds*money){ // 
    return(money->bankfund + money->savefund);
}
