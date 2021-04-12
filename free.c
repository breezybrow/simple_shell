#include "shell.h"

/**
 * free_doubleptr - free memory assigned to double pointer
 * @ptr: double pointer to free
 *
 * Return: void
 */
void free_doubleptr(char **ptr)
{
	int ptr_tok = 0;

	if (ptr == NULL)
		return; /* condition: if double pointer is empty */

	while (ptr[ptr_tok])
	{
		free(ptr[ptr_tok]);
		ptr_tok++;
	}
	if (ptr[ptr_tok] == NULL)
		free(ptr[ptr_tok]);

	free(ptr);
}

/**
 * eof_constant- handle ctrl + c interrupt signal, writes new line and frees buffer from getline
 * @buffer: pointer to buffer that contains new line
 *
 * Return: void
 */

void eof_constant(char *buffer)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);
	free(buffer);
	exit(0);
}

/**
 * exitbuilt_in- frees buffer and commands created from
 * getline, then exits child process
 * @buffer: buffer made from getline
 * @cmds: double pointer array that stores all commands
 *
 * Return: void
 */
void exitbuilt_in(char *buffer, char **cmds)
{
	free(buffer);
	free_doubleptr(cmds);
	exit(EXIT_SUCCESS); /* macro */
}

/**
 * envbuilt_in- frees buffer and commands created from
 * getline, prints the env, then exits child process
 * @buffer: buffer made from getline
 * @cmds: double pointer array that stores all commands
 * @env: environment variables
 *
 * Return: void
 */
void envbuilt_in(char *buffer, char **cmds, char **environ)
{
	free(buffer);
	free_doubleptr(cmds);
	printallenv(environ);
	exit(EXIT_SUCCESS); /* macro */
}