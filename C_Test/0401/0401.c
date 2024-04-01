//구조체 잘쓰셈 메인문 앞에
#include<stdio.h>
#define FUNDLEN 50
#define N 2

struct funds{

    char bank[FUNDLEN];
    double bankfund;
    char save[FUNDLEN];
    double savefund;
};

double sum(const struct funds money[],int n);

int main(void){

    struct funds jones[N] = {
      {  "국민은행",
        4032.27,
        "동아상호신용금고",
        8543.94
    },
    {
        "우리은행",
        3620.88,
    "대한상호신용금고",
        3802.91
    }
};

    printf("Jones 씨네 두 형제의 총 잔고는 $%.2f입니다.\n",
        sum(jones,N));
    return 0;
}
double sum(const struct funds money[],int n)
{

    double total;
    int i;

    for (i = 0 , total = 0; i < n; i++)
    total +=money[i].bankfund + money[i].savefund;




    
    return total;
}

void addineterst(struct funds * money, int n , double rate){
    int i;
    double current_bankfund = 0;
    double current_savefund = 0;
    double interest1 = 0;
    double interest2 = 0;
    for(i = 0; i< n; i++){
        printf("before bank fund: %.2f,  save fund : %.2f\n", money ->bankfund,money->savefund);
        current_bankfund = money ->bankfund;
        current_savefund = money ->savefund;
        interest1 = (current_bankfund /100) *rate;
        interest2 = (current_savefund / 100) * rate;
        money -> bankfund = current_bankfund + interest1;
        money ->savefund = current_savefund + interest2;
        printf("after bank fund: %.2f, save fund: %.2f \n", money->bankfund,money->savefund);
    }
}