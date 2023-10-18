#include "shell.h"

/**
 * _puts - prints a string to std ouput.
 * @str: The string
 * Description: This func writes the char in the input str
 * to std ouput.
 */

void _puts(const char *str)
{
	if (str)
	{
		write(1, str, strlen(str));
	}
}
