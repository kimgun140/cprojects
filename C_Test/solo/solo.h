
#include <time.h>
#include "solost.h"
#include <iostream>
using namespace std;
solo_level_up solo;
#define EXP_MAX 30000 // 1레벨 최대 경험치
// int start(solo_level_up & solo);
int power_level_up(solo_level_up &solo)
{
    srand((unsigned)time(NULL));
    // 새 기능 뭐 하지 레벨 한방에 99되게 만들어야겠다
    // 랜덤으로 100분이 1확률로 레벨 99되기
    if (rand() % 101 == 1)
    {
        cout << "여기야 여기!!";
        solo.level = 99;
    }
    // return 0;
}
int start(solo_level_up &solo)
{
    srand((unsigned)time(NULL));

    while (1)
    {
        solo.exp_up = 0;

        for (int i = 0; i < 5; i++) // 경험치 획득
        {
            solo.exp_up += rand() % 7000 - 3500; //-3500에서 3500까지 랜덤
        }

        if (solo.exp_up > 0) // 경험치 증가량이 양수일때만 이벤트 발생 (음수면 너무 자주 죽어서 수정)
        {
            solo.event = ((rand() % 41) + 10) * 0.1; // 이벤트는 경험치 증가량에 1.0~5.0배
            //  power_level_up(solo);

            solo.exp_up = solo.exp_up * solo.event;
        }
        solo.turn += 1;
        solo.exp += solo.exp_up;

        if (solo.exp >= solo.exp_max) // 경험치가 최대경험치보다 높으면 레벨업
        {
            solo.level = solo.level + 1;
            solo.exp = solo.exp - solo.exp_max; // 최대 경험치보다 높았던 만큼 경험치에 잔여
            solo.exp_range = (rand() % (26 - 18) + 18) * 0.1;
            // power_level_up(solo);
            ;
            if (solo.level < 99) // 99레벨보다 작으면 최대경험치가 증가
            {
                solo.prev_max = solo.exp_max;
                solo.exp_max += EXP_MAX * solo.exp_range; // 최대 경험치는 1레벨 최대경험치에 1.8배에서 2.5배만큼 더함
            }
            else // 99레벨이면 게임 승리
            {
                cout << "===================축하합니다 레벨 99를 달성했습니다.====================\n";
                cout << "\n"
                     << solo.name << "의 현재 경험치\n"
                     << solo.name << solo.exp << solo.exp_max << solo.level << "레벨" << solo.turn << "턴\n";
                cout << "다시하겠습니까?(진행할려면 1을 종료할려면 2를 입력)\n: ";
                cin >> solo.go;
                solo.turn = 0; // 수치 초기화
                solo.exp = 0;
                solo.exp_max = 30000;
                solo.turn = 0;
                solo.prev_max = 0;
                solo.level = 1;
                if (solo.go == 1)
                    continue;
                else
                    break;
            }
        }

        if (solo.exp < 0) // 경험치가 0보다 낮으면 레벨 다운
        {
            solo.level = solo.level - 1;
            solo.exp = solo.exp + solo.prev_max; // 경험치가 0보다 낮은만큼 이전번 최대 경험치에 더함
            solo.exp_max = solo.prev_max;

            if (solo.level <= 0) // 레벨이 1일때 레벨 다운이 일어났으면 게임오버
            {
                solo.exp = solo.exp - solo.prev_max;
                cout << "\n=================== 이런이런 망했네요 ㅜㅜ ================================\n";
                cout << solo.name << "의" << solo.exp << "/" << solo.exp_max << "현재경험치" << solo.turn << "턴\n";
                cout << "다시하겠습니까?(진행할려면 1을 종료할려면 2를 입력): ";
                cin >> solo.go;
                solo.turn = 0; // 수치 초기화
                solo.exp = 0;
                solo.exp_max = 30000;
                solo.prev_max = 0;
                solo.turn = 0;
                solo.level = 1;
                if (solo.go == 1)
                    continue;
                else
                    break;
            }
        }
        cout << solo.name << "의 현재 경험치 " << solo.exp << "/" << solo.exp_max << "       " << solo.level << "레벨" << solo.turn << "턴\n";
        // 턴이 진행될 때 마다 확인할 수 있게 출력
    }
    return solo.go;
}
