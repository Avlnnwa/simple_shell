#ifndef _SHELL_H_
#define _SHELL_H_

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
#define INFO_INIT {NULL, 0}

/**
 * struct passinfo - Struct to pass info to functions.
 * @arg: String containing user's command input.
 * @line_count: unsigned integer tracking line numbers.
 */

typedef struct passinfo
{
	char *arg;
	unsigned int line_count;
} info_t;

/* 01built_ins */
void display_prompt(void);
void execute_command(info_t *info);

int get_input(info_t *info);
void free_info(info_t *info, int flag);
void find_builtin(info_t *info);
void fork_cmd(info_t *info);
void clear_info(info_t *info);

/*void _puts(info_t *info);*/
void _puts(const char *str);

#endif
