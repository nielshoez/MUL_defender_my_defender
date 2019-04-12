/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** ayayayaya
*/

#include "my.h"

void check_ennemy_status(game_t *game)
{
    if (game->other->hit_ennemy == NULL)
        return;
    game->other->time = sfClock_getElapsedTime(game->other->hit_ennemy);
    game->other->seconds = game->other->time.microseconds / 1000000.0;

    if (game->other->seconds > 0.08 &&
        game->ennemy->health[game->other->index] > 0) {
        sfSprite_setColor(game->ennemy->sprites[game->other->index]
                        , game->other->base_color[game->other->index]);
        sfClock_destroy(game->other->hit_ennemy);
        game->other->hit_ennemy = NULL;
    }
}
