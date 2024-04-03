#include<stdio.h>
#include<stdlib.h> /*랜덤함수 사용 위해 불러옴*/
#include<time.h> /*랜덤함수 사용 위해 불러옴*/
#include"item.h"

int town_movement(int tm);/*이동아이템 획득 함수 전방선언*/
int drop_2teer20(int );/*2티어 20프로*/
int drop_3teer20(int );/*3티어 20프로*/
int drop_3teer30(int);/*3티어 30프로*/
int drop_4teer5(int);/*4티어 5프로*/
int drop_4teer10(int);/*4티어 10프로*/
int drop_4teer20(int);/*4티어 20프로*/

int drop_thirty(int thir);/*30프로 드랍 함수*/
int drop_five(int five);/*5프로 드랍함수*/
int gold_drop(int floor);/*골드 드랍 함수*/
int gold_drop_boss(int boss);/*보스 골드 드랍 함수*/


int equip_sword( Boki*); 
// int equip_longsword(sword_table,Boki*);
// int equip_japensword(sword_table,Boki*);
// int equip_nigthsword_saj(sword_table,Boki*);
int equip_first_depend(  Boki*);
int equip_second_depend(  Boki*);
int equip_third_depend(  Boki*);
int equip_fourth_depend(  Boki*);



// int equip_first_depend_mask( first_depend_table, Boki*);


int main(void)
{
    Boki* boki=(Boki*)malloc(sizeof(Boki));
    boki->def = 0;
    // sword_table a;
    // Boki a;
    // equip_sword(boki);
    
    // printf("%d\n",boki->damage);

    
    boki->def=equip_first_depend(boki);
    // +equip_first_depend(boki)+equip_second_depend(boki)+equip_third_depend(boki)+equip_fourth_depend(boki);
printf("방어력%daaaa\n",boki->def);
}

// 문제 3가지 
// 1. depend_choice 가 안되네 해결 바보같은 실수 였음 비융신
// 2. 방어력 각각 입력만 받음 방어구 5개 더해서 한번에 넣어야하는데

// sword테이블이 아니라 보키.... sword에서 [n][0]이 있니? 있으면 창작가능 없으면 안된다.
//
//무기 장착하기
int equip_sword(  Boki* boki){
    int depend_choice;



    // 1티어 방어구 장착하기
    scanf("%d",&depend_choice);
    // boki->bokiEquipment.weapon.basicsword[depend_choice][1] = 5;// 마스크 첫번째 방어구 방어력 입력 개수, 방어력, 강화
    boki->bokiEquipment.weapon.basicsword[depend_choice][0] = 1;// 테스트 때문에 방어구 한개 넣어서 확인해보기
    switch(depend_choice)
        {   //이거이거 뭐지 이거이거 뭐니
        //1 티어 무기를 한번에 착용하기 
        // 그렇게 하려면 어떻게 해야하지 선택을 하게해서 1티어리스트 뽑아주고 선택하게 하기 
            case 0 ://1티어 무기 장착하기
            printf("방어구를 입력하세여\n");
            printf("de%d\n", depend_choice);
            printf("1티어무기\n");
            if(boki->bokiEquipment.weapon.basicsword[0][0] != 0){ 
            printf("무기가있네요");// 무기가 있는지 확인
            boki->damage = boki->bokiEquipment.weapon.basicsword[0][1]; //복이 공격력에 무기 공격력 입히기
            printf("무기를 장착했습니다.");
            break;
            }else{
            printf("무기가 없습니다.");
            break;
            }
            case 1 ://1티어 무기 장착하기
            if(boki->bokiEquipment.weapon.longsword[depend_choice][0] != 0){ // 무기가 있는지 확인
            boki->damage = boki->bokiEquipment.weapon.longsword[depend_choice][1]; //복이 공격력에 무기 공격력 입히기
            printf("무기를 장착했습니다.");
            break;
            }else{
            printf("무기가 없습니다.");
            break;
            }
            case 2 ://1티어 무기 장착하기
            if(boki->bokiEquipment.weapon.japensword[depend_choice][0] != 0){ // 무기가 있는지 확인
            boki->damage = boki->bokiEquipment.weapon.japensword[depend_choice][1]; //복이 공격력에 무기 공격력 입히기
            printf("무기를 장착했습니다.");
            break;
            }else{
            printf("무기가 없습니다.");
            break;
            }
            case 3 ://1티어 무기 장착하기
            if(boki->bokiEquipment.weapon.nigthsword_saj[depend_choice][0] != 0){ // 무기가 있는지 확인
            boki->damage = boki->bokiEquipment.weapon.nigthsword_saj[depend_choice][1]; //복이 공격력에 무기 공격력 입히기
            printf("무기를 장착했습니다.");
            break;
            }else{
            printf("무기가 없습니다.");
            break;
            }
            
            
        
        
    }
    return boki->damage;
}
//1티어 방어구 장착하기
int equip_first_depend( Boki* boki){
    int depend_choice;
    //초기화
    // boki->bokiEquipment.nomal.basicmask[0][1] = 5;// 마스크 첫번째 방어구 방어력 입력 개수, 방어력, 강화
    boki->bokiEquipment.nomal.basicmask[0][0] = 1;
    boki->bokiEquipment.nomal.basicmask[0][1] = 0;// 테스트 때문에 방어구 한개 넣어서 확인해보기
    printf("ㅁㅁ%d",boki->bokiEquipment.nomal.basicmask[0][1]);
    // 1티어 방어구 장착하기
    printf("마스크\n");
    scanf("%d",&depend_choice);
    switch(depend_choice)
        {   //이거이거 뭐지 이거이거 뭐니
        //1 티어 방어구를 한번에 착용하기 
        // 그렇게 하려면 어떻게 해야하지 선택을 하게해서 1티어리스트 뽑아주고 선택하게 하기 
            case 0 ://1티어 마스크 장착하기
            
            if(boki->bokiEquipment.nomal.basicmask[depend_choice][0] != 0){ // 방어구가 있는지 확인
            boki->def += boki->bokiEquipment.nomal.basicmask[depend_choice][1]; //복이 방어력에 방어구 방어력 입히기
            printf("방어구를 장착했습니다.");
            printf("%d",boki->bokiEquipment.nomal.basicmask[depend_choice][1]);
            break;
            }else{
            printf("방어구가 없습니다.");
            break;
            }
            case 1 ://1티어 갑바 장착하기
            if(boki->bokiEquipment.nomal.basicarmor[depend_choice][0] != 0){ // 방어구가 있는지 확인
            boki->def += boki->bokiEquipment.nomal.basicarmor[depend_choice][1]; //복이 방어력에 방어구 방어력 입히기
            printf("방어구를 장착했습니다.");
            break;
            }else{
            printf("방어구가 없습니다.");
            break;
            }
            case 2 ://1티어 망토 장착하기
            if(boki->bokiEquipment.nomal.basiccape[depend_choice][0] != 0){ // 방어구가 있는지 확인
            boki->def += boki->bokiEquipment.nomal.basiccape[depend_choice][1]; //복이 방어력에 방어구 방어력 입히기
            printf("방어구를 장착했습니다.");
            break;
            }else{
            printf("방어구가 없습니다.");
            break;
            }
            case 3 ://1티어 장갑 장착하기
            if(boki->bokiEquipment.nomal.basicgloves[depend_choice][0] != 0){ // 방어구가 있는지 확인
            boki->def += boki->bokiEquipment.nomal.basicgloves[depend_choice][1]; //복이 방어력에 방어구 방어력 입히기
            printf("방어구를 장착했습니다.");
            break;
            }else{
            printf("방어구가 없습니다.");
            break;
            }
            case 4 ://1티어 부츠 장착하기
            if(boki->bokiEquipment.nomal.basicboots[depend_choice][0] != 0){ // 방어구가 있는지 확인
            boki->def += boki->bokiEquipment.nomal.basicboots[depend_choice][1]; //복이 방어력에 방어구 방어력 입히기
            printf("방어구를 장착했습니다.");
            break;
            }else{
            printf("방어구가 없습니다.");
            break;
            }
            
            
    }
return boki->def;
}

//2티어 방어구 장착하기
int equip_second_depend(  Boki* boki){
    int depend_choice;
    //초기화
    // boki->bokiEquipment.rare.k80mask[0][1] = 5;// 마스크 첫번째 방어구 방어력 입력 개수, 방어력, 강화
    boki->bokiEquipment.rare.k80mask[0][0] = 1;// 테스트 때문에 방어구 한개 넣어서 확인해보기

    // 2티어 방어구 장착하기
    scanf("%d",&depend_choice);
    switch(depend_choice)
        {   //이거이거 뭐지 이거이거 뭐니
        //1 티어 방어구를 한번에 착용하기 
        // 그렇게 하려면 어떻게 해야하지 선택을 하게해서 1티어리스트 뽑아주고 선택하게 하기 
            case 0 ://1티어 마스크 장착하기
            printf("방어구를 입력하세여\n");
            if(boki->bokiEquipment.rare.k80mask[depend_choice][0] != 0){ // 방어구가 있는지 확인
            boki->def += boki->bokiEquipment.rare.k80mask[depend_choice][1]; //복이 방어력에 방어구 방어력 입히기
            printf("방어구를 장착했습니다.");
            break;
            }else{
            printf("방어구가 없습니다.");
            break;
            }
            case 1 ://1티어 갑바 장착하기
            if(boki->bokiEquipment.rare.halfarmor[depend_choice][0] != 0){ // 방어구가 있는지 확인
            boki->def += boki->bokiEquipment.rare.halfarmor[depend_choice][1]; //복이 방어력에 방어구 방어력 입히기
            printf("방어구를 장착했습니다.");
            break;
            }else{
            printf("방어구가 없습니다.");
            break;
            }
                        case 2 ://1티어 망토 장착하기
            if(boki->bokiEquipment.rare.cottencape[depend_choice][0] != 0){ // 방어구가 있는지 확인
            boki->def += boki->bokiEquipment.rare.cottencape[depend_choice][1]; //복이 방어력에 방어구 방어력 입히기
            printf("방어구를 장착했습니다.");
            break;
            }else{
            printf("방어구가 없습니다.");
            break;
            }
                        case 3 ://1티어 장갑 장착하기
            if(boki->bokiEquipment.rare.rubbergloves[depend_choice][0] != 0){ // 방어구가 있는지 확인
            boki->def += boki->bokiEquipment.rare.rubbergloves[depend_choice][1]; //복이 방어력에 방어구 방어력 입히기
            printf("방어구를 장착했습니다.");
            break;
            }else{
            printf("방어구가 없습니다.");
            break;
            }
                        case 4 ://1티어 부츠 장착하기
            if(boki->bokiEquipment.rare.slipper[depend_choice][0] != 0){ // 방어구가 있는지 확인
            boki->def += boki->bokiEquipment.rare.slipper[depend_choice][1]; //복이 방어력에 방어구 방어력 입히기
            printf("방어구를 장착했습니다.");
            break;
            }else{
            printf("방어구가 없습니다.");
            break;
            }
            
            
        
        
    }
    return boki->def;
}

//3티어 방어구 장착하기
int equip_third_depend(  Boki* boki){
    int depend_choice;
    //초기화
    // boki->bokiEquipment.epic.k94mask[0][1] = 5;// 마스크 첫번째 방어구 방어력 입력 개수, 방어력, 강화
    boki->bokiEquipment.epic.k94mask[0][0] = 1;// 테스트 때문에 방어구 한개 넣어서 확인해보기

    // 3티어 방어구 장착하기
    scanf("%d",&depend_choice);
    switch(depend_choice)
        {   //이거이거 뭐지 이거이거 뭐니
        //1 티어 방어구를 한번에 착용하기 
        // 그렇게 하려면 어떻게 해야하지 선택을 하게해서 1티어리스트 뽑아주고 선택하게 하기 
            case 0 ://1티어 마스크 장착하기
            printf("방어구를 입력하세여\n");
            if(boki->bokiEquipment.epic.k94mask[depend_choice][0] != 0){ // 방어구가 있는지 확인
            boki->def += boki->bokiEquipment.epic.k94mask[depend_choice][1]; //복이 방어력에 방어구 방어력 입히기
            printf("방어구를 장착했습니다.");
            break;
            }else{
            printf("방어구가 없습니다.");
            break;
            }
            case 1 ://1티어 갑바 장착하기
            if(boki->bokiEquipment.epic.hoodarmor[depend_choice][0] != 0){ // 방어구가 있는지 확인
            boki->def += boki->bokiEquipment.epic.hoodarmor[depend_choice][1]; //복이 방어력에 방어구 방어력 입히기
            printf("방어구를 장착했습니다.");
            break;
            }else{
            printf("방어구가 없습니다.");
            break;
            }
            case 2 ://1티어 망토 장착하기
            if(boki->bokiEquipment.epic.silkcape[depend_choice][0] != 0){ // 방어구가 있는지 확인
            boki->def += boki->bokiEquipment.epic.silkcape[depend_choice][1]; //복이 방어력에 방어구 방어력 입히기
            printf("방어구를 장착했습니다.");
            break;
            }else{
            printf("방어구가 없습니다.");
            break;
            }
            case 3 ://1티어 장갑 장착하기
            if(boki->bokiEquipment.epic.cottengloves[depend_choice][0] != 0){ // 방어구가 있는지 확인
            boki->def += boki->bokiEquipment.epic.cottengloves[depend_choice][1]; //복이 방어력에 방어구 방어력 입히기
            printf("방어구를 장착했습니다.");
            break;
            }else{
            printf("방어구가 없습니다.");
            break;
            }
            case 4 ://1티어 부츠 장착하기
            if(boki->bokiEquipment.epic.sneakers[depend_choice][0] != 0){ // 방어구가 있는지 확인
            boki->def += boki->bokiEquipment.epic.sneakers[depend_choice][1]; //복이 방어력에 방어구 방어력 입히기
            printf("방어구를 장착했습니다.");
            break;
            }else{
            printf("방어구가 없습니다.");
            break;
            }
            
            
        
        
    }
    return boki->def;
}

//4티어 방어구 장착하기
int equip_fourth_depend(  Boki* boki){
    int depend_choice;
    //초기화
    // boki->bokiEquipment.legend.tigermask[0][1] = 5;// 마스크 첫번째 방어구 방어력 입력 개수, 방어력, 강화
    boki->bokiEquipment.legend.tigermask[0][0] = 1;// 테스트 때문에 방어구 한개 넣어서 확인해보기

    // 4티어 방어구 장착하기
    scanf("%d",&depend_choice);
    switch(depend_choice)
        {   //이거이거 뭐지 이거이거 뭐니
        //1 티어 방어구를 한번에 착용하기 
        // 그렇게 하려면 어떻게 해야하지 선택을 하게해서 1티어리스트 뽑아주고 선택하게 하기 
            case 0 ://1티어 마스크 장착하기
            printf("방어구를 입력하세여\n");
            if(boki->bokiEquipment.legend.tigermask[depend_choice][0] != 0){ // 방어구가 있는지 확인
            boki->def += boki->bokiEquipment.legend.tigermask[depend_choice][1]; //복이 방어력에 방어구 방어력 입히기
            printf("방어구를 장착했습니다.");
            break;
            }else{
            printf("방어구가 없습니다.");
            break;
            }
            case 1 ://1티어 갑바 장착하기
            if(boki->bokiEquipment.legend.dragonarmor[depend_choice][0] != 0){ // 방어구가 있는지 확인
            boki->def += boki->bokiEquipment.legend.dragonarmor[depend_choice][1]; //복이 방어력에 방어구 방어력 입히기
            printf("방어구를 장착했습니다.");
            break;
            }else{
            printf("방어구가 없습니다.");
            break;
            }
            case 2 ://1티어 망토 장착하기
            if(boki->bokiEquipment.legend.bulletcape[depend_choice][0] != 0){ // 방어구가 있는지 확인
            boki->def += boki->bokiEquipment.legend.bulletcape[depend_choice][1]; //복이 방어력에 방어구 방어력 입히기
            printf("방어구를 장착했습니다.");
            break;
            }else{
            printf("방어구가 없습니다.");
            break;
            }
            case 3 ://1티어 장갑 장착하기
            if(boki->bokiEquipment.legend.leardergloves[depend_choice][0] != 0){ // 방어구가 있는지 확인
            boki->def += boki->bokiEquipment.legend.leardergloves[depend_choice][1]; //복이 방어력에 방어구 방어력 입히기
            printf("방어구를 장착했습니다.");
            break;
            }else{
            printf("방어구가 없습니다.");
            break;
            }
            case 4 ://1티어 부츠 장착하기
            if(boki->bokiEquipment.legend.airjodan[depend_choice][0] != 0){ // 방어구가 있는지 확인
            boki->def += boki->bokiEquipment.legend.airjodan[depend_choice][1]; //복이 방어력에 방어구 방어력 입히기
            printf("방어구를 장착했습니다.");
            break;
            }else{
            printf("방어구가 없습니다.");
            break;
            }
            
            
        
        
    }
    return boki->def;
}
