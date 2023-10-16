#include "shell.h"

/**
 * _theexit - Exits the shell.
 * @info: struct contains potential arg.
 * used to maintain const func prototype.
 * Return: 0 exits with a given exit status
 * if info.argv[0] != "exit"
 */

int _theexit(info_t *info)
{
	int exitcheck;
if (info->argv[1])
{
exitcheck = _erratoi(info->argv[1]);
if (exitcheck == -1)
{
info->status = 2;
print_error(info, "illegal number: ");
puts(info->argv[1]);
putchar('\n');
return (1);
}
info->err_num = _erratoi(info->argv[1]);
return (-2);
}
info->err_num = -1;
return (-2);
}

/**
 * _thecd - This changes the current dir of the process
 * @info: The struct contains potential arg used to maintain
 * const function prototype.
 * Return: Always 0
 */

int _thecd(info_t *info)
{
char *s, *dir, buffer[1024];
int chdir_ret;

s = getcwd(buffer, 1024);

if (!s)
	puts("ToDo: >>getcwd failure emsg here<<\n");
if (!info->argc[1])
{
	dir = getenv(info, "HOME=");
	if (!dir)
		chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
	else
		chdir_ret = chdir(dir);
}
else if (strcmp(info->argv[1], "-") == 0)
{
	if (!_getenv(info, "OLDPWD="))
	{
		_puts(s);
		putchar('\n');
		return (1);
	}
	_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
	chdir_ret =
		chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
}
else
chdir_ret = chdir(info->argv[1]);
if (chdir_ret == -1)
{
	print_error(info, "can't cd to ");
	_eputs(info->argv[1]), _eputchar('\n');
}
else
{
	setenv(info, "OLDPWD", _getenv(info, "PWD="));
	setenv(info, "PWD", getcwd(buffer, 1024));
}
return (0);
}

/**
 * _thehelp - chnages current dir of the process.
 * @info: struct containing potential args used to maintain
 * const func prototype.
 * Return Always 0
 */

int _thehelp(info_t *info)
{
char **arg_array;
arg_array = info->argv;
_puts("help call works. function not yet implemented \n");
if (0)
_puts(arg_array);
return (0);
}
