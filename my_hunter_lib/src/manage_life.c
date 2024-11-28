/*
** EPITECH PROJECT, 2024
** B-MUL-100-TLS-1-1-myhunter-noah.gomes
** File description:
** manage_life
*/

#include "../../lib/include/my.h"
#include "../my_hunter_lib.h"
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <time.h>

void set_pos_life_sprite(all_data_t *name)
{
    sfVector2f pos1 = {15.00, 0.00};
    sfVector2f pos2 = {90.00, 0.00};
    sfVector2f pos3 = {165.00, 0.00};

    sfSprite_setPosition(name->hud->sprite_life1->sprite, pos1);
    sfSprite_setPosition(name->hud->sprite_life2->sprite, pos2);
    sfSprite_setPosition(name->hud->sprite_life3->sprite, pos3);
}

void check_life(all_data_t *name)
{
    sfVector2f pos_out_of_window = {1300.00, 1100.00};

    if (name->hud->life == 3)
        set_pos_life_sprite(name);
    if (name->hud->life == 2)
        sfSprite_setPosition(name->hud->sprite_life3->sprite,
            pos_out_of_window);
    if (name->hud->life == 1)
        sfSprite_setPosition(name->hud->sprite_life2->sprite,
            pos_out_of_window);
    if (name->hud->life == 0)
        sfSprite_setPosition(name->hud->sprite_life1->sprite,
            pos_out_of_window);
    if (name->hud->life == -1) {
        name->hud->score = 0;
        name->hud->life = 3;
    }
}
