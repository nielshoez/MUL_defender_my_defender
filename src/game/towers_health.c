/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** manage towers' health
*/

#include "my.h"

void check_towers_health(game_t *game, int i)
{
    if (game->tower->dropped[i] != NULL && game->tower->health != NULL
        && game->tower->health[i] <= 0) {
        sfSprite_destroy(game->tower->dropped[i]);
        game->tower->dropped[i] = NULL;
    }
}

