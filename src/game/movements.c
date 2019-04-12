/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** aya
*/

#include "my.h"

static int is_out(game_t *game, int i)
{
    if (game->ennemy->poses[i].x <= 300) {
        game->ennemy->poses[i].x = 0;
        return (1);
    }
    return (0);
}

static int is_a_turret(game_t *game, int i)
{
    sfVector2f pos;

    for (int j = 0; j != 45; j++) {
        if (game->tower->pos_dropped != NULL &&
            &(game->tower->pos_dropped[j]) != NULL
            && game->tower->dropped[j] != NULL) {
            pos = sfSprite_getPosition(game->tower->dropped[j]);
            if (pos.x  - 20 >= game->ennemy->poses[i].x &&
                pos.y - 10 <= game->ennemy->poses[i].y &&
                pos.y + 75 >= game->ennemy->poses[i].y)
                return (0);
            if (pos.x + 75 >= game->ennemy->poses[i].x &&
                pos.y - 10 <= game->ennemy->poses[i].y &&
                pos.y + 75 >= game->ennemy->poses[i].y)
                return (j);
        }
    }
    return (0);
}

static void free_line(game_t *game, int i)
{
    game->ennemy->nb_ennemies--;
    sfSprite_destroy(game->ennemy->sprites[i]);
    game->ennemy->sprites[i] = NULL;
}

static void handle_position(game_t *game, int i)
{
    int tower_pos = 0;

    game->sounds->time[0] = sfClock_getElapsedTime(game->sounds->clocks[0]);
    game->sounds->seconds = game->sounds->time[0].microseconds / 1000000.0;
    if ((tower_pos = is_a_turret(game, i)) == 0) {
        handle_animation(game, i);
        game->ennemy->poses[i].x -= game->ennemy->speed[i];
        sfSprite_setPosition(game->ennemy->sprites[i],
                            game->ennemy->poses[i]);
    } else {
        if (game->sounds->seconds >= 5) {
            game->tower->health[tower_pos] -= 9;
            sfMusic_play(game->sounds->sounds[0]);
            sfClock_restart(game->sounds->clocks[0]);
        }
    }
    check_towers_health(game, tower_pos);
    sfClock_restart(game->ennemy->clocks[i]);
}

void move_ennemies(game_t *game)
{
    for (int i = 0; i != game->ennemy->wave_lenght; i++) {
        if (game->ennemy->sprites[i] != NULL) {
            game->ennemy->time[i] =
                sfClock_getElapsedTime(game->ennemy->clocks[i]);
            game->ennemy->seconds[i] =
                game->ennemy->time[i].microseconds / 1000000.0;
            if (game->ennemy->seconds[i] > 0.1)
                handle_position(game, i);
            if (is_out(game, i)) {
                free_line(game, i);
                game->other->base_health -= 100;
            }
        }
    }
}
