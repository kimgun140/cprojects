#include<stdio.h>

// int MINMAX(int num1, int num2, int*max, int* min);
int PointMax(int ary[5], int* max);
int main (void){

/*

*/

// int num1 = 5;
// int num2 = 4;

// int* max = &num1;
// int* min = &num2;


// MINMAX(num1,num2,max,min);
// printf("max: %d\n", *max);
// printf("min: %d\n", *min);

int ary[5] = {1,6,3,9,4};
int* max =NULL;
PointMax(ary[5],*max);
printf("max: %d\n",*max);

    return 0;
}


int MINMAX(int num1, int num2, int*max, int* min){

if ( num1 > num2){
    max = &num1;
    min = &num2;
    // printf("max: %d\n", *max);
    // printf("min: %d\n", *min);


}else{
    max = &num2;
    min = &num1;
    // printf("max: %d\n", *max);
    // printf("min: %d\n", *min);

}

// return 0;
}

int PointMax(int ary[5], int* max){

    for(int i = 0 ; i<5; i++){
        if(ary[i]>ary[i+1]){
            *max = ary[i];
        }else{
            *max = ary[i+1];
        }
    }
// return *max;

}