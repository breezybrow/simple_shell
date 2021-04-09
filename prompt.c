#include "shell.h"

/**
 * main- basic shell with limited functionality
 *
 * Return: 0
 */

int main (void)
{
        char *buffer;
        size_t bufsize = 1024; /* 1024 = 1 kb */
        size_t len = 1024;

        buffer = (char*)malloc(bufsize * sizeof(char));
        while (1) /* repeat forever */
        {
                _putchar('$');/*may use print_prompt to call on function to display prompt */
                getline(&buffer, &len, stdin);
		printf("%s", buffer);
        }
        return (0);
}
