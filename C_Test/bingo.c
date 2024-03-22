#include<stdio.h>
#include<stdlib.h> //rand(), srand()
#include<time.h> //time()
int main(void){
    srand((unsigned int)time(NULL)); //seed값으로 현재시간 부여 
    printf("난수 : %d\n", rand() % 25);
    int i ;
    int j ;
    int bingo1[5][5] = {
        {1,2,3,4,5},
        {6,7,8,9,10},
        {11,12,13,14,15},
        {16,17,18,19,20},
        {21,22,23,24,25}
    };
    int bingo2[5][5] ;
    int r =rand() % 25 +1; ; // 25개중에 
    for (int i = 0; i<5; i++){
        for(int j =0; j<5; j++){
            bingo2[i][j] = r; //랜덤 1~25 랜덤 숫자 넣기 중복제거해야함
            // printf("%3d",bingo2[i][j]);
        }
    }
    // while(1 ){
    //     if( bingo2[i][j] == r){
    //             bingo2[i][j] =rand() % 25 +1;
    //         }
    // }




    return 0;
}