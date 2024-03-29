/*

스택 메모리와 힙메모리

스택메모리
메인함수에 쌓인다. 배열같은 모양 
컴파일 할때 그 크기가 결정이 된다. 브레이스문을 만나면 자동으로 해제가 된다.
사라진다는 점만 주의하자
단점
1. 수명 :함수가 반환이 되면 그 안에 있었던 함수나 데이터가 날아가게된다. 
그렇지않고 오래 보젼하려면 전역변수 선언을 하던지 static을 사용한다. 

2. 크기 : os에게 할당받은 나만의 공간이다. 그래서 많은 공간을 할당 받지는 못한다. 
특정 용도로 사용하기 위해서 특별히 할당 받은거서 크지는 않음


힙메모리
컴퓨터에 존재하는 범용적인 메모리 
스택메모리처럼 특정 용도로 떼어 놓은게 아니라 그냥있는 넓은 공간이다. 
공용공간 공공장소 같은 느낌?
스택과 달리 컴파일러 및 cpu가 자동적으로 메모리 관리를 안해줌 그래서 메모리 관리를 
내가 해줘야한다. 원하느 때 원하는 만큼 메모리를 할당받아 사용하고 원할 때 반납(해제)할 수 있다.

장점 : 용량 제한이 없다. (컴퓨터의 남아있는 메모리만큼 사용가능하다.)
프로그래머가 데이터의 수명을 직접 제어할 수 있다. 

단점 : 빌려온 메모리를 직접 해제 안하면 누구도 메모리를 쓸 수 없다.(메모리 누수가 발생한다.)
스택에 비해 할당 해제속도가 느리다. 메모리 공간에 구멍이 생긴다. 효율적으로 쓸 수는 없다. 


스택메모리는 정적 메모리 :
공간이 따로 잡혀 있고 할당/해제가 자동으로 관리되게 코드가 컴파일 된다.
오프셋 개념으로 정확하게 몇 바이트씩 사용해야하는지 컴파일과정에서 결정된다.


힙 메모리는 동적 메모리
실행 중에 크기와 할당/해제 시기가 결정된다.

동적메모리
1. 메모리 할당 void* 
    메모리를 줄 때 어떤 타입으로 줘야하는지 결정 데이터의 시작 주소를 준다. 
 주소는 가리키는 자료형이 일치하는 포인터에만 대입이가능합니다. 따라서 다리키는 자료형이 다른 주소를
 저장한는 경우라면 void 포인터를 사용합니다.
 void 포인터는 가리키는 자료형이 정해지지 않은 포인터입니다.

os는 자리를 줄 뿐이다. 주소만 담겨 있는 void포인터로 주소를 준다.
malloc을 사용할 때 타입을 주지는 않았으니까


2. 메모리 사용  (int*)malloc(size)
    쓸 때마다 형변환 하기 불편하니까
int * nums = (int*)malloc(size)



3. 메모리 반납/해제 free(nums)
    정적메모리 기모리
기준점을 옮겨 놓고 반환을 하면 다시 처음으로 되돌려놓는다. (이건 몰라도 됨)
사용과 해제는 세또다 세또!!!
메모리 할당 함수가 반환한 주소를 그대로 포인터 연산에 사용하면
메모리 해제할 때 문제가 발생할 수도 있음
최초의 받아온 주소가 아니라 다른 위치를 가리킴
-> 그 주소롤 메모리 해제 요청 -> 무슨일이 일어날지 모름 ㅈ되버릴 수도 

코딩표준 : 할당 받은 포인터로 연산 금지
    메모리 할당 함수에 받아온 포인터(주소), 포인터 연산에 사용하는 포인터를 분리하자!!
    void * nums; -> 열쇠 담당 
    int* p;
    size_t i;
    nums = malloc(LENGTH * sizeof(int));
    p = (int*)nums;

    for(i = 0; i < length){
        *p++ = 10*(i+1);
    }
    free(nums)
    free(nums);해제한 메모리를 또 해제해도 문제다.
    다음데이터가 있을 수도 있는데 날아가버릴 수도? 
코딩 표준 해제후 널포인터를 대입해준다. 
    nums = NULL;을 해준다. 





------------------------------------------------------------

void* calloc(size_t num, size_t size);
void* nums = calloc(LNENGTH, sizeof(int));
free(nums);
nums = null;

모든 바이트를 0으로 초기화 해줌

void* memset(void* dest, int ch, size_t count);
char로 초기화(1바이트씩 됨)
그외의 자료형으로 초기화 하려면 직접 for문을 써야함
count 가 dest의 영역을 넘어 설 경우 (소유하지 않은 메모리에 쓰기)
dest가 널 포인터일 경우 (널 포인터 역참조ㅓ)
void* nums;

nums = malloc(LENTH * sizeof(int));
memset(nums,0, LENGTH * sizeof(int));

free(nums);
nums = NULL;

-----------------------------------------------------

void* realloc(void* ptr, size_t new_size);
이미 존재하는 메모리(ptr의 ) 크기를 new_size바이트로 변경
새로운 크기가 허용하는 한 기존 데이터를 그대로 유지
성공시, 새롭게 할당된 메모리의 시작 주소를 반환하며 기존 메모리 해제됨
실패시 null을 반환하지만 기존 메모리는 해제되지않음 
메로미 노수 발생
1.지금 갖고 있는 메모리 뒤에 충분한 공간이 없으면 새로운 메모리를 할당한뒤 기존의 내용을 복사하고 새주소 반환
2. 지금 갖고 있는 메모리 뒤에 공간이 충분하다면 그냥 기존주소를 반환(보장x)그리고 추가된 공간을 쓸 수 있게됨

malloc 조건문은 생략
char* buffer = (char)(malloc(4);
buffer 백업
char backupBuffer = buffer;
if( null == (buffer = (char*) realloc(buffer,8)))
{
    //종료시
    free(backupbuffer);
    fprintf(stderr,"Memory allocation is failed");
    exit(1);

    // 프로그램 계속 진행할 시 주소 복구
    //buffer = backupbuffer;
}
//do something
*/