#include <iostream>
#include <sstream>
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
#include <algorithm>

#define MAX_CLNT 65535
int BUFFSIZE = 1024;

static void error_handling(std::string msg);
void deliverMsg(int sock, std::string msg);
std::string arriveMsg(int sock);
std::string intro();
void *generate_clnt(void *arg);
void membership(std::vector<std::string> &vec);

std::vector<std::vector<std::string>> matelist_show(std::string lines);
void mateshow(std::vector<std::vector<std::string>> mates);
int main(int argc, char *argv[])
{
    int sock;
    struct sockaddr_in serv_addr;
    pthread_t snd_thread, rcv_thread;
    void *thread_return;
    // if (argc != 3)
    // {
    //     printf("Usage : %s <IP> <port>\n", argv[0]);
    //     exit(1);
    // }

    sock = socket(PF_INET, SOCK_STREAM, 0);
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    // serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    serv_addr.sin_port = htons(atoi(argv[2]));
    // serv_addr.sin_port = htons(atoi("10004"));

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
std::string login(int sock, std::string &id)
{
    std::string res;
    // std::string id;
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
    system("clear");
    std::cout << "채팅프로그램\n"
              << "Q. 로그아웃\n"
              << "1. 채팅창신설\n"
              << "2. 채팅창접속\n"
              << "3. 친구관리\n";
    //   << "4. 계정관리\n";
    std::cout << "원하시는 기능을 선택하시오.\n";
    std::string choice;
    getline(std::cin, choice);
    return choice;
}

void *generate_clnt(void *arg)
{
    int sock = *((int *)arg);
    std::string first;
    std::string res;
    std::string id;
    std::vector<std::string> result;
    std::string matesLines;

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
            res = login(sock, id);
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
                    deliverMsg(sock, res);
                    // 로그아웃
                    if (res == "q" || res == "Q")
                    {
                        // std::cout << "로그아웃\n";
                        std::string logout_signal = arriveMsg(sock);
                        if (logout_signal == "1")
                        {
                            std::cout << "로그아웃 성공 .\n";
                            break;
                        }
                        else
                            break;
                    }
                    // 채팅창신설
                    else if (res == "1")
                    {
                        // 친구목록 보여주기, 채팅방 이름입력, 친구 고르기 , 서버에서 보내고 서버에서 디비 업데이트 하고
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
                            system("clear");
                            res = "";
                            std::cout << "친구관리\n";
                            std::cout << "Q. 뒤로가기\n";
                            std::cout << "1. 친구목록보기\n";
                            std::cout << "2. 친구추가\n";
                            std::cout << "3. 친구삭제\n";
                            std::cout << "4. 친구요청확인\n";
                            std::cout << "원하시는 기능을 선택하시오: ";
                            getline(std::cin, res);
                            deliverMsg(sock, res);
                            if (res == "q" || res == "Q")
                            {
                                std::cout << "친구관리를 종료합니다\n";
                                break;
                            }
                            // 친구 목록 보기 (채팅창으로 옮길까 생각중)
                            else if (res == "1")
                            {
                                // system("clear");
                                std::string lines = arriveMsg(sock);
                                std::vector<std::vector<std::string>> mates;
                                mates = matelist_show(lines);
                                if (mates.size() == 0)
                                {
                                    std::cout << "아무런 친구가 없습니다.\n";
                                    std::cout << "\n계속하려면 ENTER\n";
                                    getline(std::cin, res);
                                    res = "";
                                    continue;
                                }
                                // 보여주기
                                mateshow(mates);
                                std::cout << "\n계속하려면 ENTER\n";
                                getline(std::cin, res);
                                res = "";
                                continue;
                            }
                            // 친구 추가
                            else if (res == "2")
                            {
                                system("clear");
                                std::string matenum;

                                std::cout << "친구추가\n"
                                          << "추가하려는 친구의 고유번호를 입력하세요\n";
                                getline(std::cin, matenum);
                                deliverMsg(sock, matenum);
                                std::string res_addMate = arriveMsg(sock);
                                if (res_addMate == "Y")
                                {
                                    std::cout << "친구 추가에 성공하였습니다.\n";
                                    std::cout << "\n계속하려면 ENTER\n";

                                    getline(std::cin, res);
                                    res = "";
                                    continue;
                                }
                                // 성공Y, 부존N, 기존n, 에러e
                                else
                                {
                                    std::cout << "친구 추가에 실패하였습니다.\n";
                                    std::cout << "\n계속하려면 ENTER\n";

                                    getline(std::cin, res);
                                    res = "";
                                    continue;
                                }
                            }
                            // 친구 삭제
                            else if (res == "3")
                            {
                                system("clear");
                                ///////////////////////////////////////
                                std::string lines = arriveMsg(sock);
                                std::vector<std::vector<std::string>> mates;
                                mates = matelist_show(lines);
                                if (mates.size() == 0)
                                {
                                    std::cout << "아무런 친구가 없습니다.\n";
                                    std::cout << "\n계속하려면 ENTER\n";
                                    getline(std::cin, res);
                                    res = "";
                                    continue;
                                }
                                // 보여주기
                                mateshow(mates);
                                ////////////////////////////
                                std::cout << "친구삭제\n"
                                          << "삭제하려는 친구의 ID를 입력하세요\n";
                                std::string Fid;
                                getline(std::cin, Fid);
                                deliverMsg(sock, Fid);
                                std::string res_erase = arriveMsg(sock);
                                if (res_erase == "Y")
                                {
                                    std::cout << "친구삭제에 성공했습니다.\n";
                                    std::cout << "\n계속하려면 ENTER\n";

                                    getline(std::cin, res);
                                    res = "";
                                    continue;
                                }
                                else
                                {
                                    std::cout << "친구삭제에 실패했습니다.\n";
                                    std::cout << "\n계속하려면 ENTER\n";

                                    getline(std::cin, res);
                                    res = "";
                                    continue;
                                }
                            }
                            // 친구 요청 확인
                            else if (res == "4")
                            {
                                matesLines = arriveMsg(sock);
                                // 버그나 실패 확인
                                if (matesLines == "e")
                                {
                                    std::cout << "친구요청확인에 실패했습니다.\n";
                                    std::cout << "\n계속하려면 ENTER\n";

                                    getline(std::cin, res);
                                    res = "";
                                    continue;
                                }

                                std::stringstream SSMLS(matesLines);
                                std::string ML = "";
                                std::vector<std::string> mNOs;
                                int count = 0;
                                while (getline(SSMLS, ML))
                                {
                                    count++;
                                    std::stringstream SSML(ML);
                                    std::string mNo;
                                    std::string mNick;
                                    std::string mS;

                                    getline(SSML, mNo, ',');
                                    getline(SSML, mNick, ',');

                                    mNOs.push_back(mNo);
                                    std::cout << count;
                                    std::cout << " || 고유번호: " << mNo << " || 닉네임: " << mNick << " || 의 친구요청이 있습니다." << std::endl;
                                    ML = "";
                                }
                                int choice = 1;
                                while (choice != 0)
                                {
                                    std::cout << "관리할 친구요청을 선택하시오.(뒤로가기:0)\n";
                                    std::cin >> choice;
                                    if (!std::cin)
                                    {
                                        std::cout << "잘못된 입력입니다." << std::endl;
                                        std::cin.clear();
                                        std::cin.ignore(9999, '\n');
                                        continue;
                                    }
                                    else
                                    {
                                        if (choice > 0 && choice <= mNOs.size())
                                            break;
                                    }
                                }
                                std::cin.get();
                                deliverMsg(sock, std::to_string(choice));
                                if (choice == 0)
                                    continue;
                                // 선택한 고유번호 송신
                                deliverMsg(sock, mNOs.at(choice - 1));
                                system("clear");
                                std::cout << "친구요청을 받겠습니까?\n(친구승인: Y || 친구거절: N || 뒤로가기: Enter)\n";
                                std::string YN;
                                getline(std::cin, YN);
                                if (YN == "Y" || YN == "y")
                                {
                                    deliverMsg(sock, YN);
                                    continue;
                                }
                                else if (YN == "N" || YN == "n")
                                {
                                    deliverMsg(sock, YN);
                                    continue;
                                }
                                else
                                {
                                    deliverMsg(sock, YN);
                                    continue;
                                }
                            }
                            else
                            {
                                std::cout << "잘못된 입력입니다.\n";
                                std::cout << "\n계속하려면 ENTER\n";

                                getline(std::cin, res);
                                res = "";
                                deliverMsg(sock, res);
                                continue;
                            }
                        }
                    }
                    else
                    {
                        std::cout << "잘못된 입력입니다.\n";
                        std::cout << "\n계속하려면 ENTER\n";

                        getline(std::cin, res);
                        res = "";
                        deliverMsg(sock, res);
                        continue;
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

std::vector<std::vector<std::string>> matelist_show(std::string lines)
{
    std::stringstream input(lines);
    std::string line = "";
    std::cout << "asdfasdfasdfasdfasdfasdf" << std::endl;
    std::vector<std::vector<std::string>> mates;
    while (getline(input, line))
    {
        std::vector<std::string> mate;
        mate.resize(0);                 // mate 전부 비우기
        std::stringstream ssline(line); // line을 쪼개기
        std::string id, nick, status;   // 쪼개서 아래서 각각 담아줌
        getline(ssline, id, ',');
        getline(ssline, nick, ',');
        getline(ssline, status, ',');

        mate.push_back(id); // 쪼갠것들을 다시 mates에 담아줌
        mate.push_back(nick);
        mate.push_back(status);
        mates.push_back(mate); // mate에 담겨 있는 한사람의 정보를 벡터에 담아줌  mates에 한사람씩 담기네
        line = "";
    }

    return mates;
}
void mateshow(std::vector<std::vector<std::string>> mates)
{

    if (mates.size() != 0)
    {
        for (std::vector<std::vector<std::string>>::iterator i = mates.begin(); i != mates.end(); i++)
        {
            for (std::vector<std::string>::iterator j = i->begin(); j != i->end(); j++)
            {
                if (j == i->end() - 1)
                {
                    if (*j == "1")
                    {
                        std::cout << "접속\n";
                        break;
                    }
                    else if (*j == "0")
                    {
                        std::cout << "미접속\n";
                        break;
                    }
                }
                std::cout << *j << "  ";
            }
        }
    }
}