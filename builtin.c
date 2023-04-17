#include "shell.h"
/**
 * _myexit - exit the shell
 * @info: Structure contining potential argu. used to
 * maintain constant function prototype.
 * Return: exit with fiven exit status.
 * (0) if argv[0] != "exit"
 */
int _myexit(info_t *info)
{
	int check;

	if (info->argv[1])
	{
		check = _erratoi(info->argv[1]);
		if (check == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}
/**
 * _mycd - change the current dir of the the process
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0 (Success)
 */
int _mycd(info_t *info)
{
	char *x, *dir, buffer[1024];
	int cd;

	x = getcwd(buffer, 1024);
	if (!x)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dir = _getenv(info, "HOME=");
		if (!dir)
			cd =
				chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
		else
			cd = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(x);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		cd =
			chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
		cd = chdir(info->argv[1]);
	if (cd == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}
/**
 * _myhelp - changes the current dir of the process
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int _myhelp(info_t *info)
{
	char **arg1;

	arg1 = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg1);
	return (0);
}
