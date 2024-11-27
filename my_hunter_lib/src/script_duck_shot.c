/*
** EPITECH PROJECT, 2024
** B-MUL-100-TLS-1-1-myhunter-noah.gomes
** File description:
** script_duck_shot
*/

#include "../../lib/include/my.h"
#include "../my_hunter_lib.h"
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <time.h>

void actions_when_duck_is_shot(all_data_t *name, char *score_str,
    sfText *text)
{
    set_rand_pos(name);
    name->hud->score += 1;
    fill_score_char(name, score_str);
    sfText_setString(text, score_str);
}
