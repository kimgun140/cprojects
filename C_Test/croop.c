// summing/c -- 대화식으로 입력한 정수들의 합을 구한다.
// #include<stdio.h>
// int main(void)
// {
//     long num;
//     long sum = 0L;
//     int status ; 
    
//     printf("합을 구할 정수를 하나 입력하시오.");
//     printf("(끝내려면 q):");
//     status = scanf("%ld", &num);
//     while (status ==1)
//     {
//         sum = sum + num;
//         printf("다음 정수를 입력하시오(끝내려면 q):");
//         status = scanf("%ld", &num);
//         /* code */
//     }
//     printf("입력된 정수들의 합은 %ld입니다.\n", sum);
//     return 0;

// }

// when.c -- 루프는 언제 끝나는가
// #include<stdio.h>
// int main(void)
// {
//     int n =5;
//     while (n <7)
//     // 중괄호가 없으면 첫번째 줄만 반복문에 포함된다고 본다. 들여쓰기가 같은 층에 있어도 괄호가 없으면 안됨 ㅇㅋ?
//     {
//         printf("n = %d\n", n);
//         n++;
//         printf("이제 n = %d\n", n);
//         /* code */
//     }
//     printf("루프가 끝났다.\n");
    
//     return 0;

// }
// // cmpflt.c -- 부동소수점 수의 비교
// #include<stdio.h>
// #include<math.h>
// int main(void)

// {
//     const double ANSWER = 3.14159;
//     double response;
//     printf("원주율의 값이 얼마지?\n");
//     scanf("%lf", &response);
//     while (fabs(response - ANSWER) > 0.0001)
//     {
//         printf("다시 말해 봐!!\n");
//         scanf("%lf", &response);
//         /* code */
//     }
//     printf("충분히 가깝다!\n");
    
//     return 0;

// }


// // t_and_f. -- c에서의 true값과 false값
// #include<stdio.h>
// int main(void)
// {
//     int true_val, false_val;

//     true_val = (10>2);
//     false_val = (10 ==2);
//     printf("true = %d; false = %d \n", true_val, false_val);
    
//     return 0;

// }

// // truth.c -- 어떤 값들이 참인가?
// #include<stdio.h>
// int main(void)
// {
//     int n =3;
//     while (n)
//     {
//         printf("%2d: 참\n", n--);
//     }
//     printf("%3d: 거짓\n", n);
  
//     n = -3;
//     while (n)
//     {
//         printf("%2d: 참\n", n++);
//     }
//     printf("%2d: 거짓\n",n);

//     return 0;

// }


// // trouble.c -- =의 잘못된 사용
// #include<stdio.h>
// int main(void)
// {
//     long num;
//     long sum = 0L;
//     int status;
//     printf("합을 구할 정수를 하나 입력하시오");
//     printf("(끝내려면 q:)");
//     status = scanf("%ld", &num);
//     while (status == 1)
//     {   
//         sum = sum + num;
//         printf("다음 정수를 입력하시오(끝내려면 q:)");
//         status = scanf("%ld", &num);
//         // scanf는 값을 읽어오는데 실패하면 다시 시도한다. 다시 원래자리로 돌아와서 시도하지만 또실패하고 루프빠진다.
//         /* code */
//     }
//     printf("입력된 정수들의 합은 %ld입니다.\n", sum);
//     return 0;

// }
// no.1
// #include<stdio.h>
// int main(void)
// {
//     int n =0;
//     while (n <=10)
//     // 중괄호가 없으면 첫번째 줄만 반복문에 포함된다고 본다. 들여쓰기가 같은 층에 있어도 괄호가 없으면 안됨 ㅇㅋ?
//     {
//         printf("n = %d\n", n);
//         n++;
//         printf("이제 n = %d\n", n);
//         /* code */
//     }
//     printf("루프가 끝났다.\n");
    
//     return 0;
// }

// no.2
// #include<stdio.h>
// int main(void)
// {
//     int n =10;
//     while (n >=0)
//     // 중괄호가 없으면 첫번째 줄만 반복문에 포함된다고 본다. 들여쓰기가 같은 층에 있어도 괄호가 없으면 안됨 ㅇㅋ?
//     {
//         printf("n = %d\n", n);
//         n--;
//         printf("이제 n = %d\n", n);
//         /* code */
//     }
//     printf("루프가 끝났다.\n");
    
//     return 0;
// }



// #include<stdio.h>
// int main(void)
// {
//     int n =0;
//     while (n<=100 )
//     // 중괄호가 없으면 첫번째 줄만 반복문에 포함된다고 본다. 들여쓰기가 같은 층에 있어도 괄호가 없으면 안됨 ㅇㅋ?
//     {   
//         printf("%d\n", n);
//         n = n+2;

//     }
//     // printf("루프가 끝났다.\n");
    
//     return 0;
// }


#include<stdio.h>
int main(void)
{
    // int i =0;
    // int j = 0;
    // // char a =' ' ;
    // while (i <= 6-i)
    // // 중괄호가 없으면 첫번째 줄만 반복문에 포함된다고 본다. 들여쓰기가 같은 층에 있어도 괄호가 없으면 안됨 ㅇㅋ?
    // {   
    //     printf("0");
    //     i++;
    //     // 왜 why? 어째서?  무한? okay 그건 탈출 근데 so what?
    // }   
    // printf("*");
    // i = 0;  
    // while (i <5)
    // {
    //     printf("0");
    //     i++;
    // }
    // while (i <=4)
    // {
    //     printf("0");
    // }
    // printf("\n");
    // i=0;
    // while (i <=2)
    // {   
    //     printf("0");
    //     i++;
    // }
    // printf("***");
    // i=0;
    // while (i <=2)
    // {   
    //     printf("0");
    //     i++;
    // }



    // int i = 0;
    // int j = 11;
    // int k = 0;
    // while (i<j)
    // {
    //     printf("0");
    //     i++;
    //     while ( i == 4 )
    //     {
    //         printf("*");
    //         i++;
    //     }
    // }



    // int i = 5;
    // int j = 1;
    // int k = 5;
  
    // while (i>0)
    // {
    //     while (j <i)
    //     {
    //         printf(" ");
    //         j++;
    //     }
    //     while (k >=i)
    //     {
    //         k--;
    //         printf("* ");
    //     }
    //     printf("\n");
    //     i--;
    //     j =1;
    //     k =5;
        
        
    // }


    // int i = 1;
    // int c= 0 ;
    // int j = 0;
    // // 마름모 상단
    // while ( i <16)
    // {
    //     while (j++<16-i)
    // {
    //     printf(" ");
    // }
    //     while (c++<i)
    // {
    //     printf("* ");
    // }
    // printf("\n");
    // c= 0;
    // j=0;
    // i=i+2;
    // }


    // // 마름모 하단
    // i =13;
    // c=0;
    // j=0;
    // while (i>0)
    // {
    //     while (j++<16-i)
    //     {
    //         printf("0");
    //     }
    //     while (c++<i)
    //     {
    //         printf("* ");
    //     }
    // printf("\n");

    // c= 0;
    // j=0;
    // i=i-2;
        
        
    // }
    
  
   
    
// 모래시계 상단 위아래 반전 삼각형
    // int i =13;
    // int c=0;
    // int j=0;
    // while (i>0)
    // {
    //     while (j++<16-i)
    //     {
    //         printf(" ");
    //     }
    //     while (c++<i)
    //     {
    //         printf("* ");
    //     }
    // printf("\n");

    // c= 0;
    // j=0;
    // i=i-2;
        
        
    // }
    //  i = 1;
    //  c= 0 ;
    //  j = 0;
    // // 모래시계 삼각형
    // while ( i <16)
    // {
    //     while (j++<16-i)
    // {
    //     printf(" ");
    // }
    //     while (c++<i)
    // {
    //     printf("* ");
    // }
    // printf("\n");
    // c= 0;
    // j=0;
    // i=i+2;
    // }




    // int i = 1;
    // int c= 0 ;
    // int j = 0;
    // // 삼각형
    // while ( i <16)
    // {
    //     while (j++<16-i)
    // {
    //     printf(" ");
    // }
    //     while (c++<i)
    // {
    //     printf("* ");
    // }
    // printf("\n");
    // c= 0;
    // j=0;
    // i=i+2;
    // }
// 직사각형
//    int i = 5;
//    int c = 0;
//    int j = 5;
//     while (i<16)
//     {
//         while (j++<15)
//         {
//             printf(" ");
//         }
//         while (c++<5)
//         {
//             printf("* ");
//         }
//         printf("\n");
//         i = i+1;
//         c = 0;
//         j = 5;
//     }
    
    int i = 1;
    int c = 0 ;
    int j = 0;
    // 삼각형
    while ( i <16)
    {
        while (j++<16-i){
        printf("0");
    }
        while (c++<i){
        printf("* ");
    }
    printf("\n");
    c= 0;
    j=0;
    i=i+2;
    
    }
    
//////////////
     i = 1;
     c = 5 ;
     j = 19;
    // 트리
    while ( i <16)
    {
        while (j++<19-i){
        printf("0");
    }
        while (c++<i){
        printf("* ");
    }
    printf("\n");
    c= 0;
    j= 5;
    i= i+3;
    }
        while (j++<19-i){
        printf("0");
    }
        while (c++<i){
        printf("* ");
    }
    c= 0;
    j= 5;
    i= i+3;
        // printf("\n");
    // //////////
     i = 3;
     c = 5 ;
     j = 19;

    while ( i <16)
    {
        while (j++<19-i){
        printf("0");
    }
        while (c++<i){
        printf("* ");
    }
    printf("\n");
    c= 0;
    j= 5;
    i= i+3;
    }


    // printf("\n");
    return 0;
}