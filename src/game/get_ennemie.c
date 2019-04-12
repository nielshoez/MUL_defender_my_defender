/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** niels
*/

#include "my.h"

static void assign_speed(game_t *game, int level, int index)
{
    game->ennemy->speed[index] = level + 2;
}

static void spawn_new_ennemie(game_t *game, int level, int index)
{
    int base_hp = 8;

    game->ennemy->sprites[index] = sfSprite_create();
    if (level == 0)
        game->ennemy->health[index] = base_hp;
    else
        game->ennemy->health[index] = (level + 1) * (base_hp - 2);
    game->ennemy->poses[index] = new_random_pos();
    sfSprite_setPosition(game->ennemy->sprites[index],
                        game->ennemy->poses[index]);
    sfSprite_setTexture(game->ennemy->sprites[index],
                            game->ennemy->textures[0], sfTrue);
    sfSprite_setTextureRect(game->ennemy->sprites[index]
                            , game->ennemy->rects[level]);
    game->ennemy->ennemy_rect[index] = game->ennemy->rects[level];
    sfSprite_setScale(game->ennemy->sprites[index], get_vector(2, 2));
    assign_speed(game, level, index);
    game->other->base_color[index] =
        sfSprite_getColor(game->ennemy->sprites[index]);
}

void get_new_ennemie(game_t *game, int index)
{
    if (index > 6 && index <= 10)
        spawn_new_ennemie(game, 0, index);
    else if (index > 10)
        spawn_new_ennemie(game, 1, index);
    else
        spawn_new_ennemie(game, index, index);
}
