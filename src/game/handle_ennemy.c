/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** handle ennemies
*/

#include "my.h"

static int malloc_failed(game_t *game)
{
    if (game->ennemy->clocks == NULL || game->ennemy->time == NULL ||
        game->ennemy->seconds == NULL || game->ennemy->sprites == NULL ||
        game->ennemy->health == NULL || game->ennemy->poses == NULL ||
        game->ennemy->speed == NULL)
        return (1);
    return (0);
}

static int realloc_new_wave(game_t *game, int nb_ennemies)
{
    game->ennemy->clocks = malloc(sizeof(sfClock *) * nb_ennemies);
    game->ennemy->animations = malloc(sizeof(sfClock *) * nb_ennemies);
    game->ennemy->time = malloc(sizeof(sfTime) * nb_ennemies);
    game->ennemy->seconds = malloc(sizeof(float *) * nb_ennemies);
    game->ennemy->sprites = malloc(sizeof(sfSprite *) * nb_ennemies);
    game->ennemy->health = malloc(sizeof(int *) * nb_ennemies);
    game->ennemy->poses = malloc(sizeof(sfVector2f) * nb_ennemies);
    game->ennemy->speed = malloc(sizeof(float) * nb_ennemies);
    game->ennemy->ennemy_rect = malloc(sizeof(sfIntRect) * nb_ennemies);
    game->other->base_color = malloc(sizeof(sfColor) * nb_ennemies);
    if (malloc_failed(game))
        return (84);
    realloc_time(game, nb_ennemies);
    realloc_entities(game, nb_ennemies);
    return (0);
}

static void update_wave_display(game_t *game)
{
    char *str = my_itoa(game->other->wave_index);

    game->other->char_texts[1] = my_strcat(game->other->char_texts[0], str);
    sfText_setString(game->other->texts[0], game->other->char_texts[1]);
}

static int spawn_new_wave(game_t *game)
{
    static int nb_ennemies = 1;
    static int wave_index = 1;

    game->other->wave_index = wave_index;
    update_wave_display(game);
    game->ennemy->nb_ennemies = nb_ennemies;
    game->ennemy->wave_lenght = nb_ennemies;
    game->ennemy->wave_index = wave_index;
    if (realloc_new_wave(game, nb_ennemies) == 84)
        return (84);
    nb_ennemies += 2;
    wave_index++;
    return (0);
}

int spawn_wave(game_t *game, sfRenderWindow *window)
{
    static int status = 0;
    int return_status = 0;
    (void) window;

    if (status == 0) {
        return_status = spawn_new_wave(game);
        status = 1;
    } else if (game->ennemy->nb_ennemies == 0)
        status = 0;
    return (return_status);
}
