#include <stdio.h>
int main(void)
{
    // int cows, legs;
    
    // printf("젖소들의 다리를 세어보니 모두 몇 개 더냐?\n");
    // scanf("%d", &legs);
    // cows = legs / 4;
    // printf("그렇다면 젖소가 %d마리로구나.\n", cows);

// 프로그래밍 7번
    // int cm; 
    // scanf("%d", &cm);
    // int inch = cm * 2.54;
    // printf("cm는 %d\n",inch);

// 프로그래밍 8번
// 온스1/8컵 테이블스푼1/16컵 1/48번  핀트2컵
    float cups;
    scanf("%f" ,&cups);
    float onunce  = cups /8;
    float tablespoons = cups/16;
    float teaspoon = cups/48;
    float pint = 2*cups;
    
    printf("%.3f onunce %f tablespoons %f teaspoons %f pint",onunce,tablespoons,teaspoon,pint);
    return 0;
}