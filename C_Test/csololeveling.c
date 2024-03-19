// #include<stdio.h>
// #include<stdlib.h>
// #include <time.h>
// int main(void){
//     int level = 1;
//     int turn = 0;
//     float exp = 0;
//     int exp_max = 30000;
//     float exp_up = 0;

//     srand((unsigned int)time(NULL)); //seed값으로 현재시간 부여 
//     float aa = (rand()%(50-10+1)+10)*0.1; 
//     // float aa = (rand()%(25-18+1)+18)*0.1; 
//     printf("%lf\n", aa);
//     // printf("%lf asdasdas\n", (rand()%(50-10+1)+10)*0.1);
//     // 이벤트
//     // rand()*7000-3500;
//     exp_up = exp_up*aa ;
//     printf("%.1lf\n", exp_up);
//     turn += 1;

//     printf("===================축하합니다 레벨 99를 달성했습니다.====================\n");
//     printf("%4d 레벨까지  %4d 턴이 걸렸습니다. \n",level,turn);

//     printf("===================이런이런 망했네요 ㅜㅜ================================\n");
//     printf("%d턴만에 이렇게 되어버리다니 ㅜㅜ\n", turn);



//     return 0;
// }




#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 

int main(void)
{
    srand((unsigned)time(NULL));
    char name [20];         //캐릭터 이름
    float exp = 0;            //현재 경험치
    const float EXP_MAX = 30000; //상수 경험치 30000 초기값
    float exp_max;    //현재 필요 경험치량
    int exp_up = 0;         //경험치 증가량
    int turn = 0;           //턴
    int level = 1;          //레벨
    float exp_event;    /*1.8~2.5사이의 랜덤 값 지정*/
    float exp_range;    /*전체 max 설정 값* 랜덤*/


    puts("■  □  ■  □  ■  □  ■  □  ■  □  ■  □  ■  □  ■  □  ■  □  ■  □  ■  □  ■  □  ■");
    puts("□                                                                       □");
    puts("■                                                      고고 키티 건     ■");
    puts("□                          __,,,,_                   \t\t\t□");
    puts("■            _ ___.--'''`--''// ,-_ `-.              \t\t\t■");
    puts("□        \\`\"' ' |  \\  \\ \\/ / // / ,-  `,_            \t\t\t□");
    puts("■       /'`  \\   |  Y  | \\|/ / // / -.,__ `-.        \t\t\t■");
    puts("□      /<\"\\    \\ \\  |  | ||/ // | \\/    |`-._`-._    \t\t\t□");
    puts("■     /  _.-.  .-\\,___|  _-| / \\ \\/|_/  |    `-._    \t\t\t■");
    puts("□     `-'  f/ |       / __/ \\__  / |__/ |            \t\t\t□");
    puts("■          `-'       |  -| -|\\__ \\  |-' |            \t1. 시작하기\t■");
    puts("□                 __/   /__,-'    ),'  |'            \t\t\t□");
    puts("■                ((__.-'((____..-' \\__,'             \t2. 종료하기\t■");
    puts("□                                                                       □");
    puts("■  □  ■  □  ■  □  ■  □  ■  □  ■  □  ■  □  ■  □  ■  □  ■  □  ■  □  ■  □  ■");
                

    printf("\n게임을 시작합니다.\n이름을 입력해주세요: ");
    scanf("%s", name); 
         //이름 입력
    // printf("\n게임을 시작하려면 1을 입력해주세요.\n 게임을 종료하려면 0을 입력하세요 \n");
    char yn ;
    int num = 0;
    printf("입력해주세요");
    while (scanf("%c", &yn) != 'n')
    { //턴 시작
    
        exp_up = 0;
        // i는 매턴 5번 반복되는 경험치발생
        for (int i = 0; i < 5; i++) //경험치 획득
        {
            exp_up += rand() % 7000 - 3500; //-3500에서 3500까지 랜덤
            printf("경험치%d 턴 %.2d 현재경험치 %f 레벨 %d\n", exp_up, turn,exp,level);
            // printf("%f\n", exp);
        }
        

        float aa = ((rand()%(50-10+1)+10)*0.1); //이벤트
        exp_up = exp_up*aa ;
        printf("%d 이벤트 경험치\n", exp_up);
        if (exp_up <=0){
            exp_up -=exp_up;
        }
        turn += 1;

        exp += exp_up;

        exp_range=(rand()%(25-18+1)+18)*0.1;  /*1.8~2.5사이의 랜덤 값 지정*/
        if(exp >= exp_max)/*획득한 경험치가 경험치 통보다 클 때*/
         {
            level++;/*레벨++*/
            exp = exp - exp_max;/*획득경험치는 레벨업 후 남은 값*/
            if (level<99)/*99보다 작으면*/
            {
                exp_max=EXP_MAX*exp_range;/*총 경험치 값 상승*/
                printf("현재 경험치 %f 경험치 필요%f 레벨%d\n",exp,exp_max-exp,level);
            }
            else
                printf("%d턴에 클리어하셨습니다.\n",turn);
         }
        if ( (exp += exp_up) < 0) //레벨 감소
        level--; 
        printf("현재 경험치량%f",exp);
        printf("다시 시도 하시겠습니까?(Y/N)\n");
        if ( level >= 99){
        printf("===================축하합니다 레벨 99를 달성했습니다.====================\n");
        printf("%4d 레벨까지  %4d 턴이 걸렸습니다. \n", level,turn);
        break;
        }
        else if (level <=0){
        printf("===================이런이런 망했네요 ㅜㅜ================================\n");
        printf("%d턴만에 이렇게 되어버리다니 ㅜㅜ\n", turn);
        break;
        
        }
        // turn = 1;
        // if( (scanf("%c", &yn)) == 'y'){
        scanf("%c", &yn);
        continue;
        // }else{
        break;

        // }
        // scanf("%c", &yn);


        // if (level <= 0)
        //     printf("캐릭터가 사망하였습니다.\n%d턴동안 생존하셨습니다.", turn); //엔딩
            // break;
        // printf("축하합니다. 99레벨을 달성하셨습니다.\n %d턴만에 달성하셨습니다.", turn); 
        // break;
        // break;
    }


    // exp_range=(rand()%(25-18+1)+18)*0.1;  /*1.8~2.5사이의 랜덤 값 지정*/
    //     if(exp >= exp_max)/*획득한 경험치가 경험치 통보다 클 때*/
    //      {
    //         level++;/*레벨++*/
    //         exp = exp - exp_max;/*획득경험치는 레벨업 후 남은 값*/
    //         if (level<99)/*99보다 작으면*/
    //         {
    //             exp_max=exp_max*exp_range;/*총 경험치 값 상승*/
    //             printf("현재 경험치 %f 경험치 필요%f 레벨%d\n",exp,exp_max-exp,level);
    //         }
    //         else
    //             printf("%d턴에 클리어하셨습니다.\n",turn);
    //      }
    //     printf("다시 시도 하시겠습니까?(Y/N)\n");

    // if ( (exp += exp_up) < 0) //레벨 감소
    //     level--;
    //     if (level <= 1)
    //         printf("캐릭터가 사망하였습니다.\n%d턴동안 생존하셨습니다.", turn); //엔딩
    //         break;
    // printf("축하합니다. 99레벨을 달성하셨습니다.\n %d턴만에 달성하셨습니다.", turn); 
    //     break;





    return 0;
}