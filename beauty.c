#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * add_numbers - Adds two numbers together
 * @a: First number
 * @b: second number
 * @result: Pointer to store the result.
 * Description: This file adds two numbers.
 */

void add_numbers(int a, int b, int *result)
{
	*result = a + b;
}

/**
 * main - Entry point.
 * Description: This adds 2 numbers and display at result.
 * Return: 0(success).
 */

int main(void)
{
int num1 = 10;
int num2 = 20;
int sum = 0;
char result_str[20];
int result_len;

add_numbers(num1, num2, &sum);

result_len = snprintf(result_str, sizeof(result_str), "sum: %d\n", sum);
if (result_len < 0)
{
	write(STDERR_FILENO, "Error formatting result.\n", 26);
	return (EXIT_FAILURE);
}
write(STDOUT_FILENO, result_str, result_len);
write(STDOUT_FILENO, "\n", 1);

return (EXIT_SUCCESS);

}
