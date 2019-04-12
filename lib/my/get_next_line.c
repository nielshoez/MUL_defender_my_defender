/*
** EPITECH PROJECT, 2019
** get_next_line.c
** File description:
** it gets the next line
*/

#include "get_next_line.h"
#include "my.h"

static char *my_realloc(char *str)
{
    char *ext = malloc(my_strlen(str) + READ_SIZE);
    ext = my_memset(ext, '\0', my_strlen(str) + READ_SIZE);
    int i = 0;

    for (; str[i] != '\0'; i++)
        ext[i] = str[i];
    free(str);
    return (ext);
}

static int stock_read(int fd, char *str, int i)
{
    static int stock;
    static char buf[READ_SIZE];
    static int j = 0;
    static int value = READ_SIZE;

    if (j >= value || j == stock) {
        j = 0;
        if ((value = read(fd, buf, READ_SIZE)) < stock || fd < 0)
            return (0);
    }
    str[i] = buf[j++];
    return (value);
}

static int check_errors(int fd)
{
    int errors = 0;

    if (fd == - 1)
        errors = errors + 1;
    else
        errors = 0;
    return (errors);
}

char *get_next_line(int fd)
{
    char *result = malloc(sizeof(char) * (READ_SIZE + 1));
    result = my_memset(result, '\0', READ_SIZE + 1);
    int i = 0;
    int n = stock_read(fd, result, i);
    int errors = 0;

    errors = check_errors(fd);
    if (errors != 0)
        return (0);
    if (n == 0)
        return (0);
    while (result[i] != '\n') {
        i = i + 1;
        result = my_realloc(result);
        n = stock_read(fd, result, i);
    }
    result[i] = '\0';
    return (result);
}
