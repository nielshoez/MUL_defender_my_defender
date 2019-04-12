/*
** EPITECH PROJECT, 2018
** my_strcpy.c
** File description:
** copy a string
*/

#include <stddef.h>
#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;
    int l = my_strlen(src) - 1;

    if (src == NULL)
        return (0);
    while (l >= 0)
    {
        dest[i] = src[i];
        i++;
        l--;
    }
    dest[i] = '\0';
    return (dest);
}
