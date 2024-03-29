#include<stdio.h>
int pointmax(int ary[5],int* max);

int main(void){

    int ary[5]={1,6,2,9,4};
    int* max = NULL;

    pointmax( ary,  max);

    printf("max:%d\n",*max);



    return 0;
}

int pointmax(int ary[5],int* max){

    for(int i =0; i<4; i++){

        if( ary[i] >ary[i+1]){
            *max = ary[i];

        }else
        *max = ary[i+1];
    }


}