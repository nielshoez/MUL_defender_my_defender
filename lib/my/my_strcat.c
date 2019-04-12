/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** concat 2 strings
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int dest_len = my_strlen(dest);
    int src_len = my_strlen(src);
    char *result = malloc(sizeof(char) * (dest_len + src_len) + 1);
    int count = 0;
    int i = 0;

    for (; dest[i] != '\0'; i++, count++)
        result[i] = dest[i];
    for (int j = 0; src[j] != '\0'; j++, count++)
        result[count] = src[j];
    result[count] = '\0';
    return (result);
}
