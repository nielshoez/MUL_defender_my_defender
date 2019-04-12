/*
** EPITECH PROJECT, 2018
** octal_converter
** File description:
** convert decimal into octal
*/

#include "my.h"

void my_octal_convertor(unsigned int nb)
{
    unsigned int result = 0;

    for (int i = 1 ; nb > 0; i = i * 10) {
        result = result + (nb % 8) * i;
        nb = nb / 8;
    }
    my_put_nbr(result);
}
