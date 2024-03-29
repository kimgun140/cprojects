#include<stdio.h>
#define LEN 20

struct  names{
    char firest[LEN];
    char last[LEN];
};
struct  guy {
    struct names handle;
    char favfood[LEN];
    char job[LEN];
    float income;
};

int main(void){
    struct  guy fellow[2] = {
        {{"Ewen", "Villard"},
        "grilled salmon",
        "presonality coach",
        68112.00},
        {{"Rodney", "Swillbelly"},
        "tripe",
        "tabloid editor",
        232400.00
        }
    };
    struct guy * him;


    printf("주 소 #1: %p #2: %p \n",&fellow[0], &fellow[1]);
    him = &fellow[0];
    printf("포인터 #1: %p #2: %p\n", him, him+1);
    printf("him->income은 $%.2f: (*him).income은 $%.2f\n",
    him->income,(*him).income);
    him++;
    printf("him->favfood는 %s: him->handle.last는 %s\n",
    him->favfood, him->handle.last);
    return 0;

}