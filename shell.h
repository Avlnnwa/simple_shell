#ifndef SHELL
#define SHELL

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>

/* buffer read and write */
#define BUF_FLUSH (-1)
#define WRITE_BUF_SIZE 1024
#define READ_BUF_SIZE 1024

/**
 * struct list_s - singly linked list
 * @str: string
 * @next: This is the node pointer
 */
typedef struct list_s
{
	char *str;
	struct list_s *next;
} list_t;

/**
 * struct info_s - contins arg passed into a function
 * @argv: argument vector
 * @argc: argument count
 * @status:Exit status of the last executed command
 * @err_num: Error number
 * @history: command history
 * @alias: Alias list
 * @env: Environment variable list
 * @environ: copy of environment var as string array
 * @env_changed: Flag tracks changes in environment list
 * @cmd_buf_type: command buffer type (CMD_CHAIN, CMD_AND, CMD_OR)
 *
 */

typedef struct info_s
{
	char **argv; /* arg vector */
	int argc;  /* arg count */
	int status; /* exit's status of last ecex command */
	int err_num; /* error number */
	list_t *history; /* command history */
	list_t *alias; /* Alias list */
	list_t *env; /* environ var list */
	char **environ; /* copy environ var as string array */
	int env_changed; /* tracks changes in environ list */
	int cmd_buf_type; /* com buf type */
} info_t;

/* My functions */
int _theexit(info_t *info);
int _thecd(info_t *info);
int _thehelp(info_t *info);

/* Declaration function */
int _erratoi(const char *str);
void print_error(info_t *info, const char *message);
void _puts(const char *str);
char *_getenv(info_t *info, const char *name);
int _strcmp(const char *s1, const char *s2);

/* Error handling functions */
void _eputs(char *str);
int _eputchar(char c);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);

/* 01inbuilt */
int display_prompt;
ssize_t read_command(info_t *info, char *command, size_t max_length);
int execute_command(const char *command);

#endif
