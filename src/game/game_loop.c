/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** my_defender
*/

#include "my.h"

static void play_da_music(game_t *game)
{
    static int i = 0;

    if (i == 0) {
        sfMusic_play(game->sounds->sounds[2]);
        sfMusic_setLoop(game->sounds->sounds[2], sfTrue);
        sfMusic_setVolume(game->sounds->sounds[2], 40);
    }
    i++;
}

static void pause_game(game_t *game, sfRenderWindow *wd)
{
    sfEvent evt2;
    while (1) {
        if (pause_menu(game, wd) == 1)
            break;
        else if (pause_menu(game, wd) == 2)
            game->game_state = 1;
        while (sfRenderWindow_pollEvent(wd, &evt2)) {
            switch (evt2.type) {
            case sfEvtKeyPressed:
                if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
                    return;
                }
            default:
                break;
            }
        }
    }
}

static void check_events(game_t *game, sfRenderWindow *window, sfEvent evt)
{
    while (sfRenderWindow_pollEvent(window, &evt)) {
        switch (evt.type) {
        case sfEvtClosed:
            sfRenderWindow_close(window);
            break;
        case sfEvtKeyPressed:
            if (sfKeyboard_isKeyPressed(sfKeyEscape))
                pause_game(game, window);
            break;
        default:
            check_events2(game, window, evt);
            break;
        }
    }
}

void check_events2(game_t *game, sfRenderWindow *window, sfEvent evt)
{
        switch (evt.type) {
        case sfEvtMouseButtonPressed :
            if (sfMouse_isButtonPressed(sfMouseLeft)) {
                game->game_state = 3;
                handle_drag(game, evt);
            }
            break;
        case sfEvtMouseButtonReleased :
            if (game->other->is_dragged == 1) {
                display_dropped(game, window);
                game->other->is_dragged = 0;
            }
            break;
        default:
            break;
        }
}

void enter_game_loop(game_t *game, sfRenderWindow *window)
{
    sfEvent evt;
    play_da_music(game);

    while (sfRenderWindow_isOpen(window)) {
        if ((spawn_wave(game, window) == 84))
            return;
        check_events(game, window, evt);
        check_ennemy_status(game);
        check_money_towers(game);
        handle_end(game,window);
        display_all(game, window);
        if (game->game_state == 1)
            return;
    }
}
