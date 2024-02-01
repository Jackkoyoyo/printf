#include "main.h"

/**
 * print_out - handles specifiers and print them out
 * @character_len: length of print out characters
 * @format: character to be printed
 *
 * Return: character_len
 */

int print_out(const char *format, va_list ap)
{
	int character_len = 0;

	switch(*format)
	{
		case 'c':
			character_len += _putchar(va_arg(ap, int));
			break;
		case 's':
			character_len += print_string(va_arg(ap, char *));
			break;
		case 'd':
			character_len += _putchar(va_arg(ap, int));
			break;
		case 'i':
			character_len += _putchar(va_arg(ap, int));
			break;
		case '%':
			character_len += _putchar('%');
		case '\0':
			return (-1);
		default:
			character_len += _putchar('%');
			character_len += write(STDOUT_FILENO, &(*format), 1);
			break;
	}

	return (character_len);
}
