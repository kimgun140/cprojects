#include<stdio.h>
int main(void){
    int choice;
    void count(void);
    int money;
    int order;

    printf("하나를 선택하시오:\n");
    printf("1. 콜라                 2.우주맛콜라\n");
    printf("3. 제로콜라                   4.스프라이트\n");
    printf("3. 환타 900                   4.닥터페퍼 1100\n");
    printf("3. 몬스터 1800                   4.파워에이드 1900\n");
    printf("3. 파워에이드 1900                   4.네스티 1600\n");
    printf("3. 글라소 비타민 워터 2100                   11) 미닛메이드 1700\n");
    printf("12) 조지아 커피 900                   13) 암바사 900\n");
    printf("14)마테차 1700                   \n");
    printf("15)종료하기\n");
    printf("돈내셈");
    scanf("%d", &money);
    printf("주문 ㄱㄱ");
    while ((order = getchar()) !='q'){
        switch (order){
            case 1 : printf("주문하신 콜라입니다. 씨발.\n");{
                        money = money - 1200;
                        break;}
            case 2 : printf("주문하신 우주0맛 콜라입니다.");
{                        money = money - 1900;
                        break;}
            case 3 : printf("주문하신 우주맛 콜라입니다.");
 {                       money = money - 1900;
                        break;}   
            case 4 : printf("주문하신 제로 콜라입니다.");
  {                      money = money - 1200;
                        break;}
            case 5 : printf("주문하신 스프라이트 콜라입니다.");{
                        money = money - 1100;
                        break;}
            case 6 : printf("주문하신 환타 콜라입니다.");
  {                      money = money - 900;
                        break;}
            case 7 : printf("주문하신 닥터페퍼 콜라입니다.");
{                        money = money - 1100;
                        break;}
            case 8 : printf("주문하신 몬스터 콜라입니다.");
 {                       money = money - 1800;
                        break;}
            case 9 : printf("주문하신 파워에이드 콜라입니다.");{
                        money = money - 1900;
                        break;}
            case 10 : printf("주문하신 네스트 콜라입니다.");
{                        money = money - 1600;
                        break;}
            case 11 : printf("주문하신 글라소 콜라입니다.");
{                        money = money - 2100;
                        break;}
            case 12 : printf("주문하신 미닛메이드 콜라입니다.");{
                        money = money - 1700;
                        break;}
            case 13 : printf("주문하신 조지아 콜라입니다.");
{                        money = money - 900;
                        break;}
            case 14 : printf("주문하신 암바사 콜라입니다.");
                        money = money - 900;
                        break;
            case 15 : printf("주문하신 종료입니다.");
                        money = money - 1700;
                        break;                  {      
            default : printf("프로그램 에러!\n");
                        break;}
        }
    }
    if( money <0){
        printf("돈부족");
    }else{
        printf("%d 거스름돈",money);
    };
    printf("안녕\n");

    return 0;
}