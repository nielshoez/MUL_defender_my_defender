/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** setup structs
*/

#include "my.h"

void initialize_sounds(game_t *game)
{
    game->sounds->clocks = malloc(sizeof(sfClock *) * 1);
    game->sounds->sounds = malloc(sizeof(sfMusic *) * 3);
    game->sounds->time = malloc(sizeof(sfTime) * 1);
    game->sounds->sounds[0] =
        sfMusic_createFromFile("assets/sounds/hit_sound.ogg");
    game->sounds->sounds[1] =
        sfMusic_createFromFile("assets/sounds/death_sound.ogg");
    game->sounds->sounds[2] =
        sfMusic_createFromFile("assets/sounds/hardcorner.ogg");
    game->sounds->clocks[0] = sfClock_create();
    sfMusic_setVolume(game->sounds->sounds[0], 100);
    sfMusic_setVolume(game->sounds->sounds[1], 100);
}

static void setup_money(game_t *game)
{
    game->money->money = 100;
    game->money->money_char = my_itoa(game->money->money);
    game->money->money_text = sfText_create();
    sfText_setFont(game->money->money_text, game->other->font);
    sfText_setPosition(game->money->money_text, get_vector(40, 105));
    sfText_setScale(game->money->money_text, get_vector(1.15, 1.15));
    sfText_setString(game->money->money_text, game->money->money_char);
    sfText_setColor(game->money->money_text, sfBlack);
    game->attack->seconds = malloc(sizeof(float) * 1);
}

static int setup_text(game_t *game)
{
    game->other->char_texts = malloc(sizeof(char *) * 3);
    game->other->texts = malloc(sizeof(sfText *) * 1);
    game->other->char_texts[0] = malloc(sizeof(char) * my_strlen("Wave :"));
    game->other->font = sfFont_createFromFile("assets/font/font.ttf");
    game->other->texts[0] = sfText_create();
    game->other->char_texts[0] = "Wave :";
    sfText_setFont(game->other->texts[0], game->other->font);
    sfText_setColor(game->other->texts[0], sfWhite);
    sfText_setPosition(game->other->texts[0], get_vector(200, 770));
    sfText_setScale(game->other->texts[0], get_vector(2.5, 2.5));
    sfText_setRotation(game->other->texts[0], -45.0f);
    game->other->is_dragged = 0;
    fill_structs(game);
    initialize_menu(game);
    initialize_pause(game);
    initialize_towers(game);
    initialize_attack(game);
    initialize_sounds(game);
    initialize_end(game);
    return (0);
}

game_t *get_main_struct(game_t *game)
{
    if (game == NULL)
        return (NULL);
    game->map = malloc(sizeof(map_t));
    game->menu = malloc(sizeof(menu_t));
    game->other = malloc(sizeof(other_t));
    game->pause = malloc(sizeof(pause_t));
    game->ennemy = malloc(sizeof(ennemy_t));
    game->tower = malloc(sizeof(tower_t));
    game->attack = malloc(sizeof(attack_t));
    game->sounds = malloc(sizeof(sounds_t));
    game->money = malloc(sizeof(money_t));
    game->end = malloc(sizeof(end_t));
    game->game_state = 0;
    if (game->map == NULL || game->menu == NULL || game->other == NULL ||
        game->pause == NULL || game->ennemy == NULL || game->sounds == NULL
        || game->money == NULL || game->end == NULL)
        return (NULL);
    setup_text(game);
    setup_money(game);
    return (game);
}
