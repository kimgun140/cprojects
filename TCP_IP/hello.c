#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
void error_handling(char *message);
int main(int argc, char *argv[])
//
{
    int serv_sock;
    int clnt_sock;

    struct sockaddr_in serv_addr;
    /* struct sockaddr_in{
        sa_family_t     sin_family; 주소체계
        uint16_t        sin_port;  port번호
        struct in_addr  sin_addr;   32비트 ip주소
        char            sin_zero[8];    사용되지 않음
    }

    struct in_addr{
        in_addr_t       s_addr;     32비트 ipv4 인터넷 주소
    }
    */
    struct sockaddr_in clnt_addr;
    socklen_t clnt_addr_size;

    char message[] = "ㅎㅇ!";
    if (argc != 2)
    {
        printf("Usage : %s <port>\n", argv[0]);
        exit(1);
    }
    serv_sock = socket(PF_INET, SOCK_STREAM, 0);
    /*
    int socket( int domain, int type, int protocol);
    domain 소켓이 사용할 프로토콜 체계 정보 전달
    type 소켓의 데이터 전송 방식에 대한 정보 전달.
    protocol 두 컴퓨터간 통신에 사용되는 프로토콜 정보 전달

    */
    if (serv_sock == -1)
        error_handling("socket() error");
    // 주소세팅
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    // 주소체계 정보 저장
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    // 32비트 ip주소정보 저장
    // 네트워크 바이트 순서로 저장
    // 멤버 sin_addr의 구조체 자료형 in_addr 사실상 32비트 정수자료형
    serv_addr.sin_port = htons(atoi(argv[1]));
    // 32비트 ip주소 정보 저장
    // 네트워크 바이트 순서로 저장
    // 멤버 sin_addr의 구조체 자료형 in_addr 사실상 32비트 정수자료형
    // 주소 받기
    if (bind(serv_sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1)
        //
        // 구조체 변수 sockaddr_in은 bind 함수의 인자로 전달되는데, 매개변수 형이 sockaddr이므로 형 변황을 해야만 한다.
        // 문자열로 입력한 바이트와 포트를 비트로 빅엔디안 방식으로 변환해 바인드를 해준다.
        error_handling("bind() error");
    // 연결대기
    if (listen(serv_sock, 5) == -1)
        error_handling("listen() error");
    // 연결 수락
    clnt_addr_size = sizeof(clnt_addr);
    clnt_sock = accept(serv_sock, (struct sockaddr *)&clnt_addr, &clnt_addr_size);
    if (clnt_sock == -1)
        error_handling("accept() error");

    write(clnt_sock, message, sizeof(message));
    close(clnt_sock);
    close(serv_sock);
    return 0;
}
void error_handling(char *message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}