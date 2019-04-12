/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** main file
*/

#include "my.h"

static void free_all(game_t *game, sfRenderWindow *window)
{
    (void) window;
    for (int i = 0; i != 3; i++)
        sfMusic_destroy(game->sounds->sounds[i]);
    return;
}

int main(int argc, char **argv, char **env)
{
    game_t *game = malloc(sizeof(game_t));
    sfRenderWindow *window;
    sfVideoMode video_mode = {1920, 970, 32};
    int r_value = 0;

    r_value = check_error(argc, argv, env);
    if (r_value == 84)
        return (84);
    if (r_value == 1)
        return (0);
    window = sfRenderWindow_create(video_mode, "My_defender", sfResize |
                                    sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 50000);
    if ((game = get_main_struct(game)) == NULL)
        return (84);
    menu(game, window);
    free_all(game, window);
    return (0);
}
