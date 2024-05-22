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
#define NAME_SIZE 20

void intro();
void *recv_msg(void *arg);
void error_handling(std::string msg);
void reset_msg(char *msg, int size);
void charToStr(char *msg, std::string *string, int size);
void multi_recv_search(int sock, int size);
void recv_search(int sock);
void *readvRes(void *sock);

char name[NAME_SIZE] = "[DEFAULT]";
char msg[BUF_SIZE];

int main(int argc, char *argv[])
{
    int sock;
    struct sockaddr_in serv_addr;
    pthread_t snd_thread, rcv_thread;
    void *thread_return;
    if (argc != 3)
    {
        printf("Usage : %s <IP> <port>\n", argv[0]);
        exit(1);
    }

    sock = socket(PF_INET, SOCK_STREAM, 0);
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

void *recv_msg(void *arg) // read thread main
{
    int sock = *((int *)arg);
    char msg[BUF_SIZE];
    int str_len;
    // std::string res_bb;
    char tempmsg[800000];
    while (1)
    {
        while (1)
        {
            reset_msg(msg, BUF_SIZE);
            // 인트로
            intro();
            // 인트로 선택(1로그인,2회원가입,3도서검색,4도서반납,q종료)
            std::string intro;
            getline(std::cin, intro);
            write(sock, intro.c_str(), strlen(intro.c_str()));

            // sleep(0);
            if (intro == "q" || intro == "Q")
            {
                write(sock, msg, strlen(msg));
                std::cout << "도서관리 프로그램을 종료합니다.\n";
                close(sock);
                exit(0);
                break;
            }
            // 등급 조정 함수 디버그 필요
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
                    std::cout << "로그인 성공\n";
                    while (1)
                    {
                        // 도서상태확인
                        std::cout << "-----------------------\n"
                                  << "대여할 도서의 등록번호를 입력하시오.\n(로그아웃:Q)";

                        std::string book_no;
                        getline(std::cin, book_no);

                        // 대여할 등록번호 혹은 q 송신
                        write(sock, book_no.c_str(), strlen(book_no.c_str()));

                        if (book_no == "q" || book_no == "Q")
                        {
                            std::cout << "로그아웃!\n";
                            break;
                        }

                        // 도서상태확인 결과 수신
                        while ((str_len = read(sock, msg, strlen(msg))) == -1)
                            error_handling("read() error");

                        msg[str_len] = 0;

                        std::string res_bb(msg);

                        if (res_bb == "a") // 대여가능
                        {
                            std::cout << "도서 대여 성공\n";
                            std::cout << "책의 반납기한은 4일 후 입니다.\n";
                            continue;
                        }
                        else if (res_bb == "b") // 대여중
                        {
                            std::cout << "도서 대여 성공\n";
                            std::cout << "책의 반납기한은 7일 후 입니다.\n";
                            continue;
                        }
                        else if (res_bb == "c") // 오류 발생
                        {
                            std::cout << "회원님은 블랙 회원입니다.\n"
                                      << "도서 대여가 불가합니다.\n";
                            continue;
                        }
                        else if (res_bb == "n")
                        {
                            std::cout << "대여 중인 책입니다.\n"
                                      << "대여가 불가합니다.\n";
                            continue;
                        }
                        else if (res_bb == "e")
                        {
                            std::cout << "오류가 발생했습니다.\n"
                                      << "관리자에게 연락하시오.\n";
                            continue;
                        }
                        else
                        {
                            std::cout << "오류가 발생했습니다.\n"
                                      << "관리자에게 연락하시오.\n";
                            continue;
                        }
                        sleep(1);
                    }
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
            // 완성
            else if (intro == "2" || intro == "회원가입")
            {
                while (1)
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
                    // 이름 유도문
                    std::cout << "------------------------\n"
                              << "이름을 입력하시오.\n";
                    std::string name;
                    // name 입력
                    getline(std::cin, name);
                    // name 송신
                    write(sock, name.c_str(), strlen(name.c_str()));
                    // addrees 유도문
                    std::cout << "------------------------\n"
                              << "주소를 입력하시오.\n";
                    std::string adr;
                    // adr 입력
                    getline(std::cin, adr);
                    // adr 송신
                    write(sock, adr.c_str(), strlen(adr.c_str()));
                    while (1)
                    {
                        // phone 유도문
                        std::cout << "------------------------\n"
                                  << "전화번호를 입력하시오.\n";
                        std::string pn;
                        // pn 입력
                        getline(std::cin, pn);
                        // pn 송신
                        write(sock, pn.c_str(), strlen(pn.c_str()));
                        // check_pn 수신
                        while ((str_len = read(sock, msg, sizeof(msg))) == -1)
                            error_handling("read() error");
                        msg[str_len] = 0;
                        std::string pn_check(msg);
                        if (pn_check == "g")
                            break;
                    }
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
                        else
                        {
                            std::cout << "다시 입력하세요";
                            continue;
                        }
                    }
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
            // 함수 미완성
            else if (intro == "3" || intro == "도서검색")
            {
                while (1)
                {
                    // 도서 조회 유도문
                    std::cout << "-----------------------\n"
                              << "       도서 검색\n"
                              << "1. 단순검색  2.상세검색\n"
                              << "3. 추천도서  Q: 뒤로가기\n"
                              << "-----------------------\n";
                    // 도서검색 옵션 선택
                    std::string find_book1;
                    getline(std::cin, find_book1);
                    // 도서검색 옵션 송신
                    write(sock, find_book1.c_str(), strlen(find_book1.c_str()));
                    if (find_book1 == "q" || find_book1 == "Q")
                    {
                        std::cout << "도서검색을 중지합니다.\n";
                        break;
                    }
                    else if (find_book1 == "1")
                    {
                        // 도서명 유도문
                        std::string find_book2;
                        std::cout << "-----------------------\n"
                                  << "       도서 검색\n"
                                  << "도서의 이름을 입력하시오.\n"
                                  << "-----------------------\n";
                        getline(std::cin, find_book2);
                        // 도서명 송신
                        write(sock, find_book2.c_str(), strlen(find_book2.c_str()));
                        // 단순검색 함수결과 수신
                        while ((str_len = read(sock, msg, sizeof(msg))) == -1)
                            error_handling("read() error");
                        msg[str_len] = 0;
                        std::string res_fb2(msg);
                        // 단순검색 함수결과 판단
                        if (res_fb2 == "a")
                        {
                            // char tempmsg[800000];
                            while ((str_len = read(sock, tempmsg, sizeof(tempmsg))) == -1)
                                error_handling("read() error");
                            tempmsg[str_len] = 0;
                            std::cout << tempmsg;
                        }
                        else if (res_fb2 == "b")
                        {
                            std::cout << "오류발생:다시입력하시오\n";
                            continue;
                        }
                    }
                    else if (find_book1 == "2")
                    {
                        // 상세검색 유도문
                        std::string SDB_name;
                        std::cout << "-----------------------\n"
                                  << "     상세도서검색\n"
                                  << "도서 이름 입력: ";
                        getline(std::cin, SDB_name);
                        // 도서 이름 송신
                        if (SDB_name == "")
                            SDB_name = "%";
                        write(sock, SDB_name.c_str(), strlen(SDB_name.c_str()));
                        // 작가 이름 유도문
                        std::string SDB_writer;
                        std::cout << "작가이름 입력: ";
                        getline(std::cin, SDB_writer);
                        // 작가 이름 송신
                        if (SDB_writer == "")
                            SDB_writer = "%";
                        write(sock, SDB_writer.c_str(), strlen(SDB_writer.c_str()));
                        // 출판사 유도문
                        std::string SDB_producer;
                        std::cout << "출판사 입력: ";
                        getline(std::cin, SDB_producer);
                        // 출판사 이름 송신
                        if (SDB_producer == "")
                            SDB_producer = "%";
                        write(sock, SDB_producer.c_str(), strlen(SDB_producer.c_str()));
                        // 출판연도 유도문
                        std::string SDB_year;
                        std::cout << "출판연도 입력: ";
                        getline(std::cin, SDB_year);
                        // 출판연도 송신
                        if (SDB_year == "")
                            SDB_year = "%";
                        write(sock, SDB_year.c_str(), strlen(SDB_year.c_str()));
                        // 장르 유도문
                        std::string SDB_genre;
                        std::cout << " 000: 총류(백과사전, 신문 등)    500: 기술과학(의학, 농업 등)\n"
                                  << " 100: 철학(논리학, 심리학 등)    600: 예술(미술, 읍악, 연극 등)\n"
                                  << " 200: 종교(불교, 기독교 등)      700: 언어(한국어, 영어 등)\n"
                                  << " 300: 사회과학(경제, 정치 등)    800: 문학(시, 소설, 수필 등)\n"
                                  << " 400: 순수과학(물리, 천문 등)    900: 역사(역사, 지리, 전기 등)\n";
                        std::cout << "장르 입력: ";
                        getline(std::cin, SDB_genre);
                        if (SDB_genre == "000" || SDB_genre == "0" || SDB_genre == "총류")
                            SDB_genre = "0";
                        else if (SDB_genre == "100" || SDB_genre == "1" || SDB_genre == "철학")
                            SDB_genre = "1";
                        else if (SDB_genre == "200" || SDB_genre == "2" || SDB_genre == "종교")
                            SDB_genre = "2";
                        else if (SDB_genre == "300" || SDB_genre == "3" || SDB_genre == "사회과학")
                            SDB_genre = "3";
                        else if (SDB_genre == "400" || SDB_genre == "4" || SDB_genre == "순수과학")
                            SDB_genre = "4";
                        else if (SDB_genre == "500" || SDB_genre == "5" || SDB_genre == "기술과학")
                            SDB_genre = "5";
                        else if (SDB_genre == "600" || SDB_genre == "6" || SDB_genre == "예술")
                            SDB_genre = "6";
                        else if (SDB_genre == "700" || SDB_genre == "7" || SDB_genre == "언어")
                            SDB_genre = "7";
                        else if (SDB_genre == "800" || SDB_genre == "8" || SDB_genre == "문학")
                            SDB_genre = "8";
                        else if (SDB_genre == "900" || SDB_genre == "9" || SDB_genre == "역사")
                            SDB_genre = "9";
                        else
                            SDB_genre = "%";

                        // 장르 송신
                        write(sock, SDB_genre.c_str(), strlen(SDB_genre.c_str()));

                        // 상세검색 결과 수신
                        while ((str_len = read(sock, msg, sizeof(msg))) == -1)
                            error_handling("read() error");
                        msg[str_len] = 0;
                        std::string res_sdb(msg);
                        if (res_sdb == "a")
                        {
                            std::cout << "검색중....\n";
                            while ((str_len = read(sock, tempmsg, sizeof(tempmsg))) == -1)
                                error_handling("read() error");
                            tempmsg[str_len] = 0;
                            std::cout << tempmsg;
                        }
                        else if (res_sdb == "b")
                        {
                            std::cout << "잘못된 입력입니다.\n";
                            continue;
                        }
                    }
                    // 추천도서 시작
                    else if (find_book1 == "3")
                    {
                        // 추천도서
                        std::cout << "-----------------------\n"
                                  << "        추천도서\n"
                                  << "-----------------------\n";
                        // 추천도서 결과 수신
                        while ((str_len = read(sock, msg, sizeof(msg))) == -1)
                            error_handling("read() error");
                        msg[str_len] = 0;
                        std::string res_fb2(msg);
                        write(sock, res_fb2.c_str(), strlen(res_fb2.c_str()));

                        if (res_fb2 == "a")
                        {
                            char tempmsg[800000];
                            std::cout << "검색중....\n";
                            while ((str_len = read(sock, tempmsg, sizeof(tempmsg))) == -1)
                                error_handling("read() error");
                            tempmsg[str_len] = 0;
                            std::cout << tempmsg;
                        }
                        else if (res_fb2 == "b")
                        {
                            std::cout << "오류발생: 다시 입력하세요\n";
                            continue;
                        }
                    }
                    // 추천도서 끝끝
                }
            }
            // 완성
            else if (intro == "4" || intro == "도서반납")
            {
                // 도서반납 유도문
                std::cout << "도서 반납을 시작합니다.\n";
                while (1)
                {
                    std::cout << "반납할 도서의 등록번호를 입력하여 주시오.\n(끝내려면Q)\n";
                    // 반납할 도서의 등록번호 입력
                    std::string return_book;
                    getline(std::cin, return_book);

                    // 입력받은 등록번호 송신
                    write(sock, return_book.c_str(), strlen(return_book.c_str()));

                    // q입력시 종료
                    if (return_book == "q" || return_book == "Q")
                    {
                        std::cout << "반납 서비스를 종료합니다.\n";
                        break;
                    }

                    reset_msg(msg, BUF_SIZE);
                    // 반납상태확인 수신
                    while ((str_len = read(sock, msg, sizeof(msg))) == -1)
                        error_handling("read() error");
                    msg[str_len] = 0;
                    std::string res_ret(msg);
                    // 수신한 반납상태확인 값 판단
                    if (res_ret == "a") // 반납이 가능할 때
                    {
                        std::cout << "반납이 완료되었습니다.\n";
                        continue;
                    }
                    else // 반납이 불가할 때
                    {
                        std::cout << "반납이 불가능한 도서입니다.\n확인 후 다시 입력하여 주시오.\n";
                        continue;
                    }
                }
            }
            else
            {
                std::cout << "잘못된 입력입니다.\n";
                continue;
            }
        }
    }
    return NULL;
}

void error_handling(std::string msg)
{
    std::cout << msg << errno << std::endl;
    exit(1);
}

void intro()
{
    std::cout << "-----------------------\n"
              << "   도서관리프로그램     \n"
              << std::endl
              << "1. 로그인   2. 회원가입\n"
              << "3. 도서검색 4. 도서반납\n"
              << "Q. 종료\n"
              << "-----------------------\n"
              << "원하시는 기능을 입력하시오: "
              << std::endl;
}
// 버퍼를 비워주는 함수네
void reset_msg(char *msg, int size)
{
    for (int i = 0; i < size; i++)
        msg[i] = 0;
}

void charToStr(char *msg, std::string *string, int size)
{
    string->resize(0);
    for (int i = 0; i < size; i++)
        string->push_back(msg[i]);
}

void recv_search(int sock)
{
    int str_len;
    while ((str_len = read(sock, msg, sizeof(msg))) == -1)
        error_handling("read() error");
    msg[str_len] = 0;
    std::string res(msg);
}

void multi_recv_search(int sock, int size)
{
    for (int i = 0; i < size; i++)
    {
        recv_search(sock);
        write(sock, "a", 1);
    }
}

void *readvRes(void *arg)
{
    sleep(2);
    int sock = *((int *)arg);
    char tempmsg[80000000];
    // sleep(2);
    int len = read(sock, tempmsg, strlen(msg));
    if (len == -1)
        error_handling("readv() error:");
    std::string temp(tempmsg);
    return NULL;
}
