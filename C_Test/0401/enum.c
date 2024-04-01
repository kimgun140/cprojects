#include<stdio.h>
#include<string.h>
#include<stdbool.h>
char * s_gets(char * st, int n );

enum spectrum { red, orange, yellow, green, blue, violet};
const char * colors[] = {"red", "orange", "yellow", "green", "blue", "violet"};

#define LEN 30

int main(void){
    char choice[LEN];
    enum spectrum color;
    bool color_is_found = false;

    puts("컬러를 입력하시오(끝내려면 빈 라인) :");
    while (s_gets(choice,LEN) != NULL && choice[0] != '\0')
    {
        for (color = red; color <= violet; color++)
        {
            if (strcmp(choice, colors[color]) == 0){
                color_is_found = true;
                break;
            }
        }
        if (color_is_found)
        switch(color)
        {
            case red :puts("장미는 red.");
                break;
            case orange : puts("양귀비는 orange.");
                break;
            case yellow : puts("해바라기는 yellow.");
                break;
            case green : puts("잔디는 green.");
                break;
            case blue : puts("블루벨은 blue.");
                break;
            case violet : puts("제비꽃은 violet");
                break;
        }
        else
            printf("%s 컬러는 잘모르겠습니다. \n", choice);
        color_is_found = false;
            puts("다음 컬러를 입력사시오(끝내려면 빈 라인):");
    }
    puts("안녕!");

    return 0;
}

char *s_gets(char * st, int n)
{
    char * ret_val;
    char* find;

    ret_val = fgets(st,n,stdin);
    if(ret_val)
    {
        find = strchr(st,'\n');
        if(find)
            *find = '\0';
        else
            while(getchar()!= '\n')
                continue;
    }
    return ret_val;
}