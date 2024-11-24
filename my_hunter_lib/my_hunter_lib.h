/*
** EPITECH PROJECT, 2024
** B-MUL-100-TLS-1-1-myhunter-noah.gomes
** File description:
** my_hunter_lib
*/

#ifndef INCLUDED_MY_HUNTER_LIB_H
    #define INCLUDED_MY_HUNTER_LIB_H
    #include <SFML/Graphics.h>

typedef struct scene_params {
    sfRenderWindow *window;
    sfVideoMode video_mode;
    sfTime time;
    sfClock *clock;
    sfEvent event;
} scene_params_t;

typedef struct sprite_params {
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
} sprite_params_t;

#endif
