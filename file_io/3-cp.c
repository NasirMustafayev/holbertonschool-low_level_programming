#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "main.h"

/**
 * open_source_file - opens source file for reading
 * @filename: name of the source file
 *
 * Return: file descriptor on success, exits with 98 on failure
 */
int open_source_file(char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
		exit(98);
	}
	return (fd);
}

/**
 * open_destination_file - opens/creates destination file
 * @filename: name of the destination file
 * @source_fd: source file descriptor (for cleanup on error)
 *
 * Return: file descriptor on success, exits with 99 on failure
 */
int open_destination_file(char *filename, int source_fd)
{
	int fd;

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
		close(source_fd);
		exit(99);
	}
	return (fd);
}

/**
 * copy_file_content - copies content from source to destination
 * @source_fd: source file descriptor
 * @dest_fd: destination file descriptor
 * @source_name: source filename (for error messages)
 * @dest_name: destination filename (for error messages)
 */
void copy_file_content(int source_fd, int dest_fd,
		       char *source_name, char *dest_name)
{
	char buffer[1024];
	ssize_t bytesRead, bytesWritten;

	while ((bytesRead = read(source_fd, buffer, 1024)) > 0)
	{
		bytesWritten = write(dest_fd, buffer, bytesRead);
		if (bytesWritten == -1 || bytesWritten != bytesRead)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", dest_name);
			close(source_fd);
			close(dest_fd);
			exit(99);
		}
	}
	if (bytesRead == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", source_name);
		close(dest_fd);
		exit(98);
	}
}

/**
 * close_files - closes file descriptors and checks for errors
 * @fd1: first file descriptor to close
 * @fd2: second file descriptor to close
 */
void close_files(int fd1, int fd2)
{
	if (close(fd1) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd1);
		exit(100);
	}
	if (close(fd2) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd2);
		exit(100);
	}
}

/**
 * main - copies the content of a file to another file
 * @argc: the number of arguments passed to the program
 * @argv: an array of strings containing the arguments
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int sourceFD, destinationFD;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	sourceFD = open_source_file(argv[1]);
	destinationFD = open_destination_file(argv[2], sourceFD);
	copy_file_content(sourceFD, destinationFD, argv[1], argv[2]);
	close_files(sourceFD, destinationFD);

	return (0);
}
