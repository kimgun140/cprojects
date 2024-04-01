#include<stdio.h>
#include<stdlib.h>
int boki_hp = 100;
int weapon ;
int armor;
const int basic_sword = 5 ;
const int longsword = 10;
const int japansword = 15;
const int nigthsword_saj = 20;
int weapon_choice;// 장비창에서 무기 선택하기 1.기본검 2.장검 3.일본도 4. 싸울아비 장검
int armor_choice; // 방어구 개수 방어력 이름
int *Equipment_sword(int *weapon,int basic_sword,int longsword, int japansword, int nigthsword_saj);
// int Equipment_longsword(const int Equipment_longsword, int * weapon);

int main(void){
int* aaa;

printf("1.무기 2.방어구");
aaa = Equipment_sword( &weapon, basic_sword, longsword, japansword, nigthsword_saj);
// int* bbb =Equipment_longsword(&Equipment_longsword,&weapon);
printf("\nbbb%d",*aaa);
printf("\n%d", weapon);



    return 0;
}


int *Equipment_sword(int *weapon, int basic_sword, int longsword, int japansword, int nigthsword_saj){
    // basic_sword = 10;
    // weapon =&basic_sword ;
    printf("입력");
    scanf("%d", &weapon_choice);
    if (weapon_choice == 1){
        printf("기본검을 장착했습니다");
        *weapon = basic_sword ;
        printf("\n기본검 공격력%d",*weapon);
        
    }else if (weapon_choice ==2){
        printf("롱소드를 장착했습니다");
        *weapon = longsword ;
        printf("\n롱소드 공격력%d",*weapon);


    }else if (weapon_choice ==3){
        printf("일본도를 장착했습니다");
        *weapon = japansword ;
        printf("\n일본도 공격력%d",*weapon);


    }else if (weapon_choice ==4){
        printf("싸울아비장검을 장착했습니다");
        *weapon = nigthsword_saj ;
        printf("\n싸울아비장검을 공격력%d",*weapon);
    }


    return weapon;
    
    
}


// int Equipment_longsword(const int Equipment_longsword, int *weapon){
//     printf("입력");
//     scanf("%d", &weapon_choice);
//     if(weapon_choice == 2){
//         printf("장검을 장착했습니다");
//         weapon = &Equipment_longsword;
//         printf("%d", weapon);

    
//     }
//     return weapon;
// }
