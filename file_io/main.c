#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "main.h"

int main()
{
    int fd = open("file.txt", O_RDONLY);
    if(fd == -1)
    {
        printf("%d - Error trying to open the file\n", fd);
        return 0;
    }
    printf("%d - File opened successfully!\nContext:\n", fd);

    char buffer[1024];
    ssize_t bytesRead = read(fd, buffer, sizeof(buffer));
    
    if(bytesRead > 0)
    {
    printf("Printf: %s\n:", buffer);
    write(STDOUT_FILENO, buffer, bytesRead);
    }
    close(fd);

    printf("\nREAD_TEXTFILE\n");

    ssize_t n = read_textfile("file.txt",14);
    printf("\n(printed chars: %li)\n", n);
    return 0;
}
