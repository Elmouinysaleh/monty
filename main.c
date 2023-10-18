#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
#include "monty.h"
bus_t bus = {NULL, NULL, NULL, 0};
ssize_t c_getline(char **lineptr, size_t *n, FILE *stream) {
    char *line = NULL;
    size_t bufsize = 0;
    ssize_t read_chars = 0;

    if (!lineptr || !n || !stream) {
        return -1;
    }

    if (*lineptr) {
        line = *lineptr;
        bufsize = *n;
    } else {
        bufsize = 128;
        line = (char *)malloc(bufsize);
        if (!line) {
            return -1;
        }
    }

    if (fgets(line, bufsize, stream) != NULL) {
        read_chars = strlen(line);
        *lineptr = line;
        *n = bufsize;
    } else if (read_chars == 0) {
        free(line);
        return -1;
    }

    return read_chars;
}
/**
* main - monty code interpreter
* @argc: number of arguments
* @argv: monty file location
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	char *content;
	FILE *file;
	size_t size = 0;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	bus.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read_line > 0)
	{
		content = NULL;
		read_line = c_getline(&content, &size, file);
		bus.content = content;
		counter++;
		if (read_line > 0)
		{
			execute(content, &stack, counter, file);
		}
		free(content);
	}
	free_stack(stack);
	fclose(file);
return (0);
}
