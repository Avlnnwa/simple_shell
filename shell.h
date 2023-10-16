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

int _theexit(info_t *info);
int _thecd(info_t *info);
int _thehelp(info_t *info);

#endif
