#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    printf("====================================\n");
    printf("    PROCESS ARGUMENT PASSING DEMO\n");
    printf("====================================\n");

    if (argc < 2)
    {
        printf("Usage: %s <argument1> <argument2> ...\n", argv[0]);
        return 1;
    }

    printf("Parent Process PID: %d\n", getpid());
    printf("Arguments to be passed:\n");

    for (int i = 1; i < argc; i++)
    {
        printf("Argument %d: %s\n", i, argv[i]);
    }

    printf("\nCreating child process using fork()...\n");

    pid_t pid = fork();

    if (pid < 0)
    {
        perror("fork failed");
        return 1;
    }

    if (pid == 0)
    {
        printf("\n--- CHILD PROCESS ---\n");
        printf("Child PID: %d\n", getpid());
        printf("Parent PID: %d\n", getppid());

        printf("Child is executing argument_demo using exec()...\n\n");

        char *new_arguments[argc + 1];

        new_arguments[0] = "./argument_demo";

        for (int i = 1; i < argc; i++)
        {
            new_arguments[i] = argv[i];
        }

        new_arguments[argc] = NULL;

        execv("./argument_demo", new_arguments);

        perror("exec failed");
        exit(1);
    }
    else
    {
        printf("\n--- PARENT PROCESS ---\n");
        printf("Parent PID: %d\n", getpid());
        printf("Child PID: %d\n", pid);

        printf("Parent is waiting for child using wait()...\n");

        int status;
        wait(&status);

        if (WIFEXITED(status))
        {
            printf("\nChild completed successfully.\n");
            printf("Child Exit Status: %d\n", WEXITSTATUS(status));
        }

        printf("Parent process completed.\n");
    }

    printf("====================================\n");

    return 0;
}
