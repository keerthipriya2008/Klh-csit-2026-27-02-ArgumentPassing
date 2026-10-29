#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int fd;

    char data[] = "Jhansi - CSIT Operating System Project";

    char buffer[200];

    printf("====================================\n");
    printf("       CO5 - FILE SYSTEM\n");
    printf("====================================\n");

    fd = open("student.txt",
              O_CREAT | O_WRONLY | O_TRUNC,
              0644);

    if (fd == -1)
    {
        perror("File creation failed");
        return 1;
    }

    printf("\nFile opened successfully.\n");

    write(fd, data, strlen(data));

    printf("Data written successfully.\n");

    close(fd);

    fd = open("student.txt", O_RDONLY);

    if (fd == -1)
    {
        perror("File opening failed");
        return 1;
    }

    int bytes_read =
        read(fd, buffer, sizeof(buffer) - 1);

    if (bytes_read == -1)
    {
        perror("Read failed");
        close(fd);
        return 1;
    }

    buffer[bytes_read] = '\0';

    printf("\nData read from file:\n");
    printf("%s\n", buffer);

    close(fd);

    printf("\nFile operation completed.\n");

    return 0;
}