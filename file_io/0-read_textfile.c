#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "main.h"
/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 * @filename: the name of the file to read
 * @letters: the number of letters it should read and print
 *
 * Return: the actual number of letters it could read and print,
 * or 0 if it fails
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	if (filename == NULL)
		return (0);

	int fileDescriptor = open(filename, O_RDONLY);

	if (fileDescriptor == -1)
		return (0);

	char buffer[letters];
/*char *buffer = malloc(letters); dynamically allocate memory for the buffer*/
	ssize_t bytesRead = read(fileDescriptor, buffer, letters);

	if (bytesRead == -1)
		return (0);

	ssize_t bytesWritten = write(STDOUT_FILENO, buffer, bytesRead);

	close(fileDescriptor);

	if (bytesWritten != bytesRead)
		return (0);

	return (bytesWritten);
}
