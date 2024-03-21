// #include<stdio.h>
// int main(void){
//     int sum = 0;
//     int num = 0;
// for ( num =0; num<100; num++){
//         sum += num;
// };
//         printf("%d",sum);
// return 0;
// }
// #include<stdio.h>
// int main(void){

//     int num = 0;
//     int sum = 0;
//     for( num = 0; num <= 100; num++)
//         if (num %2 == 0)
//             sum += num;
//     printf("%d", sum);
//     return 0;
// };

// #include<stdio.h>
// int main(void){

//     int num = 0;
//     int sum = 0;
//     for( num = 0; num <= 100; +2)
//             sum += num;
//     printf("%d", sum);

//     return 0;
// };


// #include<stdio.h>
// int main(void){
//     int num = 0;
//     int sum = 0;
//     for (num = 1; num <=100; num++)
//             if( num %2 ==0){
//                 sum += num;
//             }else
//                 sum -= num;
//     printf("%d", sum);
//     return 0;
// };


// #include<stdio.h>
// int main(void){
//     int num = 1;
//     int i = 1;
//     int sum = num;
//         for (num = 5; num >=1; num--){
//                 for(i = 1; i<= num; i++){
//                         sum *=  i;
//                         // sum = num;
//                 }
//             printf("%d\n", sum);
//             sum = num;

//         }

//     return 0;
// };

// #include<stdio.h>
// int main(void){
//     int num  =10;
//     int i = 1;
//     int sum = 0;
//     for ( i= 1; i<= num; i++ ){
//         if (num % i == 0){
//                printf("%d\n",i);
//         }
//     }
//     return 0;
// };

// #include<stdio.h>
// int main(void){
//     int n1 = 10;
//     int n2 = 20;
//     int sum = 0;
//     int i ;
//     for ( i =1; i<n2; i++){
//     if (n1 % i ==0 && n2 % i  == 0){
//         printf("%d\n",i);
//     }    
// }
//     return 0;
// };

//2.1
// #include<stdio.h>
// int main(void){
//     int num [10]= {};
//     int i ;
//     for (i = 1; i<=10; i ++){
//         num[i] = i;
//     printf("%d\n",num[i]);

//     }


//     return 0;
// };


//2.2
// #include<stdio.h>
// int main(void){
//     int num [10]= {};
//     int i =0;
//     for ( i = 0; i <=100; i++ ){
//         if( i % 10 ==0){
//             num[i/10] = i;
//         }
//     }
//     for( i=10 ; i>=1; i--){
//         // printf("%d",i);
//         printf("%d %d\n", num[i],i);
//     }
//     return 0;
// };
// //2.5
// #include<stdio.h>
// int main(void){
//     int i = 0;
//     int num[] ={0,1,2,3,4,5,6,7,8,9};
//     int num1[10] = {};
//     for( i = 0; i<=4; i++ ){
//             num1[i] = num[9-i];
//             printf("%d\n", num1[i]);
//     }
//     for( i=5; i<=9; i++){
//         num1[i] = num[9-i];
//         // printf("num%d\n",num[i]);
//         printf("%d\n", num1[i]);
//     }

//     return 0;
// };

//2.4
// #include<stdio.h>
// int main(void){

//     int num[] = {0,1,2,3,4,5,6,7,8,9};
//     int max = 0;
//     int i =0;
//     for(i =0; i<10; i++){
//         if(num[i] > max)
//             max = num[i];
//     }
//             printf("%d",max);


//     return 0;
// };
// 2.5
// #include<stdio.h>
// int main(void){
//     int i = 0;
//     int num[] ={0,1,2,3,4,5,6,7,8,9};
//     int num1[10] = {};
//     for( i = 0; i<=4; i++ ){
//             num1[i] = num[9-i];
//             printf("%d\n", num1[i]);
//     }
//     for( i=5; i<=9; i++){
//         num1[i] = num[9-i];
//         // printf("num%d\n",num[i]);
//         printf("%d\n", num1[i]);
//     }

//     return 0;
// };
//2.3
// #include<stdio.h>
// int main(void){
//         int a[10] = {};
//         int i =0;
//         for(i=9; i>=0; i--){
//             a[i] = i;
//             printf("%d", a[i]);
//         }
//     return 0;
// };

// //2.6
// #include<stdio.h>
// int main(void){

//     int a[10] = {1,2,3,4,5,6,7,8,9,10} ;
//     int b[10] = {};
//     int i = 0;
//     int temp = 1 ;
//     for(i = 0; i<9; i++){
//         b[i] = a[i+1];
//         b[9] = 1;

//         printf("%d",b[i]);
//     }
//         printf("%d",b[9]);
 
//     return 0;
// };


// //문제.01 최대공약수 구하기
// #include<stdio.h>
// int main(void){

//     int num1 =12;
//     int num2 = 16;
//     int i = 0;
//     int max = 0;
//     for (i = 1; i <num1; i ++ ){
//         if( num1 % i == 0 && num2 % i == 0){
//          if(i > max){
//             max = i;
//         }   
//         }
//     }printf("%d", max);




//     return 0 ;
// }


//문제 2 직각 삼각형 모양으로 수 출력하기

// #include<stdio.h>
// int main(void){

//     int i =0;
//     int j = 0;
//     for(i = 1; i <=5; i++){
//         // printf("%d",i);
//         for (j = 1; j<=i; j++){
//             printf("%d",i);
//         }
//             printf("\n");

//     }


//     return 0 ;
// }

// #include<stdio.h>
// int main(void){

//     int i =0;
//     int j = 0;
//     for(i = 5; i >=1; i--){
//         // printf("%d",i);
//         for (j = 1; j<=i; j++){
//             printf("%d",j);
//         }
//             printf("\n");
//     }
//     return 0 ;
// }


// #include<stdio.h>
// int main(void){

//     int i =0;
//     int j = 0;
//     for(i = 1; i <=5; i++){
//         // printf("%d",i);
//         for (j = 5; j>=i; j--){
//             printf("%d",j);
//         }
//             printf("\n");

//     }


//     return 0 ;
// }



// //03.Prime Number
// #include<stdio.h>
// int main(void){

//     int a = 11;
//     int i = 0;
//     int b = 0;
//     for (i=2; i < a; i++){
//         if(a % i == 0){
//             b +=1;
//         }
//     }
//     if( b >0){
//         printf("%d소수아님",a);
//     }else{
//         printf("%d소수임",a);
//     }

//     return 0;
// }

//문제 04 
#include<stdio.h>
int main(void){
    

return 0;
}


