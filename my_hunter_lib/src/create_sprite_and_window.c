/*
** EPITECH PROJECT, 2024
** B-MUL-100-TLS-1-1-myhunter-noah.gomes
** File description:
** create_sprite_and_window
*/

#include "../../lib/include/my.h"
#include "../my_hunter_lib.h"
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <time.h>

void set_rand_pos(all_data_t *name)
{
    sfVector2f pos = {random_pos(0), random_pos(1)};

    sfSprite_setPosition(name->sprite_name->sprite, pos);
}

void create_bg(all_data_t *name)
{
    name->sprite_bg = malloc(sizeof(sprite_params_t));
    name->sprite_bg->rect.top = 0;
    name->sprite_bg->rect.left = 0;
    name->sprite_bg->rect.width = 1280;
    name->sprite_bg->rect.height = 720;
    name->sprite_bg->sprite = sfSprite_create();
    sfSprite_setTexture(name->sprite_bg->sprite,
        sfTexture_createFromFile(PATH_BG, NULL), sfTrue);
}

void create_window(all_data_t *main_data)
{
    main_data->window_name->video_mode.width = 1280;
    main_data->window_name->video_mode.height = 720;
    main_data->window_name->video_mode.bitsPerPixel = 32;
    main_data->window_name->window =
        sfRenderWindow_create(main_data->window_name->video_mode,
        "My Hunter", sfClose, NULL);
}

void anim_sprite_one_by_one(sprite_params_t *name, float seconds,
    all_data_t *name_dt)
{
    if (seconds > 0.1) {
        move_rect(&name->rect, 110, 330);
        sfClock_restart(name_dt->window_name->clock);
    }
}

void anim_sprite(all_data_t *name, float seconds)
{
    name->window_name->time = sfClock_getElapsedTime(name->window_name->clock);
    seconds = name->window_name->time.microseconds / 1000000.0;
    anim_sprite_one_by_one(name->sprite_name, seconds, name);
}
