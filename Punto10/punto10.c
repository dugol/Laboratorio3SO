#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <wait.h>
#include <string.h>

int main(int argc, char *argv[])
{
    pid_t pid_h1, pid_h2;
    pid_t pid_n1, pid_n2;
    int state;
    printf("Hilo principal- PID %d, PID padre: %d\n", getpid(), getppid());
    pid_h2 = fork();
    if (pid_h2 == 0)
    {
        printf("Hijo2- PID: %d, PID padre %d\n", getpid(), getppid());
        pid_n1 = fork();
        if (pid_n1 == 0)
        {
            printf("Nieto1- PID: %d, PID padre %d\n", getpid(), getppid());
        }
        else
        {
            pid_n2 = fork();
            if (pid_n2 == 0)
            {
                printf("Nieto2- PID: %d, PID padre %d\n", getpid(), getppid());
            }
            else
            {
                wait(&state);
                wait(&state);
            }
        }
    }
    else
    {
        pid_h1 = fork();
        if (pid_h1 == 0)
        {
            printf("Hijo1- PID: %d, PID padre: %d\n", getpid(), getppid());
        }
        else
        {
            wait(&state);
            wait(&state);
        }
    }

    return 0;
}