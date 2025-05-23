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

static void set_score_string_at_zero(char *str)
{
    str[0] = '0';
    str[1] = ' ';
    str[2] = ' ';
    str[3] = ' ';
}

void do_must_task_in_loop(all_data_t *name_dt,
    positions_co_t *element_pos, char *score_str)
{
    sfVector2f vector = {4.00, 0.0};
    float seconds = 0;

    sfRenderWindow_clear(name_dt->window_name->window, sfBlack);
    if (name_dt->hud->score == 0)
        set_score_string_at_zero(score_str);
    anim_sprite(name_dt, seconds);
    draw_sprites(name_dt);
    analyse_events(name_dt->window_name, element_pos);
    check_duck_pos(name_dt);
    check_life(name_dt);
    sfSprite_move(name_dt->sprite_name->sprite, vector);
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

static void destroy_sprite(all_data_t *name)
{
    sfSprite_destroy(name->hud->sprite_life1->sprite);
    sfSprite_destroy(name->hud->sprite_life2->sprite);
    sfSprite_destroy(name->hud->sprite_life3->sprite);
    sfSprite_destroy(name->sprite_name->sprite);
    sfSprite_destroy(name->sprite_bg->sprite);
}

static void destroy_texture(all_data_t *name)
{
    sfTexture_destroy((sfTexture *)
        sfSprite_getTexture(name->sprite_bg->sprite));
    sfTexture_destroy((sfTexture *)
        sfSprite_getTexture(name->sprite_name->sprite));
    sfTexture_destroy((sfTexture *)
        sfSprite_getTexture(name->hud->sprite_life1->sprite));
    sfTexture_destroy((sfTexture *)
        sfSprite_getTexture(name->hud->sprite_life2->sprite));
    sfTexture_destroy((sfTexture *)
        sfSprite_getTexture(name->hud->sprite_life3->sprite));
}

void free_all(all_data_t *name, sfText *text)
{
    destroy_texture(name);
    destroy_sprite(name);
    sfFont_destroy((sfFont *)sfText_getFont(text));
    sfText_destroy(text);
    sfClock_destroy(name->window_name->clock);
    sfRenderWindow_destroy(name->window_name->window);
    free(name->hud->sprite_life1);
    free(name->hud->sprite_life2);
    free(name->hud->sprite_life3);
    free(name->hud);
    free(name->sprite_bg);
    free(name->sprite_name);
    free(name->window_name);
    free(name);
}
