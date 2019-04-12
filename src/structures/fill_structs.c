/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** fill game's structs
*/

#include "my.h"

static void fill_ennemy(game_t *game)
{
    int top = 0;

    game->ennemy->textures = malloc(sizeof(sfTexture *) * 1);
    game->ennemy->rects = malloc(sizeof(sfIntRect) * 8);
    game->ennemy->textures[0] = sfTexture_createFromFile
        ("assets/textures/ennemies.png", NULL);
    for (int i = 0; i != 7; i++, top += 40)
        game->ennemy->rects[i] = get_rect(top, 0, 33, 35);
}

static void fill_map(game_t *game)
{
    game->map->textures = malloc(sizeof(sfTexture *) * 1);
    game->map->textures[0] = sfTexture_createFromFile
        ("assets/textures/map.png", NULL);
    game->map->sprites = malloc(sizeof(sfSprite *) * 3);
    for (int i = 0; i != 3; i++)
        game->map->sprites[i] = sfSprite_create();
    sfSprite_setTexture(game->map->sprites[0], game->map->textures[0], sfTrue);
    game->map->castle_health = 3;
}

void fill_structs(game_t *game)
{
    fill_ennemy(game);
    fill_map(game);
}
