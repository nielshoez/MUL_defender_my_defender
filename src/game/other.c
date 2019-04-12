/*
** EPITECH PROJECT, 2019
** defender
** File description:
** caca
*/

#include "my.h"

int is_in_a_rect(game_t *game, sfVector2f sp_pos, int k)
{
    if (game->other->is_dragged == 1 &&
        sp_pos.x >= game->tower->rects[k].left
        && sp_pos.y >= game->tower->rects[k].top
        && sp_pos.x <= (game->tower->rects[k].left +
                        game->tower->rects[k].width)
        && sp_pos.y <= (game->tower->rects[k].top +
                        game->tower->rects[k].height)
        && game->other->is_place[k] != 1)
        return (1);
    return (0);
}
