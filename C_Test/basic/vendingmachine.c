
#include<stdio.h>
char get_choice(void);
char get_first(void);
int get_int(void);
void count(void);
int get_money(void);
int money;
int main(void){
    int choice;
    void count(void);
        
    money =  get_money();
    printf("돈냈으면 주문 ㄱㄱ");
    while ((choice = get_choice()) !='q'){
        switch (choice){
            case 1 : printf("주문하신 콜라입니다. 씨발.\n");
                        break;
            case 2 : printf("주문하신 우주0맛 콜라입니다.");
                        break;
            case 3 : printf("주문하신 우주맛 콜라입니다.");
                        break;     
            case 4 : printf("주문하신 제로 콜라입니다.");
                        break;
            case 5 : printf("주문하신 스프라이트 콜라입니다.");
                        break;
            case 6 : printf("주문하신 환타 콜라입니다.");
                        break;
            case 7 : printf("주문하신 닥터페퍼 콜라입니다.");
                        break;
            case 8 : printf("주문하신 몬스터 콜라입니다.");
                        break;
            case 9 : printf("주문하신 파워에이드 콜라입니다.");
                        break;
            case 10 : printf("주문하신 네스트 콜라입니다.");
                        break;
            case 11 : printf("주문하신 글라소 콜라입니다.");
                        break;
            case 12 : printf("주문하신 미닛메이드 콜라입니다.");
                        break;
            case 13 : printf("주문하신 조지아 콜라입니다.");
                        break; 
            case 14 : printf("주문하신 암바사 콜라입니다.");
                        break;
            case 15 : printf("주문하신 종료입니다.");
                        break;                         
            // default : printf("프로그램 에러!\n");
            //             break;
        }
    }
    printf("안녕\n");

    return 0;
}
int get_money(void){
    int money;
    char ch;

    while(scanf("%d" ,&money) !=0){
        printf("돈 ㄱㄱ");
        // while ((ch = getchar()) != '\n')
        //     putchar(ch);
        // printf(": 정수가 아닙니다. \n1,2,3,10,100,100000과 같은 ");
        // printf("값을 입력하시오:\n ");
        if (money <100){
            printf("돈이 부족합니다.\n");
            printf("돈 다시주세요\n");
            continue;
            // 음료가격보다 작을 때를 만들어야겠다
            // get_first에서 1부터 15의 숫자를 가져온다.
        }//else if(money)
    
    }
    return money;
}
char get_first(void){
    // 입력받은 값이 공백인지 판별 공백이면 다시 처음부터 아니면 다음 메뉴선택으로 리턴값은 문자
    int ch;

    // ch = scanf("%d",&ch);
    printf("입력 플리즈");
    scanf("%d",&ch);

    return ch;
}
char get_choice(void){
    // get first에서 받은 메뉴 숫자로 메뉴 선택하기
    char ch; 
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

    ch = get_first();
    while((ch > 16 && ch < 0)){
        //1~15까지 숫자를 입력받지못하면 반복한다.
        printf("하나를 선택해야 합니다.\n");
        ch = get_first();
    }
    return ch;
}
// int cal(void){
//     int cal_money;
        
// }

int get_int(void){
    int input;
    char ch;
    //정수인지 아닌지 판별하

    while(scanf("%d" ,&input) !=0){
        while ((ch = getchar()) != '\n')
            putchar(ch);
        printf(": 정수가 아닙니다. \n1~15와 같은 ");
        printf("값을 입력하시오: ");
    }
    return input;
}



void count(void){
    int n ,i;

    // printf("몇까지 카운트할까요? 정수 하나를 입력하시오: \n");
    n = get_int();
    if ( n == 1){
        printf("콜라 1200");
    }

    // for (i = 1; i <= n; i++)
    // printf("%d\n", i);
    // while (getchar() != '\n')
    //     continue;
}