/*
** EPITECH PROJECT, 2019
** pause.c
** File description:
** pause
*/

#include "my.h"

void initialize_pause(game_t *game)
{
    int cnt = 0;
    game->pause->textures = malloc(sizeof(sfTexture *));
    game->pause->sprites = malloc(sizeof(sfSprite *) * 4);
    game->pause->rects = malloc(sizeof(sfIntRect) * 4);
    game->pause->textures[0] = sfTexture_createFromFile
        ("assets/textures/menu_pause.png", NULL);
    for (int i = 0; i != 4; i++)
        game->pause->sprites[i] = sfSprite_create();
    for (int j = 0; j != 3; j++, cnt += 135)
        game->pause->rects[j] = get_rect(180 + cnt, 374, 412, 125);
    game->pause->rects[3] = get_rect(5, 157, 914, 158);
}

int pause_events(game_t *game, sfRenderWindow *window, sfEvent evt)
{
    (void) game;
    while (sfRenderWindow_pollEvent(window, &evt)) {
        switch(evt.type) {
        case sfEvtClosed:
            sfRenderWindow_close(window);
            break;
        case sfEvtMouseButtonReleased :
            if (evt.mouseButton.button == sfMouseLeft) {
                    return (manage_mouse_pause(game, window));
            }
            break;
        case sfEvtKeyPressed:
                if (sfKeyboard_isKeyPressed(sfKeyEscape))
                    return (1);
            break;
        default :
            return (0);
        }
    }
    return (0);
}

static sfVector2f *get_poses(game_t *game)
{
    sfVector2f *poses = malloc(sizeof(sfVector2f) * 3);

    poses[0] = sfSprite_getPosition(game->pause->sprites[0]);
    poses[1] = sfSprite_getPosition(game->pause->sprites[1]);
    poses[2] = sfSprite_getPosition(game->pause->sprites[2]);
    return (poses);
}

int manage_mouse_pause(game_t *game, sfRenderWindow *wd)
{
    sfVector2i mouse_pos = sfMouse_getPosition(NULL);
    sfVector2f *poses = get_poses(game);
    if (mouse_pos.y >= poses[0].y && mouse_pos.x >= poses[0].x
    && mouse_pos.y <= poses[0].y + 170 && mouse_pos.x <= poses[0].x + 400) {
        return (1);
    }
    else if (mouse_pos.y >= poses[1].y && mouse_pos.x >= poses[1].x
    && mouse_pos.y <= poses[1].y + 170 &&
            mouse_pos.x <= poses[1].x + 400) {
        menu(game, wd);
        return (0);
    }
    else if (mouse_pos.y >= poses[2].y && mouse_pos.x >= poses[2].x
    && mouse_pos.y <= poses[2].y + 170 &&
            mouse_pos.x <= poses[2].x + 400) {
        sfRenderWindow_close(wd);
        sfMusic_destroy(game->sounds->sounds[2]);
        return (2);
    }
    return (0);
}

int pause_menu(game_t *game, sfRenderWindow *window)
{
    sfEvent event;

    disp_pause(game, window);
    return (pause_events(game, window, event));
}
