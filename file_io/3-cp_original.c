#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
/**
 * main - copies the content of a file to another file
 * @argc: the number of arguments passed to the program
 * @argv: an array of strings containing the arguments
 *
 * Return: 0 on success, or exits with an error code on failure
 */
int main(int argc, char *argv[])
{
	int sourceFD, destinationFD;
	char buffer[1024];
	ssize_t bytesRead, bytesWritten;

	/* Check if the number of arguments is correct */
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	/* Open the source file for reading and the destination file for writing */
	sourceFD = open(argv[1], O_RDONLY);

	/* Check if the source file was opened successfully */
	if (sourceFD == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	/*
	* Open the destination file for writing,
	* create it if it doesn't exist, and truncate it if it does
	*/
	destinationFD = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	/* Check if the destination file was opened successfully */
	if (destinationFD == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		close(sourceFD);
		exit(99);
	}

	/*
	* Read from the source file
	* and write to the destination file in chunks of 1024 bytes
	*/
	while ((bytesRead = read(sourceFD, buffer, 1024)) > 0)
	{
		/* Write the read bytes to the destination file */
		bytesWritten = write(destinationFD, buffer, bytesRead);

		/*
		* Check if the write operation was successful
		* and if the number of bytes written matches the number of bytes read
		*/
		if (bytesWritten == -1 || bytesWritten != bytesRead)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			close(sourceFD);
			close(destinationFD);
			exit(99);
		}

	}

	/* Check if the read operation was successful */
	if (bytesRead == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		close(destinationFD);
		exit(98);
	}

	/* Closing files and checking them if they closes properly*/
	if (close(sourceFD) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", sourceFD);
		exit(100);
	}

	if (close(destinationFD) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", destinationFD);
		exit(100);
	}

	return (0);
}
