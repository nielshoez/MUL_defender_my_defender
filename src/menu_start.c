/*
** EPITECH PROJECT, 2019
** menu_start.c
** File description:
** menu_start
*/

#include "my.h"

void initialize_menu(game_t *game)
{
    game->menu->textures = malloc(sizeof(sfTexture *) * 3);
    game->menu->sprites = malloc(sizeof(sfSprite *) * 3);
    game->menu->rects = malloc(sizeof(sfIntRect) * 2);
    game->menu->textures[0] = sfTexture_createFromFile
        ("assets/textures/menu_background.png", NULL);
    game->menu->textures[1] = sfTexture_createFromFile
        ("assets/textures/play.png", NULL);
    game->menu->textures[2] = sfTexture_createFromFile
        ("assets/textures/quit.png", NULL);
    for (int i = 0; i != 2; i++)
        game->menu->rects[i] = get_rect(38, 47, 187, 108);
    for (int j = 0; j != 3; j++)
        game->menu->sprites[j] = sfSprite_create();
    game->other->base_health = 100;
}

void disp_menu(game_t *game, sfRenderWindow *window)
{
    sfSprite_setTexture(game->menu->sprites[0],
                        game->menu->textures[0], sfTrue);
    sfRenderWindow_drawSprite(window, game->menu->sprites[0], NULL);
    sfSprite_setTexture(game->menu->sprites[1]
                        , game->menu->textures[1], sfTrue);
    sfSprite_setTextureRect(game->menu->sprites[1],
                            game->menu->rects[0]);
    sfRenderWindow_drawSprite(window, game->menu->sprites[1], NULL);
    sfSprite_setTexture(game->menu->sprites[2],
                        game->menu->textures[2], sfTrue);
    sfSprite_setTextureRect(game->menu->sprites[2], game->menu->rects[1]);
    sfRenderWindow_drawSprite(window, game->menu->sprites[2], NULL);
    sfSprite_setPosition(game->menu->sprites[1], get_vector(500, 200));
    sfSprite_setPosition(game->menu->sprites[2], get_vector(700, 200));
}

void scale_buttons(game_t *game, sfRenderWindow *wd)
{
    sfVector2i mouse_pos = sfMouse_getPosition(NULL);
    sfVector2f scale = get_vector(1.1, 1.1);
    sfVector2f sprite_pos = sfSprite_getPosition(game->menu->sprites[1]);
    sfVector2f sprite_pos2 = sfSprite_getPosition(game->menu->sprites[2]);
    sfVector2f scale2 = get_vector(1, 1);
    (void) wd;

    if (mouse_pos.y >= sprite_pos.y && mouse_pos.x >= sprite_pos.x
    && mouse_pos.y <= sprite_pos.y + 190 && mouse_pos.x <= sprite_pos.x + 190) {
        sfSprite_setScale(game->menu->sprites[1], scale);
    }
    else if (mouse_pos.y >= sprite_pos2.y && mouse_pos.x >= sprite_pos2.x
    && mouse_pos.y <= sprite_pos2.y + 190 &&
            mouse_pos.x <= sprite_pos2.x + 190) {
        sfSprite_setScale(game->menu->sprites[2], scale);
    }
    else {
        sfSprite_setScale(game->menu->sprites[1], scale2);
        sfSprite_setScale(game->menu->sprites[2], scale2);
    }
}

void menu_events(game_t *game, sfRenderWindow *window, sfEvent evt)
{
    (void) game;
    while (sfRenderWindow_pollEvent(window, &evt)) {
        switch(evt.type) {
        case sfEvtClosed:
            sfRenderWindow_close(window);
            break;
        case sfEvtMouseButtonReleased :
            if (evt.mouseButton.button == sfMouseLeft) {
                manage_mouse_click(game, window);
            }
            break;
        default :
            return;
        }
    }
}

void menu(game_t *game, sfRenderWindow *window)
{
    sfEvent event;

    while (sfRenderWindow_isOpen(window)) {
        disp_menu(game, window);
        menu_events(game, window, event);
        scale_buttons(game, window);
        sfRenderWindow_display(window);
        if (game->game_state == 1)
            break;
    }
    sfRenderWindow_destroy(window);
}
