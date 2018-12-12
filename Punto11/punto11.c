#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <wait.h>

long factorial(int n);

int main(int argc, char *argv[])
{
    pid_t pid_h1, pid_h2;
    int state;
    pid_h1 = fork();
    if (pid_h1 == 0)
    {
        for (int i = 1; i <= 10; i++)
        {
            int f = factorial(i);
            printf("Hijo1- fact(%d) = %d\n", i, f);
        }
    }
    else
    {
        pid_h2 = fork();
        if (pid_h2 == 0)
        {
            for (int i = 1; i <= 10; i++)
            {
                int f = factorial(i);
                printf("Hijo2- fact(%d) = %d\n", i, f);
            }
        }
        else
        {
            wait(&state);
            wait(&state);
        }
    }

    return 0;
}

long factorial(int n)
{
    if (n == 0)
        return 1;
    else
        return (n * factorial(n - 1));
}
