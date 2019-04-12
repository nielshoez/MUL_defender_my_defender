/*
** EPITECH PROJECT, 2018
** my_getnbr.c
** File description:
** my_getnbr.c
*/

#include "my.h"

int my_getnbr(char *str)
{
    int i = 0;
    int result = 0;
    int neg = 1;

    while (str[i] != '\0') {
        if (str[i] == '-')
            neg = -1;
        while (str[i] >= '0' && str[i] <= '9') {
            result = result * 10;
            result = result + str[i] - 48;
            i++;
        }
        if (result > 2147483647 || result < -2147483647)
            return (0);
        return (result * neg);
    }
    return (0);
}
