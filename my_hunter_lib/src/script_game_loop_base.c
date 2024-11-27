/*
** EPITECH PROJECT, 2024
** B-MUL-100-TLS-1-1-myhunter-noah.gomes
** File description:
** script_game_loop_base
*/

#include "../../lib/include/my.h"
#include "../my_hunter_lib.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

void do_must_task_in_loop(all_data_t *name_dt, positions_co_t *element_pos,
    sfVector2f *vector, float seconds)
{
    sfRenderWindow_clear(name_dt->window_name->window, sfBlack);
    anim_sprite(name_dt, seconds);
    draw_sprites(name_dt);
    analyse_events(name_dt->window_name, element_pos);
    check_duck_pos(name_dt);
    check_life(name_dt);
    sfSprite_move(name_dt->sprite_name->sprite, *vector);
}

void fill_mouse_pos(sfMouseButtonEvent event,
    positions_co_t *element_pos)
{
    element_pos->x = event.x;
    element_pos->y = event.y;
}

int check_is_in_the_rec(scene_params_t *scene, positions_co_t *element_pose,
    sfFloatRect *rect_bound_f)
{
    if (scene->event.type == sfEvtMouseButtonPressed) {
        if (sfFloatRect_contains(rect_bound_f,
            element_pose->x, element_pose->y) == sfTrue)
            return 0;
    }
    return 1;
}

int random_pos(int x_y)
{
    int x_min = 0;
    int x_max = 1000;
    int y_min = 0;
    int y_max = 600;
    int value = 0;

    if (x_y == 0) {
        value = rand() % (x_max - x_min + 1) + x_min;
        return value;
    }
    if (x_y == 1) {
        value = rand() % (y_max - y_min + 1) + y_min;
        return value;
    }
    return value;
}

void free_all(all_data_t *name)
{
    sfSprite_destroy(name->sprite_name->sprite);
    sfSprite_destroy(name->sprite_bg->sprite);
    sfClock_destroy(name->window_name->clock);
    sfRenderWindow_destroy(name->window_name->window);
}
