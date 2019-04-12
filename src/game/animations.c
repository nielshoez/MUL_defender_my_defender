/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** caca
*/

#include "my.h"

void handle_animation(game_t *game, int i)
{
    game->ennemy->time[i] = sfClock_getElapsedTime(game->ennemy->animations[i]);
    game->ennemy->seconds[i] = game->ennemy->time[i].microseconds / 1000000.0;
    if (game->ennemy->seconds[i] >= 0.3) {
        if (game->ennemy->ennemy_rect[i].left + 33 > 90)
            game->ennemy->ennemy_rect[i].left = 0;
        else
            game->ennemy->ennemy_rect[i].left += 33;
        sfClock_restart(game->ennemy->animations[i]);
    }
    sfSprite_setTextureRect(game->ennemy->sprites[i],
                            game->ennemy->ennemy_rect[i]);
}

void handle_end(game_t *game, sfRenderWindow *window)
{
    if (game->other->base_health <= 0) {
        sfMusic_destroy(game->sounds->sounds[2]);
        game->sounds->sounds[2] = NULL;
        end(game, window);
    }
}
