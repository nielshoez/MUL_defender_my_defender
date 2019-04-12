/*
** EPITECH PROJECT, 2018
** my_putstr.c
** File description:
** issou
*/

#include "my.h"

int my_putstr_octal(char const *str)
{
    int result = 0;

    for (int i = 0; str[i] != '\0'; i = i + 1) {
        if (str[i] < 32 || str[i] > 126) {
            my_putchar('\\');
            result = str[i];
            if (result < 0)
                result = result * -1;
            my_octal_convertor(result);
        } else
            my_putchar(str[i]);
    }
    return (0);
}
