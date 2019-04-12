/*
** EPITECH PROJECT, 2018
** my lib
** File description:
** issou
*/

#include "my.h"

char *my_memset(char *res, char c, int size)
{
    for (int i = 0; i != size; i++)
        res[i] = c;
    return (res);
}
