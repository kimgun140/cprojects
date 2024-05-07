#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int status;
    pid_t pid = fork();

    if (pid == 0)
    {
        sleep(15);
        return 24;
    }
    else
    {
        while (!waitpid(-1, &status, WNOHANG))
        //자식이 종료될때까지 기다리기
        {
            sleep(3);
            puts("SLEEP 3SEC");
        }

        if (WIFEXITED(status))
            printf("Child send one: %d \n", WEXITSTATUS(status));
    }
    return 0;
}