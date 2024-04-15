#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 
#define EXP_MAX 30000       //1레벨 최대 경험치

int main(void)
{

    srand((unsigned)time(NULL));
    char name [20];         //캐릭터 이름
    float exp = 0;          //현재 경험치
    int exp_up = 0;         //경험치 증가량
    int turn = 0;           //턴
    int level = 1;          //레벨
    float exp_max = 30000;  //최대 경험치 
    float prev_max = 0;     //이전 레벨 최대 경험치
    float exp_range;        //최대경험치 증가량 배수
    float event;            //경험치 증가량 배수
    int go;                 //프로그램 종료를 물어보는 변수
    

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
    scanf("%s", name);      //이름 입력

    while (1)
    {
        exp_up = 0;

        for (int i = 0; i < 5; i++)           //경험치 획득
        {
            exp_up += rand() % 7000 - 3500;   //-3500에서 3500까지 랜덤 
        }
        
        if (exp_up>0)       //경험치 증가량이 양수일때만 이벤트 발생 (음수면 너무 자주 죽어서 수정)
        {
            event = ((rand() % 41) + 10)*0.1; //이벤트는 경험치 증가량에 1.0~5.0배
            exp_up = exp_up*event;
        }
        turn += 1;
        exp += exp_up;

        if(exp >= exp_max)  //경험치가 최대경험치보다 높으면 레벨업   
        {
            level = level + 1;
            exp = exp - exp_max;             //최대 경험치보다 높았던 만큼 경험치에 잔여
            exp_range = (rand()%(26-18)+18)*0.1;;
            if (level<99)                    //99레벨보다 작으면 최대경험치가 증가
            {
                prev_max = exp_max;
                exp_max+=EXP_MAX*exp_range;  //최대 경험치는 1레벨 최대경험치에 1.8배에서 2.5배만큼 더함
            }
            else            //99레벨이면 게임 승리
            {
            printf("===================축하합니다 레벨 99를 달성했습니다.====================\n");
            printf("\n%s의 현재 경험치 %.2f/%.2f 레벨%d 턴%d\n",name,exp,exp_max,level, turn);
            printf("다시하겠습니까?(진행할려면 1을 종료할려면 2를 입력): ");
            scanf("%d",&go);
            turn = 0;       //수치 초기화
            exp = 0;            
            exp_max = 30000;    
            turn = 0;           
            prev_max = 0;
            level = 1;          
            if (go == 1)
                continue;
            else
                break;
            }
        }

        if (exp < 0)        //경험치가 0보다 낮으면 레벨 다운
        {
            level = level - 1;
            exp = exp + prev_max;   //경험치가 0보다 낮은만큼 이전번 최대 경험치에 더함
            exp_max = prev_max;

            if (level <= 0)         //레벨이 1일때 레벨 다운이 일어났으면 게임오버
            {
                exp = exp - prev_max;
                printf("\n=================== 이런이런 망했네요 ㅜㅜ ================================\n");
                printf("\n%s의 현재 경험치 %.2f/%.2f   턴%d\n",name,exp,exp_max, turn);
                printf("다시하겠습니까?(진행할려면 1을 종료할려면 2를 입력): ");
                scanf("%d",&go);
                turn = 0;           //수치 초기화
                exp = 0;            
                exp_max = 30000;    
                prev_max = 0;
                turn = 0;           
                level = 1;          
                if (go == 1)
                    continue;
                else
                    break;
            }
        }
        printf("\n%s의 현재 경험치 %.2f/%.2f 레벨%d 턴%d\n",name,exp,exp_max,level, turn);
        //턴이 진행될 때 마다 확인할 수 있게 출력
    }
    printf("종료되었습니다.\n");

    return 0;
}
