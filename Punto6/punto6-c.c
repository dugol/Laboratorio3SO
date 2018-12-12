#include<stdio.h>
#include<unistd.h>
main() {
    pid_t pid_hijo;
    pid_t pid_nieto;
    pid_hijo = fork();
    if (pid_hijo == 0)
    {
        pid_nieto = fork();
        if (pid_nieto == 0)
        {
            printf("!\n");
        }
        else
        {            
            printf("Mundo ");

        }
    }

    else
    {
        printf("Hola ");

    }

    return 0;
}