/*
** EPITECH PROJECT, 2019
** tower_drag&drop.c
** File description:
** tower_drag&drop
*/

#include "my.h"

int tower_hitbox(game_t *game, sfVector2i mouse_pos, sfEvent evt)
{
    sfVector2f sprite_pos = sfSprite_getPosition(game->tower->sprites[1]);
    sfVector2f sprite_pos2 = sfSprite_getPosition(game->tower->sprites[2]);
    sfVector2f sprite_pos3 = sfSprite_getPosition(game->tower->sprites[3]);
    if (mouse_pos.y >= sprite_pos.y && mouse_pos.x >= sprite_pos.x
    && mouse_pos.y <= sprite_pos.y + 140 && mouse_pos.x <= sprite_pos.x + 70) {
        drag_drop(game, game->tower->sprites[1], evt, 1);
        game->tower->what = 1;
    }
    if (mouse_pos.y >= sprite_pos2.y && mouse_pos.x >= sprite_pos2.x
    && mouse_pos.y<=sprite_pos2.y+140 && mouse_pos.x<=sprite_pos2.x+70) {
        drag_drop(game, game->tower->sprites[2], evt, 2);
        game->tower->what = 2;
    }
    if (mouse_pos.y >= sprite_pos3.y && mouse_pos.x >= sprite_pos3.x
    && mouse_pos.y <= sprite_pos3.y + 140
        && mouse_pos.x <= sprite_pos3.x + 70) {
        drag_drop(game, game->tower->sprites[3], evt, 3);
        game->tower->what = 3;
    }
    return (0);
}

int tower_hitbox2(game_t *game, sfVector2i mouse_pos, sfEvent evt)
{
    sfVector2f sprite_pos = sfSprite_getPosition(game->tower->sprites[4]);
    sfVector2f sprite_pos2 = sfSprite_getPosition(game->tower->sprites[5]);
    sfVector2f sprite_pos3 = sfSprite_getPosition(game->tower->sprites[6]);
    if (mouse_pos.y >= sprite_pos.y && mouse_pos.x >= sprite_pos.x
    && mouse_pos.y <= sprite_pos.y + 140 && mouse_pos.x <= sprite_pos.x + 70) {
        drag_drop(game, game->tower->sprites[4], evt, 4);
        game->tower->what = 4;
    }
    if (mouse_pos.y >= sprite_pos2.y && mouse_pos.x >= sprite_pos2.x
    && mouse_pos.y <= sprite_pos2.y + 140 &&mouse_pos.x <=sprite_pos2.x + 70) {
        drag_drop(game, game->tower->sprites[5], evt, 5);
        game->tower->what = 5;
    }
    if (mouse_pos.y >= sprite_pos3.y && mouse_pos.x >= sprite_pos3.x
    && mouse_pos.y <= sprite_pos3.y + 140 &&
        mouse_pos.x <= sprite_pos3.x + 70) {
        drag_drop(game, game->tower->sprites[6], evt, 6);
        game->tower->what = 6;
    }
    return (0);
}

int drag_drop(game_t *game, sfSprite *sp, sfEvent evt, int index)
{
    (void) evt;

    game->tower->index = index;
    game->tower->sprites[7] = sfSprite_copy(sp);
    game->other->is_dragged = 1;
    return (0);
}

int drop_hitbox(game_t *game, sfSprite *sp)
{
    sfVector2f sp_pos = sfSprite_getPosition(sp);
    int cnt = 7;
    int tab = 180;

    game->other->is_place = malloc(sizeof(int) * 52);
    for (int i = 0; i != 5; i++, tab += 120) {
        for (int j = 0; j != 9; j++, cnt++) {
            game->tower->rects[cnt] = get_rect(tab , 480 + 80 * j, 82, 135);
        }
    }
    for (int k = 7; k != 52; k++) {
        if (is_in_a_rect(game, sp_pos, k)) {
            game->other->is_place[k] = 1;
            game->tower->tile = k - 7;
            return (1);
        }
    }
    return (0);
}

void handle_drag(game_t *game, sfEvent evt)
{
    sfVector2i mouse_pos = sfMouse_getPosition(NULL);
    tower_hitbox(game, mouse_pos, evt);
    tower_hitbox2(game, mouse_pos, evt);
}
