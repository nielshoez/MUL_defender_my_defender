/*
** EPITECH PROJECT, 2019
** check_error.c
** File description:
** check_error
*/

#include "my.h"

static int h_flag(void)
{
    my_putstr("USAGE:\n    ./my_defender\nDESCRIPTION\n"
        "  You do have multiple turrets with different abilities to defeat\n"
        "  as many waves as possible\n"
        "  Be aware, ennemies are getting stronger every rounds\n"
        "TURRETS' DESCRIPTION\n"
        "  Ice turret can slow down oppenents but has low damages\n"
        "  Magical turret causes heavy damages\n"
        "  Reinforcement tower produces money\n"
        "  Archer tower causes normal damages for low price\n"
        "  Wall can block 10 hits instead of 2 for a normal tower\n");
    return (1);
}

int my_putstr_err(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++)
        write(2, &str[i], 1);
    return (0);
}

int check_error(int ac, char **av, char **env)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && my_strlen(av[1]) == 2)
        return (h_flag());
    if (ac != 1) {
        my_putstr_err("Too many arguments\n");
        return (84);
    }
    if (env[0] == NULL)
        return (84);
    return (0);
}
