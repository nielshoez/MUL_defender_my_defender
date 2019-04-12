/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** structures for my_defender
*/

#ifndef structs_h
#define structs_h

#include "my.h"
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Graphics/Color.h>
#include <SFML/System.h>
#include <SFML/Window/Mouse.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/System.h>
#include <SFML/System/Clock.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <time.h>

typedef struct map {
    sfClock **clocks;
    sfTime **time;
    float *seconds;
    sfTexture **textures;
    sfSprite **sprites;
    sfIntRect *rects;
    int castle_health;
} map_t;

typedef struct tower {
    sfTexture **textures;
    sfSprite **sprites;
    sfSprite **dropped;
    sfClock **clocks;
    sfTime *time;
    float seconds;
    int index;
    sfVector2f *pos_dropped;
    int *health;
    int *damage;
    sfIntRect *rects;
    int tile;
    int *type;
    int what;
} tower_t;

typedef struct ennemy {
    sfClock **clocks;
    sfClock **animations;
    sfTime *time;
    float *seconds;
    float *speed;
    sfTexture **textures;
    sfVector2f *poses;
    sfSprite **sprites;
    sfIntRect *rects;
    sfIntRect *ennemy_rect;
    int *health;
    int nb_ennemies;
    int wave_lenght;
    int wave_index;
} ennemy_t;

typedef struct attack {
    sfTexture **textures;
    sfClock **clocks;
    sfClock **shoot;
    sfClock **move;
    sfTime *time;
    float *seconds;
    sfSprite **sprites;
    sfIntRect *rects;
    int index;
    sfVector2f *pos;
    int *speed;
} attack_t;

typedef struct pause_screen {
    sfClock **clocks;
    sfTime **time;
    float *seconds;
    sfTexture **textures;
    sfSprite **sprites;
    sfIntRect *rects;
} pause_t;

typedef struct end_screen {
    sfClock **clocks;
    sfTime **time;
    float *seconds;
    sfTexture **textures;
    sfSprite **sprites;
    sfIntRect *rects;
} end_t;

typedef struct menu_screen {
    sfClock **clocks;
    sfTime **time;
    float *seconds;
    sfTexture **textures;
    sfSprite **sprites;
    sfIntRect *rects;
} menu_t;

typedef struct sounds {
    sfClock **clocks;
    sfTime *time;
    float seconds;
    sfMusic **sounds;
} sounds_t;

typedef struct other {
    sfFont *font;
    char **char_texts;
    sfText **texts;
    int wave_index;
    int is_dragged;
    int *is_place;
    sfClock *hit_ennemy;
    sfColor *base_color;
    sfTime time;
    float seconds;
    int index;
    int base_health;
} other_t;

typedef struct money {
    int money;
    char *money_char;
    sfText *money_text;
} money_t;

typedef struct game {
    map_t *map;
    menu_t *menu;
    other_t *other;
    pause_t *pause;
    ennemy_t *ennemy;
    tower_t *tower;
    attack_t *attack;
    sounds_t *sounds;
    int game_state;
    money_t *money;
    end_t *end;
} game_t;

#endif /* !structs_h */
