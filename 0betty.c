#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * add_numbers - To add two numbers together
 * @a: The first number
 * @b: The second number
 * @result: Pointer to store result.
 */

void add_numbers(int a, int b, int *result)
{
	*result = a + b;
}

/**
 * main - Entry point
 * Description: This is the main function adds
 * two numbers
 * Return: 0 (success)
 */

int main(void)
{
int num1 = 10;
int num2 = 20;
int sum = 0;

add_numbers(num1, num2, &sum);

char result_str[20];
int result_len = snprintf(result_str, sizeof(result_str), "sum: %d\n", sum);

if (result_len < 0)
{
	write(STDERR_FILENO, "Errpr Formatting result\n", 26);
	return (EXIT_FAILURE);
}
write(STDOUT_FILENO, result_str, result_len);
return (EXIT_SUCCESS);
}
