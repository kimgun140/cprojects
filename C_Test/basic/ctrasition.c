//2차원 배열 회전하기

#include<stdio.h>
int main(void){
    int ar1 [5][5] = {
        {1,2,3,4,5},
        {6,7,8,9,10},
        {11,12,13,14,15},
        {16,17,18,19,20},
        {21,22,23,24,25}
    };
    int ar2[5][5] ;
    // printf("%d",ar2[0][2]);

    int i;
    int j;
    int k;
    // for (i= 0 ; i< 5; i++){
    //     for(j = 4; j>=0; j--){
    //         for(k = 0; k<5; k++){ 
    //         ar2[k][j] = ar1[i][k];
    //         }
    //     }
    // }
    for (i= 0 ; i< 5; i++){
        for(j = 0; j<5; j++){
            ar2[j][4-i] = ar1[i][j];
            // printf("%3d", ar2[i][j]);
        }

    }

// printf("%3d", ar2[0][1]);
// printf("%3d", ar2[1][1]);
// printf("%3d", ar2[2][1]);
// printf("%3d", ar2[3][1]);
// printf("%3d", ar2[4][1]);

printf("%3d", ar2[0][0]);
printf("%3d", ar2[0][1]);
printf("%3d", ar2[0][2]);
printf("%3d", ar2[0][3]);
printf("%3d\n", ar2[0][4]);
printf("%3d", ar2[1][0]);
printf("%3d", ar2[1][1]);
printf("%3d", ar2[1][2]);
printf("%3d", ar2[1][3]);
printf("%3d", ar2[1][4]);
// i = 0;
// j = 0;
// for(i = 0; i<5; i++){
//     for(j = 0; j <5; j++){
//         printf("%3d", ar2[i][j]);
//     }
// }
    return 0;
}