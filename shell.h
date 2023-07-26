#ifndef _SHELL_H_
#define _SHELL_H_

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include <sys/wait.h>
#include <sys/types.h>
#include <limits.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>


/* To  Read/Write in the  Buffers */
#define WRITE_BUF_SIZE 1024
#define READ_BUF_SIZE 1024
#define BUF_FLUSH -1

/* To  Chain Commands  */
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

/* To  Convert Number() */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/* 1 if  System Getline() */
#define USE_STRTOK 0
#define USE_GETLINE 0

#define HIST_MAX	4096
#define HIST_FILE	".simple_shell_history"


extern char **environ;


/**
 * struct liststr -> for singly linked list
 * @str: str var
 * @next: pointer to next node
 * @num: field number
 */

typedef struct liststr
{
	char *str;
	int num;
	struct liststr *next;
} list_t;

/**
 *struct passinfo -> are pseudo-arg to pass into a function
 *@arg -> is a  str generated from getline
 *@path -> is path for the current cmd
 *@argv -> is an array of arg
 *@line_count ->  is error count
 *@err_num -> is exit()s errors code
 *@argc -> is the argcount
 *@fname -> is the program filename
 *@env -> is linked list local copy of environ
 *@linecount_flag -> if on count this lines  input
 *@environ -> is a custom modified copy of environ from LL env
 *@alias ->  is the alias node
 *@history -> is the hist node
 *@env_changed ->  on if environ was changed
 *@cmd_buf_type ->  CMD_type ||, &&, ;
 *@status -> return status of the last exec'd cmd
 *@histcount -> hist line 
 *@readfd -> is the fd from which to read line input
 *@cmd_buf -> if addr of pointer to cmd_buf
 */

typedef struct passinfo
{
	char *arg;
	char *path;
	char **argv;
	unsigned int line_count;
	int err_num;
	int argc;
	char *fname;
	int linecount_flag;
	list_t *alias;
	list_t *history;
	list_t *env;
	int env_changed;
	char **environ;
	int status;
	char **cmd_buf; 
	int readfd;
	int histcount;
	int cmd_buf_type; 
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 *struct builtin -> contains a builtin str and related function
 *@func -> are function
 *@type -> cmd flag
 */

typedef struct builtin
{
	int (*func)(info_t *);
	char *type;
} builtin_table;


/* toem_shloop.c */
int find_builtin(info_t *);
int hsh(info_t *, char **);
void fork_cmd(info_t *);
void find_cmd(info_t *);


/* toem_parser.c */
int is_cmd(info_t *, char *);
char *find_path(info_t *, char *, char *);
char *dup_chars(char *, int, int);

/* loophsh.c */
int loophsh(char **);

/* toem_errors.c */
void _eputs(char *);
int _putsfd(char *str, int fd);
int _putfd(char c, int fd);
int _eputchar(char);


/* toem_string.c */
int _strcmp(char *, char *);
int _strlen(char *);
char *_strcat(char *, char *);
char *starts_with(const char *, const char *);

/* toem_string1.c */
int _putchar(char);
char *_strdup(const char *);
char *_strcpy(char *, char *);
void _puts(char *);


/* toem_exits.c */
char *_strncpy(char *, char *, int);
char *_strchr(char *, char);
char *_strncat(char *, char *, int);

/* toem_tokenizer.c */
char **strtow2(char *, char);
char **strtow(char *, char *);

/* toem_realloc.c */
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);
char *_memset(char *, char, unsigned int);

/* toem_memory.c */
int bfree(void **);

/* toem_atoi.c */
int interactive(info_t *);
int is_delim(char, char *);
int _atoi(char *);
int _isalpha(int);


/* toem_errors1.c */
int _erratoi(char *);
char *convert_number(long int, int, int);
int print_d(int, int);
void print_error(info_t *, char *);
void remove_comments(char *);


/* toem_builtin.c */
int _mycd(info_t *);
int _myexit(info_t *);
int _myhelp(info_t *);

/* toem_builtin1.c */
int _myalias(info_t *);
int _myhistory(info_t *);

/*toem_getline.c */
ssize_t get_input(info_t *);
void sigintHandler(int);
int _getline(info_t *, char **, size_t *);

/* toem_getinfo.c */
void set_info(info_t *, char **);
void clear_info(info_t *);
void free_info(info_t *, int);

/* toem_environ.c */
char *_getenv(info_t *, const char *);
int _myunsetenv(info_t *);
int _mysetenv(info_t *);
int _myenv(info_t *);
int populate_env_list(info_t *);

/* toem_getenv.c */
char **get_environ(info_t *);
int _unsetenv(info_t *, char *);
int _setenv(info_t *, char *, char *);

/* toem_history.c */
char *get_history_file(info_t *info);
int write_history(info_t *info);
int read_history(info_t *info);
int build_history_list(info_t *info, char *buf, int linecount);
int renumber_history(info_t *info);

/* toem_lists.c */
list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
size_t print_list_str(const list_t *);
int delete_node_at_index(list_t **, unsigned int);
void free_list(list_t **);

/* toem_lists1.c */
size_t list_len(const list_t *);
char **list_to_strings(list_t *);
size_t print_list(const list_t *);
list_t *node_starts_with(list_t *, char *, char);
ssize_t get_node_index(list_t *, list_t *);

/* toem_vars.c */
int is_chain(info_t *, char *, size_t *);
void check_chain(info_t *, char *, size_t *, size_t, size_t);
int replace_alias(info_t *);
int replace_vars(info_t *);
int replace_string(char **, char *);

#endif
