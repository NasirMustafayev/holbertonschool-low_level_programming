#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>
/**
 * print_all - prints anything
 * @format: list of types of arguments passed to the function
 */
void print_all(const char * const format, ...)
{
	va_list args;
	int i = 0;
	char *str;
	const char *separators = "";

	va_start(args, format);
	while (format && format[i])
	{
		switch (format[i])
		{
			case 'c':
				printf("%s%c", separators, va_arg(args, int));
				break;
			case 'i':
				printf("%s%d", separators, va_arg(args, int));
				break;
			case 'f':
				printf("%s%f", separators, va_arg(args, double));
				break;
			case 's':
				str = va_arg(args, char *);
				if (str == NULL)
					str = "(nil)";
				printf("%s%s", separators, str);
				break;
			default:
				i++;
				continue;
		}
		separators = ", ";
		i++;
	}
	printf("\n");
	va_end(args);
}
