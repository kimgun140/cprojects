// chapter.8 문자 입출력과 입력 유효성 검사
// 파일 입출력 *버퍼* 중요*
// 리스트 8.1 echo.c -- 입력을 반복한다.

// #include<stdio.h>
// int main(void){
//     char ch;
//     while ((ch= getchar()) != '#')
//         putchar(ch);
//     return 0;
// }   
// 버퍼에 입력된걸 받아주고 버퍼에서 입력받은거 비워준다.
// 버퍼의 작동방법이다, 입력하면 버퍼에 하나씩 들어갔다가 출력할때 
//하나씩 출력된다.
// 다만 게임같은 경우 키보드입력이 즉각적으로 이뤄져야하는 경우에는 버퍼를 
//거치지않고 즉시 프로그램에 이용할 수 있게 한다.

//버퍼링 버퍼링은 두 가지의 경우악 있다 완전 버퍼링입출력과 라인 -버퍼링 입출력이있다.
// 완전 버퍼링: 버퍼가 가득 찼을때만 비워진다ㅏ. 이경우는 일반적이 파일입력에서 사용한다.
// 라인 버퍼링: 개행 문자가 나타날 때 마다 버퍼가 비워진다. 일반적으로 키보드입력은 버퍼링 입력이다. 그래서 엔터키를 누르면 버퍼가 비워진다.

//키보드 입력 끝내는 방법
// EOF  stdio.h에 포함되어있다. eof끝
// 리스트8.2 echo_eof.c -- 파일의 끝까지 입력을 에코한다.
// #include<stdio.h>
// int main(void){
//     char ch;
//     while((ch = getchar())!=EOF)
//     putchar(ch);
//     return 0;
// }


//리스트 8.4 guess.c --수 맞추기 프로그램(비효율적이고 잘못되었다.)

// #include<stdio.h>
// int main(void){
//     int guess = 1;
//     printf("1에서 100까지 범위에 있는 한 정수를 생각하시오.\n");
//     printf("내가 추축하지요. 내 추측이 맞으면 y로 응답하고, \n");
//     printf("내 추측이 틀리면 n으로 응답하시오.\n");
//     printf("당신이생각한 수가 %dl입니까?", guess);
//     while(getchar()!= 'y')
//         printf("그러면 %d입니까?\n", ++guess);
//         while( getchar()!= '\n')
//             continue;// 입력라인의 나머지는 건너뛴다.
//     printf("그것 봐요, 내가 맞출 수 있다고 했잖아요\n");

//     return 0;
// }


//리스트 8.6 showchar2.c -- 지정한 행 수와 열 수만큼 문자들을 출력한다.

// #include<stdio.h>
// void display(char cr, int lines, int width);
// int main(void){
//     int ch;         //출력할 문자
//     int rows, cols; // 행 수와 열 수
//     printf("문자 하나와 두 개의 정수를 입력하시오.\n");
//     while((ch = getchar()) != '\n')
//     {
//         if (scanf("%d %d", &rows, &cols) != 2)
//             break;
//         display(ch, rows, cols);
//         while (getchar() != '\n')
//             continue;
//         printf("또 다른 문자와 두 개의 정수를 입력하시오.\n");
//         printf("끝내려면 그냥 Enter 키를 누르시오.\n");
//     }
//     printf("안녕!\n");

//     return 0 ;
// }
// //함수를 호출을 하는거고, 메인함수 밖에서 정의를 한다. 
// void display(char cr, int lines, int width)
// {
//     int row, col;
//     for (row = 1; row<=lines; row++){
//         for (col =1; col <=width; col++)
//         putchar(cr);
//     putchar('\n'); //라인을 끝내고 새 라인을 시작한다.
//     }
// }


// //리스트8.7 checking. -- 입력의 유효성을 검사한다.
// #include<stdio.h>
// #include<stdbool.h>
// long get_long(void);
// //범위 한계가 유효한지 검사한다
// bool bad_limits(long begin, long end, long low, long high);
// //a에서 b까지의 범위에 있는
// //정수들의 제곱의 합을 계산한다.

// double sum_squares(long a, long b);
// int main (void)
// {
//     const long MIN = -100000000L; //범위의 하한
//     const long MAX = +100000000L; // 범위의 시작
//     long start; //범위의 시작
//     long stop;// 범위의 마감
//     double answer;

//     printf("이 프로그램은 어떤 범위에 있는 정수들의 제곱의 합을 계산한다.\n"
//     "범위의 시작값은 -100000000보다 작을 수 없다.\n"
//     "범위의 마감값은 +100000000보다 클 수 없다.\n"
//     "시작값과 마감값을 입력하시오.\n"
//     "(끝내려면 두 값을 모두 0으로 입력): \n 범위의 시작값: ");

//     start = get_long();
//     printf("범위의 마감값: ");
//     stop = get_long();
//     while( start !=0 || stop !=0){
//         if (bad_limits(start, stop, MIN, MAX))
//         printf("범위를 다시 지정하시오\n");
//         else{
//             answer = sum_squares(start,stop);
//             printf("정수들의 제곱의 합");
//             printf("%ld에서 %ld까지의 범위에 있는 정수들의 제곱의 합은 %g입니다.\n", start, stop, answer);
//         }
//         printf("시작값과 마감값을 입력하시오.\n"
//         "끝내려면 두 값을 모두 0으로 입력: \n" );
//         printf("범위의 시작값: ");
//         start = get_long();
//         printf("범위의 마감값: ");
//         stop = get_long();
//     }
//     printf("종료!\n");
//     return 0;
// }
// long get_long(void){
//     long input;
//     char ch;
//     while(scanf("%ld", &input) !=1){
//         while((ch = getchar()) != '\n')
//         putchar(ch); // 잘못된 입력을 폐기한다
//     printf(": 정수가 아닙니다. \n25, -178, 3과같은 ");
//     printf("정수값을 입력하시오: ");
//     }
//     return input;
// }
// double sum_squares(long a, long b){
//     double total = 0;
//     long i;

//     for (i =a; i <=b; i++)
//         total += (double)i * (double)i;

//     return total;
// }

// bool bad_limits(long begin, long end, long low, long high){

//     bool not_good =false;

//     if (begin > end){

//         printf("시작값은 마감값보다 크면 안 됩니다.\n");
//         not_good = true;
//     }
//     if (begin < low || end < low){
//         printf("시작값과 마감값은 %ld보다 크거나 같아야 합니다.\n", low);
//         not_good = true;
//     }
//     if (begin > high || end > high){
//         printf("시작값과 마감값은 %ld보다 작거나 같아야합니다.\n", high);
//         not_good = true;
//     }

//     return not_good;
// }

//리스트 8.8menuette.c -- 메뉴 테크닉

#include<stdio.h>
char get_choice(void);
char get_first(void);
int get_int(void);
void count(void);
int main(void){
    int choice;
    void count(void);

    while ((choice = get_choice()) !='q'){
        switch (choice){
            case 'a' : printf("쌀 때 사서 비쌀 때 파시오.\n");
                        break;
            case 'b' : putchar('\a');
                        break;
            case 'c' : count();
                        break;
            default : printf("프로그램 에러!\n");
                        break;
        }
    }
    printf("안녕\n");

    return 0;
}

void count(void){
    int n ,i;

    printf("몇까지 카운트할까요? 정수 하나를 입력하시오: \n");
    n = get_int();
    for (i = 1; i <= n; i++)
    printf("%d\n", i);
    while (getchar() != '\n')
        continue;
}
char get_choice(void){
    int ch; 
    printf("a,b,c,q중에서 하나를 선택하시오:\n");
    printf("a. 조언                 b.경고\n");
    printf("c. 카운트                   q.종료\n");
    ch = get_first();
    while((ch < 'a' || ch > 'c') && ch !='q'){
        printf("a,b,c,q 중에서 하나를 선택해야 합니다.\n");
        ch = get_first();
    }

    return ch;
}


char get_first(void){
    //처음 입력받는 숫자를 공백인지 확인하고 맞으면 반환
    int ch;

    ch = getchar();
    while( getchar() != '\n')
            continue;
        
    return ch;
}

int get_int(void){
    // 숫자를 판별하기
    int input;
    char ch;

    while(scanf("%d" ,&input) !=1){
        while ((ch = getchar()) != '\n')
            putchar(ch);
        printf(": 정수가 아닙니다. \n25, 178, 3과 같은 ");
        printf("정수값을 입력하시오: ");
    }
    return input;
}