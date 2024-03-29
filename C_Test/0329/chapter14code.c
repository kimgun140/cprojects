#include<stdio.h>
#include<string.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100 //책의 최대 권 수
char * s_gets(char * st, int n);


struct book { //book 템플릿으 설정한다.
    char title[MAXTITL];
    char author[MAXAUTL];
    float value
};


int main(void){

    struct book library [MAXBKS]; //book 구조체의 배열
    int count = 0;
    int index;
    
    printf("도서 제목을 입력하시오 \n");
    printf("끝내려면 라인의 시작 위치에서 [enter] 키를 누르시오.\n");
    while( count < MAXBKS && s_gets(library[count].title, MAXTITL)
        != NULL && library[count].title[0] !='\0')
    {
        printf("저자명을 입력하시오.\n");
        s_gets(library[count].author, MAXAUTL);
        printf("정가를 입력하시오.\n");
        scanf("%f", &library[count++].value);
        while(getchar() !='\n')
            continue; // 입력라인으 깨긋이 비운다.
        if (count < MAXBKS)
        printf("다음 타이틀을 입력ㅎ사이ㅗ.\n");
    }
    if (count >0){
        printf("다음은 소장하고 있는 도서들의 목록입니다.: \n");
        for(index = 0; index <count; index++)
            printf("%s by%s: $%.2f\n", library[index].title, library[index].author, library[index].value);
    }else
    printf("책이 한 권도 없어요? 야, 장하다 장해.\n");

    return 0;
}

char * s_gets(char * st, int n){
    char * ret_val;
    char * find;

    ret_val = fgets(st, n,stdin); //개행을 찾는다ㅏ.
    if (ret_val){   // 주소가 null이 아니면 널문자를 거기에 놓는다.
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
        while( getchar() != '\n')
            continue;   //행의 나머지를 처리한다.
}


return ret_val;
}