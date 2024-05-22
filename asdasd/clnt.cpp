#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/uio.h>

#define BUF_SIZE 1024
void error_handling(std::string msg);
void reset_msg(char *msg, int size);
void *recv_msg(void *arg); // read thread main

int main(int argc, char *argv[])
{
    int sock;
    struct sockaddr_in serv_addr;
    char message[BUF_SIZE];
    int str_len, recv_len, recv_cnt;

    if (argc != 3)
    {
        printf("Usage : %s <IP> <port>\n", argv[0]);
        exit(1);
    }
    sock = socket(PF_INET, SOCK_STREAM, 0);
    if (sock == -1)
        error_handling("socket() error");
    // 주소세팅
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1)
        error_handling("connect() error");

    recv_msg((void *)&sock);
    close(sock);

    return 0;
}

void intro()
{
    std::cout << "-----------------------\n"
              << "   채팅프로그램     \n"
              << std::endl
              << "1. 로그인   2. 회원가입\n"
              << "3. 채팅하기 4. 친구창\n"
              << "Q. 종료\n"
              << "-----------------------\n"
              << "원하시는 기능을 입력하시오: "
              << std::endl;
}
void *recv_msg(void *arg) // read thread main
{
    int sock = *((int *)arg);
    char msg[BUF_SIZE];
    int str_len;
    // std::string res_bb;
    char tempmsg[800000];
    while (1)
    {
        reset_msg(msg, BUF_SIZE);
        // 인트로
        intro();
        // 인트로 선택(1로그인,2회원가입,3도서검색,4도서반납,q종료)
        std::string intro;
        getline(std::cin, intro);
        write(sock, intro.c_str(), strlen(intro.c_str()));

        if (intro == "q" || intro == "Q")
        {
            write(sock, msg, strlen(msg));
            std::cout << "프로그램을 종료합니다.\n";
            close(sock);
            exit(0);
            break;
        }
        else if (intro == "1" || intro == "로그인")
        {
            // 로그인 유도문
            std::cout << "-----------------------\n"
                      << "         로그인\n"
                      << "-----------------------\n"
                      << " ID: ";
            // id 입력
            std::string id;
            getline(std::cin, id);
            // id 송신
            write(sock, id.c_str(), strlen(id.c_str()));
            // pw 입력
            std::cout << " PW: ";
            std::string pw;
            getline(std::cin, pw);
            // pw 송신
            write(sock, pw.c_str(), strlen(pw.c_str()));

            // 로그인 결과 수신
            while ((str_len = read(sock, msg, sizeof(msg))) == -1)
                error_handling("read() error");
            msg[str_len] = 0;

            // 로그인 성공
            std::string res_log(msg);
            if (res_log == "0")
            {
                std::cout << "로그인 성공.\n";
            }
            else if (res_log == "1")
            {
                std::cout << "로그인 실패: 아이디가 존재하지 않습니다.\n";
                continue;
            }
            else if (res_log == "2")
            {
                std::cout << "로그인 실패: 비밀번호가 틀립니다.\n";
                continue;
            }
            else
            {
                std::cout << "로그인 오류\n";
                continue;
            }
        }
        else if (intro == "2" || intro == "회원가입")
        {
            while (1) // 회원가입
            {
                while (1)
                {
                    // 아이디 입력 유도문
                    std::cout << "------------------------\n"
                              << "ID를 입력하시오.\n";
                    std::string id;
                    // 아이디 입력
                    getline(std::cin, id);
                    // 아이디 송신
                    write(sock, id.c_str(), strlen(id.c_str()));
                    // id 결과 수신
                    while ((str_len = read(sock, msg, sizeof(msg))) == -1)
                        error_handling("read() error");
                    msg[str_len] = 0;
                    std::string id_check(msg);
                    if (id_check == "a")
                    {
                        break;
                    }
                }
                // 비밀입력 유도문
                std::cout << "------------------------\n"
                          << "비밀번호를 입력하시오.\n";
                std::string pw;
                // pw 입력
                getline(std::cin, pw);
                // pw 송신
                write(sock, pw.c_str(), strlen(pw.c_str()));

                while (1)
                {
                    // mail 유도문
                    std::cout << "------------------------\n"
                              << "이메일을 입력하시오.\n";
                    std::string mail;
                    // mail 입력
                    getline(std::cin, mail);
                    // mail 송신
                    write(sock, mail.c_str(), strlen(mail.c_str()));
                    // mail 수신
                    while ((str_len = read(sock, msg, sizeof(msg))) == -1)
                        error_handling("read() error");
                    msg[str_len] = 0;
                    std::string mail_check(msg);
                    if (mail_check == "d")
                        break;
                }
                // 닉네임 유도문
                std::cout << "------------------------\n"
                          << "닉네임을 입력하시오.\n";
                std::string Nickname;
                // name 입력
                getline(std::cin, Nickname);
                // name 송신
                write(sock, Nickname.c_str(), strlen(Nickname.c_str()));

                while ((str_len = read(sock, msg, sizeof(msg))) == -1)
                    error_handling("read() error");
                msg[str_len] = 0;
                std::string sign_check(msg);
                if (sign_check == "a")
                {
                    std::cout << "회원가입 성공!" << std::endl;
                    break;
                }
            }
        }
    }
}
void error_handling(std::string msg)
{
    std::cout << msg << errno << std::endl;
    exit(1);
}
void reset_msg(char *msg, int size)
{
    for (int i = 0; i < size; i++)
        msg[i] = 0;
}