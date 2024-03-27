#include<stdio.h>
#include<stdlib.h>
#include<time.h>
// 랜덤출력
int main(void){
    srand((unsigned int)time(NULL)); //seed값으로 현재시간 부여 
    int num[25] ;
    int num2[25] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
    // 0~ 24 의 숫자 25개를 담는다. 중복없이 그리고 그 숫자를 출력한다.
    int i = 0;
    for( i = 0; i <25; i++){
            num[i] = rand() % 25;
            if( num2[i] == i ){
            
            }
    }

    int b[5][5] = {{1,2,3,4,5}
                ,{6,7,8,9,10}
                ,{11,12,13,14,15}
                ,{16,17,18,19,20}
                ,{21,22,23,24,25}};
    for (int i = 0; i < 5; i++ ){
        printf("\n");
        for(int j =0; j < 5; j++){
            printf("%3d  |", b[i][j]);

        }
    }


    return 0;
}