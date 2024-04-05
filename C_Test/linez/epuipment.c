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
void equipement_window(Boki*);
int equip(Boki*);


// int equip_first_depend_mask( first_depend_table, Boki*);


int main(void)
{
    Boki* boki=(Boki*)malloc(sizeof(Boki));
    // boki->def = 0;
    // sword_table a;
    // Boki a;
    // equip_sword(boki);
    
    // printf("%d\n",boki->damage);

    
//     boki->def=equip_first_depend(boki);
//     // +equip_first_depend(boki)+equip_second_depend(boki)+equip_third_depend(boki)+equip_fourth_depend(boki);
// printf("방어력%daaaa\n",boki->def);
// equip_fourth_depend(boki);
    int sum;
    equip(boki);
    printf("방어력%d\n",boki->def);

    
}


int equip_sword(  Boki* boki){
    int depend_choice;
    // 1티어 방어구 장착하기
    scanf("%d",&depend_choice);
    // boki->bokiEquipment.weapon.basicsword[depend_choice][1] = 5;// 마스크 첫번째 방어구 방어력 입력 개수, 방어력, 강화
    boki->bokiEquipment.weapon.basicsword[0][0] = 1;// 테스트 때문에  한개 넣어서 확인해보기
    boki->bokiEquipment.weapon.basicsword[0][1] = 5;// 테스트 때문에  한개 넣어서 확인해보기
    boki->bokiEquipment.weapon.basicsword[0][2] = 1;// 테스트 때문에  한개 넣어서 확인해보기
    // boki->bokiEquipment.weapon.basicsword[0][0] = 1;// 테스트 때문에 방어구 한개 넣어서 확인해보기
    switch(depend_choice)
        {   
            case 0 ://1티어 무기 장착하기
            int equip_choice;
            for(int i=0; i<5; i++){ //아이템 정보출력
            if(boki->bokiEquipment.weapon.basicsword[i][0] != 0){ //i번째 장비의 정보 출력
                printf("\n 기본검 %d 번 장비의 공격력%d : \n 강화수치 %d\n", i,boki->bokiEquipment.weapon.basicsword[i][1],boki->bokiEquipment.weapon.basicsword[i][2] );
                }
            }
            printf("번호를 입력하세여\n");
            scanf("%d",&equip_choice); //5개중에 고르기 0~4번
            if(boki->bokiEquipment.weapon.basicsword[equip_choice][0] != 0){ 
            printf("무기가있네요\n");// 무기가 있는지 확인
            boki->damage = boki->bokiEquipment.weapon.basicsword[equip_choice][1]; //복이 공격력에 무기 공격력 입히기
            printf("무기를 장착했습니다.");
            break;
            }else{
            printf("무기가 없습니다.");
            break;
            }
            case 1 ://2티어 무기 장착하기
            // int equip_choice;
            for(int i=0; i<5; i++){ //아이템 정보출력
            if(boki->bokiEquipment.weapon.longsword[i][0] != 0){ //i번째 장비의 정보 출력
                printf("\n 장검 %d 번 장비의 공격력%d : \n 강화수치 %d\n", i,boki->bokiEquipment.weapon.longsword[i][1],boki->bokiEquipment.weapon.longsword[i][2] );
                }
            }
            printf("번호를 입력하세여\n");
            scanf("%d",&equip_choice); //5개중에 고르기 0~4번
            if(boki->bokiEquipment.weapon.longsword[equip_choice][0] != 0){ // 무기가 있는지 확인
            boki->damage = boki->bokiEquipment.weapon.longsword[equip_choice][1]; //복이 공격력에 무기 공격력 입히기
            printf("무기를 장착했습니다.");
            break;
            }else{
            printf("무기가 없습니다.");
            break;
            }
            case 2 ://1티어 무기 장착하기
            // int equip_choice;
            for(int i=0; i<5; i++){ //아이템 정보출력
            if(boki->bokiEquipment.weapon.japensword[i][0] != 0){ //i번째 장비의 정보 출력
                printf("\n 일본도 %d 번 장비의 공격력%d : \n 강화수치 %d\n", i,boki->bokiEquipment.weapon.japensword[i][1],boki->bokiEquipment.weapon.japensword[i][2] );
                }
            }
            printf("번호를 입력하세여\n");
            scanf("%d",&equip_choice); //5개중에 고르기 0~4번
            if(boki->bokiEquipment.weapon.japensword[equip_choice][0] != 0){ // 무기가 있는지 확인
            boki->damage = boki->bokiEquipment.weapon.japensword[equip_choice][1]; //복이 공격력에 무기 공격력 입히기
            printf("무기를 장착했습니다.");
            break;
            }else{
            printf("무기가 없습니다.");
            break;
            }
            case 3 ://1티어 무기 장착하기
            // int equip_choice;
            for(int i=0; i<5; i++){ //아이템 정보출력
            if(boki->bokiEquipment.weapon.nigthsword_saj[i][0] != 0){ //i번째 장비의 정보 출력
                printf("\n 싸울아비장검 %d 번 장비의 공격력%d : \n 강화수치 %d\n", i,boki->bokiEquipment.weapon.nigthsword_saj[i][1],boki->bokiEquipment.weapon.nigthsword_saj[i][2] );
                }
            }
            printf("번호를 입력하세여\n");
            scanf("%d",&equip_choice); //5개중에 고르기 0~4번
            if(boki->bokiEquipment.weapon.nigthsword_saj[equip_choice][0] != 0){ // 무기가 있는지 확인
            boki->damage = boki->bokiEquipment.weapon.nigthsword_saj[equip_choice][1]; //복이 공격력에 무기 공격력 입히기
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
    boki->bokiEquipment.nomal.basicmask[0][1] = 5;// 마스크 첫번째 방어구 방어력 입력 개수, 방어력, 강화
    boki->bokiEquipment.nomal.basicmask[0][0] = 1;
    // boki->bokiEquipment.nomal.basicmask[0][1] = 0;// 테스트 때문에 방어구 한개 넣어서 확인해보기
    printf("%d",boki->bokiEquipment.nomal.basicmask[0][1]);
    // 1티어 방어구 장착하기
    printf("마스크\n");
    scanf("%d",&depend_choice);
    switch(depend_choice)
        {    
            case 0 ://1티어 마스크 장착하기
            int equip_choice;
            for(int i=0; i<5; i++){ //아이템 정보출력
            if(boki->bokiEquipment.nomal.basicmask[i][0] != 0){ //i번째 장비의 정보 출력
                printf("\n기본마스크 %d 번 장비의 방어력%d : \n 강화수치 %d\n", i,boki->bokiEquipment.nomal.basicmask[i][1],boki->bokiEquipment.nomal.basicmask[i][2] );
                }
            }
            printf("방어구번호를 입력하세여\n");
            scanf("%d",&equip_choice); //5개중에 고르기 0~4번
            if(boki->bokiEquipment.nomal.basicmask[equip_choice][0] != 0){ // 방어구가 있는지 확인
            boki->def += boki->bokiEquipment.nomal.basicmask[equip_choice][1]; //복이 방어력에 방어구 방어력 입히기
            printf("방어구를 장착했습니다.");
            printf("%d",boki->bokiEquipment.nomal.basicmask[equip_choice][1]);
            break;
            }else{
            printf("방어구가 없습니다.");
            break;
            }
            case 1 ://1티어 갑바 장착하기
            
            for(int i=0; i<5; i++){ //아이템 정보출력
            if(boki->bokiEquipment.nomal.basicarmor[i][0] != 0){ //i번째 장비의 정보 출력
                printf("\n기본갑바%d 번 장비의 방어력%d : \n 강화수치 %d\n", i,boki->bokiEquipment.nomal.basicarmor[i][1],boki->bokiEquipment.nomal.basicarmor[i][2] );
                }
            }
            printf("방어구번호를 입력하세여\n");
            scanf("%d",&equip_choice); //5개중에 고르기 0~4번
            if(boki->bokiEquipment.nomal.basicarmor[equip_choice][0] != 0){ // 방어구가 있는지 확인
            boki->def += boki->bokiEquipment.nomal.basicarmor[equip_choice][1]; //복이 방어력에 방어구 방어력 입히기
            printf("방어구를 장착했습니다.");
            break;
            }else{
            printf("방어구가 없습니다.");
            break;
            }
            case 2 ://1티어 망토 장착하기
            
            for(int i=0; i<5; i++){ //아이템 정보출력
            if(boki->bokiEquipment.nomal.basiccape[i][0] != 0){ //i번째 장비의 정보 출력
                printf("\n기본망토%d 번 장비의 방어력%d : \n 강화수치 %d\n", i,boki->bokiEquipment.nomal.basiccape[i][1],boki->bokiEquipment.nomal.basiccape[i][2] );
                }
            }
            printf("방어구번호를 입력하세여\n");
            scanf("%d",&equip_choice); //5개중에 고르기 0~4번
            if(boki->bokiEquipment.nomal.basiccape[equip_choice][0] != 0){ // 방어구가 있는지 확인
            boki->def += boki->bokiEquipment.nomal.basiccape[equip_choice][1]; //복이 방어력에 방어구 방어력 입히기
            printf("방어구를 장착했습니다.");
            break;
            }else{
            printf("방어구가 없습니다.");
            break;
            }
            case 3 ://1티어 장갑 장착하기
            
            for(int i=0; i<5; i++){ //아이템 정보출력
            if(boki->bokiEquipment.nomal.basicgloves[i][0] != 0){ //i번째 장비의 정보 출력
                printf("\n기본장갑%d 번 장비의 방어력%d : \n 강화수치 %d\n", i,boki->bokiEquipment.nomal.basicgloves[i][1],boki->bokiEquipment.nomal.basicgloves[i][2] );
                }
            }
            printf("방어구번호를 입력하세여\n");
            scanf("%d",&equip_choice); //5개중에 고르기 0~4번
            if(boki->bokiEquipment.nomal.basicgloves[equip_choice][0] != 0){ // 방어구가 있는지 확인
            boki->def += boki->bokiEquipment.nomal.basicgloves[equip_choice][1]; //복이 방어력에 방어구 방어력 입히기
            printf("방어구를 장착했습니다.");
            break;
            }else{
            printf("방어구가 없습니다.");
            break;
            }
            case 4 ://1티어 부츠 장착하기
            
            for(int i=0; i<5; i++){ //아이템 정보출력
            if(boki->bokiEquipment.nomal.basicboots[i][0] != 0){ //i번째 장비의 정보 출력
                printf("\n기본부츠%d 번 장비의 방어력%d : \n 강화수치 %d\n", i,boki->bokiEquipment.nomal.basicboots[i][1],boki->bokiEquipment.nomal.basicboots[i][2] );
                }
            }
            printf("방어구번호를 입력하세여\n");
            scanf("%d",&equip_choice); //5개중에 고르기 0~4번
            if(boki->bokiEquipment.nomal.basicboots[equip_choice][0] != 0){ // 방어구가 있는지 확인
            boki->def += boki->bokiEquipment.nomal.basicboots[equip_choice][1]; //복이 방어력에 방어구 방어력 입히기
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
    boki->bokiEquipment.rare.k80mask[0][1] = 5;// 마스크 첫번째 방어구 방어력 입력 개수, 방어력, 강화
    boki->bokiEquipment.rare.k80mask[0][0] = 1;// 테스트 때문에 방어구 한개 넣어서 확인해보기

    // 2티어 방어구 장착하기
    scanf("%d",&depend_choice);
    switch(depend_choice)
        {   

            case 0 :// 장착하기
            int equip_choice;
            for(int i=0; i<5; i++){ //아이템 정보출력
            if(boki->bokiEquipment.rare.k80mask[i][0] != 0){ //i번째 장비의 정보 출력
                printf("\nk80마스크%d 번 장비의 방어력%d : \n 강화수치 %d\n", i,boki->bokiEquipment.rare.k80mask[i][1],boki->bokiEquipment.rare.k80mask[i][2] );
                }
            }
            printf("방어구번호를 입력하세여\n");
            scanf("%d",&equip_choice); //5개중에 고르기 0~4번
            if(boki->bokiEquipment.rare.k80mask[equip_choice][0] != 0){ // 방어구가 있는지 확인
            boki->def += boki->bokiEquipment.rare.k80mask[equip_choice][1]; //복이 방어력에 방어구 방어력 입히기
            printf("방어구를 장착했습니다.");
            break;
            }else{
            printf("방어구가 없습니다.");
            break;
            }
            case 1 ://1티어 갑바 장착하기
            
            for(int i=0; i<5; i++){ //아이템 정보출력
            if(boki->bokiEquipment.rare.halfarmor[i][0] != 0){ //i번째 장비의 정보 출력
                printf("\n반팔갑옷 %d 번 장비의 방어력%d : \n 강화수치 %d\n", i,boki->bokiEquipment.rare.halfarmor[i][1],boki->bokiEquipment.rare.halfarmor[i][2] );
                }
            }
            printf("방어구번호를 입력하세여\n");
            scanf("%d",&equip_choice); //5개중에 고르기 0~4번
            if(boki->bokiEquipment.rare.halfarmor[equip_choice][0] != 0){ // 방어구가 있는지 확인
            boki->def += boki->bokiEquipment.rare.halfarmor[equip_choice][1]; //복이 방어력에 방어구 방어력 입히기
            printf("방어구를 장착했습니다.");
            break;
            }else{
            printf("방어구가 없습니다.");
            break;
            }
            case 2 ://1티어 망토 장착하기
            
            for(int i=0; i<5; i++){ //아이템 정보출력
            if(boki->bokiEquipment.rare.cottencape[i][0] != 0){ //i번째 장비의 정보 출력
                printf("\n천망토 %d 번 장비의 방어력%d : \n 강화수치 %d\n", i,boki->bokiEquipment.rare.cottencape[i][1],boki->bokiEquipment.rare.cottencape[i][2] );
                }
            }
            printf("방어구번호를 입력하세여\n");
            scanf("%d",&equip_choice); //5개중에 고르기 0~4번
            if(boki->bokiEquipment.rare.cottencape[equip_choice][0] != 0){ // 방어구가 있는지 확인
            boki->def += boki->bokiEquipment.rare.cottencape[equip_choice][1]; //복이 방어력에 방어구 방어력 입히기
            printf("방어구를 장착했습니다.");
            break;
            }else{
            printf("방어구가 없습니다.");
            break;
            }
            case 3 :// 장갑 장착하기
            
            for(int i=0; i<5; i++){ //아이템 정보출력
            if(boki->bokiEquipment.rare.rubbergloves[i][0] != 0){ //i번째 장비의 정보 출력
                printf("\n고무장갑 %d 번 장비의 방어력%d : \n 강화수치 %d\n", i,boki->bokiEquipment.rare.rubbergloves[i][1],boki->bokiEquipment.rare.rubbergloves[i][2] );
                }
            }
            printf("방어구번호를 입력하세여\n");
            scanf("%d",&equip_choice); //5개중에 고르기 0~4번
            if(boki->bokiEquipment.rare.rubbergloves[equip_choice][0] != 0){ // 방어구가 있는지 확인
            boki->def += boki->bokiEquipment.rare.rubbergloves[equip_choice][1]; //복이 방어력에 방어구 방어력 입히기
            printf("방어구를 장착했습니다.");
            break;
            }else{
            printf("방어구가 없습니다.");
            break;
            }
            case 4 ://부츠 장착하기
            
            for(int i=0; i<5; i++){ //아이템 정보출력
            if(boki->bokiEquipment.rare.slipper[i][0] != 0){ //i번째 장비의 정보 출력
                printf("\n슬리퍼 %d 번 장비의 방어력%d : \n 강화수치 %d\n", i,boki->bokiEquipment.rare.slipper[i][1],boki->bokiEquipment.rare.slipper[i][2] );
                }
            }
            printf("방어구번호를 입력하세여\n");
            scanf("%d",&equip_choice); //5개중에 고르기 0~4번
            if(boki->bokiEquipment.rare.slipper[equip_choice][0] != 0){ // 방어구가 있는지 확인
            boki->def += boki->bokiEquipment.rare.slipper[equip_choice][1]; //복이 방어력에 방어구 방어력 입히기
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
    boki->bokiEquipment.epic.k94mask[0][1] = 5;// 마스크 첫번째 방어구 방어력 입력 개수, 방어력, 강화
    boki->bokiEquipment.epic.k94mask[0][0] = 1;// 테스트 때문에 방어구 한개 넣어서 확인해보기

    // 3티어 방어구 장착하기
    scanf("%d",&depend_choice);
    switch(depend_choice)
        {   //이거이거 뭐지 이거이거 뭐니
        //1 티어 방어구를 한번에 착용하기 
        // 그렇게 하려면 어떻게 해야하지 선택을 하게해서 1티어리스트 뽑아주고 선택하게 하기 
            case 0 ://마스크 장착하기
            int equip_choice;
            for(int i=0; i<5; i++){ //아이템 정보출력
            if(boki->bokiEquipment.epic.k94mask[i][0] != 0){ //i번째 장비의 정보 출력
                printf("\nk94마스크 %d 번 장비의 방어력%d : \n 강화수치 %d\n", i,boki->bokiEquipment.epic.k94mask[i][1],boki->bokiEquipment.epic.k94mask[i][2] );
                }
            }
            printf("방어구번호를 입력하세여\n");
            scanf("%d",&equip_choice); //5개중에 고르기 0~4번
            if(boki->bokiEquipment.epic.k94mask[equip_choice][0] != 0){ // 방어구가 있는지 확인
            boki->def += boki->bokiEquipment.epic.k94mask[equip_choice][1]; //복이 방어력에 방어구 방어력 입히기
            printf("방어구를 장착했습니다.");
            break;
            }else{
            printf("방어구가 없습니다.");
            break;
            }
            case 1 :// 갑바 장착하기
            
            for(int i=0; i<5; i++){ //아이템 정보출력
            if(boki->bokiEquipment.epic.hoodarmor[i][0] != 0){ //i번째 장비의 정보 출력
                printf("\n후드갑바 %d 번 장비의 방어력%d : \n 강화수치 %d\n", i,boki->bokiEquipment.epic.hoodarmor[i][1],boki->bokiEquipment.epic.hoodarmor[i][2] );
                }
            }
            printf("방어구번호를 입력하세여\n");
            scanf("%d",&equip_choice); //5개중에 고르기 0~4번
            if(boki->bokiEquipment.epic.hoodarmor[equip_choice][0] != 0){ // 방어구가 있는지 확인
            boki->def += boki->bokiEquipment.epic.hoodarmor[equip_choice][1]; //복이 방어력에 방어구 방어력 입히기
            printf("방어구를 장착했습니다.");
            break;
            }else{
            printf("방어구가 없습니다.");
            break;
            }
            case 2 ://1티어 망토 장착하기
            
            for(int i=0; i<5; i++){ //아이템 정보출력
            if(boki->bokiEquipment.epic.silkcape[i][0] != 0){ //i번째 장비의 정보 출력
                printf("\n실크망토 %d 번 장비의 방어력%d : \n 강화수치 %d\n", i,boki->bokiEquipment.epic.silkcape[i][1],boki->bokiEquipment.epic.silkcape[i][2] );
                }
            }
            printf("방어구번호를 입력하세여\n");
            scanf("%d",&equip_choice); //5개중에 고르기 0~4번
            if(boki->bokiEquipment.epic.silkcape[equip_choice][0] != 0){ // 방어구가 있는지 확인
            boki->def += boki->bokiEquipment.epic.silkcape[equip_choice][1]; //복이 방어력에 방어구 방어력 입히기
            printf("방어구를 장착했습니다.");
            break;
            }else{
            printf("방어구가 없습니다.");
            break;
            }
            case 3 :// 장갑 장착하기
            
            for(int i=0; i<5; i++){ //아이템 정보출력
            if(boki->bokiEquipment.epic.cottengloves[i][0] != 0){ //i번째 장비의 정보 출력
                printf("\n천장갑 %d 번 장비의 방어력%d : \n 강화수치 %d\n", i,boki->bokiEquipment.epic.cottengloves[i][1],boki->bokiEquipment.epic.cottengloves[i][2] );
                }
            }
            printf("방어구번호를 입력하세여\n");
            scanf("%d",&equip_choice); //5개중에 고르기 0~4번
            if(boki->bokiEquipment.epic.cottengloves[equip_choice][0] != 0){ // 방어구가 있는지 확인
            boki->def += boki->bokiEquipment.epic.cottengloves[equip_choice][1]; //복이 방어력에 방어구 방어력 입히기
            printf("방어구를 장착했습니다.");
            break;
            }else{
            printf("방어구가 없습니다.");
            break;
            }
            case 4 :// 부츠 장착하기
            
            for(int i=0; i<5; i++){ //아이템 정보출력
            if(boki->bokiEquipment.epic.sneakers[i][0] != 0){ //i번째 장비의 정보 출력
                printf("\n스니커즈%d 번 장비의 방어력%d : \n 강화수치 %d\n", i,boki->bokiEquipment.epic.sneakers[i][1],boki->bokiEquipment.epic.sneakers[i][2] );
                }
            }
            printf("방어구번호를 입력하세여\n");
            scanf("%d",&equip_choice); //5개중에 고르기 0~4번
            if(boki->bokiEquipment.epic.sneakers[equip_choice][0] != 0){ // 방어구가 있는지 확인
            boki->def += boki->bokiEquipment.epic.sneakers[equip_choice][1]; //복이 방어력에 방어구 방어력 입히기
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
    boki->bokiEquipment.legend.tigermask[0][1] = 5;// 마스크 첫번째 방어구 방어력 입력 개수, 방어력, 강화
    boki->bokiEquipment.legend.tigermask[0][0] = 1;// 테스트 때문에 방어구 한개 넣어서 확인해보기
    printf("4티어 방어구입니다.");
    
    // 4티어 방어구 장착하기
    scanf("%d",&depend_choice);
    switch(depend_choice)
        { 
        //4 티어 방어구를 한번에 착용하기 
        // 그렇게 하려면 어떻게 해야하지 선택을 하게해서 1티어리스트 뽑아주고 선택하게 하기 
            case 0 ://4티어 마스크 장착하기
            int equip_choice;
            for(int i=0; i<5; i++){ //아이템 정보출력
            if(boki->bokiEquipment.legend.tigermask[i][0] != 0){ //i번째 장비의 정보 출력
                printf("\n타이거마스크 %d 번 장비의 방어력%d : \n 강화수치 %d\n", i,boki->bokiEquipment.legend.tigermask[i][1],boki->bokiEquipment.legend.tigermask[i][2] );
                }
            }
            printf("방어구번호를 입력하세여\n");
            scanf("%d",&equip_choice); //5개중에 고르기 0~4번
            if(boki->bokiEquipment.legend.tigermask[equip_choice][0] != 0){ // 방어구가 있는지 확인
            boki->def += boki->bokiEquipment.legend.tigermask[equip_choice][1]; //복이 방어력에 방어구 방어력 입히기
            boki->bokiEquipment.legend.tigermask[equip_choice][0] = 0;
            printf("%d번 방어구를 장착했습니다.",equip_choice);
            break;
            }else{
            printf("방어구가 없습니다.");
            break;
            }
            case 1 ://4티어 갑바 장착하기
            
            for(int i=0; i<5; i++){
            if(boki->bokiEquipment.legend.dragonarmor[i][0] != 0){ //i번째 장비의 정보 출력
                printf("\n드래곤갑바 %d 번 장비의 방어력%d : \n 강화수치 %d\n", i,boki->bokiEquipment.legend.dragonarmor[i][1],boki->bokiEquipment.legend.dragonarmor[i][2] );
                }
            }
            printf("방어구번호를 입력하세여\n");
            scanf("%d",&equip_choice); // 5개중에 고르기 0~4번
            if(boki->bokiEquipment.legend.dragonarmor[equip_choice][0] != 0){ // 방어구가 있는지 확인
            boki->def += boki->bokiEquipment.legend.dragonarmor[equip_choice][1]; //복이 방어력에 방어구 방어력 입히기
            printf("방어구를 장착했습니다.");
            break;
            }else{
            printf("방어구가 없습니다.");
            break;
            }
            case 2 ://4티어 망토 장착하기
            
            for(int i=0; i<5; i++){
            if(boki->bokiEquipment.legend.bulletcape[i][0] != 0){ //i번째 장비의 정보 출력
                printf("\n방탄망토%d 번 장비의 방어력%d : \n 강화수치 %d\n", i,boki->bokiEquipment.legend.bulletcape[i][1],boki->bokiEquipment.legend.bulletcape[i][2] );
                }
            }
            printf("방어구번호를 입력하세여\n");
            scanf("%d",&equip_choice); // 5개중에 고르기 0~4번
            if(boki->bokiEquipment.legend.bulletcape[equip_choice][0] != 0){ // 방어구가 있는지 확인
            boki->def += boki->bokiEquipment.legend.bulletcape[equip_choice][1]; //복이 방어력에 방어구 방어력 입히기
            printf("방어구를 장착했습니다.");
            break;
            }else{
            printf("방어구가 없습니다.");
            break;
            }
            case 3 ://4티어 장갑 장착하기
            
            for(int i=0; i<5; i++){ //아이템 정보출력
            if(boki->bokiEquipment.legend.leardergloves[i][0] != 0){ //i번째 장비의 정보 출력
                printf("\n가죽갑옷%d 번 장비의 방어력%d : \n 강화수치 %d\n", i,boki->bokiEquipment.legend.leardergloves[i][1],boki->bokiEquipment.legend.leardergloves[i][2] );
                }
            }
            printf("방어구번호를 입력하세여\n");
            scanf("%d",&equip_choice); // 5개중에 고르기 0~4번
            if(boki->bokiEquipment.legend.leardergloves[equip_choice][0] != 0){ // 방어구가 있는지 확인
            boki->def += boki->bokiEquipment.legend.leardergloves[equip_choice][1]; //복이 방어력에 방어구 방어력 입히기
            printf("방어구를 장착했습니다.");
            break;
            }else{
            printf("방어구가 없습니다.");
            break;
            }
            case 4 ://4티어 부츠 장착하기
            
            for(int i=0; i<5; i++){ //아이템 정보출력
            if(boki->bokiEquipment.legend.airjodan[i][0] != 0){ //i번째 장비의 정보 출력
                printf("\n조던%d 번 장비의 방어력%d : \n 강화수치 %d\n", i,boki->bokiEquipment.legend.airjodan[i][1],boki->bokiEquipment.legend.airjodan[i][2] );
                }
            }
            printf("방어구번호를 입력하세여\n");
            scanf("%d",&equip_choice); //타이거 마스크 5개중에 고르기 0~4번
            if(boki->bokiEquipment.legend.airjodan[equip_choice][0] != 0){ // 방어구가 있는지 확인
            boki->def += boki->bokiEquipment.legend.airjodan[equip_choice][1]; //복이 방어력에 방어구 방어력 입히기
            printf("방어구를 장착했습니다.");
            break;
            }else{
            printf("방어구가 없습니다.");
            break;
            }
            
            
        
        
    }
    return boki->def;
}

int equip(Boki* boki){
    
    
    int asdf;
    int sum;
    printf("입력하세요");
    scanf("%d",&asdf);
    if(asdf == 0){
        printf("무기창입니다");
      sum +=  equip_sword( boki);

        printf("1티어 방어구 창입니다.");
       sum +=  equip_first_depend(boki);

        printf("2티어 방어구 창입니다.");
       sum +=  equip_second_depend(boki);

        printf("3티어 방어구 창입니다.");
        sum +=   equip_third_depend(boki);

        printf("4티어 방어구 창입니다.");
       sum +=  equip_fourth_depend(boki);
    }
    return sum;
}

// 지금 방어구 4개만 낄 수 있네 티어가 4개니까 
// 