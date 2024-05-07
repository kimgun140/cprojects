// 안중요 chap.1,2
// 중요 chap.33p 157p chap.5 
// chap.6 roop dowhile 중첩루프
// 챕터 7 333p 보지마라
// 배열과 포인터 문자열과 함수
// 12챕터 저장클래스 메모리 
// 챕터14구조체
// 챕터 17패스
// 반갑다 논리야
// //chcount.c -- 논리연산자 and를 사용한다.
// #include<stdio.h>
// #define PERIOD '.'
// int main(void){
//     int ch;
//     int charcount = 0;

//     while ((ch = getchar()) != PERIOD);{
//         if ( ch != '"' && ch!= '\''){
//             charcount++;
//         }
//         printf("따옴표를 빼고, 문자는 %d개가 들어 있습니다.\n", charcount);
//     }
//     return 0;
// }

// wordcnt.c -- 문자수 단어수 라인수를 카운트한다.
// #include<stdio.h>
// #include<ctype.h>
// #include<stdbool.h>
// #define STOP '|'
// int main(void){
//     char c;
//     char prev;
//     long n_chars = 0L;
//     int n_lines = 0;
//     int n_word = 0;
//     int p_lines = 0;
//     bool inword = false;

//     printf("분석할 영문 텍스트를 입력하시오 (끝내려면|):\n");
//     prev = '\n';
//     while ((c = getchar()) != STOP){
//         n_chars++;
//         if (c== '\n'){
//             n_lines++;
//         }
//         if (!isspace(c) && !inword){
//             inword = true;
//             n_word++;
//         }
//         if (isspace(c) && inword){
//             inword = false;
//         }
//         prev = c;
//     }
//     if (prev != '\n'){
//         p_lines = 1;
//     }
//     printf("문자 수 =  %ld, 단어 수 = %d, 라인수 = %d,",n_chars,n_word,n_lines);
//     printf("불완전한 라인 수 = %d\n", p_lines);
// return 0;
// }
// //paint.c 조건 연산자를 사용한다.
// #include<stdio.h>
// #define COVERAGE 350
// int main(void){
//     int sq_feet;
//     int cans;

//     printf("페인트로 칠할 면적을 평반피트 단위로 입력하시오:\n");
//     while(scanf("%d", & sq_feet) == 1){
//         cans = sq_feet / COVERAGE;
//         cans += (sq_feet % COVERAGE == 0) ? 0 : 1;
//         printf("페인트 %d통(%s)을 구입해야 한다.\n",cans, cans ==1 ? "can" : "cans");
//         printf("다음 값을 입력하시오(끝내려면 q): \n");
//     }
// return 0;
// }






// continue 를 만나면 그자리에서 다시 반복문의 시작으로 돌아가서 다시 시작한다. 
//  스위치케이스문 여러번 else if쓸데 사용가능?간단한 질문을 확인하는게 편함
// //skippart.c -- continue를 사용하여 루프를 일부를 건너 뛴다.
// #include<stdio.h>

// int main(void){

//     const float MIN = 0.0f;
//     const float MAX = 100.0f;

//     float score;
//     float total = 0.0f;
//     int n = 0;
//     float min = MAX;
//     float max = MIN;
//     printf("첫 번째 스코어를 입력하시오(끝내려면q):");
//     while( scanf("%f", &score) == 1){
//         if (score < MIN || score > MAX){
//             printf("%0.1f: 유효한 값이 아닙니다. 다시입력하시오:",score);
//             continue; //while 루프 테스트 조건을 점프한다.    
//         }
//         printf("%0.1f: 유효한 값입니다.\n", score);
//         min = (score <min)? score: min;
//         max = (score > max)? score: max;
//         total += score;
//         n++;
//         printf("다음 스코어를 입력하시오(끝내려면 q):");
//     }        
//     if (n>0){
//         printf("스코어 %d개의 평균은 %0.1f입니다.\n",n,total /n);
//         printf("최저 = %0.1f, 최고 = %0.1f\n",min,max);
//     }
//     else{
//         printf("유효한 값을 전혀 입력하지 않았습니다.\n");
//     }
// return 0;
// }




// // break.c 루프를 벗어나기 위해 break를 사용한다.
// #include<stdio.h>

// int main(void){
//     float length,width;
//     printf("사각형의 길이를 입력하시오(종료는 q):\n");
//     while(scanf("%f", &length) == 1){
//         printf("길이 = %0.2f:\n", length);
//         printf("너비를 입력하시오:\n");
//         if (scanf("%f", &width) != 1){
//             break;
//         }
//         printf("너비 = %0.2f: \n", width);
//         printf("넓이 = %0.2f:\n", length * width);
//         printf("사각형의 길이를 입력하시오(종료는 q):\n");
//     }
//     printf("종료!\n");
        
// return 0;
// }

// // animals.c -- switch 문을 사용한다
// #include<stdio.h>
// #include<ctype.h>
// int main(void){
//     char ch;
//     printf("알파벳 글자를 입력하시오.");
//     printf("그러면 내가 \n 그 글자로 시작하는 동물 이름을 하나 대겠습니다.\n");
//     printf("글자를 하나 입력하시오(끝내려면q):\n");
//     while((ch = getchar())!= '#'){
//         if('\n' == ch){
//             continue;
//         }
//         if(islower(ch)){
//             switch (ch)
//             {
//             case 'a':
//                   printf("argali, 아시아의 야생 양\n");
//                                 break;
//             case 'b' :
//                    printf("babirusa, 말레이 반도의 야생 돼지\n");
//                                 break;
//             case 'c' :
//                    printf("coati\n");
//                                 break;
//             case 'd':
//                    printf("desman:\n"); 
//                                 break;
//             case 'e' :
//                      printf("echidna,\n");
//                                 break;
//             case 'f':
//                     printf("fisher,\n");
//                                 break;
//             default:
//                     printf("에이, 너무어렵다!\n");   
//             }
      
//         } 
//         else{
//             printf("나는 소문자만 알아듣는다.\n");
//         }
//         while (getchar() != '\n'){
//             continue;
//         }
//         printf("다른 글자를 하나 입력하시오(끝내려면 #):\n");
//     }
//     printf("안녕!\n");
    
//     return 0;
// }

// // vowels.c -- 한 문장에 다수의 레이블을 사용한다.
// // 간단한 질문을 처리한다? 있는지 없는지? 이런종류의 간단한 질문/???

// #include<stdio.h>
// int main(void){
//     char ch;
//     int a_ct,e_ct,i_ct,o_ct,u_ct;
//     a_ct = e_ct = i_ct = o_ct= u_ct = 0;

//     printf("간단한 영문 텍스트를 입력하시오(끝내려면#):\n");
//     while( (ch = getchar()) != '#'){
//         switch (ch){
//             case 'a':
//             case 'A':a_ct++;
//                     break;
//             case 'e':
//             case 'E':e_ct++;
//                     break;
//             case 'i': 
//             case 'I':i_ct++;
//                     break;
//             case 'o':
//             case 'O':o_ct++;
//                     break;
//             case 'u':
//             case 'U':u_ct++;
//             default : break;
//         } //스위치 끝
//     }//while끝
//     printf("모음의 수: A    E   I   O   U\n");
//     printf("        %4d %4d %4d %4d %4d\n", a_ct,e_ct,i_ct,o_ct,u_ct);
//     return 0;
// }
// #include<stdio.h>
// int main(void){
//     int weight, height;
//     printf("무게, 키를 입력하세요:");
//     scanf("%d %d",&weight,&height);
//     if (weight < 100 && height >64){
//         if (height >72){
//         printf("몸무게에 비해 키가 너무 크네요.\n");
//         }
//         else if(height <72 && height> 64){
//             printf("몸무게에 비해 키가 조금 크네요.\n");
//         }
//     }
//     else if(weight >= 300 && height <48){
//         if(height <48){
//             printf("몸무게에 비해 키가 아주 작네요.\n");
//         }
//     else{
//         printf("이상적인 몸무게 입니다.\n");
//     }
//     }
//  return 0;   
// }
// //
// 5번문제
// #include<stdio.h>
// int main(void){
//     int num ;
//     for (num = 1; num <=11; num++){
//         if (num % 3 == 0){
//             putchar('$');
//         }else
//             putchar('*');
//             putchar('#');
//             putchar('%');
        
//     }
//     putchar('\n');
//     return 0;
// }
// 6번문제
// #include<stdio.h>
// int main(void){
//     int i = 0;
//     while(i <33){
//         switch(i++){
//             case 0 : printf("fat ");
//             case 1 : printf("hat ");
//             case 2 : printf("cat ");
//             default: printf("Oh no!");
//         }
//         putchar('\n');
//     }

//     return 0;
// }

// //7번문제
// #include<stdio.h>
// int main(void){
//     char ch;
//     int lc = 0;
//     int uc = 0;
//     int oc = 0;

//     while((ch =getchar()) != '#'){
//         if (ch >='a' && ch<='z'){
//             lc++;
//         }else if (ch >='A' && ch <='Z'){
//             uc++;
//         }else
//                 oc++;
//     }
//     printf("소문자 %d개, 대문자 %d개, 기타 문자 %d개 \n", lc,uc,oc);
//     return 0 ;
// }

// // 8번문제
// #include<stdio.h>
// int main(void){
//     int age = 20;
//     while( age++ <= 65){
//         if ((age % 20) == 0){
//             printf("%d세입니다. 승진할 나이입니다.\n",age);
//         }
//         if(age == 65){
//             printf("%d세입니다. 퇴직할 나이입니다.\n",age);
//         }
//     }
//     return 0 ;
// }


// //9번문제
// q
// c
// h
// b
// #include<stdio.h>
// int main(void){
//     char ch;
//     while((ch = getchar()) != '#'){
//         if (ch == '\n'){
//             // continue;
//         }
//         printf("1단계\n");
//         if ( ch == 'c'){
//             // continue;
//         }
//         else if (ch == 'b'){
//             break;
//         }
//         else if (ch == 'h'){
//         printf("3단계\n");
//         }
//         printf("2단계 \n");
    
//     }
//     printf("종료\n");
//     return 0;

// }
// //프로그래밍 연습
// //1번
// #include<stdio.h>
// #define SPACE ' '
// #define ENTER '\n'
// int main(void){

//     char ch ;
//     int cnt_s = 0;
//     int cnt_e = 0 ;
//     int cnt_o = 0;
//     while((ch = getchar()) != '#'){
//         if ( ch == SPACE){
//             cnt_s++;
//         }else if (ch == ENTER){
//                 cnt_e++;
//         }else{
//             cnt_o++;
//         }
//     }
//     printf("%d %d %d", cnt_s,cnt_e,cnt_o);
//     return 0;
// }
// //2번문제
// #include<stdio.h>
// int main(void){
//     char ch;
//     int cnt = 0;
//     while((ch = getchar()) != '#'){
        
//         printf("%4d %4c ",ch,ch);
//         cnt++;
//         if (cnt %8 ==0){
//             printf("\n");
//         }
//     }
    
//     return 0;
// }
// // 3번문제
// #include<stdio.h>
// #define  ZERO 0
// int main(void){
    
//     int num ; //입력 숫자
//     int even = 0; //짝수 개수
//     int even_P = 0; // 다 더한 값
//     int odd = 0; // 홀수 개수
//     int odd_P = 0; // 다 더한 값
//     while((scanf("%d", &num)) !=ZERO){
//             printf("입력점");
//             if (num %2 ==0 ){
//                 even++;
//                 even_P = even_P +num;
//             }else{
//                 odd++;
//                 odd_P = odd_P +num;
//             }
//     }
//         printf("%d %d %d %d",even,(even_P/even), odd,(odd_P/odd));
 
//         return 0;
// }

//4번문제
#include<stdio.h>
int main(void){
    char ch ;
    int cnt = 0;
    while((ch = getchar()) !='#'){
        if (ch != '.' && ch !='!'){
            printf("%c",ch);
        }else if(ch =='.'){
            printf("!");
            cnt++;
        }else if(ch =='!'){
            printf("!!");
            cnt++;
        }
    }printf("%d",cnt);

    return 0;
}

// // 5번문제 ㅁㄹ
// #include<stdio.h>
// int main(void){
//     char ch ;
//     int cnt = 0;
//     while( (ch = getchar())!='#'){
       
//             switch(ch){
//                 case '.':printf("!");
//                         break;
//                 case '!':printf("!!");
//                         break;
//                 default : printf("%c",ch);
//             }
        
//     }
//     return 0;
// }

// // 6번문제 ㅁㄹ
// #include<stdio.h>
// int main(void){
//     char ch;
//     int cnt = 0 ;
//     while((ch = getchar())!='#'){
//         if (ch == ('e')){
//             cnt++;
            
//         }
        
//     }
//     printf("%d", cnt);
//     return 0;
// }


// // 7번문제

// #include<stdio.h>

// int main(void){
//     float gross =0.00;
//     float taxes = 0.00;
//     float net = 0.00; 
//     float work =0.00 ;
//     float basic = 0.00; // 기본급 시간당 10.00
//     float over; //  초과근무수당
//     printf("입력하세요");
//     while ((scanf("%f", &work)) !=0){
//                 basic = work * 10;
//             if( work >40){
//                 over = (work * 15.00) - basic;
//                 gross = over + basic;
//             }
//             if (gross <=300){
//                 taxes = (gross * 0.15);
//                 net = gross - taxes;
//             }else if (gross <=450){
//                 taxes = gross * 0.2;
//                 net = gross - taxes;
//             }else{
//                 taxes = gross * 0.25;
//                 net = gross - taxes;
//             }
//                 printf("%f %f %f %f %f",basic,over, gross,taxes,net);

//     }

//     return 0 ;
// }

//8qjs