/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** yoloswag
*/

#include "my.h"

void disp_pause(game_t *game, sfRenderWindow *window)
{
    if (!sfRenderWindow_isOpen(window)) {
        return;
    }
    for (int i = 0; i != 3; i++) {
        sfSprite_setTexture(game->pause->sprites[i],
                            game->pause->textures[0], sfTrue);
        sfSprite_setTextureRect(game->pause->sprites[i],
                                game->pause->rects[i]);
        sfSprite_setPosition(game->pause->sprites[i], get_vector(720, 150 * i));
        sfRenderWindow_drawSprite(window, game->pause->sprites[i], NULL);
    }
    sfRenderWindow_display(window);
}
