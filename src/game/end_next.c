/*
** EPITECH PROJECT, 2019
** end_next.c
** File description:
** end_next
*/

#include "my.h"

int manage_mouse_end(game_t *game, sfRenderWindow *wd)
{
    sfVector2i mouse_pos = sfMouse_getPosition(NULL);
    sfVector2f sprite_pos2 = sfSprite_getPosition(game->end->sprites[2]);

    if (mouse_pos.y >= sprite_pos2.y && mouse_pos.x >= sprite_pos2.x
        && mouse_pos.y <= sprite_pos2.y + 190 &&
        mouse_pos.x <= sprite_pos2.x + 190) {
        sfRenderWindow_close(wd);
        return (0);
    }
    return (1);
}
