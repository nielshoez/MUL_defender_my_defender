/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** handle hit
*/

#include "my.h"

static int is_an_arrow_weak(game_t *game, int index, int i)
{
    if (index == 1) {
        game->ennemy->health[i] -= 3;
        return (1);
    }
    return (0);
}

static int is_an_arrow_heavy(int index)
{
    if (index == 5)
        return (1);
    return (0);
}

static int is_a_snow_ball(int index)
{
    if (index == 6)
        return (1);
    return (0);
}

static int is_a_bolt(int index)
{
    if (index == 2)
        return (1);
    return (0);
}

void handle_hit(game_t *game, int index, int i)
{
    static int is_slowed = 0;

    if (is_an_arrow_weak(game, index, i) == 1) {
        return;
    } if (is_an_arrow_heavy(index)) {
        game->ennemy->health[i] -= 6;
        return;
    } if (is_a_snow_ball(index)) {
        game->ennemy->health[i] -= 5;
        if (is_slowed == 0) {
            game->ennemy->speed[i] = game->ennemy->speed[i] / 2;
            is_slowed = 1;
        }
        return;
    }
    if (is_a_bolt(index)) {
        game->ennemy->health -= 5;
        return;
    }
}
