#include <stdio.h>
#include "item.h"
#include "monster1.h"
#include <time.h>
#include <stdlib.h>
int battle(Monster* monster,Boki* boki, int floor, int monstername);
int main(void)
{
    Boki boki;
    Monster monster;
    int Boki_hp;
    int max_hp;
    if (Boki_hp <= 0)
    {
        boki.chp = max_hp * 0.1;
        printf("최대체력 10%%로 부활합니다.\n");    
    }


return 0;
}
// 사망후 체력 회복

int battle(Monster* monster,Boki* boki, int floor, int monstername)//스위치 사용해서 몬스터네임이 1로 들어오면 1층애들만난다.  학생용사가 2, int battleboss 
{
    
    int choice;
    int item_choice;
    srand(time(NULL));
    while(1)
    {   
        switch (floor)
        {
            printf("1.전투\n2.아이템 사용\n3.도망 ");
        case 1:
            if(choice ==1){// 전투
            monster->oaks_warrior.hp -= boki->damage;
            printf("몬스터 남은 hp %f\n",monster->oaks_warrior.hp);
            printf("boki %d체력", boki->chp);
            boki->chp -= monster->oaks_warrior.damage;
            printf("boki 남은 hp %f\n", boki->chp);
            if(monster->oaks_warrior.hp<=0)
            {
                monster->oaks_warrior.hp=(rand() % 51 )+50;
                printf("승리했습니다.");
                break;
            }else if(boki->chp <=0){
                printf("패배했습니다.");
                break;
            }else if(monster->oaks_warrior.hp>0){
                



            }
            break;
        
        
        default:
            break;
        }


        }
    }

}


// 물약 사용
#include <stdio.h>
int main(void)
{
int red_potion;
int orange_potion;
int pure_potion;
int high_potion;
int potion_choice;
int Boki_hp;
int max_hp;
int item_choice;
printf("\n아이템을 선택해주세요\n 1.레드포션 2.주황포션 3.맑은물약 4.고농도물약\n ");
        scanf("%d", & item_choice);
        if (item_choice ==1 )
        {
            //포션
            if (red_potion<1){
            red_potion -= 1;
            printf("레드포션을 사용합니다. 남은 레드포션개수:%.0d\n", red_potion);
            Boki_hp = Boki_hp + red_potion;
            if(Boki_hp > max_hp){
                    Boki_hp =max_hp;
            printf("현재HP:%.0f", Boki_hp);
            }
        }
        }
        else if (item_choice ==2)
        {   
            if (orange_potion<1){
            orange_potion -= 1;
            printf("주황포션을 사용합니다. 남은 주황포션개수:%.0d\n", orange_potion);
            Boki_hp = Boki_hp + orange_potion;
            if(Boki_hp > max_hp)
                    Boki_hp =max_hp; 
        }
        }
        else if (item_choice ==3)
        {
            if (pure_potion<1){
            pure_potion -= 1;
            printf("맑은물약을 사용합니다. 남은 맑은물약개수:%0d\n", pure_potion);
            Boki_hp = Boki_hp + pure_potion;
            if(Boki_hp > max_hp)
                    Boki_hp =max_hp;
        }            
        }
        else if (item_choice ==4)
        {
            if (high_potion<1){
            high_potion -= 1;
        printf("고농도물약을 사용합니다. 남은 고농도물약개수:%0d\n", high_potion);
        Boki_hp = Boki_hp + high_potion;
        if(Boki_hp > max_hp)
                Boki_hp =max_hp;
        }
        }

return 0;
}

// #include <stdio.h>
// #include <stdlib.h>
// #include<time.h>
// int main(void)
// {
// int random;

// srand(time(NULL));
// random = rand()%101; //1부터 100까지 출력 
// if (random <= 30) //1부터 30까지 랜덤수
//     {
//     printf("%d, 도망성공", random);
//     }
//     else
// {
// printf("도망실패");
// }
    
// return 0;
// }
// //도망 로직