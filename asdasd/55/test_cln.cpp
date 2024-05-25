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

#define BUF_SIZE 100
#define NAME_SIZE 20
char name[NAME_SIZE] = "[DEFAULT]";
char msg[BUF_SIZE];

// #define MAX_CLNT 65535
// int BUFFSIZE = 1024;

static void error_handling(std::string msg);
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

    // generate_clnt((void *)&sock);
    pthread_create(&snd_thread, NULL, send_msg, (void *)&sock);
    pthread_create(&rcv_thread, NULL, recv_msg, (void *)&sock);
    pthread_join(snd_thread, &thread_return);
    pthread_join(rcv_thread, &thread_return);

    close(sock);
    return 0;
}

static void error_handling(std::string msg)
{
    std::cerr << msg << errno << std::endl;
    exit(1);
}

void *send_msg(void *arg) // send thread main
{
    int sock = *((int *)arg);
    char name_msg[NAME_SIZE + BUF_SIZE];
    std::string ddd;
    while (1)
    {
        std::cout<< "돌아"<<std::endl;
        fgets(msg, BUF_SIZE, stdin);
        getline(std::cin, ddd);

        if (!strcmp(msg, "q\n") || !strcmp(msg, "Q\n"))
        {
            close(sock);
            exit(0);
        }
        // sprintf(name_msg,"%s %s", name, msg);
        // write(sock, name_msg, strlen(name_msg));
        std::cout<< "슈웃"<<std::endl;

        write(sock, ddd.c_str(), strlen(ddd.c_str()));
    }
    return NULL;
}

void *recv_msg(void *arg) // read thread main
{
    int sock = *((int *)arg);
    char name_msg[NAME_SIZE + BUF_SIZE];
    int str_len;
    while (1)
    {
        // str_len = read(sock, name_msg, NAME_SIZE + BUF_SIZE - 1);
        while ((str_len = read(sock, msg, sizeof(msg))) == -1)
            error_handling("read() error");
        if (str_len == -1)
            return (void *)-1;
        name_msg[str_len] = 0;
        fputs(name_msg, stdout);
    }
    return NULL;
}

// void *chat(void *arg)
// {
//     int sock = *((int *)arg);
//     std::string first;
//     std::string res;
//     std::vector<std::string> result;
//     std::map<std::string, std::string> matesList;
// }