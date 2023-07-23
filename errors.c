#include "shell.h"

/**
 * _eputs - Prints a null-terminated string to stderr.
 * @str: The string to be printed.
 *
 * Return: Nothing.
 */
void _eputs(char *str)
{
	if (!str)
		return;

	for (int i = 0; str[i] != '\0'; i++)
		_eputchar(str[i]);
}

/**
 * _eputchar - Writes the character 'c' to the standard error (stderr).
 * @c: The character to be printed.
 *
 * Return: On success 1.
 *         On error, -1 is returned, and errno is set appropriately.
 */
int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	switch (c)
	{
	case BUF_FLUSH:
		write(2, buf, i);
		i = 0;
		break;
	default:
		if (i >= WRITE_BUF_SIZE)
		{
			write(2, buf, i);
			i = 0;
		}
		buf[i++] = c;
	}

	return (1);
}

/**
 * _putfd - Writes the character 'c' to the given file descriptor 'fd'.
 * @c: The character to be printed.
 * @fd: The file descriptor to write to.
 *
 * Return: On success 1.
 *         On error, -1 is returned, and errno is set appropriately.
 */
int _putfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	switch (c)
	{
	case BUF_FLUSH:
		write(fd, buf, i);
		i = 0;
		break;
	default:
		if (i >= WRITE_BUF_SIZE)
		{
			write(fd, buf, i);
			i = 0;
		}
		buf[i++] = c;
	}

	return (1);
}

/**
 * _putsfd - Prints a null-terminated string to the given file descriptor 'fd'.
 * @str: The string to be printed.
 * @fd: The file descriptor to write to.
 *
 * Return: The number of characters written.
 */
int _putsfd(char *str, int fd)
{
	if (!str)
		return (0);

	int i = 0;

	for (; *str; str++)
		i += _putfd(*str, fd);

	return (i);
}

