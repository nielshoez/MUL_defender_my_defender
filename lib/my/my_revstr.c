/*
** EPITECH PROJECT, 2018
** my_revstr.c
** File description:
** reverse a string
*/

#include "my.h"

char *my_revstr(char *str)
{
    int length = my_strlen(str) - 1;
    int y = 0;
    char swap;

    while (length > y)
    {
        swap = str[length];
        str[length] = str[y];
        str[y] = swap;
        length--;
        y++;
    }
    return (str);
}
