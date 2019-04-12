/*
** EPITECH PROJECT, 2018
** my_lib
** File description:
** my replace
*/

#include "my.h"

char *my_replace(char *str, char target, char replace)
{
    int i = my_strlen(str) - 1;

    while (str[i] == target) {
        str[i] = replace;
        i = i - 1;
    }
    return (str);
}
