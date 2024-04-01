#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include <termios.h>
#include"getch.h"

// #include <conio.h> //_getch가 포함되어있는 헤더 리눅스 우분투에 없음 ㅅㅂ


#define MAPSIZE 50
int usermovement[1][5]={{10,10}};
// 유저 위치 

int main(void){

if((usermovement[0][0]<0 || usermovement[0][0]>50) || (usermovement[0][1]<0 || usermovement[0][1]>50) ){
    printf("유저의 위치를 수정해야 합니다.");
    // return -1;
}

// 맵사이즈 50 X 50
char map[MAPSIZE][MAPSIZE];
int movement=0;
for (int i = 0; i < MAPSIZE; i++)
{
    for (int j = 0; j < MAPSIZE; j++)
    {
        map[i][j]='x'; 
    }
    
}
// 방향키 입력받기 헤더파일 생성해서 getch()만듬
 int ch;

    // printf("%c 키가 눌려졌습니다.", ch);
// UP = (00, 72), LEFT = (00, 75), RIGHT = (00, 77), DOWN = (00, 80)
    printf("아무키나 누르세요 ...\n");

int cursor=getch();
if (cursor==0 || cursor==0x00){
        // if(cursor)
        cursor=getch();


}
printf("%d",cursor);


    return 0;
}