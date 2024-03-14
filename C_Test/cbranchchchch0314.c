// #include<stdio.h>
// #define SIZE 8
// int main(void){
//     int by_twos[SIZE];
//     int index;

//     for (index = 0; index < SIZE; index++){
//         by_twos[index] = 2* (index + 1);
//     }
//     for (index = 0; index < SIZE; index++){
//         printf("%d",by_twos[index]);
//     printf("\n");
//     }
    
//     return 0;
// }

// //12번문제 long형을 리턴하게 한다 이게 무슨말이지 ? return long; like this?
// #include<stdio.h>
// int main(void){
//     long a;
//         return 0;
// }

// #include<stdio.h>
// int main(void){
//     long square(int num){

//     }
//         return ((long)num) * num;
// }

#include<stdio.h>
int main(void){
    int k;

    for (k = 1, printf("%d: 안녕!\n",k);printf("k = %d\n",k),k*k  <26; k+=2, printf("이제 k는 %d\n",k))
    printf("루프 몸체에서 k는 %d\n", k);
    return 0;
}