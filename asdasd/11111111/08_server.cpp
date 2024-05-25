#include <iostream>
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
#include <algorithm>
#include "dbclass.cpp"

#define MAX_CLNT 65535

std::vector<int> clnt_socks;
int clnt_cnt = 0;
int BUFFSIZE = 1024;

void error_handling(std::string msg);
void *handle_clnt(void *arg);
std::string arriveMsg(int sock);
void deliverMsg(int sock, std::string msg);
std::string login(int clnt_sock, DB db);

int main(int argc, char *argv[])
{
    pthread_mutex_t mutx;

    int serv_sock, clnt_sock;
    struct sockaddr_in serv_adr, clnt_adr;
    socklen_t clnt_adr_sz;
    pthread_t t_id;

    // if (argc != 2)
    // {
    //     printf("Usage : %s <port>\n", argv[0]);
    //     exit(1);
    // }

    pthread_mutex_init(&mutx, NULL);
    serv_sock = socket(PF_INET, SOCK_STREAM, 0);

    memset(&serv_adr, 0, sizeof(serv_adr));
    serv_adr.sin_family = AF_INET;
    serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_adr.sin_port = htons(atoi(argv[1]));
    // serv_adr.sin_port = htons(atoi("10004"));

    if (bind(serv_sock, (struct sockaddr *)&serv_adr, sizeof(serv_adr)) == -1)
        error_handling("bind() error");

    if (listen(serv_sock, 5) == -1)
        error_handling("listen() error");

    while (1)
    {
        clnt_adr_sz = sizeof(clnt_adr);
        clnt_sock = accept(serv_sock, (struct sockaddr *)&clnt_adr, &clnt_adr_sz);

        pthread_mutex_lock(&mutx);
        clnt_socks.push_back(clnt_sock);
        pthread_mutex_unlock(&mutx);

        printf("Connectd client IP: %s \n", inet_ntoa(clnt_adr.sin_addr));
        pthread_create(&t_id, NULL, handle_clnt, (void *)&clnt_sock);
        pthread_detach(t_id);

        pthread_mutex_lock(&mutx);
        clnt_socks.erase(std::find(clnt_socks.begin(), clnt_socks.end(), clnt_sock));
        pthread_mutex_unlock(&mutx);
    }
    close(serv_sock);
    return 0;
}

void error_handling(std::string msg)
{
    std::cerr << msg << errno << std::endl;
    exit(1);
}

std::string arriveMsg(int sock)
{
    int str_len = 0;
    char recv_msg[BUFFSIZE];
    std::string result;
    do
    {
        // 소켓에서 문자열을 읽어옴
        str_len = read(sock, recv_msg, sizeof(recv_msg));
        // 실패 시 에러 발생
        if (str_len == -1)
            error_handling("read() error");
        // 받은 문자열 다음을 0으로 설정
        recv_msg[str_len] = 0;
        // string으로 변환하여 result에 append
        result.append(std::string(recv_msg));
    } while (recv_msg[str_len - 1] != EOF); // 받은 문자열의 마지막이 EOF가 아니면 반복
    if (result.size() != 0)
        result.pop_back();

    return result;
}

void deliverMsg(int sock, std::string msg)
{
    // 문자열 끝에 EOF 추가
    msg.push_back(EOF);
    // 문자열을 자를 시작 포인트
    int splitPoint = 0;

    if (strlen(msg.c_str()) <= BUFFSIZE)
        write(sock, msg.c_str(), strlen(msg.c_str())); // 만약 버퍼크기 보다 보내는 문자열이 작으면 바로 송신
    else
    {
        // 만약 문자열의 크기가 버퍼크기보다 크다면
        while (splitPoint > strlen(msg.c_str()))
        {
            // 버프 사이즈만큼 문자열을 잘라서
            std::string tempMsg = msg.substr(splitPoint, splitPoint + BUFFSIZE);
            // 문자열 송신
            write(sock, tempMsg.c_str(), strlen(tempMsg.c_str()));
            // 자를 시작 포인트 갱신
            splitPoint += BUFFSIZE;
            // 임시 문자열 초기화
            tempMsg = "";
        }
    }
}

// 로그인 함수에 id참조를 보내서 id를 가져왔음. 디버그필요.
void *handle_clnt(void *arg)
{
    DB db;
    int clnt_sock = *((int *)arg);
    std::string user_no;
    std::string user_id;
    std::string first;
    std::string temp;
    std::string res;
    std::string manage_mate_choice;
    std::string matesLines;

    while (1)
    {
        std::cout << "0-0-0" << std::endl;
        first = arriveMsg(clnt_sock);
        std::cout << first << std::endl;

        if (first == "q" || first == "Q")
        {
            break;
        }
        else if (first == "1" || first == "로그인")
        {
            temp = "";
            res = "";
            std::cout << "1-1-0\n";
            std::string login_first = "-1";
            std::string login_second = "-1";
            temp = arriveMsg(clnt_sock);
            login_first = db.check_login(temp, clnt_sock, user_id);
            deliverMsg(clnt_sock, login_first);
            if (login_first == "9")
            {
                res = "오류";
            }
            else if (login_first == "5")
            {
                temp = arriveMsg(clnt_sock);
                login_second = db.check_SLogin(temp, clnt_sock, user_id);
                deliverMsg(clnt_sock, login_second);
                if (login_second == "9")
                {
                    res = "오류";
                    std::cout << res << std::endl;
                    continue;
                }
                else if (login_second == "2")
                {
                    res = "아이디 실패";
                    std::cout << res << std::endl;
                    continue;
                }
                else if (login_second == "3")
                {
                    res = "비밀번호 실패";
                    std::cout << res << std::endl;
                    continue;
                }
                else if (login_second == "4")
                {
                    res = "고유번호 실패";
                    std::cout << res << std::endl;
                    continue;
                }
                else if (login_second == "0")
                {
                }
                else
                {
                    res = "오류";
                    std::cout << res << std::endl;
                    continue;
                }
            }
            else if (login_first == "0")
            {
            }
            else if (login_first == "1" || login_first == "2" || login_first == "3" || login_first == "4")
            {
                res = "실패";
                std::cout << "로그인 실패" << std::endl;
                continue;
            }
            else
            {
                res = "오류";
                std::cout << "로그인 오류" << std::endl;
                continue;
            }
            if (login_first == "0" || login_second == "0")
            {
                while (1)
                {
                    res = "";
                    std::cout << "로그인 성공" << std::endl;
                    res = arriveMsg(clnt_sock);
                    // 로그아웃
                    if (res == "q" || res == "Q")
                    {
                        // 로그아웃 성공하면
                        std::string logout_signal = db.Logout(user_id);
                        deliverMsg(clnt_sock, logout_signal);
                        if (logout_signal == "1")
                            break;
                        else
                            break;
                    }
                    // 채팅창신설
                    else if (res == "1")
                    {
                    }
                    // 채팅창접속
                    else if (res == "2")
                    {
                    }
                    // 친구관리
                    else if (res == "3")
                    {
                        while (1)
                        {
                            std::cout << "3" << std::endl;
                            manage_mate_choice = arriveMsg(clnt_sock);
                            // 뒤로가기
                            if (manage_mate_choice == "q" || manage_mate_choice == "Q")
                            {
                                break;
                            }
                            // 친구 목록 보기
                            else if (manage_mate_choice == "1")
                            {
                                std::string lines = db.Call_Mate_all(user_id);
                                // 친구 목록 전체를 보내주네
                                deliverMsg(clnt_sock, lines);
                                continue;
                            }
                            // 친구 추가
                            else if (manage_mate_choice == "2")
                            {

                                std::string matenum = arriveMsg(clnt_sock);
                                std::string res_addMate = db.add_mate(user_id, matenum);
                                deliverMsg(clnt_sock, res_addMate);
                                continue;
                                
                            }
                            // 친구 삭제
                            else if (manage_mate_choice == "3")
                            {
                                std::string lines = db.Call_Mate_all(user_id);
                                deliverMsg(clnt_sock, lines);
                                std::string Fid = arriveMsg(clnt_sock);
                                std::string res_EM = db.Erase_Mate(user_id, Fid);
                                deliverMsg(clnt_sock, res_EM);
                                continue;
                            }
                            // 친구 요청 확인
                            else if (manage_mate_choice == "4")
                            {
                                matesLines = db.Call_requestMate(user_id);
                                deliverMsg(clnt_sock, matesLines);
                                // 버그나 실패 확인
                                if (matesLines == "e")
                                {
                                    continue;
                                }
                                std::string count = arriveMsg(clnt_sock);
                                std::cout << count << std::endl;
                                if (count == "0")
                                    continue;
                                // 선택한 고유번호 수신
                                std::string mNo_arrived = arriveMsg(clnt_sock);
                                std::cout << mNo_arrived << std::endl;
                                std::string YN = arriveMsg(clnt_sock);
                                if (YN == "Y" || YN == "y")
                                {
                                    db.accept_mate(user_id, mNo_arrived);
                                    continue;
                                }
                                else if (YN == "N" || YN == "n")
                                {
                                    db.deny_mate(user_id, mNo_arrived);
                                    continue;
                                }
                                else
                                {
                                    continue;
                                }
                            }
                            else
                            {
                                arriveMsg(clnt_sock);
                                continue;
                            }
                        }
                    }
                    else
                    {
                        arriveMsg(clnt_sock);
                        continue;
                    }
                }
            }
        }
        else if (first == "2" || first == "회원가입")
        {
            while (1)
            {
                std::cout << "1-2-0\n";
                while (1)
                {
                    std::cout << "1-2-id\n";
                    temp = arriveMsg(clnt_sock);
                    std::cout << temp << std::endl;
                    res = db.IDcheck(temp);
                    std::cout << res << std::endl;
                    deliverMsg(clnt_sock, res);
                    if (res == "a")
                    {
                        break;
                    }
                    else if (res == "b")
                    {
                        continue;
                    }
                    else if (res == "c")
                    {
                        break;
                    }
                }
                while (1)
                {
                    std::cout << "1-2-e\n";
                    temp = arriveMsg(clnt_sock);
                    std::cout << temp << std::endl;
                    res = db.EMAILcheck(temp);
                    std::cout << res << std::endl;
                    deliverMsg(clnt_sock, res);
                    if (res == "a")
                        break;
                    else if (res == "b")
                        continue;
                    else if (res == "c")
                        break;
                    else
                        continue;
                }
                while (1)
                {
                    temp = arriveMsg(clnt_sock);
                    if (temp == "1" || temp == "예" || temp == "y" || temp == "Y")
                    {
                        res = arriveMsg(clnt_sock);
                        res = db.insert_member(res);
                        deliverMsg(clnt_sock, res);
                        break;
                    }
                    else if (temp == "2" || temp == "아니오" || temp == "n" || temp == "N")
                    {
                        std::cout << "회원가입을 중지합니다.\n";
                        res = "";
                        break;
                    }
                    else
                    {
                        std::cout << "잘못된 입력입니다.\n";
                        temp = "";
                        res = "";
                        continue;
                    }
                }
                if (temp == "1" || temp == "예" || temp == "y" || temp == "Y")
                {
                    temp = "";
                    break;
                }
                else if (temp == "2" || temp == "아니오" || temp == "n" || temp == "N")
                {
                    temp = "";
                    break;
                }
            }
        }
        else
        {
            std::cout << "잘못된 입력입니다.\n";
            continue;
        }
    }
    return NULL;
}