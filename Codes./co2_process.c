#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    printf("====================================\n");
    printf("       CO2 - PROCESS CONTROL\n");
    printf("====================================\n");

    if (argc < 2)
    {
        printf("No arguments supplied.\n");
        printf("Usage: ./co2_process argument1 argument2 ...\n");
        return 1;
    }

    printf("Parent PID: %d\n", getpid());

    printf("\nArguments received by parent:\n");

    for (int i = 1; i < argc; i++)
    {
        printf("Argument %d: %s\n", i, argv[i]);
    }

    printf("\nCalling fork()...\n");

    pid_t pid = fork();

    if (pid < 0)
    {
        perror("fork failed");
        return 1;
    }

    if (pid == 0)
    {
        printf("\n========== CHILD PROCESS ==========\n");

        printf("Child PID: %d\n", getpid());
        printf("Parent PID: %d\n", getppid());

        printf("\nChild is calling exec()...\n");

        char *new_args[argc + 1];

        new_args[0] = "./co1_argument";

        for (int i = 1; i < argc; i++)
        {
            new_args[i] = argv[i];
        }

        new_args[argc] = NULL;

        execv("./co1_argument", new_args);

        perror("exec failed");

        exit(1);
    }
    else
    {
        printf("\n========== PARENT PROCESS ==========\n");

        printf("Parent PID: %d\n", getpid());
        printf("Child PID: %d\n", pid);

        printf("\nParent is waiting using wait()...\n");

        int status;

        wait(&status);

        if (WIFEXITED(status))
        {
            printf("\nChild exited successfully.\n");
            printf("Child exit status: %d\n",
                   WEXITSTATUS(status));
        }

        printf("\nParent process completed.\n");
    }

    printf("\n====================================\n");

    return 0;
}