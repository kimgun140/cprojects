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
#include <vector>
#include <map>

#define MAX_CLNT 65535
int BUFFSIZE = 1024;

static void error_handling(std::string msg);
void deliverMsg(int sock, std::string msg);
std::string arriveMsg(int sock);
std::string intro();
void *generate_clnt(void *arg);
void membership(std::vector<std::string> &vec);
void *recv_msg(void *arg);
void *send_msg(void *arg);
pthread_t snd_thread, rcv_thread;

int main(int argc, char *argv[])
{
    int sock;
    struct sockaddr_in serv_addr;
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

    generate_clnt((void *)&sock);

    close(sock);
}

static void error_handling(std::string msg)
{
    std::cerr << msg << errno << std::endl;
    exit(1);
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
    result.pop_back();

    return result;
}

std::string intro()
{
    std::string result = "";
    while (1)
    {
        if (result == "1" || result == "2" || result == "Q" || result == "q")
            break;
        std::cout << "시작\n"
                  << "1. 로그인\n"
                  << "2. 회원가입\n"
                  << "Q. 종료\n"
                  << "원하시는 항목을 입력하시오: ";
        getline(std::cin, result);
    }
    return result;
}

void membership(int sock, std::vector<std::string> &vec)
{
    while (1)
    {
        system("clear");
        std::string temp;
        std::string result;
        std::cout << "회원가입\n";
        while (1)
        {
            std::cout << "1. 아이디\n";
            std::cout << "사용하실 아이디를 입력하시오.\n";
            getline(std::cin, temp);
            deliverMsg(sock, temp);
            result = arriveMsg(sock);
            if (result == "a")
            {
                std::cout << "사용가능한 ID입니다.\n";
                vec.push_back(temp);
                break;
            }
            else if (result == "b")
            {
                std::cout << "중복된 ID입니다.\n";
                result = "";
                temp = "";
                continue;
            }
            else if (result == "c")
            {
                error_handling("DB오류");
                break;
            }
            else
            {
                std::cout << "알 수 없는 오류입니다.\n이상이 반복되면 관리자에게 연락하세요.\n";
                continue;
            }
        }
        while (1)
        {
            std::cout << "2. 비밀번호\n"
                      << "사용하실 비밀 번호를 입력하시오.\n";
            getline(std::cin, temp);
            if (temp == "")
            {
                std::cout << "잘못된 입력입니다.\n";
                continue;
            }
            else
            {
                std::cout << "사용가능한 비밀번호입니다.\n";
                vec.push_back(temp);
                break;
            }
        }
        while (1)
        {
            std::cout << "3. 이메일\n"
                      << "사용하실 이메일을 입력하시오.\n";
            getline(std::cin, temp);
            deliverMsg(sock, temp);
            result = arriveMsg(sock);
            if (result == "a")
            {
                std::cout << "사용 가능한 이메일입니다.\n";
                vec.push_back(temp);
                break;
            }
            else if (result == "b")
            {
                std::cout << "중복된 이메일입니다.\n";
                result = "";
                temp = "";
                continue;
            }
            else if (result == "c")
            {
                error_handling("DB오류");
                break;
            }
            else
            {
                std::cout << "알 수 없는 오류입니다.\n이상이 반복되면 관리자에게 연락하세요.\n";
                continue;
            }
        }
        while (1)
        {
            std::cout << "4. 닉네임\n"
                      << "사용하실 닉네임을 입력하십시오.\n";
            getline(std::cin, temp);
            if (temp == "")
            {
                std::cout << "잘못된 입력입니다.\n";
                continue;
            }
            else
            {
                std::cout << "사용 가능한 닉네임입니다.\n";
                vec.push_back(temp);
                break;
            }
        }
        while (1)
        {
            std::cout << "입력하신 정보를 확인합니다.\n";
            std::cout << "ID: " << vec[0] << std::endl;
            std::cout << "PW: " << vec[1] << std::endl;
            std::cout << "E-mail: " << vec[2] << std::endl;
            std::cout << "닉네임: " << vec[3] << std::endl;
            std::cout << "입력하신 정보가 맞습니까?\n1.예    2.아니오\n";
            getline(std::cin, temp);
            deliverMsg(sock, temp);
            if (temp == "1" || temp == "예" || temp == "y" || temp == "Y")
            {
                std::string result = vec[0] + "," + vec[1] + "," + vec[2] + "," + vec[3];
                deliverMsg(sock, result);
                vec.resize(0);
                // 확인필요
                result = arriveMsg(sock);
                std::cout << "당신의 고유번호는 [" + result + "] 입니다.\n5회 이상 로그인 실패 시 입력해야하므로 꼭 기억해주십시오.\n(다음으로 넘어가려면 ENTER)\n";
                getline(std::cin, result);
                result = "";
                vec.resize(0);
                return;
            }
            else if (temp == "2" || temp == "아니오" || temp == "n" || temp == "N")
            {
                std::cout << "회원가입을 중지합니다.\n";
                vec.resize(0);
                temp = "";
                return;
            }
            else
            {
                std::cout << "잘못된 입력입니다.\n";
                temp = "";
                continue;
            }
        }
    }
}

// 리턴값 성공시:"성공" || 실패시 "실패" || 오류발생시 "오류"
std::string login(int sock)
{
    std::string res;
    std::string id;
    std::string pw;
    std::string idpw;
    std::cout << "로그인 화면\n";
    std::cout << "ID: ";
    getline(std::cin, id);
    std::cout << "PW: ";
    getline(std::cin, pw);
    idpw = id + "," + pw;
    deliverMsg(sock, idpw);
    res = arriveMsg(sock);
    if (res == "9")
    {
        error_handling("Login error: ");
        return "오류";
    }
    else if (res == "5")
    {
        // deliverMsg(sock, res);
        // sleep(0);
        std::string unique;
        std::cout << "고유번호: ";
        getline(std::cin, unique);
        idpw = idpw + "," + unique;
        deliverMsg(sock, idpw);
        std::string res2;
        res2 = arriveMsg(sock);
        if (res2 == "9")
        {
            error_handling("SLogin error:");
            return "오류";
        }
        else if (res2 == "3")
        {
            std::cout << "잘못된 비밀번호입니다.\n로그인에 실패하였습니다.\n";
            return "실패";
        }
        else if (res2 == "2")
        {
            std::cout << "잘못된 아이디입니다.\n로그인에 실패하였습니다.\n";
            return "실패";
        }
        else if (res2 == "4")
        {
            std::cout << "잘못된 고유번호입니다.\n로그인에 실패하였습니다.\n";
            return "실패";
        }
        else if (res2 == "0")
        {
            std::cout << "로그인에 성공하였습니다.\n";
            return "성공";
        }
        else
        {
            std::cout << "알 수 없는 오류가 발생하였습니다.\n증상이 계속되면 관리자에게 문의하세요\n";
            return "오류";
        }
    }
    else if (res == "0")
    {
        std::cout << "로그인에 성공하였습니다.\n";
        return "성공";
    }
    else if (res == "1" || res == "2" || res == "3" || res == "4")
    {
        std::cout << "잘못된 비밀번호입니다.\n로그인에 실패하였습니다.\n";
        return "실패";
    }
    return "오류";
}

std::string after_login_intro()
{
    // system("clear");
    std::cout << "채팅프로그램\n"
              << "Q. 로그아웃\n"
              << "1. 채팅창신설\n"
              << "2. 채팅창접속\n"
              << "3. 친구관리\n"
              << "4. 계정관리\n";
    std::cout << "원하시는 기능을 선택하시오.\n";
    std::string choice;
    getline(std::cin, choice);
    return choice;
}

// std::string manage_mate(int sock)
// {
//     while(1)
//     {
//         manage_mate_intro();
//     }
// }
// void manage_mate_intro()
// {
//     system("clear");
//     std::cout << "친구관리\n";
//     std::cout << "Q. 뒤로가기\n"
//               << "1. 친구추가\n"
//               << "2. 친구삭제\n"
//               << "3. 친구신청관리\n";
// }
// void mates_list(std::string lines, std::map<std::string, std::string> &mapMates)

void *generate_clnt(void *arg)
{
    int sock = *((int *)arg);
    std::string first;
    std::string res;
    std::vector<std::string> result;
    std::map<std::string, std::string> matesList;
    while (1)
    {
        std::cout << "0-0-0" << std::endl;
        first = intro();
        std::cout << first << std::endl;
        deliverMsg(sock, first);

        if (first == "q" || first == "Q")
        {
            std::cout << "프로그램을 종료합니다.\n";
            break;
        }
        else if (first == "1" || first == "로그인")
        {
            res = login(sock);
            if (res == "오류")
            {
                break;
            }
            else if (res == "실패")
            {
                continue;
            }
            else if (res == "성공")
            {
                while (1)
                {
                    res = "";
                    res = after_login_intro();
                    std::cout << "성공\n";
                    deliverMsg(sock, res);
                    // 로그아웃
                    if (res == "q" || res == "Q")
                    {
                        std::cout << "로그아웃\n";
                        std::string logout_signal = arriveMsg(sock);
                        if (logout_signal == "1")
                        {
                            std::cout << "로그아웃 성공 .\n";
                            break;
                        }
                        // else
                        //     break;
                    }
                    // 채팅창신설
                    else if (res == "1")
                    {
                        std::cout<<"1번"<<std::endl;
                        // break;
                    }
                    // 채팅창접속
                    else if (res == "2")
                    {
                        std::cout << "채팅" << std::endl;
                        // break;

                     while(1){
                        pthread_create(&snd_thread, NULL, send_msg, (void *)&sock);
                        pthread_create(&rcv_thread, NULL, recv_msg, (void *)&sock);
                        pthread_detach(snd_thread);
                        pthread_detach(rcv_thread);
                     }
                    }
                    // 친구관리
                    else if (res == "3")
                    {
                        std::cout<<"3번"<<std::endl;
                        // break;


                    }
                    // 계정관리
                    else if (res == "4")
                    {
                        std::cout<<"4번"<<std::endl;
                        // break;


                    }
                    // 기타
                    else if (res == "5")
                    {
                        std::cout<<"5번"<<std::endl;
                        // break;

                        // continue;
                    }
                }
            }
            else
            {
                break;
            }
        }
        else if (first == "2" || first == "회원가입")
        {
            membership(sock, result);
        }
        else
        {
            std::cout << "잘못된 입력입니다.\n";
            continue;
        }
    }
    return NULL;
}

void *recv_msg(void *arg) // read thread main
{
    int sock = *((int *)arg);
    // char name_msg[NAME_SIZE+BUF_SIZE];
    int str_len;
    while (1)
    {
        std::string result = arriveMsg(sock);
        std::cout << result << std::endl;
    }
    return NULL;
}

// std::string arriveMsg(int sock)
// {
//     int str_len = 0;
//     char recv_msg[BUFFSIZE];
//     std::string result;
//     do
//     {
//         // 소켓에서 문자열을 읽어옴
//         str_len = read(sock, recv_msg, sizeof(recv_msg));
//         // 실패 시 에러 발생
//         if (str_len == -1)
//             error_handling("read() error");
//         // 받은 문자열 다음을 0으로 설정
//         recv_msg[str_len] = 0;
//         // string으로 변환하여 result에 append
//         result.append(std::string(recv_msg));
//     } while (recv_msg[str_len - 1] != EOF); // 받은 문자열의 마지막이 EOF가 아니면 반복
//     if (result.size() != 0)
//         result.pop_back();

//     return result;
// }
//
void *send_msg(void *arg) // send thread main
{
    int sock = *((int *)arg);
    while (1)
    {
        std::string msg;
        getline(std::cin, msg);
        if (msg == "q" || msg == "Q")
        {
            deliverMsg(sock, msg);
            break;
            // close(sock);
            // exit(0);
        }
        // sprintf(name_msg,"%s %s", name, msg);
        // write(sock, name_msg, strlen(name_msg));
        deliverMsg(sock, msg);
    }
    return NULL;
}

// void deliverMsg(int sock, std::string msg)
// {
//     // 문자열 끝에 EOF 추가
//     msg.push_back(EOF);
//     // 문자열을 자를 시작 포인트
//     int splitPoint = 0;

//     if (strlen(msg.c_str()) <= BUFFSIZE)
//         write(sock, msg.c_str(), strlen(msg.c_str())); // 만약 버퍼크기 보다 보내는 문자열이 작으면 바로 송신
//     else
//     {
//         // 만약 문자열의 크기가 버퍼크기보다 크다면
//         while (splitPoint > strlen(msg.c_str()))
//         {
//             // 버프 사이즈만큼 문자열을 잘라서
//             std::string tempMsg = msg.substr(splitPoint, splitPoint + BUFFSIZE);
//             // 문자열 송신
//             write(sock, tempMsg.c_str(), strlen(tempMsg.c_str()));
//             // 자를 시작 포인트 갱신
//             splitPoint += BUFFSIZE;
//             // 임시 문자열 초기화
//             tempMsg = "";
//         }
//     }
// }