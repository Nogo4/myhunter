/*
** EPITECH PROJECT, 2024
** B-MUL-100-TLS-1-1-myhunter-noah.gomes
** File description:
** check_duck_pos
*/

#include "../../lib/include/my.h"
#include "../my_hunter_lib.h"
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <time.h>

void check_duck_pos(all_data_t *name)
{
    sfVector2f pos_out_of_window = {1300.00, 810.00};
    sfVector2f pos_duck = sfSprite_getPosition(name->sprite_name->sprite);

    if (pos_duck.x > pos_out_of_window.x) {
        name->hud->life -= 1;
        set_rand_pos(name);
    }
}
