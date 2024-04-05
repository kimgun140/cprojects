#include <stdio.h>
#include "monster1.h"
#include <time.h>
#include <stdlib.h>
int battle(Monster *monster, Boki *boki, int floor, int monstername);
int battle_boss(Monster *monster, Boki *boki, int floor, int monstername);
int battle_oak_worrior(Monster *monster, Boki *boki, int floor, int monstername);
int battle_zombie(Monster *monster, Boki *boki, int floor, int monstername);
int battle_ghoul(Monster *monster, Boki *boki, int floor, int monstername);
int battle_skeleton(Monster *monster, Boki *boki, int floor, int monstername);
int battle_spartoi(Monster *monster, Boki *boki, int floor, int monstername);
int battle_baphomet(Monster *monster, Boki *boki, int floor, int monstername);
int battle_boss(Monster *monster, Boki *boki, int floor, int monstername);
int battle_realboss(Monster *monster, Boki *boki, int floor, int monstername);

int main(void)
{
    Boki boki;
    Monster monster;
    monster.oaks_warrior.hp=100;
    monster.oaks_warrior.damage=10;
    boki.fhp=100;
    boki.chp=100;
    boki.damage=20;
    boki.consume.potion.redpotion = 1;
    battle(&monster,&boki,1,1);
    

    return 0;
}


int battle(Monster *monster, Boki *boki, int floor, int monstername) // 스위치 사용해서 몬스터네임이 1로 들어오면 1층애들만난다.  학생용사가 2, int battleboss
{
    while (1)
    {   
        printf("1.전투\n2.물약 사용\n3.도망 ");
        int choice;
        int item_choice;
        scanf("%d",&choice);
        switch (floor)
        {
        case 1:
            if (choice == 1)
            { // 오크전사 전투
                monster->oaks_warrior.hp -= boki->damage; // 유저의 공격
                printf("몬스터 남은 hp %d\n", monster->oaks_warrior.hp);
                printf("boki %d체력", boki->chp);
                boki->chp -= monster->oaks_warrior.damage; //몬스터의 공격
                printf("boki 남은 hp %d\n", boki->chp);
                if (monster->oaks_warrior.hp <= 0) //몬스터가 죽었을 때
                {
                    printf("승리했습니다."); // 승리 메세지 출력
                    break;
                }
                else if (boki->chp <= 0)
                {
                    printf("패배했습니다."); //패배 메세지 출력
                    break;
                }
                else if (monster->oaks_warrior.hp > 0) //몬스터가 살아 있으면 콘티뉴
                {
                    break;;
                }
            break;
            }
            else if(choice ==2){
                //물약 사용

            int item_choice;
            printf("\n아이템을 선택해주세요\n 1.빨간물약 2.주황물약 3.맑은물약 4.고농도물약\n ");
                    scanf("%d", & item_choice);
                    switch(item_choice){
                    case 1: 
                    {
                        //포션
                        if (boki->consume.potion.redpotion>0){
                        boki->consume.potion.redpotion -= 1;
                        printf("빨간물약을 사용합니다. 남은 빨간물약개수:%d\n", boki->consume.potion.redpotion);
                        boki->chp +=30;

                        if(boki->chp > boki->fhp){
                            boki->chp = boki->fhp;
                        printf("현재HP:%d", boki->chp);
                        choice=0;
                        }
                        }
                        break;
                    }
                    case 2: 
                    {
                        //주황포션
                        if (boki->consume.potion.orangepotion>1){
                        boki->consume.potion.orangepotion -= 1;
                        printf("주황물약 사용합니다. 남은 주황물약개수:%d\n", boki->consume.potion.orangepotion);
                        boki->chp = boki->chp+50;
                        if(boki->chp > boki->fhp)
                            boki->chp = boki->fhp;
                        printf("현재HP:%d", boki->chp);
                        choice=0;
                        break;
                        }
                        break;
                    }                    
                    case 3: 
                    {
                        //포션
                        if (boki->consume.potion.purepotion>1){
                        boki->consume.potion.purepotion -= 1;
                        printf("맑은물약을 사용합니다. 남은 맑은물약개수:%d\n", boki->consume.potion.purepotion);
                        boki->chp = boki->chp+70;
                        if(boki->chp > boki->fhp)
                            boki->chp = boki->fhp;
                        printf("현재HP:%d", boki->chp);
                        choice=0;
                        break;
                        }
                        break;
                    }                    
                    case 4: 
                    {
                        //포션
                        if (boki->consume.potion.redpotion>1){
                        boki->consume.potion.redpotion -= 1;
                        printf("고농도물약을 사용합니다. 남은 고농도물약개수:%d\n", boki->consume.potion.highpotion);
                        boki->chp = boki->chp+150;
                        if(boki->chp > boki->fhp)
                            boki->chp = boki->fhp;
                        printf("현재HP:%d", boki->chp);
                        choice=0;
                        break;
                        }
                    break; 
                    }
                    
                    default:
                        break;
                    
                    }
        
            
            }else if(choice == 3){
            //도망가기
                srand(time(NULL));
                int random = rand()%100+1; //1부터 100까지 출력
                if (random <= 30) //1부터 30까지 랜덤수
                    {
                    printf("%d, 도망성공", random);
                    break;
                    }
                else
                {
                    printf("%d 도망실패", random);
                    break;
                }
            break;
            }
            case 2:
            if (choice == 1)
            { // 좀비 전투
                monster->zombie.hp -= boki->damage;
                printf("몬스터 남은 hp %d\n", monster->zombie.hp);
                printf("boki %d체력", boki->chp);
                boki->chp -= monster->zombie.damage;
                printf("boki 남은 hp %d\n", boki->chp);
                if (monster->zombie.hp <= 0)
                {
                    printf("승리했습니다.");
                    break;
                }
                else if (boki->chp <= 0)
                {
                    printf("패배했습니다.");
                    break;
                }
                else if (monster->zombie.hp > 0)
                {
                    continue;
                }
                // default:
                break;
            }
            else if(choice ==2){
                //물약 사용

            int item_choice;
            printf("\n아이템을 선택해주세요\n 1.빨간물약 2.주황물약 3.맑은물약 4.고농도물약\n ");
                    scanf("%d", & item_choice);
                    switch(item_choice){
                    case 1: 
                    {
                        //포션
                        if (boki->consume.potion.redpotion>1){
                        boki->consume.potion.redpotion -= 1;
                        printf("빨간물약을 사용합니다. 남은 빨간물약개수:%d\n", boki->consume.potion.redpotion);
                        boki->chp = boki->chp+30;
                        if(boki->chp > boki->fhp)
                            boki->chp = boki->fhp;
                        printf("현재HP:%d", boki->chp);
                        choice=0;
                        break;
                        }
                    }
                    case 2: 
                    {
                        //주황포션
                        if (boki->consume.potion.orangepotion>1){
                        boki->consume.potion.orangepotion -= 1;
                        printf("주황물약 사용합니다. 남은 주황물약개수:%d\n", boki->consume.potion.orangepotion);
                        boki->chp = boki->chp+50;
                        if(boki->chp > boki->fhp)
                            boki->chp = boki->fhp;
                        printf("현재HP:%d", boki->chp);
                        choice=0;
                        break;

                        }
                    }                    
                    case 3: 
                    {
                        //포션
                        if (boki->consume.potion.purepotion>1){
                        boki->consume.potion.purepotion -= 1;
                        printf("맑은물약을 사용합니다. 남은 맑은물약개수:%d\n", boki->consume.potion.purepotion);
                        boki->chp = boki->chp+70;
                        if(boki->chp > boki->fhp)
                            boki->chp = boki->fhp;
                        printf("현재HP:%d", boki->chp);
                        choice=0;
                        break;
                        
                        }
                    }                    
                    case 4: 
                    {
                        //포션
                        if (boki->consume.potion.redpotion>1){
                        boki->consume.potion.redpotion -= 1;
                        printf("고농도물약을 사용합니다. 남은 고농도물약개수:%d\n", boki->consume.potion.highpotion);
                        boki->chp = boki->chp+150;
                        if(boki->chp > boki->fhp)
                            boki->chp = boki->fhp;
                        printf("현재HP:%d", boki->chp);
                        choice=0;
                        break;
                        
                        }
                    }
                    }
        
            
            }else if(choice == 3){
            //도망가기
                srand(time(NULL));
                int random = rand()%100+1; //1부터 100까지 출력
                if (random <= 30) //1부터 30까지 랜덤수
                    {
                    printf("%d, 도망성공", random);
                    break;
                    }
                else
                {
                    printf("%d 도망실패", random);
                    continue;
                }
            }

            case 3:
            if (choice == 1)
            { // 구울 전투
                monster->skeleton.hp -= boki->damage;
                printf("몬스터 남은 hp %d\n", monster->ghoul.hp);
                printf("boki %d체력", boki->chp);
                boki->chp -= monster->ghoul.damage;
                printf("boki 남은 hp %d\n", boki->chp);
                if (monster->ghoul.hp <= 0)
                {

                    printf("승리했습니다.");
                    break;
                }
                else if (boki->chp <= 0)
                {
                    printf("패배했습니다.");
                    break;
                }
                else if (monster->ghoul.hp > 0)
                {
                    continue;
                }
                // default:
                break;
            }
                        else if(choice ==2){
                //물약 사용

            int item_choice;
            printf("\n아이템을 선택해주세요\n 1.빨간물약 2.주황물약 3.맑은물약 4.고농도물약\n ");
                    scanf("%d", & item_choice);
                    switch(item_choice){
                    case 1: 
                    {
                        //포션
                        if (boki->consume.potion.redpotion>1){
                        boki->consume.potion.redpotion -= 1;
                        printf("빨간물약을 사용합니다. 남은 빨간물약개수:%d\n", boki->consume.potion.redpotion);
                        boki->chp = boki->chp+30;
                        if(boki->chp > boki->fhp)
                            boki->chp = boki->fhp;
                        printf("현재HP:%d", boki->chp);
                        choice=0;
                        break;
                        }
                    }
                    case 2: 
                    {
                        //주황포션
                        if (boki->consume.potion.orangepotion>1){
                        boki->consume.potion.orangepotion -= 1;
                        printf("주황물약 사용합니다. 남은 주황물약개수:%d\n", boki->consume.potion.orangepotion);
                        boki->chp = boki->chp+50;
                        if(boki->chp > boki->fhp)
                            boki->chp = boki->fhp;
                        printf("현재HP:%d", boki->chp);
                        choice=0;
                        break;

                        }
                    }                    
                    case 3: 
                    {
                        //포션
                        if (boki->consume.potion.purepotion>1){
                        boki->consume.potion.purepotion -= 1;
                        printf("맑은물약을 사용합니다. 남은 맑은물약개수:%d\n", boki->consume.potion.purepotion);
                        boki->chp = boki->chp+70;
                        if(boki->chp > boki->fhp)
                            boki->chp = boki->fhp;
                        printf("현재HP:%d", boki->chp);
                        choice=0;
                        break;
                        
                        }
                    }                    
                    case 4: 
                    {
                        //포션
                        if (boki->consume.potion.redpotion>1){
                        boki->consume.potion.redpotion -= 1;
                        printf("고농도물약을 사용합니다. 남은 고농도물약개수:%d\n", boki->consume.potion.highpotion);
                        boki->chp = boki->chp+150;
                        if(boki->chp > boki->fhp)
                            boki->chp = boki->fhp;
                        printf("현재HP:%d", boki->chp);
                        choice=0;
                        break;
                        
                        }
                    }
                    }
        
            
            }else if(choice == 3){
            //도망가기
                srand(time(NULL));
                int random = rand()%100+1; //1부터 100까지 출력
                if (random <= 30) //1부터 30까지 랜덤수
                    {
                    printf("%d, 도망성공", random);
                    break;
                    }
                else
                {
                    printf("%d 도망실패", random);
                    continue;
                }
            }
            case 4:
            if (choice == 1)
            { // 스켈레톤 전투
                monster->skeleton.hp -= boki->damage;
                printf("몬스터 남은 hp %d\n", monster->skeleton.hp);
                printf("boki %d체력", boki->chp);
                boki->chp -= monster->skeleton.damage;
                printf("boki 남은 hp %d\n", boki->chp);
                if (monster->skeleton.hp <= 0)
                {

                    printf("승리했습니다.");
                    break;
                }
                else if (boki->chp <= 0)
                {
                    printf("패배했습니다.");
                    break;
                }
                else if (monster->skeleton.hp > 0)
                {
                    continue;
                }
                // default:
                break;
            }
                        else if(choice ==2){
                //물약 사용

            int item_choice;
            printf("\n아이템을 선택해주세요\n 1.빨간물약 2.주황물약 3.맑은물약 4.고농도물약\n ");
                    scanf("%d", & item_choice);
                    switch(item_choice){
                    case 1: 
                    {
                        //포션
                        if (boki->consume.potion.redpotion>1){
                        boki->consume.potion.redpotion -= 1;
                        printf("빨간물약을 사용합니다. 남은 빨간물약개수:%d\n", boki->consume.potion.redpotion);
                        boki->chp = boki->chp+30;
                        if(boki->chp > boki->fhp)
                            boki->chp = boki->fhp;
                        printf("현재HP:%d", boki->chp);
                        choice=0;
                        break;
                        }
                    }
                    case 2: 
                    {
                        //주황포션
                        if (boki->consume.potion.orangepotion>1){
                        boki->consume.potion.orangepotion -= 1;
                        printf("주황물약 사용합니다. 남은 주황물약개수:%d\n", boki->consume.potion.orangepotion);
                        boki->chp = boki->chp+50;
                        if(boki->chp > boki->fhp)
                            boki->chp = boki->fhp;
                        printf("현재HP:%d", boki->chp);
                        choice=0;
                        break;

                        }
                    }                    
                    case 3: 
                    {
                        //포션
                        if (boki->consume.potion.purepotion>1){
                        boki->consume.potion.purepotion -= 1;
                        printf("맑은물약을 사용합니다. 남은 맑은물약개수:%d\n", boki->consume.potion.purepotion);
                        boki->chp = boki->chp+70;
                        if(boki->chp > boki->fhp)
                            boki->chp = boki->fhp;
                        printf("현재HP:%d", boki->chp);
                        choice=0;
                        break;
                        
                        }
                    }                    
                    case 4: 
                    {
                        //포션
                        if (boki->consume.potion.redpotion>1){
                        boki->consume.potion.redpotion -= 1;
                        printf("고농도물약을 사용합니다. 남은 고농도물약개수:%d\n", boki->consume.potion.highpotion);
                        boki->chp = boki->chp+150;
                        if(boki->chp > boki->fhp)
                            boki->chp = boki->fhp;
                        printf("현재HP:%d", boki->chp);
                        choice=0;
                        break;
                        
                        }
                    }
                    }
        
            
            }else if(choice == 3){
            //도망가기
                srand(time(NULL));
                int random = rand()%100+1; //1부터 100까지 출력
                if (random <= 30) //1부터 30까지 랜덤수
                    {
                    printf("%d, 도망성공", random);
                    break;
                    }
                else
                {
                    printf("%d 도망실패", random);
                    continue;
                }
            }
        case 5:
            if (choice == 1)
            { // 스파토이 전투
                monster->spartoi.hp -= boki->damage;
                printf("몬스터 남은 hp %d\n", monster->spartoi.hp);
                printf("boki %d체력", boki->chp);
                boki->chp -= monster->spartoi.damage;
                printf("boki 남은 hp %d\n", boki->chp);
                if (monster->spartoi.hp <= 0)
                {

                    printf("승리했습니다.");
                    break;
                }
                else if (boki->chp <= 0)
                {
                    printf("패배했습니다.");
                    break;
                }
                else if (monster->spartoi.hp > 0)
                {
                    continue;
                }
                // default:
                break;
            }
                        else if(choice ==2){
                //물약 사용

            int item_choice;
            printf("\n아이템을 선택해주세요\n 1.빨간물약 2.주황물약 3.맑은물약 4.고농도물약\n ");
                    scanf("%d", & item_choice);
                    switch(item_choice){
                    case 1: 
                    {
                        //포션
                        if (boki->consume.potion.redpotion>1){
                        boki->consume.potion.redpotion -= 1;
                        printf("빨간물약을 사용합니다. 남은 빨간물약개수:%d\n", boki->consume.potion.redpotion);
                        boki->chp = boki->chp+30;
                        if(boki->chp > boki->fhp)
                            boki->chp = boki->fhp;
                        printf("현재HP:%d", boki->chp);
                        choice=0;
                        break;
                        }
                    }
                    case 2: 
                    {
                        //주황포션
                        if (boki->consume.potion.orangepotion>1){
                        boki->consume.potion.orangepotion -= 1;
                        printf("주황물약 사용합니다. 남은 주황물약개수:%d\n", boki->consume.potion.orangepotion);
                        boki->chp = boki->chp+50;
                        if(boki->chp > boki->fhp)
                            boki->chp = boki->fhp;
                        printf("현재HP:%d", boki->chp);
                        choice=0;
                        break;

                        }
                    }                    
                    case 3: 
                    {
                        //포션
                        if (boki->consume.potion.purepotion>1){
                        boki->consume.potion.purepotion -= 1;
                        printf("맑은물약을 사용합니다. 남은 맑은물약개수:%d\n", boki->consume.potion.purepotion);
                        boki->chp = boki->chp+70;
                        if(boki->chp > boki->fhp)
                            boki->chp = boki->fhp;
                        printf("현재HP:%d", boki->chp);
                        choice=0;
                        break;
                        
                        }
                    }                    
                    case 4: 
                    {
                        //포션
                        if (boki->consume.potion.redpotion>1){
                        boki->consume.potion.redpotion -= 1;
                        printf("고농도물약을 사용합니다. 남은 고농도물약개수:%d\n", boki->consume.potion.highpotion);
                        boki->chp = boki->chp+150;
                        if(boki->chp > boki->fhp)
                            boki->chp = boki->fhp;
                        printf("현재HP:%d", boki->chp);
                        choice=0;
                        break;
                        
                        }
                    }
                    }
        
            
            }else if(choice == 3){
            //도망가기
                srand(time(NULL));
                int random = rand()%100+1; //1부터 100까지 출력
                if (random <= 30) //1부터 30까지 랜덤수
                    {
                    printf("%d, 도망성공", random);
                    break;
                    }
                else
                {
                    printf("%d 도망실패", random);
                    continue;
                }
            }
        case 6:
            if (choice == 1)
            { // 바포메트 전투
                monster->Baphomet.hp -= boki->damage;
                printf("몬스터 남은 hp %d\n", monster->Baphomet.hp);
                printf("boki %d체력", boki->chp);
                boki->chp -= monster->Baphomet.damage;
                printf("boki 남은 hp %d\n", boki->chp);
                if (monster->Baphomet.hp <= 0)
                {

                    printf("승리했습니다.");
                    break;
                }
                else if (boki->chp <= 0)
                {
                    printf("패배했습니다.");
                    break;
                }
                else if (monster->Baphomet.hp > 0)
                {
                    continue;
                }
                // default:
                break;
            }
                        else if(choice ==2){
                //물약 사용

            int item_choice;
            printf("\n아이템을 선택해주세요\n 1.빨간물약 2.주황물약 3.맑은물약 4.고농도물약\n ");
                    scanf("%d", & item_choice);
                    switch(item_choice){
                    case 1: 
                    {
                        //포션
                        if (boki->consume.potion.redpotion>1){
                        boki->consume.potion.redpotion -= 1;
                        printf("빨간물약을 사용합니다. 남은 빨간물약개수:%d\n", boki->consume.potion.redpotion);
                        boki->chp = boki->chp+30;
                        if(boki->chp > boki->fhp)
                            boki->chp = boki->fhp;
                        printf("현재HP:%d", boki->chp);
                        choice=0;
                        break;
                        }
                    }
                    case 2: 
                    {
                        //주황포션
                        if (boki->consume.potion.orangepotion>1){
                        boki->consume.potion.orangepotion -= 1;
                        printf("주황물약 사용합니다. 남은 주황물약개수:%d\n", boki->consume.potion.orangepotion);
                        boki->chp = boki->chp+50;
                        if(boki->chp > boki->fhp)
                            boki->chp = boki->fhp;
                        printf("현재HP:%d", boki->chp);
                        choice=0;
                        break;

                        }
                    }                    
                    case 3: 
                    {
                        //포션
                        if (boki->consume.potion.purepotion>1){
                        boki->consume.potion.purepotion -= 1;
                        printf("맑은물약을 사용합니다. 남은 맑은물약개수:%d\n", boki->consume.potion.purepotion);
                        boki->chp = boki->chp+70;
                        if(boki->chp > boki->fhp)
                            boki->chp = boki->fhp;
                        printf("현재HP:%d", boki->chp);
                        choice=0;
                        break;
                        
                        }
                    }                    
                    case 4: 
                    {
                        //포션
                        if (boki->consume.potion.redpotion>1){
                        boki->consume.potion.redpotion -= 1;
                        printf("고농도물약을 사용합니다. 남은 고농도물약개수:%d\n", boki->consume.potion.highpotion);
                        boki->chp = boki->chp+150;
                        if(boki->chp > boki->fhp)
                            boki->chp = boki->fhp;
                        printf("현재HP:%d", boki->chp);
                        choice=0;
                        break;
                        
                        }
                    }
                    }
        
            
            }else if(choice == 3){
            //도망가기
                srand(time(NULL));
                int random = rand()%100+1; //1부터 100까지 출력
                if (random <= 30) //1부터 30까지 랜덤수
                    {
                    printf("%d, 도망성공", random);
                    break;
                    }
                else
                {
                    printf("%d 도망실패", random);
                    continue;
                }
            }
        }
    }
}
// int battle_boss(Monster *monster, Boki *boki, int floor, int monstername)
// {

//     while (1)
//     {
//         int choice;
//         switch (floor)
//         {
//             printf("1.전투\n2.아이템 사용\n3.도망 ");
//         case 1:
//             if (choice == 1)
//             { // 전투 boss
//                 monster->boss.hp -= boki->damage;
//                 printf("몬스터 남은 hp %d\n", monster->boss.hp);
//                 printf("boki %d체력", boki->chp);
//                 boki->chp -= monster->boss.damage;
//                 printf("boki 남은 hp %d\n", boki->chp);
//                 if (monster->boss.hp <= 0)
//                 {

//                     printf("승리했습니다.");
//                     break;
//                 }
//                 else if (boki->chp <= 0)
//                 {
//                     printf("패배했습니다.");
//                     break;
//                 }
//                 else if (monster->boss.hp > 0)
//                 {
//                     continue;
//                 }
//             default:
//                 break;
//             }
//                         else if(choice ==2){
//                 //물약 사용

//             int item_choice;
//             printf("\n아이템을 선택해주세요\n 1.빨간물약 2.주황물약 3.맑은물약 4.고농도물약\n ");
//                     scanf("%d", & item_choice);
//                     switch(item_choice){
//                     case 1: 
//                     {
//                         //포션
//                         if (boki->consume.potion.redpotion>1){
//                         boki->consume.potion.redpotion -= 1;
//                         printf("빨간물약을 사용합니다. 남은 빨간물약개수:%d\n", boki->consume.potion.redpotion);
//                         boki->chp = boki->chp+30;
//                         if(boki->chp > boki->fhp)
//                             boki->chp = boki->fhp;
//                         printf("현재HP:%d", boki->chp);
//                              choice=0;
//                         break;
//                         }
//                     }
//                     case 2: 
//                     {
//                         //주황포션
//                         if (boki->consume.potion.orangepotion>1){
//                         boki->consume.potion.orangepotion -= 1;
//                         printf("주황물약 사용합니다. 남은 주황물약개수:%d\n", boki->consume.potion.orangepotion);
//                         boki->chp = boki->chp+50;
//                         if(boki->chp > boki->fhp)
//                             boki->chp = boki->fhp;
//                         printf("현재HP:%d", boki->chp);
//                         break;

//                         }
//                     }                    
//                     case 3: 
//                     {
//                         //포션
//                         if (boki->consume.potion.purepotion>1){
//                         boki->consume.potion.purepotion -= 1;
//                         printf("맑은물약을 사용합니다. 남은 맑은물약개수:%d\n", boki->consume.potion.purepotion);
//                         boki->chp = boki->chp+70;
//                         if(boki->chp > boki->fhp)
//                             boki->chp = boki->fhp;
//                         printf("현재HP:%d", boki->chp);
//                         break;
                        
//                         }
//                     }                    
//                     case 4: 
//                     {
//                         //포션
//                         if (boki->consume.potion.redpotion>1){
//                         boki->consume.potion.redpotion -= 1;
//                         printf("고농도물약을 사용합니다. 남은 고농도물약개수:%d\n", boki->consume.potion.highpotion);
//                         boki->chp = boki->chp+150;
//                         if(boki->chp > boki->fhp)
//                             boki->chp = boki->fhp;
//                         printf("현재HP:%d", boki->chp);
//                         break;
                        
//                         }
//                     }
//                     }
        
            
//             }else if(choice == 3){
//             //도망가기
//                 srand(time(NULL));
//                 int random = rand()%100+1; //1부터 100까지 출력
//                 if (random <= 30) //1부터 30까지 랜덤수
//                     {
//                     printf("%d, 도망성공", random);
//                     break;
//                     }
//                 else
//                 {
//                     printf("%d 도망실패", random);
//                     continue;
//                 }
//             }
//             case 2:
//             if (choice == 1)
//             { // 전투 boss
//                 monster->realboss.hp -= boki->damage;
//                 printf("몬스터 남은 hp %d\n", monster->realboss.hp);
//                 printf("boki %d체력", boki->chp);
//                 boki->chp -= monster->realboss.damage;
//                 printf("boki 남은 hp %d\n", boki->chp);
//                 if (monster->realboss.hp <= 0)
//                 {

//                     printf("승리했습니다.");
//                     break;
//                 }
//                 else if (boki->chp <= 0)
//                 {
//                     printf("패배했습니다.");
//                     break;
//                 }
//                 else if (monster->realboss.hp > 0)
//                 {
//                     continue;
//                 }
//             // default:
//                 break;
//             }
//                         else if(choice ==2){
//                 //물약 사용

//             int item_choice;
//             printf("\n아이템을 선택해주세요\n 1.빨간물약 2.주황물약 3.맑은물약 4.고농도물약\n ");
//                     scanf("%d", & item_choice);
//                     switch(item_choice){
//                     case 1: 
//                     {
//                         //포션
//                         if (boki->consume.potion.redpotion>1){
//                         boki->consume.potion.redpotion -= 1;
//                         printf("빨간물약을 사용합니다. 남은 빨간물약개수:%d\n", boki->consume.potion.redpotion);
//                         boki->chp = boki->chp+30;
//                         if(boki->chp > boki->fhp)
//                             boki->chp = boki->fhp;
//                         printf("현재HP:%d", boki->chp);
//                         break;
//                         }
//                     }
//                     case 2: 
//                     {
//                         //주황포션
//                         if (boki->consume.potion.orangepotion>1){
//                         boki->consume.potion.orangepotion -= 1;
//                         printf("주황물약 사용합니다. 남은 주황물약개수:%d\n", boki->consume.potion.orangepotion);
//                         boki->chp = boki->chp+50;
//                         if(boki->chp > boki->fhp)
//                             boki->chp = boki->fhp;
//                         printf("현재HP:%d", boki->chp);
//                         break;

//                         }
//                     }                    
//                     case 3: 
//                     {
//                         //포션
//                         if (boki->consume.potion.purepotion>1){
//                         boki->consume.potion.purepotion -= 1;
//                         printf("맑은물약을 사용합니다. 남은 맑은물약개수:%d\n", boki->consume.potion.purepotion);
//                         boki->chp = boki->chp+70;
//                         if(boki->chp > boki->fhp)
//                             boki->chp = boki->fhp;
//                         printf("현재HP:%d", boki->chp);
//                         break;
                        
//                         }
//                     }                    
//                     case 4: 
//                     {
//                         //포션
//                         if (boki->consume.potion.redpotion>1){
//                         boki->consume.potion.redpotion -= 1;
//                         printf("고농도물약을 사용합니다. 남은 고농도물약개수:%d\n", boki->consume.potion.highpotion);
//                         boki->chp = boki->chp+150;
//                         if(boki->chp > boki->fhp)
//                             boki->chp = boki->fhp;
//                         printf("현재HP:%d", boki->chp);
//                         break;
                        
//                         }
//                     }
//                     }
        
            
//             }else if(choice == 3){
//             //도망가기
//                 srand(time(NULL));
//                 int random = rand()%100+1; //1부터 100까지 출력
//                 if (random <= 30) //1부터 30까지 랜덤수
//                     {
//                     printf("%d, 도망성공", random);
//                     break;
//                     }
//                 else
//                 {
//                     printf("%d 도망실패", random);
//                     continue;
//                 }
//             }
//             case 3:
//             if (choice == 1)
//             { // 전투 학생용사  ???? 
//                 monster->hero.hp -= boki->damage;
//                 printf("몬스터 남은 hp %d\n", monster->realboss.hp);
//                 printf("boki %d체력", boki->chp);
//                 boki->chp -= monster->realboss.damage;
//                 printf("boki 남은 hp %d\n", boki->chp);
//                 if (monster->realboss.hp <= 0)
//                 {

//                     printf("승리했습니다.");
//                     break;
//                 }
//                 else if (boki->chp <= 0)
//                 {
//                     printf("패배했습니다.");
//                     break;
//                 }
//                 else if (monster->realboss.hp > 0)
//                 {
//                     continue;
//                 }
//             // default:
//                 break;
//             }

//                         else if(choice ==2){
//                 //물약 사용

//             int item_choice;
//             printf("\n아이템을 선택해주세요\n 1.빨간물약 2.주황물약 3.맑은물약 4.고농도물약\n ");
//                     scanf("%d", & item_choice);
//                     switch(item_choice){
//                     case 1: 
//                     {
//                         //포션
//                         if (boki->consume.potion.redpotion>1){
//                         boki->consume.potion.redpotion -= 1;
//                         printf("빨간물약을 사용합니다. 남은 빨간물약개수:%d\n", boki->consume.potion.redpotion);
//                         boki->chp = boki->chp+30;
//                         if(boki->chp > boki->fhp)
//                             boki->chp = boki->fhp;
//                         printf("현재HP:%d", boki->chp);
//                         break;
//                         }
//                     }
//                     case 2: 
//                     {
//                         //주황포션
//                         if (boki->consume.potion.orangepotion>1){
//                         boki->consume.potion.orangepotion -= 1;
//                         printf("주황물약 사용합니다. 남은 주황물약개수:%d\n", boki->consume.potion.orangepotion);
//                         boki->chp = boki->chp+50;
//                         if(boki->chp > boki->fhp)
//                             boki->chp = boki->fhp;
//                         printf("현재HP:%d", boki->chp);
//                         break;

//                         }
//                     }                    
//                     case 3: 
//                     {
//                         //포션
//                         if (boki->consume.potion.purepotion>1){
//                         boki->consume.potion.purepotion -= 1;
//                         printf("맑은물약을 사용합니다. 남은 맑은물약개수:%d\n", boki->consume.potion.purepotion);
//                         boki->chp = boki->chp+70;
//                         if(boki->chp > boki->fhp)
//                             boki->chp = boki->fhp;
//                         printf("현재HP:%d", boki->chp);
//                         break;
                        
//                         }
//                     }                    
//                     case 4: 
//                     {
//                         //포션
//                         if (boki->consume.potion.redpotion>1){
//                         boki->consume.potion.redpotion -= 1;
//                         printf("고농도물약을 사용합니다. 남은 고농도물약개수:%d\n", boki->consume.potion.highpotion);
//                         boki->chp = boki->chp+150;
//                         if(boki->chp > boki->fhp)
//                             boki->chp = boki->fhp;
//                         printf("현재HP:%d", boki->chp);
//                         break;
                        
//                         }
//                     }
//                     }
        
            
//             }else if(choice == 3){
//             //도망가기
//                 srand(time(NULL));
//                 int random = rand()%100+1; //1부터 100까지 출력
//                 if (random <= 30) //1부터 30까지 랜덤수
//                     {
//                     printf("%d, 도망성공", random);
//                     break;
//                     }
//                 else
//                 {
//                     printf("%d 도망실패", random);
//                     continue;
//                 }
//             }
//         }
//     }
// }



// 어떤 조건에서 만나는지를 모르겠네


// int battle_oak_worrior(Monster *monster, Boki *boki, int floor, int monstername){
//     //오크 워리어 전투
// while(1){
//                 printf("오크워리어를 만났습니다.\n");

//                 printf("1.전투\n2.아이템 사용\n3.도망 ");
//                 int choice;
//                 scanf("%d",&choice);
//             if (choice == 1)
//             { // 오크전사 전투
//                 monster->oaks_warrior.hp -= boki->damage; // 유저의 공격
//                 printf("몬스터 남은 hp %d\n", monster->oaks_warrior.hp);
//                 printf("boki %d체력", boki->chp);
//                 boki->chp -= monster->oaks_warrior.damage; //몬스터의 공격
//                 printf("boki 남은 hp %d\n", boki->chp);
//                 if (monster->oaks_warrior.hp <= 0) //몬스터가 죽었을 때
//                 {
//                     printf("승리했습니다."); // 승리 메세지 출력
//                     break;
//                 }
//                 else if (boki->chp <= 0)
//                 {
//                     printf("패배했습니다."); //패배 메세지 출력
//                     break;
//                 }
//                 else if (monster->oaks_warrior.hp > 0) //몬스터가 살아 있으면 콘티뉴
//                 {
//                     continue;
//                 }
//             if(choice ==2){
//                 //아이템 사용
//                 continue;
//             }else if(choice == 3){
//             //도망가기
//                     srand(time(NULL));
//                     int   random = rand()%101; //1부터 100까지 출력
//                 if (random <= 30) //1부터 30까지 랜덤수
//                     {
//                     printf("%d, 도망성공", random);
//                     break;
//                     }
//                 else
//                 {
//                     printf("도망실패");
//                     continue;
//                 }
//             }
//         }
//     }
// }

// int battle_zombie(Monster *monster, Boki *boki, int floor, int monstername){
//     while(1){
//                 printf("좀비를 만났습니다.\n");

//                 printf("1.전투\n2.아이템 사용\n3.도망 ");
//                 int choice;
//                 scanf("%d",&choice);
                
//             if (choice == 1)
//             { // 좀비 전투
            
//                 monster->zombie.hp -= boki->damage; // 유저의 공격
//                 printf("몬스터 남은 hp %d\n", monster->zombie.hp);
//                 printf("boki %d체력", boki->chp);
//                 boki->chp -= monster->zombie.damage; //몬스터의 공격
//                 printf("boki 남은 hp %d\n", boki->chp);
//                 if (monster->zombie.hp <= 0) //몬스터가 죽었을 때
//                 {
//                     printf("승리했습니다."); // 승리 메세지 출력
//                     break;
//                 }
//                 else if (boki->chp <= 0)
//                 {
//                     printf("패배했습니다."); //패배 메세지 출력
//                     break;
//                 }
//                 else if (monster->zombie.hp > 0) //몬스터가 살아 있으면 콘티뉴
//                 {
//                     continue;
//                 }
//             if(choice ==2){
//                 //아이템 사용
//                 continue;
//             }else if(choice == 3){
//             //도망가기
//                     srand(time(NULL));
//                     int   random = rand()%101; //1부터 100까지 출력
//                 if (random <= 30) //1부터 30까지 랜덤수
//                     {
//                     printf("%d, 도망성공", random);
//                     break;
//                     }
//                 else
//                 {
//                     printf("도망실패");
//                     continue;
//                 }
//             }
//         }
//     }
// }

// int battle_ghoul(Monster *monster, Boki *boki, int floor, int monstername){
//     while(1){
//                 printf("구울을 만났습니다.\n");

//                 printf("1.전투\n2.아이템 사용\n3.도망 ");
//                 int choice;
//                 scanf("%d",&choice);
//             if (choice == 1)
//             { // ghoul 전투
//                 monster->ghoul.hp -= boki->damage; // 유저의 공격
//                 printf("몬스터 남은 hp %d\n", monster->ghoul.hp);
//                 printf("boki %d체력", boki->chp);
//                 boki->chp -= monster->ghoul.damage; //몬스터의 공격
//                 printf("boki 남은 hp %d\n", boki->chp);
//                 if (monster->ghoul.hp <= 0) //몬스터가 죽었을 때
//                 {
//                     printf("승리했습니다."); // 승리 메세지 출력
//                     break;
//                 }
//                 else if (boki->chp <= 0)
//                 {
//                     printf("패배했습니다."); //패배 메세지 출력
//                     break;
//                 }
//                 else if (monster->ghoul.hp > 0) //몬스터가 살아 있으면 콘티뉴
//                 {
//                     continue;
//                 }
//             if(choice ==2){
//                 //아이템 사용
//                 continue;
//             }else if(choice == 3){
//             //도망가기
//                     srand(time(NULL));
//                     int   random = rand()%101; //1부터 100까지 출력
//                 if (random <= 30) //1부터 30까지 랜덤수
//                     {
//                     printf("%d, 도망성공", random);
//                     break;
//                     }
//                 else
//                 {
//                     printf("도망실패");
//                     continue;
//                 }
//             }
//         }
//     }
// }
// int battle_skeleton(Monster *monster, Boki *boki, int floor, int monstername){
//     while(1){
//                 printf("스켈레톤을 만났습니다.\n");

//                 printf("1.전투\n2.아이템 사용\n3.도망 ");
//                 int choice;
//                 scanf("%d",&choice);
//             if (choice == 1)
//             { // skeleton 전투
            
//                 monster->skeleton.hp -= boki->damage; // 유저의 공격
//                 printf("몬스터 남은 hp %d\n", monster->skeleton.hp);
//                 printf("boki %d체력", boki->chp);
//                 boki->chp -= monster->skeleton.damage; //몬스터의 공격
//                 printf("boki 남은 hp %d\n", boki->chp);
//                 if (monster->skeleton.hp <= 0) //몬스터가 죽었을 때
//                 {
//                     printf("승리했습니다."); // 승리 메세지 출력
//                     break;
//                 }
//                 else if (boki->chp <= 0)
//                 {
//                     printf("패배했습니다."); //패배 메세지 출력
//                     break;
//                 }
//                 else if (monster->skeleton.hp > 0) //몬스터가 살아 있으면 콘티뉴
//                 {
//                     continue;
//                 }
//             if(choice ==2){
//                 //아이템 사용
//                 continue;
//             }else if(choice == 3){
//             //도망가기
//                     srand(time(NULL));
//                     int   random = rand()%101; //1부터 100까지 출력
//                 if (random <= 30) //1부터 30까지 랜덤수
//                     {
//                     printf("%d, 도망성공", random);
//                     break;
//                     }
//                 else
//                 {
//                     printf("도망실패");
//                     continue;
//                 }
//             }
//         }
//     }
// }

// int battle_spartoi(Monster *monster, Boki *boki, int floor, int monstername){
//     while(1){
//                 printf("스파토이를 만났습니다.\n");

//                 printf("1.전투\n2.아이템 사용\n3.도망 ");
//                 int choice;
//                 scanf("%d",&choice);
//             if (choice == 1)
//             { // spartoi 전투
//                 monster->spartoi.hp -= boki->damage; // 유저의 공격
//                 printf("몬스터 남은 hp %d\n", monster->spartoi.hp);
//                 printf("boki %d체력", boki->chp);
//                 boki->chp -= monster->spartoi.damage; //몬스터의 공격
//                 printf("boki 남은 hp %d\n", boki->chp);
//                 if (monster->spartoi.hp <= 0) //몬스터가 죽었을 때
//                 {
//                     printf("승리했습니다."); // 승리 메세지 출력
//                     break;
//                 }
//                 else if (boki->chp <= 0)
//                 {
//                     printf("패배했습니다."); //패배 메세지 출력
//                     break;
//                 }
//                 else if (monster->spartoi.hp > 0) //몬스터가 살아 있으면 콘티뉴
//                 {
//                     continue;
//                 }
//             if(choice ==2){
//                 //아이템 사용
//                 continue;
//             }else if(choice == 3){
//             //도망가기
//                     srand(time(NULL));
//                     int   random = rand()%101; //1부터 100까지 출력
//                 if (random <= 30) //1부터 30까지 랜덤수
//                     {
//                     printf("%d, 도망성공", random);
//                     break;
//                     }
//                 else
//                 {
//                     printf("도망실패");
//                     continue;
//                 }
//             }
//         }
//     }
// }

// int battle_baphomet(Monster *monster, Boki *boki, int floor, int monstername){
//     while(1){
//                 printf("바포메트를 만났습니다.\n");

//                 printf("1.전투\n2.아이템 사용\n3.도망 ");
//                 int choice;
//                 scanf("%d",&choice);
//             if (choice == 1)
//             { // ghoul 전투
//                 monster->Baphomet.hp -= boki->damage; // 유저의 공격
//                 printf("몬스터 남은 hp %d\n", monster->Baphomet.hp);
//                 printf("boki %d체력", boki->chp);
//                 boki->chp -= monster->Baphomet.damage; //몬스터의 공격
//                 printf("boki 남은 hp %d\n", boki->chp);
//                 if (monster->Baphomet.hp <= 0) //몬스터가 죽었을 때
//                 {
//                     printf("승리했습니다."); // 승리 메세지 출력
//                     break;
//                 }
//                 else if (boki->chp <= 0)
//                 {
//                     printf("패배했습니다."); //패배 메세지 출력
//                     break;
//                 }
//                 else if (monster->Baphomet.hp > 0) //몬스터가 살아 있으면 콘티뉴
//                 {
//                     continue;
//                 }
//             if(choice ==2){
//                 //아이템 사용
//                 continue;
//             }else if(choice == 3){
//             //도망가기
//                     srand(time(NULL));
//                     int   random = rand()%101; //1부터 100까지 출력
//                 if (random <= 30) //1부터 30까지 랜덤수
//                     {
//                     printf("%d, 도망성공", random);
//                     break;
//                     }
//                 else
//                 {
//                     printf("도망실패");
//                     continue;
//                 }
//             }
//         }
//     }
// }

// int battle_boss(Monster *monster, Boki *boki, int floor, int monstername){
//     while(1){
//                 printf("보스를 만났습니다.\n");

//                 printf("1.전투\n2.아이템 사용\n3.도망 ");
//                 int choice;
//                 scanf("%d",&choice);
//             if (choice == 1)
//             { // ghoul 전투
//                 monster->boss.hp -= boki->damage; // 유저의 공격
//                 printf("몬스터 남은 hp %d\n", monster->boss.hp);
//                 printf("boki %d체력", boki->chp);
//                 boki->chp -= monster->boss.damage; //몬스터의 공격
//                 printf("boki 남은 hp %d\n", boki->chp);
//                 if (monster->boss.hp <= 0) //몬스터가 죽었을 때
//                 {
//                     printf("승리했습니다."); // 승리 메세지 출력
//                     break;
//                 }
//                 else if (boki->chp <= 0)
//                 {
//                     printf("패배했습니다."); //패배 메세지 출력
//                     break;
//                 }
//                 else if (monster->boss.hp > 0) //몬스터가 살아 있으면 콘티뉴
//                 {
//                     continue;
//                 }
//             if(choice ==2){
//                 //아이템 사용
//                 continue;
//             }else if(choice == 3){
//             //도망가기
//                     srand(time(NULL));
//                     int   random = rand()%101; //1부터 100까지 출력
//                 if (random <= 30) //1부터 30까지 랜덤수
//                     {
//                     printf("%d, 도망성공", random);
//                     break;
//                     }
//                 else
//                 {
//                     printf("도망실패");
//                     continue;
//                 }
//             }
//         }
//     }
// }

// int battle_realboss(Monster *monster, Boki *boki, int floor, int monstername){
//     while(1){
//                 printf("리얼보스를 만났습니다.\n");

//                 printf("1.전투\n2.아이템 사용\n3.도망 ");
//                 int choice;
//                 scanf("%d",&choice);
//             if (choice == 1)
//             { //  전투
//                 monster->realboss.hp -= boki->damage; // 유저의 공격
//                 printf("몬스터 남은 hp %d\n", monster->realboss.hp);
//                 printf("boki %d체력", boki->chp);
//                 boki->chp -= monster->realboss.damage; //몬스터의 공격
//                 printf("boki 남은 hp %d\n", boki->chp);
//                 if (monster->realboss.hp <= 0) //몬스터가 죽었을 때
//                 {
//                     printf("승리했습니다."); // 승리 메세지 출력
//                     break;
//                 }
//                 else if (boki->chp <= 0)
//                 {
//                     printf("패배했습니다."); //패배 메세지 출력
//                     break;
//                 }
//                 else if (monster->realboss.hp > 0) //몬스터가 살아 있으면 콘티뉴
//                 {
//                     continue;
//                 }
//             if(choice ==2){
//                 //아이템 사용
//                 continue;
//             }else if(choice == 3){
//             //도망가기
//                     srand(time(NULL));
//                     int   random = rand()%101; //1부터 100까지 출력
//                 if (random <= 30) //1부터 30까지 랜덤수
//                     {
//                     printf("%d, 도망성공", random);
//                     break;
//                     }
//                 else
//                 {
//                     printf("도망실패");
//                     continue;
//                 }
//             }
//         }
//     }
// }

// int battle_hero(Monster *monster, Boki *boki, int floor, int monstername){
//     while(1){
//                 printf("학생용사를 만났습니다.\n");

//                 printf("1.전투\n2.아이템 사용\n3.도망 ");
//                 int choice;
//                 scanf("%d",&choice);
//             if (choice == 1)
//             { //  전투
//                 monster->hero.hp -= boki->damage; // 유저의 공격
//                 printf("몬스터 남은 hp %d\n", monster->hero.hp);
//                 printf("boki %d체력", boki->chp);
//                 boki->chp -= monster->hero.damage; //몬스터의 공격
//                 printf("boki 남은 hp %d\n", boki->chp);
//                 if (monster->hero.hp <= 0) //몬스터가 죽었을 때
//                 {
//                     printf("승리했습니다."); // 승리 메세지 출력
//                     break;
//                 }
//                 else if (boki->chp <= 0)
//                 {
//                     printf("패배했습니다."); //패배 메세지 출력
//                     break;
//                 }
//                 else if (monster->hero.hp > 0) //몬스터가 살아 있으면 콘티뉴
//                 {
//                     continue;
//                 }
//             if(choice ==2){
//                 //아이템 사용
//                 continue;
//             }else if(choice == 3){
//             //도망가기
//                     srand(time(NULL));
//                     int   random = rand()%101; //1부터 100까지 출력
//                 if (random <= 30) //1부터 30까지 랜덤수
//                     {
//                     printf("%d, 도망성공", random);
//                     break;
//                     }
//                 else
//                 {
//                     printf("도망실패");
//                     continue;
//                 }
//             }
//         }
//     }
// }