/*
** EPITECH PROJECT, 2024
** B-MUL-100-TLS-1-1-myhunter-noah.gomes
** File description:
** my_hunter
*/

#include "lib/include/my.h"
#include "my_hunter_lib/my_hunter_lib.h"
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <math.h>

static void manage_mouse_click(sfMouseButtonEvent event)
{
    my_printf("Mouse x=%d y=%d\n", event.x, event.y);
}

static void close_window(sfRenderWindow *window)
{
    sfRenderWindow_close(window);
}

void analyse_events(scene_params_t *scene, positions_co_t *mouse_pos)
{
    while (sfRenderWindow_pollEvent(scene->window, &scene->event)) {
        fill_mouse_pos(scene->event.mouseButton, mouse_pos);
        if (scene->event.type == sfEvtClosed)
            close_window(scene->window);
        if (scene->event.type == sfEvtMouseButtonPressed)
            manage_mouse_click(scene->event.mouseButton);
    }
}

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    rect->left += offset;
    if (rect->left == max_value)
        rect->left = 0;
}

void window_loop(all_data_t *dt_name)
{
    float seconds;
    sfVector2f vector = {0.05, 0.0};
    sfVector2f out_of_screen_pos = {1300.00, 1000.00};
    sfFloatRect rect_bound_f = sfSprite_getGlobalBounds(dt_name->sprite_name->sprite);
    positions_co_t mouse_pos = {0};

    dt_name->window_name->clock = sfClock_create();
    while (sfRenderWindow_isOpen(dt_name->window_name->window)) {
        dt_name->window_name->time = sfClock_getElapsedTime(dt_name->window_name->clock);
        seconds = dt_name->window_name->time.microseconds / 1000000.0;
        if (seconds > 0.1) {
            move_rect(&dt_name->sprite_name->rect, 110, 330);
            sfClock_restart(dt_name->window_name->clock);
        }
        do_must_task_in_loop(dt_name, &mouse_pos);
        sfSprite_move(dt_name->sprite_name->sprite, vector);
        rect_bound_f = sfSprite_getGlobalBounds(dt_name->sprite_name->sprite);
        if (check_is_in_the_rec(dt_name->window_name, &mouse_pos, &rect_bound_f) == 0)
            sfSprite_setPosition(dt_name->sprite_name->sprite, out_of_screen_pos);
        destroy_sprite_out_of_window(dt_name->sprite_name);
    }
    sfRenderWindow_destroy(dt_name->window_name->window);
}

void create_scene_with_sprite(void)
{
    all_data_t *main_data = malloc(sizeof(all_data_t));
    main_data->sprite_name = malloc(sizeof(sprite_params_t));
    main_data->window_name = malloc(sizeof(scene_params_t));
    main_data->lkl_name = malloc(sizeof(linked_list_t));

    main_data->sprite_name->rect.top = 0;
    main_data->sprite_name->rect.left = 0;
    main_data->sprite_name->rect.width = 110;
    main_data->sprite_name->rect.height = 110;
    main_data->sprite_name->sprite = sfSprite_create();
    sfSprite_setTexture(main_data->sprite_name->sprite,
        sfTexture_createFromFile(PATH_DUCK, NULL), sfTrue);
    main_data->window_name->video_mode.width = 1280;
    main_data->window_name->video_mode.height = 720;
    main_data->window_name->video_mode.bitsPerPixel = 32;
    main_data->window_name->window = sfRenderWindow_create(main_data->window_name->video_mode,
        "Main scene", sfClose, NULL);
    create_and_add_in_list_sprite(3, main_data);
    window_loop(main_data);
}

int main(void)
{
    create_scene_with_sprite();
}
