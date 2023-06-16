#include "shell.h"

/**
  * file_status - checks if a file exists in the pathname
  * @pathname: pointer to the file path
  * @statbuf: pointer to buffer containing file information
  * Return: true or false
  */
bool file_status(char *pathname, struct stat *statbuf)
{
	int fileStatus;

	fileStatus = stat(pathname, statbuf);
	if (returnStatus == 0)
		return (true);
	return (false);
}
/**
  * errorHandler - Error handler
  * @pid: child process id
  */
void errorHandler(pid_t pid)
{
	if (pid == -1)
	{
		_puts("Error");
		exit(EXIT_FALURE);
	}
}
/**
 * _puts - prints a string, followed by a new line, to stdout
 * @str: the string to print
 */
void _puts(char *str)
{
	for (; *str != '\0'; str++)
	{
		_putchar(*str);
	}
	_putchar('\n');
}
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
