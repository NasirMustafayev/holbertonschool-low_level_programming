#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
/**
 * append_text_to_file - appends text to the end of a file
 * @filename: the name of the file to append to
 * @text_content: the text to append to the file
 *
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fileDescriptor;
	ssize_t bytesWritten;
	ssize_t length;

	if (filename == NULL)
		return (-1);

	fileDescriptor = open(filename, O_WRONLY | O_APPEND, 0600);
	if (fileDescriptor == -1)
		return (-1);

	if (text_content != NULL)
	{
		length = strlen(text_content);
		bytesWritten = write(fileDescriptor, text_content, length);
		if (bytesWritten == -1 || bytesWritten != length)
		{
			close(fileDescriptor);
			return (-1);
		}
	}

	close(fileDescriptor);
	return (1);
}
