/*
** EPITECH PROJECT, 2024
** B-MUL-100-TLS-1-1-myhunter-noah.gomes
** File description:
** create_hud_player
*/

#include "../../lib/include/my.h"
#include "../my_hunter_lib.h"
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <time.h>

void create_first_heart(all_data_t *name)
{
    sfVector2f pos = {15.00, 0.00};

    name->hud->sprite_life1 = malloc(sizeof(sprite_params_t));
    name->hud->sprite_life1->rect.top = 0;
    name->hud->sprite_life1->rect.left = 0;
    name->hud->sprite_life1->rect.width = 65;
    name->hud->sprite_life1->rect.height = 80;
    name->hud->sprite_life1->sprite = sfSprite_create();
    sfSprite_setPosition(name->hud->sprite_life1->sprite, pos);
    sfSprite_setTexture(name->hud->sprite_life1->sprite,
        sfTexture_createFromFile(PATH_HEARTH, NULL), sfTrue);
}

void create_second_heart(all_data_t *name)
{
    sfVector2f pos = {90.00, 0.00};

    name->hud->sprite_life2 = malloc(sizeof(sprite_params_t));
    name->hud->sprite_life2->rect.top = 0;
    name->hud->sprite_life2->rect.left = 0;
    name->hud->sprite_life2->rect.width = 65;
    name->hud->sprite_life2->rect.height = 80;
    name->hud->sprite_life2->sprite = sfSprite_create();
    sfSprite_setPosition(name->hud->sprite_life2->sprite, pos);
    sfSprite_setTexture(name->hud->sprite_life2->sprite,
        sfTexture_createFromFile(PATH_HEARTH, NULL), sfTrue);
}

void create_third_heart(all_data_t *name)
{
    sfVector2f pos = {165.00, 0.00};

    name->hud->sprite_life3 = malloc(sizeof(sprite_params_t));
    name->hud->sprite_life3->rect.top = 0;
    name->hud->sprite_life3->rect.left = 0;
    name->hud->sprite_life3->rect.width = 65;
    name->hud->sprite_life3->rect.height = 80;
    name->hud->sprite_life3->sprite = sfSprite_create();
    sfSprite_setPosition(name->hud->sprite_life3->sprite, pos);
    sfSprite_setTexture(name->hud->sprite_life3->sprite,
        sfTexture_createFromFile(PATH_HEARTH, NULL), sfTrue);
}

void create_hud_player(all_data_t *name)
{
    name->hud = malloc(sizeof(hud_player_t));
    name->hud->life = 3;
    name->hud->score = 0;
    create_first_heart(name);
    create_second_heart(name);
    create_third_heart(name);
}
