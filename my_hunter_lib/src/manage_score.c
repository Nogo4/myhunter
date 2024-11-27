/*
** EPITECH PROJECT, 2024
** B-MUL-100-TLS-1-1-myhunter-noah.gomes
** File description:
** manage_score
*/

#include "../../lib/include/my.h"
#include "../my_hunter_lib.h"
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <time.h>

int count_power_score(int power)
{
    int exp = 1;

    while (power > 10) {
        power /= 10;
        exp++;
    }
    return exp;
}

void fill_score_char(all_data_t *name, char *str)
{
    int score = name->hud->score;
    int power = 10;
    int i = 1;
    int rest = 0;
    int index_str = 0;

    while (power <= score) {
        power *= 10;
        i++;
    }
    power /= 10;
    while (i != 0) {
        rest = score % power;
        score /= power;
        str[index_str] = score + 48;
        score = rest;
        power /= 10;
        i--;
        index_str++;
    }
}
