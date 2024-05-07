#include <stdio.h>
#include <unistd.h>
#include <signal.h>
void timeout(int sig)
{
    if (sig == SIGALRM)
        puts("Time out!");
    alarm(2);
}

void keycontrol(int sig)
{
    if (sig == SIGINT)

        puts("CTRL+C pressed");
}
int main(int argc, char *agrv[])
{
    int i;
    signal(SIGALRM, timeout);
    // 시그너이 발생하면 sleep 함수의 호출로 블로킹 상태에 있던 프로세스가 깨어납니다.
    signal(SIGINT, keycontrol);
    alarm(2);
    for (i = 0; i < 3; i++)
    {
        puts("wait...");
        sleep(100);
    }
    return 0;
}