#include "shell.h"

/**
 * shell_cd - this changes the current working directory of the shell
 * @args: the arguments of the array
 */
void shell_cd(char **args)
{
	char *dir = args[1];
	int ret;

	/* If no argument is provided, change to HOME directory */
	if (dir == NULL)
	{
		dir = _getenv("HOME");
		if (dir == NULL)
		{
			_puts("cd: No HOME directory found\n");
			return;
		}
	}

	ret = chdir(dir);
	if (ret == -1)
	{
		perror("cd");
	}
}
