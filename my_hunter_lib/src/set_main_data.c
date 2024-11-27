/*
** EPITECH PROJECT, 2024
** B-MUL-100-TLS-1-1-myhunter-noah.gomes
** File description:
** set_main_data
*/

#include "../../lib/include/my.h"
#include "../my_hunter_lib.h"
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <time.h>

void set_main_data(all_data_t *main_data)
{
    main_data->sprite_name = malloc(sizeof(sprite_params_t));
    main_data->window_name = malloc(sizeof(scene_params_t));
    main_data->sprite_name->rect.top = 0;
    main_data->sprite_name->rect.left = 0;
    main_data->sprite_name->rect.width = 110;
    main_data->sprite_name->rect.height = 110;
    main_data->sprite_name->sprite = sfSprite_create();
    set_rand_pos(main_data);
}
