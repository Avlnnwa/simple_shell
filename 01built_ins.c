#include "shell.h"

/**
 * display_prompt - Display shell prompt
 */

void display_prompt(void)
{
_puts("#cisfun$ ");
}

/**
 * execute_command - Execute the user's command.
 * @info: Pointer to shell info structure.
 */

void execute_command(info_t *info)
{
	find_builtin(info);
	fork_cmd(info);
	clear_info(info);
}

/**
 * main - Entry point
 * Description: This function serves as the entry point
 * of the shell.
 * Return: 0(success)
 */

int main(void)
{
	int status;
	info_t info = INFO_INIT;

	while (1)
	{
		display_prompt();
		status = get_input(&info);

		if (status == EOF)
		{
			_puts("\n");
			break;
		}

		if (info.arg)
		{
			execute_command(&info);
		}
	}
	free_info(&info, 1);
	return (0);
}
