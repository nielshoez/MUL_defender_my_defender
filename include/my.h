/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** main header
*/

#ifndef my_h
#define my_h

#include "structs.h"
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
#include <SFML/Window/Export.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Vector2.h>
    /* src */

        /* game */

sfVector2f new_random_pos(void);
void move_ennemies(game_t *game);
void check_money_towers(game_t *game);
int is_in_a_rect(game_t *, sfVector2f, int);
void handle_animation(game_t *game, int i);
int spawn_wave(game_t *game, sfRenderWindow *window);
void get_new_ennemie(game_t *game, int index);
void display_all(game_t *, sfRenderWindow *);
int random_rect(void);
int is_ennemi_line(game_t *game, sfSprite *sprite);
void init_towers_2(game_t *game);
void realloc_entities(game_t *game, int nb_ennemies);
void check_ennemy_status(game_t *game);
void realloc_time(game_t *game, int nb_ennemies);
void handle_hit(game_t *game, int index, int i);
void enter_game_loop(game_t *, sfRenderWindow *);
void handle_end(game_t *game, sfRenderWindow *window);
int manage_mouse_end(game_t *game, sfRenderWindow *wd);
void initialize_end(game_t *game);
void disp_end(game_t *game, sfRenderWindow *window);
void scale_end(game_t *game, sfRenderWindow *wd);
void end_events(game_t *game, sfRenderWindow *window, sfEvent evt);
void end(game_t *game, sfRenderWindow *window);
void check_events2(game_t *game, sfRenderWindow *window, sfEvent evt);

        /* structures */

game_t *get_main_struct(game_t *);
void fill_structs(game_t *);
sfVector2f get_vector(float, float);
sfIntRect get_rect(int, int, int, int);
void menu(game_t *game, sfRenderWindow *window);
void disp_menu(game_t *game, sfRenderWindow *window);
void initialize_menu(game_t *game);
void check_towers_health(game_t *game, int i);
int manage_mouse_click(game_t *game, sfRenderWindow *);
void disp_pause(game_t *game, sfRenderWindow *window);
void initialize_pause(game_t *game);
int pause_menu(game_t *game, sfRenderWindow *window);
int manage_mouse_pause(game_t *game, sfRenderWindow *wd);
int pause_events(game_t *game, sfRenderWindow *window, sfEvent evt);
void create_tower_rects(game_t *game);
void selection_bar(game_t *game, sfRenderWindow *window);
void display_select(game_t *game, sfRenderWindow *window);
void initialize_towers(game_t *game);
void scale_towers(game_t *game, sfRenderWindow *wd);
void scale_towers2(game_t *game, sfRenderWindow *wd);
void scale_towers3(game_t *game, sfRenderWindow *wd);
int drag_drop(game_t *game, sfSprite *sp, sfEvent evt, int index);
void handle_drag(game_t *game, sfEvent evt);
int tower_hitbox2(game_t *game, sfVector2i mouse_pos, sfEvent evt);
int tower_hitbox(game_t *game, sfVector2i mouse_pos, sfEvent evt);
void display_dropped(game_t *game, sfRenderWindow *window);
int drop_hitbox(game_t *game, sfSprite *sp);
void setup_towers(game_t *game, sfVector2f pos);
void display_towers(game_t *game, sfRenderWindow *window);
void initialize_attack(game_t *game);
void shoot_anime(game_t *game, sfRenderWindow *);
void move_proj(game_t *game);
void setup_shoot(game_t *game, int shoot);
int is_ennemi_touch(game_t *game, sfVector2f pos, int index);
void shoot_anime2(game_t *game, sfRenderWindow *wd, int j);

/* lib */

int my_putstr_octal(char const *str);
void my_binary_convertor(unsigned int nb);
int my_printf(const char *str, ...);
void get_addr_ptr(char *str);
char *my_revstr(char *str);
void my_put_nbr(int nb);
char *my_memset(char *res, char c, int size);
int my_strlen(char const *str);
int my_getnbr(char *const str);
char *my_itoa(int number);
char *my_replace(char *str, char target, char replace);
char *my_strcat(char *dest, char const *src);
char *get_next_line(int fd);
void my_octal_convertor(unsigned int nb);
void my_hex_convertor(unsigned int nb);
void my_hex_convertor_min(unsigned int nb);
void get_addr_ptr(char *str);
int check_null_ptr(char *str);
void my_putchar(char c);
int my_putstr(char const *str);
int check_error(int ac, char **av, char **env);
int my_putstr_err(char const *str);
#endif /* !my.h */
