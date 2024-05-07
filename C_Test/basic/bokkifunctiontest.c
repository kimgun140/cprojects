#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#define MAPSIZE 20
#define MCOUNT 28
int main(void){


srand((unsigned int)time(NULL)); //seed값으로 현재시간 부여 
// 전투 승리후 체력을 회복한다. 전투승리후 전체체력통이 증가한다.
// 전체 체력통(max_hp)가 있어야 체력회복하고 체력통을 증가 시킬 수 있음

float user_hp = 3000;
float user_maxhp = 3000 ; 
int choice = 0 ;
int turn = 1 ; 
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



while(1){
printf("1:전투 2:아이템 3:도망\n행동을 입력하세여\n");
scanf("%d", &choice);
if ( choice == 1){
printf("%d번째 턴입니다.\n",turn);
//전투
//유저의 공격
monster_hp = monster_hp - user_attack;
printf("몬스터 hp%.0f\n유저의 공격%.0f\n",monster_hp,user_attack);
user_attack = (user_hp*0.5)*(rand() % 5 + 1); // 다음공격 위해서 유저 공격력 재설정

if(monster_hp >0){
user_hp = user_hp - monster_attack;
printf("유저 체력%.0f\n 몬스터의 공격 %.0f\n", user_hp,monster_attack);
monster_attack = user_maxhp*(rand() % 25 + 6) * 0.1; //다음 공격을 위해서 몬스터 공격력 재설정
if(user_hp >0){ //공격받고 살아있으면 다시 행동시작
turn +=1;
monster_hp=user_maxhp*(rand() % 30 + 10) * 0.1;
continue;

}else
printf("Lose 망했어요 ㅠㅠ\n"); //패배
user_hp = 3000;
monster_hp=user_maxhp*(rand() % 30 + 10) * 0.1;
break;  

}else{
//승리 메세지 출력 현재 hp출력 후 행동 종료
printf("Victory 현재hp: %.0f\n", user_hp);
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

//몬스터의 공격
user_hp = user_hp - monster_attack;
printf("유저 체력%.0f\n몬스터의 공격 %.0f\n", user_hp,monster_attack);
monster_attack = user_maxhp*(rand() % 25 + 6) * 0.1; //다음 공격을 위해서 몬스터 공격력 재설정
if(user_hp >0){
turn +=1;
continue;
}else
printf("Lose 망했어요 ㅠㅠ"); //패배
user_hp = 3000;
break;
}
else if( choice == 2){
//아이템
//포션
printf("아이템을 선택해주세요\n 1.포션 2.복이칼리버 3.방패 4.부활 ");
scanf("%d", &item_choice);
if (item_choice ==1 ){
//포션
printf("포션을 사용합니다. 남은 포션개수:%.0f\n", potion);
user_hp = user_hp *(rand() % 81 + 40) * 0.1;
potion -= 1;
turn +=1;
printf("현재HP:%.0f", user_hp);
continue;
}else if(item_choice ==2){
// bokki_hp = 0;
if (bokkicalibur > 0){
printf("복이가 아니라서 아이템이 없어집니다."); 
bokkicalibur -= 1;
turn++;
continue;
}
else{
printf("아이템이 없습니다.\n");
turn++;
continue;
}
}else if(item_choice ==3){ // 방패
printf("방패 아이템을 사용합니다 남은 개수%d\n한 번 적의 공격을 절반으로 만듭니다.\n",item_guard);
monster_attack = monster_attack*0.5;
item_guard -= 1;
printf("방패개수 %d",item_guard);
if (item_guard >10){
item_guard =10;
turn++;
}
continue;


}
//아이템 사용 끝나고 몬스터의 공격 
user_hp = user_hp - monster_attack;
printf("유저 체력%.0f\n몬스터의 공격 %.0f\n", user_hp,monster_attack);
monster_attack = user_maxhp*(rand() % 25 + 6) * 0.1; //다음 공격을 위해서 몬스터 공격력 재설정
if(user_hp >0){
turn +=1;
continue;
}else
printf("Lose 망했어요 ㅠㅠ"); //패배
user_hp = 3000;

break;


}else if(choice == 3 ){
//도망
if (run > 0.3){ //도망 실패
printf("Run 실패 안광민띠!!\n٩(´Д` ;)۶:.*\n");
run = (rand() % 10 + 1) * 0.1; //도망 확률 재설정
// 도망 실패 후 맞기 
user_hp = user_hp - monster_attack;
printf("유저 체력%.0f\n몬스터의 공격 %.0f\n", user_hp,monster_attack);
monster_attack = user_maxhp*(rand() % 25 + 6) * 0.1; //다음 공격을 위해서 몬스터 공격력 재설정
if(user_hp >0){
turn +=1;
continue;
}else
printf("********8Lose 망했어요 ㅠㅠ*****88"); //패배
user_hp = 3000;

break;
}else //도망성공
printf("Run 성공 기모띠\nദ്ദി◍•ᴗ•◍)\n");
run = (rand() % 10 + 1) * 0.1;//도망 확률 재설정
break; // 다시 돌아가기
}
 
}
return 0;
}
