#include<stdio.h>
#include<stdlib.h> /*랜덤함수 사용 위해 불러옴*/
#include<time.h> /*랜덤함수 사용 위해 불러옴*/
#include"item.h"



int equip_sword( Boki*); 
int equip_mask(  Boki*);
int equip_armor(  Boki*);
int equip_cape(  Boki*);
int equip_gloves(  Boki*);
int equip_boots(Boki*);
int equip(Boki*);





int main(void)
{
    Boki* boki=(Boki*)malloc(sizeof(Boki));
    // boki->def = 0;
    // sword_table a;
    // Boki a;
    // equip_sword(boki);
    
    // printf("%d\n",boki->damage);

    
//     boki->def=equip_mask(boki);
//     // +equip_mask(boki)+equip_armor(boki)+equip_cape(boki)+equip_gloves(boki);
// printf("방어력%daaaa\n",boki->def);
// equip_gloves(boki);
    int sum;
    equip(boki);
    printf("테스트 출력 방어력%d\n",boki->def);

    
}

int equip_sword(  Boki* boki){
    char aaaaaa;
  static  int depend_choice;
    
   
    // 무기장착
      while (1)
        {
        aaaaaa=getchar();
        depend_choice=atoi(&aaaaaa); //문자숫자를 진짜 숫자로 바꿔줌 근대 숫자가아니면 0반환   
        if(depend_choice==1||depend_choice==2||depend_choice==3||depend_choice==4)
        {
            break;
        }
        }
    // boki->bokiEquipment.weapon.basicsword[depend_choice][1] = 5;// 마스크 첫번째 방어구 방어력 입력 개수, 방어력, 강화
   
    // boki->bokiEquipment.weapon.basicsword[0][0] = 1;// 테스트 때문에 방어구 한개 넣어서 확인해보기
    switch(depend_choice)
        {   
            case 1 ://1티어 무기 장착하기
            static int equip_choice;
            
            for(int i=0; i<5; i++){ //아이템 정보출력
            if(boki->bokiEquipment.weapon.basicsword[i][0] != 0){ //i번째 장비의 정보 출력
                printf("\n 기본검 %d 번 장비의 공격력%f : \n 강화수치 %f\n", i+1,boki->bokiEquipment.weapon.basicsword[i][1],boki->bokiEquipment.weapon.basicsword[i][2] );
                }
            }
            printf("번호를 입력하세요. \n");
        while (1)
        {
        aaaaaa=getchar();  
        equip_choice=atoi(&aaaaaa); //차 변수 주소로들어가서 *변수=> 1 실제 1이아니라 문자 1은 정수로 49임 그런대 이걸 함수가 그냥 정수 1로바꿔줌 
        if(equip_choice==1||equip_choice==2||equip_choice==3||equip_choice==4||equip_choice==5)
        {
            break;
        }
        } //5개중에 고르기 0~4번
            
        if(boki->bokiEquipment.weapon.basicsword[equip_choice-1][0] != 0){ 
            printf("무기가있네요\n");// 무기가 있는지 확인
            boki->damage = boki->bokiEquipment.weapon.basicsword[equip_choice-1][1]; //복이 공격력에 무기 공격력 입히기
            printf("무기를 장착했습니다.\n");
            break;
            }else{
            printf("무기가 없습니다.\n");
            break;
            }
            case 2 ://2티어 무기 장착하기 depend_choice 2
            // int equip_choice;
            for(int i=0; i<5; i++){ //아이템 정보출력
            if(boki->bokiEquipment.weapon.longsword[i][0] != 0){ //i번째 장비의 정보 출력
                printf("\n 장검 %d 번 장비의 공격력%f : \n 강화수치 %f\n", i+1,boki->bokiEquipment.weapon.longsword[i][1],boki->bokiEquipment.weapon.longsword[i][2] );
                }
            }
            printf("번호를 입력하세요. \n");
              while (1)
            {
            aaaaaa=getchar();
            equip_choice=atoi(&aaaaaa);  
            if(equip_choice==1||equip_choice==2||equip_choice==3||equip_choice==4||equip_choice==5)
            {
                break;
            }
            }  //5개중에 고르기 0~4번
            if(boki->bokiEquipment.weapon.longsword[equip_choice-1][0] != 0){ // 무기가 있는지 확인
            boki->damage = boki->bokiEquipment.weapon.longsword[equip_choice-1][1]; //복이 공격력에 무기 공격력 입히기
            printf("무기를 장착했습니다.\n");
            break;
            }else{
            printf("무기가 없습니다.\n");
            break;
            }
            case 3 ://3티어 무기 장착하기
            // int equip_choice;
            for(int i=0; i<5; i++){ //아이템 정보출력
            if(boki->bokiEquipment.weapon.japensword[i][0] != 0){ //i번째 장비의 정보 출력
                printf("\n 일본도 %d 번 장비의 공격력%f : \n 강화수치 %f\n", i+1,boki->bokiEquipment.weapon.japensword[i][1],boki->bokiEquipment.weapon.japensword[i][2] );
                }
            }
            printf("번호를 입력하세요. \n");
              while (1)
            {
            aaaaaa=getchar();
            equip_choice=atoi(&aaaaaa);  
            if(equip_choice==1||equip_choice==2||equip_choice==3||equip_choice==4||equip_choice==5)
            {
                break;
            }
            } //5개중에 고르기 0~4번
            if(boki->bokiEquipment.weapon.japensword[equip_choice-1][0] != 0){ // 무기가 있는지 확인
            boki->damage = boki->bokiEquipment.weapon.japensword[equip_choice-1][1]; //복이 공격력에 무기 공격력 입히기
            printf("무기를 장착했습니다.\n");
            break;
            }else{
            printf("무기가 없습니다.\n");
            break;
            }
            case 4 ://1티어 무기 장착하기
            // int equip_choice;
            for(int i=0; i<5; i++){ //아이템 정보출력
            if(boki->bokiEquipment.weapon.nigthsword_saj[i][0] != 0){ //i번째 장비의 정보 출력
                printf("\n 싸울아비장검 %d 번 장비의 공격력%f : \n 강화수치 %f\n", i+1,boki->bokiEquipment.weapon.nigthsword_saj[i][1],boki->bokiEquipment.weapon.nigthsword_saj[i][2] );
                }
            }
            printf("번호를 입력하세요. \n");
              while (1)
            {
            aaaaaa=getchar();
            equip_choice=atoi(&aaaaaa);  
            if(equip_choice==1||equip_choice==2||equip_choice==3||equip_choice==4||equip_choice==5)
            {
                break;
            }
            } //5개중에 고르기 0~4번
            if(boki->bokiEquipment.weapon.nigthsword_saj[equip_choice-1][0] != 0){ // 무기가 있는지 확인
            boki->damage = boki->bokiEquipment.weapon.nigthsword_saj[equip_choice-1][1]; //복이 공격력에 무기 공격력 입히기
            printf("무기를 장착했습니다.\n");
            break;
            }else{
            printf("무기가 없습니다.\n");
            break;
            }
    }
    return boki->damage;
}
//1티어 방어구 장착하기
int equip_mask( Boki* boki){
    char aaaaaa;
 static   int depend_choice;
    //초기화
    
    // boki->bokiEquipment.nomal.basicmask[0][1] = 0;// 테스트 때문에 방어구 한개 넣어서 확인해보기
    // printf("%d",boki->bokiEquipment.nomal.basicmask[0][1]);
    // 1티어 방어구 장착하기
      while (1)
        {
        aaaaaa=getchar();
        depend_choice=atoi(&aaaaaa);  
        if(depend_choice==1||depend_choice==2||depend_choice==3||depend_choice==4)
        {
            break;
        }
        }
    switch(depend_choice)
        {    
            case 1 ://1티어 마스크 장착하기
         static  int equip_choice;
            for(int i=0; i<5; i++){ //아이템 정보출력
            if(boki->bokiEquipment.nomal.basicmask[i][0] != 0){ //i번째 장비의 정보 출력
                printf("\n기본마스크 %d 번 장비의 방어력%f : \n 강화수치 %f\n", i+1,boki->bokiEquipment.nomal.basicmask[i][1],boki->bokiEquipment.nomal.basicmask[i][2] );
                }
            }
            printf("방어구번호를 입력하세요. \n");
            while (1)
            {
            aaaaaa=getchar();
            equip_choice=atoi(&aaaaaa);  
            if(equip_choice==1||equip_choice==2||equip_choice==3||equip_choice==4||equip_choice==5)
            {
                break;
            }
            }//5개중에 고르기 0~4번
            if(boki->bokiEquipment.nomal.basicmask[equip_choice-1][0] != 0){ // 방어구가 있는지 확인
            boki->def += boki->bokiEquipment.nomal.basicmask[equip_choice-1][1]; //복이 방어력에 방어구 방어력 입히기
            printf("방어구를 장착했습니다.\n");
            break;
            }else{
            printf("방어구가 없습니다.\n");
            break;
            }
            case 2 ://1티어 갑바 장착하기
            for(int i=0; i<5; i++){ //아이템 정보출력
            if(boki->bokiEquipment.rare.k80mask[i][0] != 0){ //i번째 장비의 정보 출력
                printf("\nk80마스크%d 번 장비의 방어력%f : \n 강화수치 %f\n", i+1,boki->bokiEquipment.rare.k80mask[i][1],boki->bokiEquipment.rare.k80mask[i][2] );
                }
            }
            printf("방어구번호를 입력하세요. \n");
            while (1)
            {
            aaaaaa=getchar();
            equip_choice=atoi(&aaaaaa);  
            if(equip_choice==1||equip_choice==2||equip_choice==3||equip_choice==4||equip_choice==5)
            {
                break;
            }
            } //5개중에 고르기 0~4번
            if(boki->bokiEquipment.rare.k80mask[equip_choice-1][0] != 0){ // 방어구가 있는지 확인
            boki->def += boki->bokiEquipment.rare.k80mask[equip_choice-1][1]; //복이 방어력에 방어구 방어력 입히기
            printf("방어구를 장착했습니다.\n");
            break;
            }else{
            printf("방어구가 없습니다.\n");
            break;
            }
            case 3 ://1티어 망토 장착하기
            for(int i=0; i<5; i++){ //아이템 정보출력
            if(boki->bokiEquipment.epic.k94mask[i][0] != 0){ //i번째 장비의 정보 출력
                printf("\nk94마스크 %d 번 장비의 방어력%f : \n 강화수치 %f\n", i+1,boki->bokiEquipment.epic.k94mask[i][1],boki->bokiEquipment.epic.k94mask[i][2] );
                }
            }
            printf("방어구번호를 입력하세요. \n");
            while (1)
            {
            aaaaaa=getchar();
            equip_choice=atoi(&aaaaaa);  
            if(equip_choice==1||equip_choice==2||equip_choice==3||equip_choice==4||equip_choice==5)
            {
                break;
            }
            }//5개중에 고르기 0~4번
            if(boki->bokiEquipment.epic.k94mask[equip_choice-1][0] != 0){ // 방어구가 있는지 확인
            boki->def += boki->bokiEquipment.epic.k94mask[equip_choice-1][1]; //복이 방어력에 방어구 방어력 입히기
            printf("방어구를 장착했습니다.\n");
            break;
            }else{
            printf("방어구가 없습니다.\n");
            break;
            }
            case 4 ://1티어 장갑 장착하기

            for(int i=0; i<5; i++){ //아이템 정보출력
            if(boki->bokiEquipment.legend.tigermask[i][0] != 0){ //i번째 장비의 정보 출력
                printf("\n타이거마스크 %d 번 장비의 방어력%f : \n 강화수치 %f\n", i+1,boki->bokiEquipment.legend.tigermask[i][1],boki->bokiEquipment.legend.tigermask[i][2] );
                }
            }
            printf("방어구번호를 입력하세요. \n");
            while (1)
            {
            aaaaaa=getchar();
            equip_choice=atoi(&aaaaaa);  
            if(equip_choice==1||equip_choice==2||equip_choice==3||equip_choice==4||equip_choice==5)
            {
                break;
            }
            }//5개중에 고르기 0~4번
            if(boki->bokiEquipment.legend.tigermask[equip_choice-1][0] != 0){ // 방어구가 있는지 확인
            boki->def += boki->bokiEquipment.legend.tigermask[equip_choice-1][1]; //복이 방어력에 방어구 방어력 입히기
            boki->bokiEquipment.legend.tigermask[equip_choice][0] = 0;
            printf("%d번 방어구를 장착했습니다.\n",equip_choice);
            break;
            }else{
            printf("방어구가 없습니다.\n");
            break;
            }
    }
return boki->def;
}

//아머 장착하기
int equip_armor(  Boki* boki){
    char aaaaaa;
 static   int depend_choice;
    //초기화
   
    // 아머 장착하기    getchar(aaaaaa);
    while (1)
        {
        aaaaaa=getchar();
        depend_choice=atoi(&aaaaaa);  //티어는 4개
        if(depend_choice==1||depend_choice==2||depend_choice==3||depend_choice==4)
        {
            break;
        }
        }
    switch(depend_choice)
        {   
            case 1 :// 티어는 4개
           static int equip_choice;
            for(int i=0; i<5; i++){ //아이템 정보출력
            if(boki->bokiEquipment.nomal.basicarmor[i][0] != 0){ //i번째 장비의 정보 출력
                printf("\n기본갑바%d 번 장비의 방어력%f : \n 강화수치 %f\n", i+1,boki->bokiEquipment.nomal.basicarmor[i][1],boki->bokiEquipment.nomal.basicarmor[i][2] );
                }
            }
            printf("방어구번호를 입력하세요. \n");
            while (1)
            {
            aaaaaa=getchar();
            equip_choice=atoi(&aaaaaa);  
            if(equip_choice==1||equip_choice==2||equip_choice==3||equip_choice==4||equip_choice==5)
            {
                break;
            }
            } //5개중에 고르기 0~4번
            if(boki->bokiEquipment.nomal.basicarmor[equip_choice-1][0] != 0){ // 방어구가 있는지 확인
            boki->def += boki->bokiEquipment.nomal.basicarmor[equip_choice-1][1]; //복이 방어력에 방어구 방어력 입히기
            printf("방어구를 장착했습니다.\n");
            break;
            }else{
            printf("방어구가 없습니다.\n");
            break;
            }
            case 2 ://1티어 갑바 장착하기
            
            for(int i=0; i<5; i++){ //아이템 정보출력
            if(boki->bokiEquipment.rare.halfarmor[i][0] != 0){ //i번째 장비의 정보 출력
                printf("\n반팔갑옷 %d 번 장비의 방어력%f : \n 강화수치 %f\n", i+1,boki->bokiEquipment.rare.halfarmor[i][1],boki->bokiEquipment.rare.halfarmor[i][2] );
                }
            }
            printf("방어구번호를 입력하세요. \n");
            while (1)
            {
            aaaaaa=getchar();
            equip_choice=atoi(&aaaaaa);  
            if(equip_choice==1||equip_choice==2||equip_choice==3||equip_choice==4||equip_choice==5)
            {
                break;
            }
            }//5개중에 고르기 0~4번
            if(boki->bokiEquipment.rare.halfarmor[equip_choice-1][0] != 0){ // 방어구가 있는지 확인
            boki->def += boki->bokiEquipment.rare.halfarmor[equip_choice-1][1]; //복이 방어력에 방어구 방어력 입히기
            printf("방어구를 장착했습니다.\n");
            break;
            }else{
            printf("방어구가 없습니다.\n");
            break;
            }
            case 3 ://1티어 망토 장착하기
            
            for(int i=0; i<5; i++){ //아이템 정보출력
            if(boki->bokiEquipment.epic.hoodarmor[i][0] != 0){ //i번째 장비의 정보 출력
                printf("\n후드갑바 %d 번 장비의 방어력%f : \n 강화수치 %f\n", i+1,boki->bokiEquipment.epic.hoodarmor[i][1],boki->bokiEquipment.epic.hoodarmor[i][2] );
                }
            }
            printf("방어구번호를 입력하세요. \n");
            while (1)
            {
            aaaaaa=getchar();
            equip_choice=atoi(&aaaaaa);  
            if(equip_choice==1||equip_choice==2||equip_choice==3||equip_choice==4||equip_choice==5)
            {
                break;
            }
            } //5개중에 고르기 0~4번
            if(boki->bokiEquipment.epic.hoodarmor[equip_choice-1][0] != 0){ // 방어구가 있는지 확인
            boki->def += boki->bokiEquipment.epic.hoodarmor[equip_choice-1][1]; //복이 방어력에 방어구 방어력 입히기
            printf("방어구를 장착했습니다.\n");
            break;
            }else{
            printf("방어구가 없습니다.\n");
            break;
            }
            case 4 :// 드래곤갑바
            
            for(int i=0; i<5; i++){
            if(boki->bokiEquipment.legend.dragonarmor[i][0] != 0){ //i번째 장비의 정보 출력
                printf("\n드래곤갑바 %d 번 장비의 방어력%f : \n 강화수치 %f\n", i+1,boki->bokiEquipment.legend.dragonarmor[i][1],boki->bokiEquipment.legend.dragonarmor[i][2] );
                }
            }
            printf("방어구번호를 입력하세요. \n");
            while (1)
            {
            aaaaaa=getchar();
            equip_choice=atoi(&aaaaaa);  
            if(equip_choice==1||equip_choice==2||equip_choice==3||equip_choice==4||equip_choice==5)
            {
                break;
            }
            } // 5개중에 고르기 0~4번
            if(boki->bokiEquipment.legend.dragonarmor[equip_choice-1][0] != 0){ // 방어구가 있는지 확인
            boki->def += boki->bokiEquipment.legend.dragonarmor[equip_choice-1][1]; //복이 방어력에 방어구 방어력 입히기
            printf("방어구를 장착했습니다.\n");
            break;
            }else{
            printf("방어구가 없습니다.\n");
            break;
            } 
    }
    return boki->def;
}

//망토 장착하기
int equip_cape(  Boki* boki){
    char aaaaaa;
  static  int depend_choice;
    //초기화
   

    // 3티어 방어구 장착하기    getchar(aaaaaa);
    while (1)
        {
        aaaaaa=getchar();
        depend_choice=atoi(&aaaaaa);  //티어는 4개
        if(depend_choice==1||depend_choice==2||depend_choice==3||depend_choice==4)
        {
            break;
        }
        }
   static int equip_choice;
    switch(depend_choice)
        {   //이거이거 뭐지 이거이거 뭐니
        //1 티어 방어구를 한번에 착용하기 
        // 그렇게 하려면 어떻게 해야하지 선택을 하게해서 1티어리스트 뽑아주고 선택하게 하기 
            case 1 ://마스크 장착하기
            for(int i=0; i<5; i++){ //아이템 정보출력
            if(boki->bokiEquipment.nomal.basiccape[i][0] != 0){ //i번째 장비의 정보 출력
                printf("\n기본망토%d 번 장비의 방어력%f : \n 강화수치 %f\n", i+1,boki->bokiEquipment.nomal.basiccape[i][1],boki->bokiEquipment.nomal.basiccape[i][2] );
                }
            }
            printf("방어구번호를 입력하세요. \n");
            while (1)
            {
            aaaaaa=getchar();
            equip_choice=atoi(&aaaaaa);  
            if(equip_choice==1||equip_choice==2||equip_choice==3||equip_choice==4||equip_choice==5)
            {
                break;
            }
            } //5개중에 고르기 0~4번
            if(boki->bokiEquipment.nomal.basiccape[equip_choice-1][0] != 0){ // 방어구가 있는지 확인
            boki->def += boki->bokiEquipment.nomal.basiccape[equip_choice-1][1]; //복이 방어력에 방어구 방어력 입히기
            printf("방어구를 장착했습니다.\n");
            break;
            }else{
            printf("방어구가 없습니다.\n");
            break;
            }
            case 2 :// 갑바 장착하기
            
            for(int i=0; i<5; i++){ //아이템 정보출력
            if(boki->bokiEquipment.rare.cottencape[i][0] != 0){ //i번째 장비의 정보 출력
                printf("\n천망토 %d 번 장비의 방어력%f : \n 강화수치 %f\n", i+1,boki->bokiEquipment.rare.cottencape[i][1],boki->bokiEquipment.rare.cottencape[i][2] );
                }
            }
            printf("방어구번호를 입력하세요. \n");
            while (1)
            {
            aaaaaa=getchar();
            equip_choice=atoi(&aaaaaa);  
            if(equip_choice==1||equip_choice==2||equip_choice==3||equip_choice==4||equip_choice==5)
            {
                break;
            }
            } //5개중에 고르기 0~4번
            if(boki->bokiEquipment.rare.cottencape[equip_choice-1][0] != 0){ // 방어구가 있는지 확인
            boki->def += boki->bokiEquipment.rare.cottencape[equip_choice-1][1]; //복이 방어력에 방어구 방어력 입히기
            printf("방어구를 장착했습니다.\n");
            break;
            }else{
            printf("방어구가 없습니다.\n");
            break;
            }
            case 3 ://1티어 망토 장착하기
            
            for(int i=0; i<5; i++){ //아이템 정보출력
            if(boki->bokiEquipment.epic.silkcape[i][0] != 0){ //i번째 장비의 정보 출력
                printf("\n실크망토 %d 번 장비의 방어력%f : \n 강화수치 %f\n", i+1,boki->bokiEquipment.epic.silkcape[i][1],boki->bokiEquipment.epic.silkcape[i][2] );
                }
            }
            printf("방어구번호를 입력하세요. \n");
            while (1)
            {
            aaaaaa=getchar();
            equip_choice=atoi(&aaaaaa);  
            if(equip_choice==1||equip_choice==2||equip_choice==3||equip_choice==4||equip_choice==5)
            {
                break;
            }
            } //5개중에 고르기 0~4번
            if(boki->bokiEquipment.epic.silkcape[equip_choice-1][0] != 0){ // 방어구가 있는지 확인
            boki->def += boki->bokiEquipment.epic.silkcape[equip_choice-1][1]; //복이 방어력에 방어구 방어력 입히기
            printf("방어구를 장착했습니다.\n");
            break;
            }else{
            printf("방어구가 없습니다.\n");
            break;
            }
            case 4 :// 장갑 장착하기
            
            for(int i=0; i<5; i++){
            if(boki->bokiEquipment.legend.bulletcape[i][0] != 0){ //i번째 장비의 정보 출력
                printf("\n방탄망토%d 번 장비의 방어력%f : \n 강화수치 %f\n", i+1,boki->bokiEquipment.legend.bulletcape[i][1],boki->bokiEquipment.legend.bulletcape[i][2] );
                }
            }
            printf("방어구번호를 입력하세요. \n");
            while (1)
            {
            aaaaaa=getchar();
            equip_choice=atoi(&aaaaaa);  
            if(equip_choice==1||equip_choice==2||equip_choice==3||equip_choice==4||equip_choice==5)
            {
                break;
            }
            } // 5개중에 고르기 0~4번
            if(boki->bokiEquipment.legend.bulletcape[equip_choice-1][0] != 0){ // 방어구가 있는지 확인
            boki->def += boki->bokiEquipment.legend.bulletcape[equip_choice-1][1]; //복이 방어력에 방어구 방어력 입히기
            printf("방어구를 장착했습니다.\n");
            break;
            }else{
            printf("방어구가 없습니다.\n");
            break;
            }
    }
    return boki->def;
}

//장갑 장착하기
int equip_gloves(  Boki* boki){
    char aaaaaa;
  static  int depend_choice;
    //초기화


    // 4티어 방어구 장착하기    getchar(aaaaaa);
    while (1)
        {
        aaaaaa=getchar(); //티어는 4개
        depend_choice=atoi(&aaaaaa);  
        if(depend_choice==1||depend_choice==2||depend_choice==3||depend_choice==4)
        {
            break;
        }
        }
    switch(depend_choice)
        { 
        //4 티어 방어구를 한번에 착용하기 
        // 그렇게 하려면 어떻게 해야하지 선택을 하게해서 1티어리스트 뽑아주고 선택하게 하기 
            case 1 ://4티어 마스크 장착하기
            for(int i=0; i<5; i++){ //아이템 정보출력
            if(boki->bokiEquipment.nomal.basicgloves[i][0] != 0){ //i번째 장비의 정보 출력
                printf("\n기본장갑%d 번 장비의 방어력%f : \n 강화수치 %f\n", i+1,boki->bokiEquipment.nomal.basicgloves[i][1],boki->bokiEquipment.nomal.basicgloves[i][2] );
                }
            }
            printf("방어구번호를 입력하세요. \n");
          static  int equip_choice;
            while (1)
        {
        aaaaaa=getchar();
        equip_choice=atoi(&aaaaaa);  
        if(equip_choice==1||equip_choice==2||equip_choice==3||equip_choice==4||equip_choice==5)
        {
            break;
        }
        }//5개중에 고르기 0~4번
            if(boki->bokiEquipment.nomal.basicgloves[equip_choice-1][0] != 0){ // 방어구가 있는지 확인
            boki->def += boki->bokiEquipment.nomal.basicgloves[equip_choice-1][1]; //복이 방어력에 방어구 방어력 입히기
            printf("방어구를 장착했습니다.\n");
            break;
            }else{
            printf("방어구가 없습니다.\n");
            break;
            }
            case 2 ://4티어 갑바 장착하기
            
            for(int i=0; i<5; i++){ //아이템 정보출력
            if(boki->bokiEquipment.rare.rubbergloves[i][0] != 0){ //i번째 장비의 정보 출력
                printf("\n고무장갑 %d 번 장비의 방어력%f : \n 강화수치 %f\n", i+1,boki->bokiEquipment.rare.rubbergloves[i][1],boki->bokiEquipment.rare.rubbergloves[i][2] );
                }
            }
            printf("방어구번호를 입력하세요. \n");
           while (1)
        {
        aaaaaa=getchar();
        equip_choice=atoi(&aaaaaa);  
        if(equip_choice==1||equip_choice==2||equip_choice==3||equip_choice==4||equip_choice==5)
        {
            break;
        }
        }//5개중에 고르기 0~4번
            if(boki->bokiEquipment.rare.rubbergloves[equip_choice-1][0] != 0){ // 방어구가 있는지 확인
            boki->def += boki->bokiEquipment.rare.rubbergloves[equip_choice-1][1]; //복이 방어력에 방어구 방어력 입히기
            printf("방어구를 장착했습니다.\n");
            break;
            }else{
            printf("방어구가 없습니다.\n");
            break;
            }
            case 3 ://4티어 망토 장착하기
            for(int i=0; i<5; i++){ //아이템 정보출력
            if(boki->bokiEquipment.epic.cottengloves[i][0] != 0){ //i번째 장비의 정보 출력
                printf("\n천장갑 %d 번 장비의 방어력%f : \n 강화수치 %f\n", i+1,boki->bokiEquipment.epic.cottengloves[i][1],boki->bokiEquipment.epic.cottengloves[i][2] );
                }
            }
            printf("방어구번호를 입력하세요. \n");
            while (1)
        {
        aaaaaa=getchar();
        equip_choice=atoi(&aaaaaa);  
        if(equip_choice==1||equip_choice==2||equip_choice==3||equip_choice==4||equip_choice==5)
        {
            break;
        }
        } //5개중에 고르기 0~4번
            if(boki->bokiEquipment.epic.cottengloves[equip_choice-1][0] != 0){ // 방어구가 있는지 확인
            boki->def += boki->bokiEquipment.epic.cottengloves[equip_choice-1][1]; //복이 방어력에 방어구 방어력 입히기
            printf("방어구를 장착했습니다.\n");
            break;
            }else{
            printf("방어구가 없습니다.\n");
            break;
            }
            case 4 ://4티어  장착하기
            
            for(int i=0; i<5; i++){ //아이템 정보출력
            if(boki->bokiEquipment.legend.leardergloves[i][0] != 0){ //i번째 장비의 정보 출력
                printf("\n가죽갑옷%d 번 장비의 방어력%f : \n 강화수치 %f\n", i+1,boki->bokiEquipment.legend.leardergloves[i][1],boki->bokiEquipment.legend.leardergloves[i][2] );
                }
            }
            printf("방어구번호를 입력하세요. \n");
           while (1)
        {
        aaaaaa=getchar();
        equip_choice=atoi(&aaaaaa);  
        if(equip_choice==1||equip_choice==2||equip_choice==3||equip_choice==4||equip_choice==5)
        {
            break;
        }
        }// 5개중에 고르기 0~4번
            if(boki->bokiEquipment.legend.leardergloves[equip_choice-1][0] != 0){ // 방어구가 있는지 확인
            boki->def += boki->bokiEquipment.legend.leardergloves[equip_choice-1][1]; //복이 방어력에 방어구 방어력 입히기
            printf("방어구를 장착했습니다.\n");
            break;
            }else{
            printf("방어구가 없습니다.\n");
            break;
            }            
    }
    return boki->def;
}

int equip_boots(  Boki* boki){// 부츠
    char aaaaaa;
  static  int depend_choice;
    //초기화

    printf("부츠 장착창입니다..\n");
    
    // 4티어 방어구 장착하기    getchar(aaaaaa);
    while (1)
        {
        aaaaaa=getchar();
        depend_choice=atoi(&aaaaaa);  
        if(depend_choice==1||depend_choice==2||depend_choice==3||depend_choice==4)
        {
            break;
        }
        }
    switch(depend_choice)
        { 
        //4 티어 방어구를 한번에 착용하기 
        // 그렇게 하려면 어떻게 해야하지 선택을 하게해서 1티어리스트 뽑아주고 선택하게 하기 
            case 1 ://4티어 마스크 장착하기
           static int equip_choice;
            for(int i=0; i<5; i++){ //아이템 정보출력
            if(boki->bokiEquipment.nomal.basicboots[i][0] != 0){ //i번째 장비의 정보 출력
                printf("\n기본부츠%d 번 장비의 방어력%f : \n 강화수치 %f\n", i+1,boki->bokiEquipment.nomal.basicboots[i][1],boki->bokiEquipment.nomal.basicboots[i][2] );
                }
            }
            printf("방어구번호를 입력하세요. \n");
            while (1)
        {
        aaaaaa=getchar();
        equip_choice=atoi(&aaaaaa);  
        if(equip_choice==1||equip_choice==2||equip_choice==3||equip_choice==4||equip_choice==5)
        {
            break;
        }
        } //5개중에 고르기 0~4번
            if(boki->bokiEquipment.nomal.basicboots[equip_choice-1][0] != 0){ // 방어구가 있는지 확인
            boki->def += boki->bokiEquipment.nomal.basicboots[equip_choice-1][1]; //복이 방어력에 방어구 방어력 입히기
            printf("방어구를 장착했습니다.\n");
            break;
            }else{
            printf("방어구가 없습니다.\n");
            break;
            }
            case 2 ://4티어 갑바 장착하기
            
            for(int i=0; i<5; i++){ //아이템 정보출력
            if(boki->bokiEquipment.rare.slipper[i][0] != 0){ //i번째 장비의 정보 출력
                printf("\n슬리퍼 %d 번 장비의 방어력%f : \n 강화수치 %f\n", i+1,boki->bokiEquipment.rare.slipper[i][1],boki->bokiEquipment.rare.slipper[i][2] );
                }
            }
            printf("방어구번호를 입력하세요. \n");
            while (1)
        {
        aaaaaa=getchar();
        equip_choice=atoi(&aaaaaa);  
        if(equip_choice==1||equip_choice==2||equip_choice==3||equip_choice==4||equip_choice==5)
        {
            break;
        }
        } //5개중에 고르기 0~4번
            if(boki->bokiEquipment.rare.slipper[equip_choice-1][0] != 0){ // 방어구가 있는지 확인
            boki->def += boki->bokiEquipment.rare.slipper[equip_choice-1][1]; //복이 방어력에 방어구 방어력 입히기
            printf("방어구를 장착했습니다.\n");
            break;
            }else{
            printf("방어구가 없습니다.\n");
            break;
            }
            case 3 ://4티어 망토 장착하기
            
            for(int i=0; i<5; i++){ //아이템 정보출력
            if(boki->bokiEquipment.epic.sneakers[i][0] != 0){ //i번째 장비의 정보 출력
                printf("\n스니커즈%d 번 장비의 방어력%f : \n 강화수치 %f\n", i+1,boki->bokiEquipment.epic.sneakers[i][1],boki->bokiEquipment.epic.sneakers[i][2] );
                }
            }
            printf("방어구번호를 입력하세요. \n");
            while (1)
        {
        aaaaaa=getchar();
        equip_choice=atoi(&aaaaaa);  
        if(equip_choice==1||equip_choice==2||equip_choice==3||equip_choice==4||equip_choice==5)
        {
            break;
        }
        } //5개중에 고르기 0~4번
            if(boki->bokiEquipment.epic.sneakers[equip_choice-1][0] != 0){ // 방어구가 있는지 확인
            boki->def += boki->bokiEquipment.epic.sneakers[equip_choice-1][1]; //복이 방어력에 방어구 방어력 입히기
            printf("방어구를 장착했습니다.\n");
            break;
            }else{
            printf("방어구가 없습니다.\n");
            break;
            }
            case 4 :

            for(int i=0; i<5; i++){ //아이템 정보출력
            if(boki->bokiEquipment.legend.airjodan[i][0] != 0){ //i번째 장비의 정보 출력
                printf("\n조던%d 번 장비의 방어력%f : \n 강화수치 %f\n", i+1,boki->bokiEquipment.legend.airjodan[i][1],boki->bokiEquipment.legend.airjodan[i][2] );
                }
            }
            printf("방어구번호를 입력하세요. \n");
            while (1)
        {
        aaaaaa=getchar();
        equip_choice=atoi(&aaaaaa);  
        if(equip_choice==1||equip_choice==2||equip_choice==3||equip_choice==4||equip_choice==5)
        {
            break;
        }
        }//타이거 마스크 5개중에 고르기 0~4번
            if(boki->bokiEquipment.legend.airjodan[equip_choice-1][0] != 0){ // 방어구가 있는지 확인
            boki->def += boki->bokiEquipment.legend.airjodan[equip_choice-1][1]; //복이 방어력에 방어구 방어력 입히기
            printf("방어구를 장착했습니다.\n");
            break;
            }else{
            printf("방어구가 없습니다.\n");
            break;
            }
    }
    return boki->def;
}

int equip(Boki* boki){
    
    int sum;
    printf("\n장비 장착창입니다 \n");
   

    printf("무기창입니다\n");
    printf("1번기본검   2번 장검    3번 일본도     4번 싸울아비장검\n");
        boki->def = 0;
        boki->damage = 0;
        sum +=  equip_sword( boki);

    printf("마스크 장비창입니다.\n");
    printf("1번 기본마스크      2번 k84마스크       3번k90마스크        4번타이거마스크     \n");
       sum +=  equip_mask(boki);

    printf("갑바 장비창입니다.\n");
    printf("1번 기본갑바      2번 반팔갑바       3번 후드갑바        4번용갑바     \n");

       sum +=  equip_armor(boki);

    printf("망토 장비창입니다.\n");
    printf("1번 기본망토      2번 면망토       3번 비단망토        4번 방탄망토     \n");

        sum +=   equip_cape(boki);

    printf("장갑 장비창입니다.\n");
    printf("1번 기본장갑      2번 고무장갑       3번 면장갑        4번 가죽장갑     \n");

       sum +=  equip_gloves(boki);
    printf("부츠 장비창입니다.\n");
    printf("1번 기본부츠      2번 슬리퍼       3번 스니커즈        4번 조던     \n");

       sum +=  equip_boots(boki);
    
    return sum;
}