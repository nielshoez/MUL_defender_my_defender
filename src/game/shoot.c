/*
** EPITECH PROJECT, 2019
** shoot.c
** File description:
** shoot
*/

#include "my.h"

void shoot_anime(game_t *game, sfRenderWindow *wd)
{
    for (int j = 0; j != 45; j++) {
        sfSprite_setTexture(game->attack->sprites[j],
                    game->attack->textures[0], sfTrue);
        if (game->tower->type[j] == 2) {
            sfSprite_setTextureRect(game->attack->sprites[j],
                                        game->attack->rects[0]);
            sfSprite_setRotation(game->attack->sprites[j], -55);
        }
        if (game->tower->type[j] == 1 || game->tower->type[j] == 5)
            sfSprite_setTextureRect(game->attack->sprites[j],
                                        game->attack->rects[2]);
        if (game->tower->type[j] == 6)
            sfSprite_setTextureRect(game->attack->sprites[j],
                                        game->attack->rects[1]);
        if (game->tower->type[j] == 3 || game->tower->type[j] == 4);
        shoot_anime2(game, wd, j);
    }
}

void shoot_anime2(game_t *game, sfRenderWindow *wd, int j)
{
    sfVector2f scale = {0.3, 0.3};
    sfVector2f test = {-200, -200};

    sfSprite_setScale(game->attack->sprites[j], scale);
    if (game->tower->type[j] == 3 || game->tower->type[j] == 4)
        sfSprite_setPosition(game->attack->sprites[j], test);
    else
        sfSprite_setPosition(game->attack->sprites[j], game->attack->pos[j]);
    sfRenderWindow_drawSprite(wd, game->attack->sprites[j], NULL);
    if (is_ennemi_touch(game, game->attack->pos[j], game->tower->type[j])
        && game->tower->dropped[j] != NULL) {
        game->attack->pos[j].x =
            sfSprite_getPosition(game->tower->dropped[j]).x;
    }
}

void move_proj(game_t *game)
{
    for (int i = 0; i != 45; i++) {
        if (is_ennemi_line(game, game->tower->dropped[i]) == 1) {
            game->attack->pos[i].x += game->attack->speed[i];
        }
    }
}

int is_ennemi_touch(game_t *game, sfVector2f pos, int index)
{
    for (int i = 0; i != game->ennemy->wave_lenght; i++) {
        if (game->ennemy->poses[i].x >= pos.x - 5
        && game->ennemy->poses[i].x <= pos.x + 5
        && game->ennemy->poses[i].y >= pos.y - 30
        && game->ennemy->poses[i].y <= pos.y + 30) {
            handle_hit(game, index, i);
            sfSprite_setColor(game->ennemy->sprites[i] , sfTransparent);
            game->other->index = i;
            game->other->hit_ennemy = sfClock_create();
            return (1);
        }
    }
    return (0);
}
