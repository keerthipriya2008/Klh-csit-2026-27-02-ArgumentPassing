#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("====================================\n");

    printf("       ARGUMENT PASSING DEMO\n");
    printf("====================================\n");

    printf("Program Name: %s\n", argv[0]);
    printf("Number of Arguments: %d\n", argc - 1);

    if (argc == 1)
    {
        printf("No arguments were passed.\n");
    }
    else
    {
        printf("\nArguments received:\n");

        for (int i = 1; i < argc; i++)
        {
            printf("Argument %d: %s\n", i, argv[i]);
        }
    }

    printf("====================================\n");

    return 0;
}
