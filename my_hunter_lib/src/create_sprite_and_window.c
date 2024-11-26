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

sprite_params_t *create_sprite(sprite_params_t *name)
{
    sprite_params_t *next_sprite = malloc(sizeof(sprite_params_t));
    sfVector2f pos = {random_pos(0), random_pos(1)};

    next_sprite->rect.top = 0;
    next_sprite->rect.left = 0;
    next_sprite->rect.width = 110;
    next_sprite->rect.height = 110;
    next_sprite->sprite = sfSprite_copy(name->sprite);
    sfSprite_setPosition(next_sprite->sprite, pos);
    return next_sprite;
}

void create_sprite_list(linked_list_t **head, all_data_t *sprite)
{
    sprite->lkl_name->data = sprite->sprite_name;
    sprite->lkl_name->next = *head;
    *head = sprite->lkl_name;
}

void create_and_add_in_list_sprite(int nb_sprite, all_data_t *name)
{
    linked_list_t *head = NULL;
    for (int i = 0; i != nb_sprite; i++) {
        create_sprite_list(&head, name);
    }
}

void draw_and_anime_sprite(all_data_t *name)
{
    sprite_params_t *data = NULL;

    while (name->lkl_name != NULL) {
        my_printf("dedans\n");
        data = name->lkl_name->data;
        sfSprite_setTextureRect(data->sprite, data->rect);
        sfRenderWindow_drawSprite(name->window_name->window, data->sprite, NULL);
        name->lkl_name = name->lkl_name->next;
    }
}
