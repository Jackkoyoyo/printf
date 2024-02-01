#include "main.h"

/**
  *print_string - function that prints strings to stdout
  *@strin_null: pointer to a null string
  *@strg_len: stores the string length
  *@getlen: length of string printed out
  *@str: pointer to a string
  * Return: length of string
  */

int print_string(const char *str)
{
	const char *strin_null = "(null)";
	int strg_len = 0;
	int getlen;

	if (str == NULL)
	{
		str = strin_null;
	}

	while (*str != '\0')
	{
		getlen = write(STDOUT_FILENO, str++, 1);
		if (getlen == -1)
		{
			return (-1);
		}
		strg_len += getlen;
	}
	if (getlen == -1)
	{
		return (-1);
	}
	strg_len += getlen;

	return (strg_len - 1);
}
