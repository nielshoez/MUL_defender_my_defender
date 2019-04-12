/*
** EPITECH PROJECT, 2019
** display_towers.c
** File description:
** display_towers
*/

#include "my.h"

void setup_towers(game_t *game, sfVector2f pos)
{
    sfVector2f middle;
    int nb = game->tower->tile;
    (void) pos;
    middle.y = game->tower->rects[nb + 7].height / 2 +
    game->tower->rects[nb + 7].top;
    middle.x = game->tower->rects[nb + 7].width / 2 +
    game->tower->rects[nb + 7].left;
    sfVector2f scale = get_vector(1.5, 1.5);
    game->tower->health = malloc(sizeof(int) * 45);
    game->tower->damage = malloc(sizeof(int) * 45);
    game->tower->dropped[nb] = game->tower->sprites[7];
    game->tower->damage[nb] = 5;
    game->tower->health[nb] = 10;
    game->tower->pos_dropped = malloc(sizeof(sfVector2f) * 45);
    sfSprite_setScale(game->tower->dropped[nb], scale);
    sfSprite_setPosition(game->tower->dropped[nb], middle);
    game->tower->pos_dropped[nb] = middle;
    game->attack->pos[nb].x = middle.x;
    game->attack->pos[nb].y = middle.y + 70;
    game->tower->type[nb] = game->tower->what;
}

static void check_tower_health(game_t *game)
{
    for (int j = 0; game->ennemy->wave_lenght != j; j++) {
        if (game->ennemy->sprites[j] != NULL && game->ennemy->health[j] <= 0) {
            sfSprite_destroy(game->ennemy->sprites[j]);
            game->ennemy->poses[j].x = -100;
            game->ennemy->nb_ennemies--;
            game->ennemy->sprites[j] = NULL;
            sfMusic_play(game->sounds->sounds[1]);
            game->money->money += 10;
        }
    }
}

void display_towers(game_t *game, sfRenderWindow *window)
{
    for (int i = 0; i != 45; i++) {
        game->attack->time[0] = sfClock_getElapsedTime(game->attack->shoot[i]);
        game->attack->seconds[0] =
            game->attack->time[0].microseconds / 1000000.0;
        if (game->tower->dropped[i] != NULL) {
            sfRenderWindow_drawSprite(window, game->tower->dropped[i], NULL);
            if (is_ennemi_line(game, game->tower->dropped[i]) == 1 &&
                game->attack->seconds[0] > 0.75) {
                shoot_anime(game, window);
            }
        }
    }
    check_tower_health(game);
}
