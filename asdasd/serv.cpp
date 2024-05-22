#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/uio.h>
#define BUF_SIZE 1024
#define MAX_CLNT 256
#include "classes_sg_01.cpp"
int clnt_cnt = 0;
int clnt_socks[MAX_CLNT];
pthread_mutex_t mutx;

void error_handling(std::string msg);
void charToStr(char *msg, string &string, int size);
void *handle_clnt(void *arg);

int main(int argc, char *argv[])
{
    int serv_sock, clnt_sock;
    struct sockaddr_in serv_adr, clnt_adr;
    socklen_t clnt_adr_sz;
    pthread_t t_id;

    if (argc != 2)
    {
        printf("Usage : %s <port>\n", argv[0]);
        exit(1);
    }

    pthread_mutex_init(&mutx, NULL);
    serv_sock = socket(PF_INET, SOCK_STREAM, 0);

    memset(&serv_adr, 0, sizeof(serv_adr));
    serv_adr.sin_family = AF_INET;
    serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_adr.sin_port = htons(atoi(argv[1]));

    if (bind(serv_sock, (struct sockaddr *)&serv_adr, sizeof(serv_adr)) == -1)
        error_handling("bind() error");

    if (listen(serv_sock, 5) == -1)
        error_handling("listen() error");

    while (1)
    {
        clnt_adr_sz = sizeof(clnt_adr);
        clnt_sock = accept(serv_sock, (struct sockaddr *)&clnt_adr, &clnt_adr_sz);
        // clnt_sock에 서버소켓의 파일 디스크립터가 담겨 있다.
        pthread_mutex_lock(&mutx);
        clnt_socks[clnt_cnt++] = clnt_sock;
        pthread_mutex_unlock(&mutx);

        pthread_create(&t_id, NULL, handle_clnt, (void *)&clnt_sock);
        pthread_detach(t_id);
        printf("Connectd client IP: %s \n", inet_ntoa(clnt_adr.sin_addr));
    }
    close(serv_sock);
    return 0;
}
void error_handling(std::string msg)
{
    std::cout << msg << errno << std::endl;
    exit(1);
}

void *handle_clnt(void *arg)
{
    Rent a("OPERATOR", "1234");
    // Rent a("ADMIN", "1234");
    int clnt_sock = *((int *)arg);
    int str_len = 0, i;
    char recv_msg[BUF_SIZE];
    char sendmsg[BUF_SIZE];
    std::string b_book;

    while (1)
    {
        recv_msg[0] = 0;
        while ((str_len = read(clnt_sock, recv_msg, sizeof(recv_msg))) == -1)
            error_handling("read() error");
        recv_msg[str_len] = 0; // 데이터의 크기의 +1위치에 0을 넣어서 파일을 읽을 때 그만 읽게해 전송한 데이터만 읽게 만든다?
        std::string choice(recv_msg);

        // strcpy(choice, msg);
        if (choice == "q" || choice == "Q")
            break;
        // 완성 등급 조정 함수 디버그 필요
        else if (choice == "1" || choice == "로그인")
        {
            // id 수신
            while ((str_len = read(clnt_sock, recv_msg, sizeof(recv_msg))) == -1)
                error_handling("read() error");
            // 클라이언트에서 송신한 데이터가 클라이언트 소켓의 출력버퍼에 담겨 있고,
            // 송신했다는 신호를 서버에서 받으면 송신한 데이터가 서버소켓의 입력 버퍼에 담긴다.
            // 그게 여기서는 recv_msg 이녀석인거고 배열의 길이의 위치에 0을 넣어주면  읽는걸 거기까지만 할거고
            // 그 데이터가 아무튼 string id에 담길거고 그 데이터를 함수에 넣으면 알아서 읽을 때
            recv_msg[str_len] = 0;
            std::string id(recv_msg);
            // pw 수신
            while ((str_len = read(clnt_sock, recv_msg, sizeof(recv_msg))) == -1)
                error_handling("read() error");
            recv_msg[str_len] = 0;
            std::string pw(recv_msg);

            pthread_mutex_lock(&mutx); // 뮤텍스 시작
            // db 확인
            // 함수에서 int 리턴  // 로그인  성공시 0 반환, 아이디 부존재 시 1, 비밀번호 불일치 시 2 반환, 에러발생 시 9 반환
            int res_log = a.LOGIN(id, pw);
            if (res_log == 2)
            {
                a.LOGIN_FAILED(id);
            }
            pthread_mutex_unlock(&mutx); // 뮤텍스 종료
            std::string reslogstr = to_string(res_log);
            strcpy(sendmsg, reslogstr.c_str());
            sendmsg[strlen(reslogstr.c_str())] = 0;
            // 로그인 결과 송신
            write(clnt_sock, sendmsg, strlen(sendmsg));

            if (res_log == 0) // 로그인 성공
            {
                std::cout << "로그인 성공";
            }
            else // 로그인 실패
            {
                // 실패하면 클라이언트에서 시작화면으로 돌아간다. 서버도 시작 부분으로 돌아가서 수신대기한다.
                continue;
            }
        }
        else if (choice == "2" || choice == "회원가입")
        {
            while (1)
            {
                std::string id;
                std::string mail;
                // std::string Nickname;
                while (1)
                {
                    // 아이디 수신
                    while ((str_len = read(clnt_sock, recv_msg, sizeof(recv_msg))) == -1)
                        error_handling("read() error");
                    recv_msg[str_len] = 0;
                    charToStr(recv_msg, id, strlen(recv_msg));
                    // std::string id(recv_msg);
                    pthread_mutex_lock(&mutx);
                    std::string check_id = a.SINGUP_IDcheck(id);
                    pthread_mutex_unlock(&mutx);
                    // id결과 송신
                    write(clnt_sock, check_id.c_str(), strlen(check_id.c_str()));
                    if (check_id == "a")
                        // ok
                        break;
                }
                // pw 수신
                while ((str_len = read(clnt_sock, recv_msg, sizeof(recv_msg))) == -1)
                    error_handling("read() error");
                recv_msg[str_len] = 0;
                std::string pw(recv_msg);
                while (1)
                {
                    // mail 수신
                    while ((str_len = read(clnt_sock, recv_msg, sizeof(recv_msg))) == -1)
                        // read 는 비트수를 반환하고 sizeof는 바이트 수를 반환한다rh? strlen 은 문자열의 글자 수를 반환한다. 얘네들 다 0/ 만날때까지 읽어
                        error_handling("read() error");
                    recv_msg[str_len] = 0;
                    charToStr(recv_msg, mail, strlen(recv_msg));
                    // std::string mail(recv_msg);
                    std::string check_mail = a.SINGUP_EMAILcheck(mail);
                    // check_mail 송신
                    write(clnt_sock, check_mail.c_str(), strlen(check_mail.c_str()));
                    if (check_mail == "d")
                        break;
                }
                // Nickname 수신
                while ((str_len = read(clnt_sock, recv_msg, sizeof(recv_msg))) == -1)
                    error_handling("read() error");
                recv_msg[str_len] = 0;
                std::string Nickname(recv_msg);

                std::string check_sign = a.SIGNUP(id, pw, Nickname, mail);
                write(clnt_sock, check_sign.c_str(), strlen(check_sign.c_str()));
                if (check_sign == "a")
                    // 회원가입 성공
                    break;
            }
        }
    }
}

void charToStr(char *msg, string &string, int size)
{
    string.resize(0);
    for (int i = 0; i < size; i++)
        string.push_back(msg[i]);
}
