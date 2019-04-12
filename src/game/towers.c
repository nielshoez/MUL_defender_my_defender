/*
** EPITECH PROJECT, 2019
** towers.c
** File description:
** towers
*/

#include "my.h"

void initialize_towers(game_t *game)
{
    game->tower->textures = malloc(sizeof(sfTexture * )* 2);
    game->tower->sprites = malloc(sizeof(sfSprite *) * 8);
    game->tower->rects = malloc(sizeof(sfIntRect) * 52);
    game->tower->clocks = malloc(sizeof(sfClock *) * 45);
    game->tower->dropped = malloc(sizeof(sfSprite *) * 45);
    game->tower->time = malloc(sizeof(sfTime) * 1);
    game->tower->type = malloc(sizeof(int) * 45);
    game->tower->what = 0;
    game->tower->textures[0] = sfTexture_createFromFile
        ("assets/textures/selection.png", NULL);
    game->tower->textures[1] = sfTexture_createFromFile
        ("assets/textures/towers.png", NULL);
    for (int i = 0; i != 8; i++)
        game->tower->sprites[i] = sfSprite_create();
    for (int j = 0; j != 45; j++)
        game->tower->dropped[j] = sfSprite_create();
    init_towers_2(game);
}

void display_select(game_t *game, sfRenderWindow *window)
{
    sfSprite_setTexture(game->tower->sprites[0],
                        game->tower->textures[0], sfTrue);
    sfRenderWindow_drawSprite(window, game->tower->sprites[0], NULL);
    sfSprite_setScale(game->tower->sprites[0], get_vector(0.7, 0.7));
    for (int i = 1; i != 7; i++) {
        sfSprite_setTexture(game->tower->sprites[i],
                            game->tower->textures[1], sfTrue);
        sfSprite_setTextureRect(game->tower->sprites[i],
                                game->tower->rects[i]);
        sfSprite_setPosition(game->tower->sprites[i],
                            get_vector(60 + 85 * i, 20));
        sfRenderWindow_drawSprite(window, game->tower->sprites[i], NULL);
    }
    scale_towers(game, window);
    scale_towers2(game, window);
    scale_towers3(game, window);
}

void scale_towers(game_t *game, sfRenderWindow *wd)
{
    sfVector2i mouse_pos = sfMouse_getPosition(NULL);
    sfVector2f scale = get_vector(1.1, 1.1);
    sfVector2f sprite_pos = sfSprite_getPosition(game->tower->sprites[1]);
    sfVector2f sprite_pos2 = sfSprite_getPosition(game->tower->sprites[2]);
    sfVector2f scale2 = get_vector(1, 1);
    (void) wd;

    if (mouse_pos.y >= sprite_pos.y && mouse_pos.x >= sprite_pos.x
    && mouse_pos.y <= sprite_pos.y + 140 && mouse_pos.x <= sprite_pos.x + 70) {
        sfSprite_setScale(game->tower->sprites[1], scale);
    }
    else if (mouse_pos.y >= sprite_pos2.y && mouse_pos.x >= sprite_pos2.x
    && mouse_pos.y <= sprite_pos2.y + 140 &&
            mouse_pos.x <= sprite_pos2.x + 70) {
        sfSprite_setScale(game->tower->sprites[2], scale);
    }
    else {
        sfSprite_setScale(game->tower->sprites[1], scale2);
        sfSprite_setScale(game->tower->sprites[2], scale2);
    }
}

void scale_towers2(game_t *game, sfRenderWindow *wd)
{
    sfVector2i mouse_pos = sfMouse_getPosition(NULL);
    sfVector2f scale = get_vector(1.1, 1.1);
    sfVector2f sprite_pos = sfSprite_getPosition(game->tower->sprites[3]);
    sfVector2f sprite_pos2 = sfSprite_getPosition(game->tower->sprites[4]);
    sfVector2f scale2 = get_vector(1, 1);
    (void) wd;

    if (mouse_pos.y >= sprite_pos.y && mouse_pos.x >= sprite_pos.x
    && mouse_pos.y <= sprite_pos.y + 140 && mouse_pos.x <= sprite_pos.x + 70) {
        sfSprite_setScale(game->tower->sprites[3], scale);
    }
    else if (mouse_pos.y >= sprite_pos2.y && mouse_pos.x >= sprite_pos2.x
    && mouse_pos.y <= sprite_pos2.y + 140 &&
            mouse_pos.x <= sprite_pos2.x + 70) {
        sfSprite_setScale(game->tower->sprites[4], scale);
    }
    else {
        sfSprite_setScale(game->tower->sprites[3], scale2);
        sfSprite_setScale(game->tower->sprites[4], scale2);
    }
}

void scale_towers3(game_t *game, sfRenderWindow *wd)
{
    sfVector2i mouse_pos = sfMouse_getPosition(NULL);
    sfVector2f scale = get_vector(1.1, 1.1);
    sfVector2f sprite_pos = sfSprite_getPosition(game->tower->sprites[5]);
    sfVector2f sprite_pos2 = sfSprite_getPosition(game->tower->sprites[6]);
    sfVector2f scale2 = get_vector(1, 1);
    (void) wd;

    if (mouse_pos.y >= sprite_pos.y && mouse_pos.x >= sprite_pos.x
    && mouse_pos.y <= sprite_pos.y + 140 && mouse_pos.x <= sprite_pos.x + 70) {
        sfSprite_setScale(game->tower->sprites[5], scale);
    }
    else if (mouse_pos.y >= sprite_pos2.y && mouse_pos.x >= sprite_pos2.x
    && mouse_pos.y <= sprite_pos2.y + 140 &&
            mouse_pos.x <= sprite_pos2.x + 70) {
        sfSprite_setScale(game->tower->sprites[6], scale);
    }
    else {
        sfSprite_setScale(game->tower->sprites[5], scale2);
        sfSprite_setScale(game->tower->sprites[6], scale2);
    }
}
