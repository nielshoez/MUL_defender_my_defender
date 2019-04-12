/*
** EPITECH PROJECT, 2019
** end_screen.c
** File description:
** end_screen
*/

#include "my.h"

void initialize_end(game_t *game)
{
    game->end->textures = malloc(sizeof(sfTexture *) * 3);
    game->end->sprites = malloc(sizeof(sfSprite *) * 3);
    game->end->rects = malloc(sizeof(sfIntRect) * 2);
    game->end->textures[0] = sfTexture_createFromFile
        ("assets/textures/game_over.png", NULL);
    game->end->textures[1] = sfTexture_createFromFile
        ("assets/textures/play.png", NULL);
    game->end->textures[2] = sfTexture_createFromFile
        ("assets/textures/quit.png", NULL);
    for (int i = 0; i != 2; i++)
        game->end->rects[i] = get_rect(38, 47, 187, 108);
    for (int j = 0; j != 3; j++)
        game->end->sprites[j] = sfSprite_create();
}

void disp_end(game_t *game, sfRenderWindow *window)
{
    sfSprite_setTexture(game->end->sprites[0],
                        game->end->textures[0], sfTrue);
    sfRenderWindow_drawSprite(window, game->end->sprites[0], NULL);
    sfSprite_setTexture(game->end->sprites[1]
                        , game->end->textures[1], sfTrue);
    sfSprite_setTextureRect(game->end->sprites[1],
                            game->end->rects[0]);
    sfSprite_setTexture(game->end->sprites[2],
                        game->end->textures[2], sfTrue);
    sfSprite_setTextureRect(game->end->sprites[2], game->end->rects[1]);
    sfRenderWindow_drawSprite(window, game->end->sprites[2], NULL);
    sfSprite_setPosition(game->end->sprites[1], get_vector(500, 200));
    sfSprite_setPosition(game->end->sprites[2], get_vector(700, 200));
}

void scale_end(game_t *game, sfRenderWindow *wd)
{
    sfVector2i mouse_pos = sfMouse_getPosition(NULL);
    sfVector2f scale = get_vector(1.1, 1.1);
    sfVector2f sprite_pos2 = sfSprite_getPosition(game->end->sprites[2]);
    sfVector2f scale2 = get_vector(1, 1);
    (void) wd;

    if (mouse_pos.y >= sprite_pos2.y && mouse_pos.x >= sprite_pos2.x
    && mouse_pos.y <= sprite_pos2.y + 190 &&
            mouse_pos.x <= sprite_pos2.x + 190) {
        sfSprite_setScale(game->end->sprites[2], scale);
    }
    else {
        sfSprite_setScale(game->end->sprites[1], scale2);
        sfSprite_setScale(game->end->sprites[2], scale2);
    }
}

void end_events(game_t *game, sfRenderWindow *window, sfEvent evt)
{
    (void) game;
    while (sfRenderWindow_pollEvent(window, &evt)) {
        switch(evt.type) {
        case sfEvtClosed:
            sfRenderWindow_close(window);
            break;
        case sfEvtMouseButtonReleased :
            if (evt.mouseButton.button == sfMouseLeft) {
                manage_mouse_end(game, window);
            }
            break;
        default :
            return;
        }
    }
}

void end(game_t *game, sfRenderWindow *window)
{
    sfEvent event;

    while (sfRenderWindow_isOpen(window)) {
        disp_end(game, window);
        end_events(game, window, event);
        scale_end(game, window);
        sfRenderWindow_display(window);
        if (game->game_state == 1)
            break;
    }
    sfRenderWindow_destroy(window);
}