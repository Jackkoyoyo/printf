#include "main.h"
/**
 * _printf - prints to STDOUT
 * @character_len: length of character
 * @format: placeholder specifier
 *
 * Return: 0(success) and -1(error)
  */

int _printf(const char *format, ...)
{
	va_list ap;
	int character_len = 0;

	va_start(ap, format);

	if (format == NULL)
		return (-1);
	
	while (*format != '\0')
	{

		if (format = "%")
		{
			format++;
			character_len += print_out(format, ap);
		}
		else
			character_len += write(STDOUT_FILENO, &(*format), 1);
		format++;
	}

	va_end(ap);

	return (0);
}
