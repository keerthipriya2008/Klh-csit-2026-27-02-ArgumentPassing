#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    int pipe_fd[2];

    char message[] = "Hello from Parent Process";

    char buffer[100];

    printf("====================================\n");
    printf("       CO3 - ANONYMOUS PIPE\n");
    printf("====================================\n");

    if (pipe(pipe_fd) == -1)
    {
        perror("pipe failed");
        return 1;
    }

    pid_t pid = fork();

    if (pid < 0)
    {
        perror("fork failed");
        return 1;
    }

    if (pid == 0)
    {
        close(pipe_fd[1]);

        printf("\nChild Process\n");
        printf("Child PID: %d\n", getpid());

        read(pipe_fd[0], buffer, sizeof(buffer));

        printf("\nMessage received through pipe:\n");
        printf("%s\n", buffer);

        close(pipe_fd[0]);

        exit(0);
    }
    else
    {
        close(pipe_fd[0]);

        printf("\nParent Process\n");
        printf("Parent PID: %d\n", getpid());

        printf("\nMessage sent:\n");
        printf("%s\n", message);

        write(pipe_fd[1],
              message,
              strlen(message) + 1);

        close(pipe_fd[1]);

        wait(NULL);

        printf("\nPipe communication completed.\n");
    }

    return 0;
}