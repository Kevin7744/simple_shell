<<<<<<< HEAD
#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/* --for read and writes buffers */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* --for command chaining */
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

/* --for convert_number() */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/* 1 if using system getline() */
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;


/**
 * struct liststr - singly linked list
 * @num: param - the number field
 * @str: param - a string
 * @next: param - points to the next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 * struct passinfo - contains pseudo-arguments to pass into a function allowing uniform prototype for function pointer struct
 * @arg: param - a string generated from getline containing arguements
 * @argv: param - an array of strings generated from arg
 * @path: param - string path for the current command
 * @argc: param - argument count
 * @line_count: param -  error count
 * @err_num: param - error code for exit()s
 * @linecount_flag: param - if on count this line of input
 * @fname: param -  The program filename
 * @env: param - linked list local copy of environ
 * @environ: param - custom modified copy of environ from LL env
 * @history: param -  history node
 * @alias: param -  alias node
 * @env_changed: param - on if environ was changed
 * @status: param - The return status of the last executed command
 * @cmd_buf: param - address of pointer to cmd_buf and on if chaining
 * @cmd_buf_type: param - CMD_type ||, &&, ;
 * @readfd: param - The fd from which to read line input
 * @histcount: param - history line number count
 */
typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf;
	/* Address pointer to cmd; chain buffer, for mem mangement */
	int cmd_buf_type; /* CMD_type ||, &&, ; */
	int readfd;
	int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 * struct builtin - contains a builtin string and related function
 * @type: param - builtin command flag
 * @func: param - function
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;


/* toem_shloop.c */
int hsh(info_t *, char **);
int find_builtin(info_t *);
void find_cmd(info_t *);
void fork_cmd(info_t *);

/* toem_parser.c */
int is_cmd(info_t *, char *);
char *dup_chars(char *, int, int);
char *find_path(info_t *, char *, char *);

/* loophsh.c */
int loophsh(char **);

/* toem_errors.c */
void _eputs(char *);
int _eputchar(char);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);

/* toem_string.c */
int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);

/* toem_string1.c */
char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);

/* toem_exits.c */
char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);

/* toem_tokenizer.c */
char **strtow(char *, char *);
char **strtow2(char *, char);

/* toem_realloc.c */
char *_memset(char *, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);

/* toem_memory.c */
int bfree(void **);

/* toem_atoi.c */
int interactive(info_t *);
int is_delim(char, char *);
int _isalpha(int);
int _atoi(char *);

/* toem_errors1.c */
int _erratoi(char *);
void print_error(info_t *, char *);
int print_d(int, int);
char *convert_number(long int, int, int);
void remove_comments(char *);

/* toem_builtin.c */
int _myexit(info_t *);
int _mycd(info_t *);
int _myhelp(info_t *);

/* toem_builtin1.c */
int _myhistory(info_t *);
int _myalias(info_t *);

/*toem_getline.c */
ssize_t get_input(info_t *);
int _getline(info_t *, char **, size_t *);
void sigintHandler(int);

/* toem_getinfo.c */
void clear_info(info_t *);
void set_info(info_t *, char **);
void free_info(info_t *, int);

/* toem_environ.c */
char *_getenv(info_t *, const char *);
int _myenv(info_t *);
int _mysetenv(info_t *);
int _myunsetenv(info_t *);
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
=======
#ifndef SHELL_H
#define SHELL_H

/* Include library */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <signal.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#define SPACE_SIZE 120

/* Struct */


/**
* struct path - Each node contain a directory of the PATH
*
* @current_dir: Str that contain a directory
* @next: Pointer to the next node
*/
typedef struct path
{
	char *current_dir;
	struct path *next;
} path;

/**
* struct built_in - Built in command
*
* @command: Command to check (without any flag)
* @f: Pointer to function to use
*/
typedef struct built_in
{
	char *command;
	int (*f)(void);
} built_in;


/* Variable global */


char **new_env;
path *path_head;
char **array_command;
char *user_input;
int exit_var;


/* Prototype */


/* ENV COMMAND */
void _envcpy(char **);
char *_envget(const char *);
int _envprint(void);
int _setenv(void);
int _setenv_real(char *);
int _setenv_unreal(void);
void _envnew(int);
void _setenverr(void);
int _unsetenv(void);

/* PROGRAM RUN COMMAD */
void _pathinit(void);
size_t lst_prt(const path *);
int cmd_path(char *);
int (*check_built_in(const char *))(void);
int _exit_(void);
void shell_loop(char **);
void _exevc(void);
void _execute(void);
void handl_sigs(__attribute__((unused)) int);
int dollar(void);
int var(void);
int xit_stat(void);
void usr_input(void);
void _prompt(void);
void err_process(void);
ssize_t _getlines(char **, size_t *, FILE *);
int f_get_c(FILE *);
size_t _fread(void *, size_t, FILE *);
int err_tst(char *);
void prt_num(unsigned int);
int _putchar(int);

/* LINKED LIST USEFUL COMMAND */
path *add_node_end(path **, char *);

/* STR USEFULL COMMAND */
void strtow(char *);
int _strlen_letter(char *);
int _strcount_word(char *);
int _strcmp(const char *, char *);
int _strlen(char *);
char *_strdup(char *str);
void sep_to_space(void);
int _atoi(char *);

/* FREE COMMAND */
void free_list(path *);
void free_all(void);
void free_cmd(void);
void free_env(void);
void free_path(void);

/* MEMORY FUNCTION */
char *_memcpy(char *, char *);
void *_realloc(void *, unsigned int);
char **_realloc_ptr(char **, unsigned int);

/* HELP ASSORTMENT */
int _help(void);
void _helperror(void);
void _helpexit(void);
void _helpenv(void);
void _helpsetenv(void);
void _helpunsetenv(void);

#endif /* SHELL_H */
>>>>>>> 1ff7b7d9550ce6ec363dbd58a267d2a8d3d92874
