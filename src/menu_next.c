/*
** EPITECH PROJECT, 2019
** menu_next.c
** File description:
** menu_next
*/

#include "my.h"

int manage_mouse_click(game_t *game, sfRenderWindow *wd)
{
    sfVector2i mouse_pos = sfMouse_getPosition(NULL);
    sfVector2f sprite_pos = sfSprite_getPosition(game->menu->sprites[1]);
    sfVector2f sprite_pos2 = sfSprite_getPosition(game->menu->sprites[2]);

    if (mouse_pos.y >= sprite_pos.y && mouse_pos.x >= sprite_pos.x
    && mouse_pos.y <= sprite_pos.y + 190 && mouse_pos.x <= sprite_pos.x + 190) {
        enter_game_loop(game, wd);
        return (0);
    }
    else if (mouse_pos.y >= sprite_pos2.y && mouse_pos.x >= sprite_pos2.x
    && mouse_pos.y <= sprite_pos2.y + 190 &&
            mouse_pos.x <= sprite_pos2.x + 190) {
        sfRenderWindow_close(wd);
        return (0);
    }
    return (1);
}
