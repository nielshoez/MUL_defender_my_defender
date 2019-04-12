/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** my_printf
*/

#include "my.h"
#include <stdarg.h>

void print_convertor_flags(const char *str, va_list ap, int i)
{
    switch (str[i]) {
    case 'x':
        my_hex_convertor(va_arg(ap, unsigned int));
        break;
    case 'X':
        my_hex_convertor_min(va_arg(ap, unsigned int));
        break;
    case 'b':
        my_binary_convertor(va_arg(ap, unsigned int));
        break;
    case 'o':
        my_octal_convertor(va_arg(ap, unsigned int));
        break;
    default:
        my_putchar(str[i - 1]);
        my_putchar(str[i]);
        break;
    }
}

void print_type_flag2(const char *str, va_list ap, int i)
{
    switch (str[i]) {
    case 'p':
        get_addr_ptr(va_arg(ap, char *));
        break;
    case '%':
        my_putchar('%');
        break;
    case 'S':
        my_putstr_octal(va_arg(ap, char *));
        break;
    default:
        print_convertor_flags(str, ap, i);
        break;
    }
}

void print_type_flag(const char *str, va_list ap, int i)
{
    switch (str[i]) {
    case 'c':
        my_putchar(va_arg(ap, int));
        break;
    case 's':
        my_putstr(va_arg(ap, char *));
        break;
    case 'd':
    case 'i':
        my_put_nbr(va_arg(ap, int));
        break;
    default:
        print_type_flag2(str, ap, i);
        break;
    }
}

int my_printf(const char *str, ...)
{
    va_list ap;
    va_start(ap, str);

    for (int i = 0; str[i] != '\0'; i = i + 1) {
        if (str[i] == '%') {
            i = i + 1;
            print_type_flag(str, ap, i);
        } else
            my_putchar(str[i]);
    }
    va_end(ap);
    return (0);
}
