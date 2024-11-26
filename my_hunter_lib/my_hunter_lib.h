/*
** EPITECH PROJECT, 2024
** B-MUL-100-TLS-1-1-myhunter-noah.gomes
** File description:
** my_hunter_lib
*/

#include <SFML/Graphics.h>

#ifndef INCLUDED_MY_HUNTER_LIB_H
    #define INCLUDED_MY_HUNTER_LIB_H
    #define PATH_DUCK "duck.png"
    #define PATH_BG "background.png"

typedef struct scene_params {
    sfRenderWindow *window;
    sfVideoMode video_mode;
    sfTime time;
    sfClock *clock;
    sfEvent event;
} scene_params_t;

typedef struct sprite_params {
    sfSprite *sprite;
    sfIntRect rect;
} sprite_params_t;

typedef struct positions_co {
    float x;
    float y;
} positions_co_t;

typedef struct linked_list {
    sprite_params_t *data;
    struct linked_list *next;
} linked_list_t;

typedef struct all_data {
    scene_params_t *window_name;
    sprite_params_t *sprite_name;
    sprite_params_t *sprite_bg;
    linked_list_t *lkl_name;
} all_data_t;

void do_must_task_in_loop(all_data_t *name_dt, positions_co_t *element_pos);
void fill_mouse_pos(sfMouseButtonEvent event,
    positions_co_t *element_pos);
void analyse_events(scene_params_t *scene, positions_co_t *mouse_pos);
int check_is_in_the_rec(scene_params_t *scene, positions_co_t *element_pose,
    sfFloatRect *rect_bound_f);
void move_rect(sfIntRect *rect, int offset, int max_value);
int random_pos(int x_y);
void set_rand_pos(all_data_t *name);
void create_window(all_data_t *main_data);
void create_bg(all_data_t *name);
void anim_sprite(all_data_t *name, float seconds);

#endif
