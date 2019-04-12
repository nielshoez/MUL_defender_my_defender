/*
** EPITECH PROJECT, 2018
** my_itoa.c
** File description:
** integer to array
*/

#include "my.h"

char *my_itoa(int number)
{
    int lenght = 0;
    char *buffer;

    for (int temp = number; temp > 0; temp = temp / 10)
        lenght++;
    buffer = malloc(lenght + 1);
    buffer = my_memset(buffer, '\0', lenght + 1);
    while (lenght--) {
        buffer[lenght] = number % 10  + '0';
        number = number / 10;
    }
    return (buffer);
}
