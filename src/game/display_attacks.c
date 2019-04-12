/*
** EPITECH PROJECT, 2019
** display_attacks.c
** File description:
** display_attacks
*/

#include "my.h"

void init_attack_2(game_t *game)
{
    game->attack->index = 0;
    game->attack->move = malloc(sizeof(sfClock *) * 46);
    for (int k = 0; k != 45; k++)
        game->attack->move[k] = sfClock_create();
}

void initialize_attack(game_t *game)
{
    game->attack->textures = malloc(sizeof(sfTexture * ) * 2);
    game->attack->sprites = malloc(sizeof(sfSprite *) * 46);
    game->attack->rects = malloc(sizeof(sfIntRect) * 3);
    game->attack->clocks = malloc(sizeof(sfClock *) * 46);
    game->attack->shoot = malloc(sizeof(sfClock *) * 46);
    game->attack->time = malloc(sizeof(sfTime) * 2);
    game->attack->textures[0] = sfTexture_createFromFile
        ("assets/textures/projectiles.png", NULL);
    game->attack->pos = malloc(sizeof(sfVector2f) * 46);
    game->attack->speed = malloc(sizeof(int) * 46);
    for (int i = 0; i != 45; i++)
        game->attack->sprites[i] = sfSprite_create();
    game->attack->rects[0] = get_rect(0, 5, 124, 191);
    game->attack->rects[1] = get_rect(204, 5, 162, 158);
    game->attack->rects[2] = get_rect(374, 5, 169, 59);
    for (int k = 0; k != 45; k++) {
        game->attack->clocks[k] = sfClock_create();
        game->attack->shoot[k] = sfClock_create();
    } for (int l = 0; l != 45; l++)
        game->attack->speed[l] = 1;
    init_attack_2(game);
}

int is_ennemi_line(game_t *game, sfSprite *sprite)
{
    if (sprite == NULL)
        return (0);
    sfVector2f pos = sfSprite_getPosition(sprite);
    sfVector2f pos_en;

    for (int i = 0; i != game->ennemy->wave_lenght; i++) {
        if (game->ennemy->sprites[i] != NULL) {
            pos_en = sfSprite_getPosition(game->ennemy->sprites[i]);
            if (pos_en.y >= pos.y && pos_en.x >= pos.x
                && pos_en.y <= pos.y + 70 && pos_en.x <= pos.x + 900) {
                game->attack->index = i;
                return (1);
            }
        }
    }
    return (0);
}
