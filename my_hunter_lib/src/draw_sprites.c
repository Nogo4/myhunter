/*
** EPITECH PROJECT, 2024
** B-MUL-100-TLS-1-1-myhunter-noah.gomes
** File description:
** draw_sprites
*/

#include "../../lib/include/my.h"
#include "../my_hunter_lib.h"
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <time.h>

void draw_life_sprite(all_data_t *name_dt)
{
    sfSprite_setTextureRect(name_dt->hud->sprite_life1->sprite,
        name_dt->hud->sprite_life1->rect);
    sfRenderWindow_drawSprite(name_dt->window_name->window,
        name_dt->hud->sprite_life1->sprite, NULL);
    sfSprite_setTextureRect(name_dt->hud->sprite_life1->sprite,
        name_dt->hud->sprite_life2->rect);
    sfRenderWindow_drawSprite(name_dt->window_name->window,
        name_dt->hud->sprite_life2->sprite, NULL);
    sfSprite_setTextureRect(name_dt->hud->sprite_life1->sprite,
        name_dt->hud->sprite_life3->rect);
    sfRenderWindow_drawSprite(name_dt->window_name->window,
        name_dt->hud->sprite_life3->sprite, NULL);
}

void draw_sprites(all_data_t *name_dt)
{
    sfSprite_setTextureRect(name_dt->sprite_name->sprite,
        name_dt->sprite_name->rect);
    sfRenderWindow_drawSprite(name_dt->window_name->window,
        name_dt->sprite_bg->sprite, NULL);
    sfSprite_setTextureRect(name_dt->sprite_name->sprite,
        name_dt->sprite_name->rect);
    sfRenderWindow_drawSprite(name_dt->window_name->window,
        name_dt->sprite_name->sprite, NULL);
    draw_life_sprite(name_dt);
}
