#include "shell.h"

/**
<<<<<<< HEAD
 * hsh - the main shell loop
 * @info: the parameter & return info struct
 * @av: the argument vector from main()
 *
 * Return: returns 0 on success and 1 on error and or error code
 */
int hsh(info_t *info, char **av)
{
	ssize_t r = 0;
	int builtin_ret = 0;

	while (r != -1 && builtin_ret != -2)
	{
		clear_info(info);
		if (interactive(info))
			_puts("$ ");
		_eputchar(BUF_FLUSH);
		r = get_input(info);
		if (r != -1)
		{
			set_info(info, av);
			builtin_ret = find_builtin(info);
			if (builtin_ret == -1)
				find_cmd(info);
		}
		else if (interactive(info))
			_putchar('\n');
		free_info(info, 0);
	}
	write_history(info);
	free_info(info, 1);
	if (!interactive(info) && info->status)
		exit(info->status);
	if (builtin_ret == -2)
	{
		if (info->err_num == -1)
			exit(info->status);
		exit(info->err_num);
	}
	return (builtin_ret);
}

/**
 * find_builtin - finds a builtin command
 * @info: the parameter & return info struct
 *
 * Return: returns -1 if builtin not found 0 if builtin executed successfully and 1 if builtin found but not successful and 2 if builtin signals exit()
 */
int find_builtin(info_t *info)
{
	int i, built_in_ret = -1;
	builtin_table builtintbl[] = {
		{"exit", _myexit},
		{"env", _myenv},
		{"help", _myhelp},
		{"history", _myhistory},
		{"setenv", _mysetenv},
		{"unsetenv", _myunsetenv},
		{"cd", _mycd},
		{"alias", _myalias},
		{NULL, NULL}
	};

	for (i = 0; builtintbl[i].type; i++)
		if (_strcmp(info->argv[0], builtintbl[i].type) == 0)
		{
			info->line_count++;
			built_in_ret = builtintbl[i].func(info);
			break;
		}
	return (built_in_ret);
}

/**
 * find_cmd - finds a command in PATH
 * @info: the parameter & return info struct
 *
 * Return: returns void
 */
void find_cmd(info_t *info)
{
	char *path = NULL;
	int i, k;

	info->path = info->argv[0];
	if (info->linecount_flag == 1)
	{
		info->line_count++;
		info->linecount_flag = 0;
	}
	for (i = 0, k = 0; info->arg[i]; i++)
		if (!is_delim(info->arg[i], " \t\n"))
			k++;
	if (!k)
		return;

	path = find_path(info, _getenv(info, "PATH="), info->argv[0]);
	if (path)
	{
		info->path = path;
		fork_cmd(info);
	}
	else
	{
		if ((interactive(info) || _getenv(info, "PATH=")
					|| info->argv[0][0] == '/') && is_cmd(info, info->argv[0]))
			fork_cmd(info);
		else if (*(info->arg) != '\n')
		{
			info->status = 127;
			print_error(info, "not found\n");
		}
	}
}

/**
 * fork_cmd - forks a an execution thread to run cmd
 * @info: the parameter & return info struct
 *
 * Return: returns void
 */
void fork_cmd(info_t *info)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		/* TODO: PUT ERROR FUNCTION */
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(info->path, info->argv, get_environ(info)) == -1)
		{
			free_info(info, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
		/* TODO: PUT ERROR FUNCTION */
	}
	else
	{
		wait(&(info->status));
		if (WIFEXITED(info->status))
		{
			info->status = WEXITSTATUS(info->status);
			if (info->status == 126)
				print_error(info, "Permission denied\n");
		}
	}
}


=======
* main - Run the shell loop
*
* @ac: Number of arg
* @av: Value of arg, in a 2D array
* @env: Environement variable
*
* Return: 0 (succes);
*/
int main(__attribute__((unused)) int ac, char **av, char **env)
{
	if (av[1] == NULL)
		shell_loop(env);
	else
		printf("Error syntaxe : ./simple_shell\n");
	return (0);
}

/**
* shell_loop - Run the shell until exit command
*
* @env: pointer of enviroment
*
* Return: Anything, cause void function
*/
void shell_loop(char **env)
{
	size_t number_of_bytes = 0;
	int i;

	_envcpy(env);
	_pathinit();
	exit_var = 0;
	do {
		_prompt();
		signal(SIGINT, handl_sigs);
		if ((getline(&user_input, &number_of_bytes, stdin)) == -1)
		{
			free_env();
			free_path();
			free(user_input);
			break;
		}
		if (user_input[0] == '\n' || user_input[0] == '#')
			continue;
		for (i = 0; user_input[i]; i++)
		{
			if (user_input[i] != ' ')
				break;
		}
		if (i == _strlen(user_input) - 1)
			continue;
		usr_input();
		strtow(user_input);
		_execute();
		} while (1);
		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, "\n", 1);
}
>>>>>>> 1ff7b7d9550ce6ec363dbd58a267d2a8d3d92874
