/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** my_defender
*/

#include "my.h"

static void display_map(game_t *game, sfRenderWindow *window)
{
    for (int i = 0; i != 3; i++)
        sfRenderWindow_drawSprite(window, game->map->sprites[i], NULL);
}

static void display_dragged(game_t *game, sfRenderWindow *window)
{
    sfVector2i temp = sfMouse_getPosition(NULL);
    sfVector2f pos = {temp.x - 20, temp.y - 100};

    sfSprite_setPosition(game->tower->sprites[7], pos);
    sfRenderWindow_drawSprite(window, game->tower->sprites[7], NULL);
}

void display_dropped(game_t *game, sfRenderWindow *window)
{
    (void) window;
    sfVector2i temp = sfMouse_getPosition(NULL);
    sfVector2f pos = {temp.x - 20, temp.y - 100};

    if (drop_hitbox(game, game->tower->sprites[7]) == 1 &&
        game->money->money >= (game->tower->index * 10)) {
        setup_towers(game, pos);
        game->money->money -= (game->tower->index * 10);
        return;
    }
}

static void display_ennemies(game_t *game, sfRenderWindow *window)
{
    move_ennemies(game);
    for (int i = 0; i != game->ennemy->wave_lenght; i++) {
        if (game->ennemy->sprites[i] != NULL)
            sfRenderWindow_drawSprite(window, game->ennemy->sprites[i], NULL);
    }
}

void display_all(game_t *game, sfRenderWindow *window)
{
    display_map(game, window);
    display_select(game, window);
    display_ennemies(game, window);
    display_towers(game, window);
    move_proj(game);
    sfText_setString(game->money->money_text, my_itoa(game->money->money));
    sfRenderWindow_drawText(window, game->other->texts[0], NULL);
    sfRenderWindow_drawText(window, game->money->money_text, NULL);
    if (game->other->is_dragged == 1)
            display_dragged(game, window);
    sfRenderWindow_display(window);
}
