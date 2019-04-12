/*
** EPITECH PROJECT, 2018
** my_put_nbr.c
** File description:
** displays the number given as a parameter
*/

void my_putchar(char c);

void my_put_nbr(int nb)
{
    if ( nb < 0) {
        my_putchar('-');
        nb =  nb *( -1);
    }
    if ( nb >= 0 && nb <= 9)
        my_putchar(nb+48);
    else  {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    }
}
