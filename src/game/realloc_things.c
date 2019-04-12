/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** my_defender
*/

#include "my.h"

void realloc_entities(game_t *game, int nb_ennemies)
{
    for (int i = 0; i != nb_ennemies; i++) {
        get_new_ennemie(game, i);
    }
}

void realloc_time(game_t *game, int nb_ennemies)
{
    for (int i = 0; i != nb_ennemies; i++) {
        game->ennemy->clocks[i] = sfClock_create();
        game->ennemy->animations[i] = sfClock_create();
    }
}

void init_towers_2(game_t *game)
{
    for (int k = 0; k != 45; k++) {
        game->tower->type[k] = 0;
        game->tower->clocks[k] = sfClock_create();
    }
    game->tower->rects[1] = get_rect(261, 117, 44, 75);
    game->tower->rects[2] = get_rect(177, 112, 44, 75);
    game->tower->rects[3] = get_rect(177, 264, 44, 75);
    game->tower->rects[4] = get_rect(11, 117, 44, 75);
    game->tower->rects[5] = get_rect(256, 262, 44, 74);
    game->tower->rects[6] = get_rect(100, 104, 44, 75);
    game->tower->tile = 0;
}
