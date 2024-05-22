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

#include "classes_sg_01.cpp"

#define BUF_SIZE 1024
#define MAX_CLNT 256

void *handle_clnt(void *arg);
void echo_msg(char *msg, int len, int clnt_sock);
void error_handling(std::string msg);
void charToStr(char *msg, string &string, int size);
void send_search(std::vector<string> res, int clnt_sock);
void multi_send_search(std::vector<std::vector<std::string>> mres, int clnt_sock);
void writevRes(std::vector<std::vector<std::string>> mres, int clnt_sock);
std::string subWritevRes(std::vector<std::string> str, std::string temp);

int clnt_cnt = 0;
int clnt_socks[MAX_CLNT];
pthread_mutex_t mutx;
// 

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
        // clnt_sock에 클라이언트에서 받아온 데이터가 담겨있겠네 
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

void *handle_clnt(void *arg)
{
    Rent a("ADMIN", "1234");
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

            pthread_mutex_lock(&mutx);          // 뮤텍스 시작
            // db 확인
            int res_log = a.LOGIN(id, pw);
            pthread_mutex_unlock(&mutx); // 뮤텍스 종료
            std::string reslogstr = to_string(res_log);
            strcpy(sendmsg, reslogstr.c_str());
            sendmsg[strlen(reslogstr.c_str())] = 0;
            // 로그인 결과 송신
            write(clnt_sock, sendmsg, strlen(sendmsg));

            if (res_log == 0) // 로그인 성공
            {

                while (1)
                {
                    // 로그인 성공(211)
                    std::string res_up = a.UPDATE_USER(id); // update 등급(버그 발생 중)
                    // 대여를 원하는 도서의 등록번호 수신
                    while ((str_len = read(clnt_sock, recv_msg, sizeof(recv_msg))) == -1)
                        error_handling("read() error");
                    recv_msg[str_len] = 0;
                    charToStr(recv_msg, b_book, strlen(recv_msg));

                    // q || Q 입력시 반복문 탈출
                    if (b_book == "q" || b_book == "Q")
                    {
                        break;
                    }

                    // 도서상태확인 함수 작동 및 결과 반환
                    pthread_mutex_lock(&mutx);
                    std::string res_bb = a.Borrow_book(id, b_book);
                    pthread_mutex_unlock(&mutx);

                    // 작동함수 결과 변환(INT -> STRING)

                    // 도서상태확인 결과 송신(STRING -> CHAR*)
                    write(clnt_sock, res_bb.c_str(), strlen(res_bb.c_str()));
                }
            }
            else // 로그인 실패
            {
                continue;
            }
        }
        // 완성
        else if (choice == "2" || choice == "회원가입")
        {
            while (1)
            {
                std::string id;
                std::string pn;
                std::string mail;
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
                        break;
                }
                // pw 수신
                while ((str_len = read(clnt_sock, recv_msg, sizeof(recv_msg))) == -1)
                    error_handling("read() error");
                recv_msg[str_len] = 0;
                std::string pw(recv_msg);
                // name 수신
                while ((str_len = read(clnt_sock, recv_msg, sizeof(recv_msg))) == -1)
                    error_handling("read() error");
                recv_msg[str_len] = 0;
                std::string Nickname(recv_msg);
                // adr 수신
                while ((str_len = read(clnt_sock, recv_msg, sizeof(recv_msg))) == -1)
                    error_handling("read() error");
                recv_msg[str_len] = 0;
                std::string adr(recv_msg);
                while (1)
                {
                    // pn 수신
                    while ((str_len = read(clnt_sock, recv_msg, sizeof(recv_msg))) == -1)
                        error_handling("read() error");
                    recv_msg[str_len] = 0;
                    charToStr(recv_msg, pn, strlen(recv_msg));
                    // std::string pn(recv_msg);
                    std::string check_pn = a.SINGUP_PHONEcheck(pn);
                    // check_pn 송신
                    write(clnt_sock, check_pn.c_str(), strlen(check_pn.c_str()));
                    if (check_pn == "g")
                        break;
                }
                while (1)
                {
                    // mail 수신
                    while ((str_len = read(clnt_sock, recv_msg, sizeof(recv_msg))) == -1)
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
                std::string check_sign = a.SIGNUP(id, pw, Nickname ,  mail);
                write(clnt_sock, check_sign.c_str(), strlen(check_sign.c_str()));
                if (check_sign == "a")
                    break;
            }
        }
        // 함수 미완성
        else if (choice == "3" || choice == "도서검색")
        {
            while (1)
            {
                // 도서검색 옵션 수신
                while ((str_len = read(clnt_sock, recv_msg, sizeof(recv_msg))) == -1)
                    error_handling("read() error");
                recv_msg[str_len] = 0;
                std::string find_book1(recv_msg);

                if (find_book1 == "q" || find_book1 == "Q")
                {
                    break;
                }
                else if (find_book1 == "1")
                {
                    // 도서명 수신
                    while ((str_len = read(clnt_sock, recv_msg, sizeof(recv_msg))) == -1)
                        error_handling("read() error");
                    recv_msg[str_len] = 0;
                    std::string find_book2(recv_msg);
                    // 단순검색 함수 발동
                    // pthread_mutex_lock(&mutx);
                    std::string res_fb2 = a.search_book(find_book2);
                    // pthread_mutex_unlock(&mutx);
                    // 단순검색 함수결과 송신
                    write(clnt_sock, res_fb2.c_str(), strlen(res_fb2.c_str()));
                    sleep(0);
                    // 단순검색 함수결과 판단
                    if (res_fb2 == "a")
                    {
                        pthread_mutex_lock(&mutx);
                        std::vector<std::vector<std::string>> res = a.res_search();
                        pthread_mutex_unlock(&mutx);
                        std::string temp;
                        std::vector<std::vector<std::string>>::iterator it = res.begin();
                        for (it; it != res.end(); it++)
                        {
                            std::vector<std::string> tvec = *it;
                            std::vector<std::string>::iterator iter;
                            for (iter = tvec.begin(); iter != tvec.end(); iter++)
                            {
                                temp += *iter;
                                if (iter != tvec.end() - 1)
                                    temp += ", ";
                            }
                            temp += "\n";
                        }
                        write(clnt_sock, temp.c_str(), strlen(temp.c_str()));
                        temp.resize(0);
                    }
                    else if (res_fb2 == "b")
                    {
                        continue;
                    }
                }
                else if (find_book1 == "2")
                {
                    // 도서 이름 수신
                    while ((str_len = read(clnt_sock, recv_msg, sizeof(recv_msg))) == -1)
                        error_handling("read() error");
                    recv_msg[str_len] = 0;
                    std::string SDB_name(recv_msg);
                    // 작가 이름 수신
                    while ((str_len = read(clnt_sock, recv_msg, sizeof(recv_msg))) == -1)
                        error_handling("read() error");
                    recv_msg[str_len] = 0;
                    std::string SDB_writer(recv_msg);
                    // 출판사 이름 수신
                    while ((str_len = read(clnt_sock, recv_msg, sizeof(recv_msg))) == -1)
                        error_handling("read() error");
                    recv_msg[str_len] = 0;
                    std::string SDB_producer(recv_msg);
                    // 출판연도 수신
                    while ((str_len = read(clnt_sock, recv_msg, sizeof(recv_msg))) == -1)
                        error_handling("read() error");
                    recv_msg[str_len] = 0;
                    std::string SDB_year(recv_msg);
                    // 장르 수신
                    while ((str_len = read(clnt_sock, recv_msg, sizeof(recv_msg))) == -1)
                        error_handling("read() error");
                    recv_msg[str_len] = 0;
                    std::string SDB_genre(recv_msg);
                    // 상세검색 함수 발동
                    // pthread_mutex_lock(&mutx);
                    std::string res_sdb = a.search_d_book(SDB_name, SDB_writer, SDB_producer, SDB_year, SDB_genre);
                    // pthread_mutex_unlock(&mutx);
                    // 상세검색 결과 송신
                    write(clnt_sock, res_sdb.c_str(), strlen(res_sdb.c_str()));
                    if (res_sdb == "a")
                    {
                        sleep(1);
                        // pthread_mutex_lock(&mutx);
                        std::vector<std::vector<std::string>> res = a.res_search();
                        // pthread_mutex_unlock(&mutx);
                        std::string temp;
                        std::vector<std::vector<std::string>>::iterator it = res.begin();
                        for (it; it != res.end(); it++)
                        {
                            std::vector<std::string> tvec = *it;
                            std::vector<std::string>::iterator iter;
                            for (iter = tvec.begin(); iter != tvec.end(); iter++)
                            {
                                temp += *iter;
                                if (iter != tvec.end() - 1)
                                    temp += ", ";
                            }
                            temp += "\n";
                        }
                        write(clnt_sock, temp.c_str(), strlen(temp.c_str()));
                        temp.resize(0);
                    }
                    else if (res_sdb == "b")
                    {
                        continue;
                    }
                }
                // 추천도서 시작
                else if (find_book1 == "3")
                {
                    // sleep(1);
                    // 추천도서 함수 발동
                    pthread_mutex_lock(&mutx);
                    std::string res_db = a.Sugest_b();
                    pthread_mutex_unlock(&mutx);
                    // 추천도서 검색 결과 송신
                    write(clnt_sock, res_db.c_str(), strlen(res_db.c_str()));

                    while ((str_len = read(clnt_sock, recv_msg, sizeof(recv_msg))) == -1)
                        error_handling("read() error");
                    recv_msg[str_len] = 0;
                    std::string res_sdb(recv_msg);

                    if (res_sdb == "a")
                    {
                        sleep(1);
                        pthread_mutex_lock(&mutx);
                        std::vector<std::vector<std::string>> res = a.res_search();
                        pthread_mutex_unlock(&mutx);
                        std::string temp;
                        std::vector<std::vector<std::string>>::iterator it = res.begin();
                        for (it; it != res.end(); it++)
                        {
                            std::vector<std::string> tvec = *it;
                            std::vector<std::string>::iterator iter;
                            for (iter = tvec.begin(); iter != tvec.end(); iter++)
                            {
                                temp += *iter;
                                if (iter != tvec.end() - 1)
                                    temp += ", ";
                            }
                            temp += "\n";
                        }
                        write(clnt_sock, temp.c_str(), strlen(temp.c_str()));
                        temp.resize(0);
                    }
                    else if (res_sdb == "b")
                    {
                        continue;
                    }
                }
                // 추천도서 끝
            }
        }
        // 완성
        else if (choice == "4" || choice == "도서반납")
        {
            while (1)
            {
                // 입력받은 등록번호 수신
                while ((str_len = read(clnt_sock, recv_msg, sizeof(recv_msg))) == -1)
                    error_handling("read() error");
                recv_msg[str_len] = 0;
                std::string return_book(recv_msg);
                // q입력시 종료
                if (return_book == "q" || return_book == "Q")
                    break;
                // 반납상태확인 함수 발동
                pthread_mutex_lock(&mutx);
                std::string res_ret = a.Return_book(return_book);
                pthread_mutex_unlock(&mutx);
                //책 반납 후 블랙회원 판별
                a.makeblack(return_book);
                // 반납상태확인 송신
                write(clnt_sock, res_ret.c_str(), strlen(res_ret.c_str()));
            }
        }
        else
        {
            continue;
        }
    }
    std::cout << "end" << std::endl; // 종료 확인

    pthread_mutex_lock(&mutx);
    for (i = 0; i < clnt_cnt; i++) // remove disconnected clinet
    {
        if (clnt_sock == clnt_socks[i])
        {
            while (i++ < clnt_cnt - 1)
                clnt_socks[i] = clnt_socks[i + 1];
            break;
        }
    }
    clnt_cnt--;
    pthread_mutex_unlock(&mutx);
    close(clnt_sock);
    return NULL;
}

void echo_msg(char *recv_msg, int len, int clnt_sock) // echo sended msg
{
    int i;
    pthread_mutex_lock(&mutx);
    write(clnt_sock, recv_msg, len);
    pthread_mutex_unlock(&mutx);
}

void error_handling(std::string msg)
{
    std::cout << msg << errno << std::endl;
    exit(1);
}

void charToStr(char *msg, string &string, int size)
{
    string.resize(0);
    for (int i = 0; i < size; i++)
        string.push_back(msg[i]);
}

void send_search(std::vector<string> res, int clnt_sock)
{
    std::string temp = "";
    char recv[1] = {};

    for (std::vector<string>::iterator iter = res.begin(); iter != res.end(); iter++)
    {
        temp += *iter;
        if (iter != res.end() - 1)
            temp += ", ";
    }
    temp += "\n";
    std::string ssres(temp);
    write(clnt_sock, ssres.c_str(), strlen(ssres.c_str()));
}

void multi_send_search(std::vector<std::vector<std::string>> mres, int clnt_sock)
{
    char temp[1] = {};
    std::vector<std::vector<std::string>>::iterator it = mres.begin();
    for (it; it != mres.end(); it++)
    {
        send_search(*it, clnt_sock);
        while (1)
        {
            if (read(clnt_sock, temp, 1) != -1)
                ;
            break;
        }
    }
}

std::string subWritevRes(std::vector<std::string> str, std::string temp)
{
    std::vector<std::string>::iterator iter;
    for (iter = str.begin(); iter != str.end(); iter++)
    {
        temp += *iter;
        if (iter != str.end() - 1)
            temp += ", ";
    }
    temp += "\n";
    return temp;
}

void writevRes(std::vector<std::vector<std::string>> mres, int clnt_sock)
{
    // sleep(1);
    std::string temp;
    std::vector<std::vector<std::string>>::iterator it = mres.begin();
    for (it; it != mres.end(); it++)
    {
        subWritevRes(*it, temp);
    }
    write(clnt_sock, temp.c_str(), sizeof(temp.c_str()));
}
