/*
** EPITECH PROJECT, 2018
** get_addr_ptr
** File description:
** get_addr_ptr
*/

#include "my.h"

void get_addr_ptr(char *str)
{
    if (check_null_ptr(str) == (0))
        return;
    else {
        unsigned int adr = (unsigned long) str;
        char *base = "0123456789abcdef";
        char res[9];
        int i = 8;

        while ((adr / 16) > 0 || i >= 8) {
            res[i] = base[(adr % 16)];
            adr /= 16;
            i--;
        }
        res[i] = base[(adr % 16)];
        my_putstr("0x");
        while (i < 9) {
            my_putchar(res[i]);
            i++;
        }
    }
}

int check_null_ptr(char *str)
{
    if (str == NULL) {
        my_putstr("(nil)");
        return (0);
    } else
        return (84);
}
