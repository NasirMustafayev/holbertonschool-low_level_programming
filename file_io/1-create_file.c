#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
/**
 * create_file - creates a file and writes text to it
 * @filename: the name of the file to create
 * @text_content: the text to write to the file
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int fileDescriptor;
	ssize_t bytesWritten;

	if (filename == NULL)
		return (-1);

	fileDescriptor = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fileDescriptor == -1)
		return (-1);

	if (text_content != NULL)
	{
		bytesWritten = write(fileDescriptor, text_content, strlen(text_content));
		if (bytesWritten == -1)
			return (-1);
	}

	close(fileDescriptor);
	return (1);
}
