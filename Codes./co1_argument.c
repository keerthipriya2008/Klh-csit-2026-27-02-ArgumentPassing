#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("====================================\n");
    printf("       CO1 - ARGUMENT PASSING\n");
    printf("====================================\n");

    printf("argc = %d\n\n", argc);

    for (int i = 0; i < argc; i++)
    {
        printf("argv[%d] = %s\n", i, argv[i]);
    }

    printf("\nCommand completed successfully.\n");

    return 0;
}