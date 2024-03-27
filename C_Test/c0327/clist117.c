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

// const char * list[LISTSIZE] = {
//     "astronomy", "astounding",
//     "astrophysics", "ostracize",
//     "asterism", "astrophobia"
// };
// int count = 0;
// int i;
// for (i = 0; i< LISTSIZE; i++)
//     if( strncmp(list[i], "astro", 5)==0){
//         printf("찾았다: %s\n", list[i]);
//         count++;
//     }
//     printf("astro로 시작하는 단어를 %d개""찾았다\n", count);






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

/*
gets()
getchar()
사용자가 입력한 스트림에서 하나의 문자 아스키 코드값을 얻어오는 함수다.
gets()
표준 스트림 stdin에서 줄을 읽고 버퍼에 저장합니다. 줄은 첫번째 줄바꿈 문자까지 모든 문자로 구성된다.
gets는 줄을 반환하기 전에 줄바꿈 문자를 null문자('\0')로 대체합니다. 반대로 fgets() 함수는 줄 바꿈 문자를 유지합니다. 


******fgets(str, numchars, stream)******

str 데이터 스토리지 위치
numChars 읽을 최대 문자 수
stream file구조체에 대한 포인터입니다.
--MS-
fgets()입력 stream인수에서 문자열을 읽어 str에 저장합니다 fgets는 현재 스트림 위치에서 첫 번째 줄 바꿈 문자,
스트림의 끝 또는 읽은 문자 수가 1과 같은 numChars을 때까지 문자를 읽습니다. str에 저장된 결과는 null문자와 함께 추가 된다. 
줄바꿈 문자는 읽을 경우 문자열에 포함됩니다. 

-IBM-
#include <stdio.h>
char *fgets(char *string, int n , FILE *stream);
fgets() 함수는 현재 stream 위치에서 어느 것이 먼저 오건 첫 번째 줄바꾸기 문자(\n)까지, 
스트림의 끝까지 또는 읽은 문자 수가 n-1과 같을 때까지 문자를 읽습니다.
fgets() 함수는 결과를 string에 저장하고 스트링 끝에 널(null)문자(\0)를 추가합니다.
string은 줄 바꾸기 문자를 포함합니다(읽은 경우). n이 1이면 string이 비어있습니다.


******fputs()******
fputs() 함수는 string을 현재 위치의 출력 stream으로 복사합니다. 스트링 끝 null문자 (\0)를 복사하지 않습니다.




******puts()******
int puts( const char *str);
매개 변수 : str 출력문자열
설명: 이 함수는 puts 표준 출력 스트림 stdout에 기록 str하여 문자열의 종료문자 null문자("\0")를
출력 스트림의 줄바꿈 문자 ("\n")로 바꿔줍니다.

******gets()******
#include<stdio.h>
char *gets(char *buffer);
gets() 함수는 표준 입력 스트림 stdin으로부터 행을 읽고, buffer에 저장합니다.
행은 줄 바꾸기 문자(\n) 또는 eof(End Of File)를 포함하지 않지만 해당 문자까지 모든 문자로 구성됩니다.
gets() 함수는 행을 리턴하기 전에 읽은 경우 줄바꾸기 문자를 null(\0)로 대체합니다.


******strcmp()******
#include <string.h>
int strcmp(const char *string1, const char *string2);
strcmp() 함수는 sring1과 string2를 비교합니다. 함수는 null로 끝나는 스트링에서 작동합니다.
함수에 대한 스트링 인수는 스트링 끝을 나타내는 널문자 (\0)를 포함해야합니다.
리턴값이 0보다 작으면 string1이 string2보다 작음
0보다 작으면 string1이 string2와 같음
0보다 크면 string1이 string2보다 큼


*/