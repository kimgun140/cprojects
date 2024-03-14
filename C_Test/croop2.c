//// sweetie2.c -- for 를 사용하는 카운팅 루프
// #include<stdio.h>
// int main(void)
// {
//     const int NUMBER = 22;
//     int count;

//     for( count = 1; count<= NUMBER; count++)
//         printf("달콤한 나의 발렌타인!\n");

//     return 0;
// }


// // for_ cube.c -- for 루프를 사용하여 세제곱 표를 만든다.
// #include<stdio.h>
// int main(void)
// {
//     int num;
//     printf("    n\t n의 세제곱\n");
//     for (num = 1; num <= 6; num++)
// // 위의 식을 아래식으로 대체할 수 있다.세제곱의 크기를 제한하고싶을 때 사용할 수 있는 방식이다.
//// 이런식으로 검사조건을 활용할 수 있는 방법을 생각해보자
// // for(num = 1; num*num*num <=216; num ++)

// //조건식      시작값   마지막값?  증가식
//     {
//         printf("%5d %5d\n", num, num*num*num);
//         // easy
//     }
//     return 0;
// }

// // for_down.c
// #include<stdio.h>
// int main(void)
// {
//     int sec;
//     for (sec  = 5; sec < 100; sec = sec +13)
//     {
//         printf("%d초!\n", sec);
//     }
//     return 0;
// }

// //  for_char.c
// #include<stdio.h>
// int main(void)

// {
//     char ch;
//     for ( ch = 'a'; ch <= 'z'; ch++)
//     //반복문으로 문자를 카운트 할 수 있다.
//     // 이게 동작하는 이유는 실제로 문자가 저장될때는 정수로 저장되고 그 정수값을 증가식만큼 세어서 
//     // 프린트할때 지정자를 통해서 출력이 되는것이다.
//     // 중요한점은 문자도 저장될때는 정수 즉 숫자로 저장된다는 점이다.
//     {
//         printf("%c에 해당하는 ASCII코드 값은 %d입니다.\n", ch,ch);
//     }
    
    


//     return 0;
// }


// // for_ego.c
// #include<stdio.h>
// int main(void)
// {
//     double debt;
//     for (debt  = 100.0; debt < 150.0; debt = debt * 1.1)
// // debt = debt * 1.1 를  debt * 1.1 로 오기 했더니 무한루프에 빠지게되었다.
// // 왜 이렇게 된걸까? 생각해보니 증감식으로 debt값을 점점 증가 시켜야하지만 하지않았더니
// //루프를 종료할떄로 진행하지 못한것이다. ㅇㅋ? ㅇㅋ
//     {
//         printf("당신의 신용불량채무 이제 $%.2f입니다.\n", debt);
//     }
    
//     return 0;
// }
//// for_wild.c
// #include<stdio.h>
// int main(void)
// {
//     int x;
//     int y = 55;
//     for (x =1; y <= 75; y = (++x * 5)+50)
//     {
//         printf("%10d %10d\n", x, y);
//     }
//     return 0;
// }
// // do_while.c -- 탈출 조건 루프
// #include<stdio.h>
// int main(void)
// {
//     const int secret_code = 13;
//     int code_entered;

//     do
//     {
//         printf("13일의 금요일 공포중 치료 동호회에 들어오려면,\n");
//         printf("비밀 코드번호를 입력하시오:");
//         scanf("%d", &code_entered);
//     } while (code_entered != secret_code);
//     printf("축하합니다! 치료되었습니다.\n");
    
//     return 0;
// }


// // 중첩루프를 사용한다.
// #include<stdio.h>
// #define ROWS 6
// #define CHARS 10
// int main(void)
// {
//     int row;
//     char ch;

//     for (row = 0; row <ROWS; row++)
//     // 아래 반복문에서 알파벳을 10개씩 6줄을 반복할 때
//     {
//         for (ch = 'A'; ch <('A' + CHARS); ch++)
//         // a~j까지 10개의 알바펫을 출력한다. 1개씩 증가한다.
//         printf("%2c", ch);
//     printf("\n");
//     }
//     return 0;
// }

// // rows2.c -- 의존적인 중첩루프를 사용한다.
// #include<stdio.h>
// int main(void)
// {
//     const int ROWS = 6;
//     const int CHARS = 6;
//     int row;
//     int ch;
//     for (row = 0; row < ROWS; row++)
//     {
//         for (ch  = ('A' + row); ch<('A'+CHARS); ch++)
//         {
//             printf("%c",ch);
            
//         }
//         printf("\n");
        
//     }
    
//     return 0;
// }
// 문자열은 컴퓨터가 전체를 하나로 보고 
// 문자배열은 하나하나의 요소를 다룰 수 있다.
// 문자열의 요소를 수정할 때는 배열로 바꿔서 수정이 가능하게 만들어준다.
//  아무튼 문자열이랑 문자 배열은 다르긴하다..



// score.c -- 배열 처리에 루프를 사용한다.
#include<stdio.h>
#define SIZE 10
#define PAR 72

int main(void)
{
    int index,score[SIZE];
    int sum = 0;
    float average;

    printf("%d개의 골프 스코어를 입력하시오:\n", SIZE);
    for (index = 0; index< SIZE; index++)
    {scanf("%d", &score[index]); // 10개의 골프 스코어 읽기
    }
    printf("읽은 스코어들은 다음과 같다.\n");
    for (index = 0; index <SIZE; index++)
    {
        printf("%5d", score[index]);
    }
    printf("\n");
    for (index = 0; index <SIZE; index++)
        {
            sum+= score[index];//모두 더하기
        }
    average = (float)sum / SIZE; //평균구하기  sum을 명시적인 형변환을 해서 float으로 바꿔줌  
    printf("스코어의 합 %d, 평균 = %2f\n", sum, average);
    printf("핸디캡이 %0.1f이다.\n", average - PAR); 
    //여기서 문자열을 읽어온건가? 문자배열이면 반복문으로 한번에 가져오고?
    //  리스트와 반복문과 비슷한 내용이다. 문법이 달라졌다.
    return 0;
}