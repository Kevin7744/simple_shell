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

/* Global Variables*/

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
