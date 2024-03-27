#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<time.h>


int battle(int choice, int turn, float monster_hp, float user_attack,float user_hp, float monster_attack, float user_maxhp);
int main(void){
srand((unsigned int)time(NULL)); //seed값으로 현재시간 부여 
float user_hp = 3000;
    float user_maxhp = 3000 ; 
    int choice = 0 ;
    int turn = 1 ;
    int* turnptr=&turn; 
    float monster_hp = user_hp*(rand() % 30 + 10) * 0.1; //현재 유저체력의1~3배
    float monster_attack = user_maxhp*(rand() % 25 + 6) * 0.1; //현재 유저 전체 체력의 0.5~3.0배
    float user_attack = (user_hp*0.5)*(rand() % 5 + 1); // 현재 체력의 
    float bokki_hp = user_hp*(rand() % 30 + 51) * 0.1; // 전체체력의 5~8배
    float potion = user_hp*(rand() % 8 + 4) * 0.1; //전체체력의 0.3 ~0.8배 회복
    float victory_hp = user_hp*(rand() % 10 + 1 +3) * 0.1;//전투후 0.3~1.0배 회복  
    // float max_hp = user_hp*(rand() % 26 + 13) * 0.1; // 전투 후 체력 재산정 max_hp
    float run = (rand() % 10 + 1) * 0.1;
    int item_choice = 0;
    int item_guard = 0;
    int bokkicalibur = 0;
    int usermovement[1][2]={{10,10}};
    int monstercreating[20][20];
    int item_possibility = rand() % 100 +1;
    int revival=0;
    int item_potion=3;

    battle(choice, turn,monster_hp,user_attack, user_hp, monster_attack ,user_maxhp);


    return 0;
}
int battle(int choice, int turn, float monster_hp, float user_attack,float user_hp, float monster_attack, float user_maxhp){
while(1){
printf("\n1:전투 2:아이템 3:도망\n행동을 입력하세여\n");
    scanf("%d", &choice);
    if ( choice == 1){
        printf("%d번째 턴입니다.\n",turn);
    //전투
    //유저의 공격
    monster_hp = monster_hp - user_attack; 
    printf("\n&&&&&&&&&전투 시작&&&&&&&&&&&\n");
    printf("-----------------------------------유저의 턴------------------------------------\n");

    printf("현재 몬스터 hp : %.0f\n유저의 공격 : %.0f\n",monster_hp,user_attack);
    user_attack = (user_hp*0.5)*(rand() % 5 + 1); // 다음공격 위해서 유저 공격력 재설정

        
        if(monster_hp >0){
        user_hp = user_hp - monster_attack;
        printf("----------------------------------몬스터의 턴---------------------------------\n");

        printf("몬스터의 공격 : %.0f\n현재 유저 체력 : %.0f\n",monster_attack,user_hp);
        monster_attack = user_maxhp*(rand() % 25 + 6) * 0.1; //다음 공격을 위해서 몬스터 공격력 재설정
            if(user_hp >0){ //공격받고 살아있으면 다시 행동시작
            turn +=1;
            monster_hp=user_maxhp*(rand() % 30 + 10) * 0.1;

            continue;
            }else
            printf("Lose 망했어요 ㅠㅠ\n"); //패배
            user_hp = user_maxhp;
            monster_hp=user_maxhp*(rand() % 30 + 10) * 0.1;
            break;
        }else{
            //승리 메세지 출력 현재 hp출력 후 행동 종료
            printf("***********************************Victory**********************************\n승리후 남은hp: %.0f\n", user_hp);
            //승리후 hp통 증가
            user_maxhp = user_maxhp *(rand() % 26 + 13) * 0.1 ;
            //승리후 hp 회복
            user_hp = user_hp + user_maxhp * ((rand() % 11 + 3) * 0.1); 
            if(user_hp >user_maxhp)
                user_hp =user_maxhp;
            printf("전투후\n현재 HP%.0f\n",user_hp);
            monster_hp = user_hp*(rand() % 30 + 10) * 0.1;
            break;
        }
    }


    return 0;
}
}