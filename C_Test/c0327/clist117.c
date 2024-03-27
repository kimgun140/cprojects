#include<stdio.h>
#include<string.h>
#define LISTSIZE 6
#define STLEN 10
#define ANSWER "Grant"
int main(void){

//     char words[STLEN];
//     puts("문자열을 입력하세요 (탈출하려면 빈 행):");
//     while (fgets(words, STLEN, stdin) != NULL && words[0] != '\n')
//     fputs(words, stdout);
// puts("종료");
//fputs는 버퍼창을 오버플로해도 정해진 크기만큼 출력하고 넘어간것도 그만큼 출력해서
// 다 출력한다. //

//fputs는 개행문자도 저장한다.? 입력받은 문자를 정해진 크기만큼 읽고 나머지 읽고 반복해서 전부 출력한다.
//입력이 전부 버퍼에 저장되어있다. 

//fgets3.c --

//     char words[STLEN];
//     int i;

//     puts("문자열을 입력하세요 (탈출하려면 빈 행):");
//     while (fgets(words, STLEN, stdin) != NULL
//                  && words[0] !='\n')
//  {           i = 0;
//     while(words[i] != '\n' && words[i] !='\0')
//                 i++;
//     if (words[i] == '\n')
//         words[i] = '\0';
//     else //word[i] == '\0' 이어야 한다.
//         while (getchar() != '\n')
//             continue;
//     puts(words);
//  }
//  puts("종료");

// gets()는 입력행이 실제 배열의 크기에 딱 맞는지 검사하지않는다. 
// 입력이 배열의 크기보다 넘칠 가능성을 생각하지 않는다. 넘어가면 버퍼 오버플로난다.
// 넘쳐서 이탈한 문자들은 빈 메모리 공간으로 이동해서 문제를 즉시 이르키지는 않는다.
// 개행문자 읽어서 버린다.    

//fgets()  최대크기를 정해준다.   개행문자를 읽어서 저장을한다.
//fputs()

//puts 는 자동으로 개행문자를 삽입을 해준다.

// /*puts*/
// //nono.c - no! puts
// char side_a[] = "Side A"; //널문자가 삽입 되어있다. 
// char dont[] =  {'W','O', 'W','!'};
// char side_b[]= "Side B";

// puts(dont);
// //dont은 종결 널 문자가 없기 때문에 문자열이아니다.그래서 puts는 어디서 멈춰야하는지 모른다.
// // 그래서 어디간에 있는 널 문자를 만날때 까지 dont 부터 ㅣ작해서 그 뒤에 이쓴 메모모리 내용을 계속 출력한다.
// //puts()는 종결문자를 만날 때까지 출력한다.??????


// fputs() 함수 출력에 개행을 추가하지 않는다.
// gets()는 입력에 개행을 읽고 버린다. 그러나 puts()는 출력에 개행을 추가한다.
// fputs는 출력에 개행을 추가하지않는다..+

//strlen 문자열 길이 알기
//strcat 문자열 결합
//strcmp 문자열 비교

const char * list[LISTSIZE] = {
    "astronomy", "astounding",
    "astrophysics", "ostracize",
    "asterism", "astrophobia"
};
int count = 0;
int i;
for (i = 0; i< LISTSIZE; i++)
    if( strncmp(list[i], "astro", 5)==0){
        printf("찾았다: %s\n", list[i]);
        count++;
    }
    printf("astro로 시작하는 단어를 %d개""찾았다\n", count);






    return 0 ;
}
// char * s_gets(char * st, int n)
// {
//     char *ret_val;
//     int i = 0;

//     ret_val = fgets(st,n, stdin);
//     if (ret_val) //즉 ret_val != NULL
//     {
//     while( st[i] !='\n' && st[i] != '\0')
//         i++;
//     if(st[i] == '\n')
//         st[i] ='\0';
//     else // words[i] == '\0'이 있어야한다.
//         while(getchar() !='\n')
//             continue;
//     }
//     return ret_val;

// }