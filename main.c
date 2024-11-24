/*
** EPITECH PROJECT, 2024
** B-MUL-100-TLS-1-1-myhunter-noah.gomes
** File description:
** my_hunter
*/

#include "lib/include/my.h"
#include "my_hunter_lib/my_hunter_lib.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

void manage_mouse_click(sfMouseButtonEvent event)
{
    my_printf("Mouse x=%d y=%d\n", event.x, event.y);
}

void close_window(sfRenderWindow *window)
{
    sfRenderWindow_close(window);
}

void analyse_events(sfRenderWindow *window, sfEvent event)
{
    while (sfWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            close_window(window);
        if (event.type == sfEvtMouseButtonPressed)
            manage_mouse_click(event.mouseButton);
    }
}

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    rect->left += offset;
    if (rect->left == max_value)
        rect->left = 0;
}

void window_loop(scene_params_t *name, sprite_params_t *sp_name)
{
    float seconds;

    name->clock = sfClock_create();
    while (sfRenderWindow_isOpen(name->window)) {
        name->time = sfClock_getElapsedTime(name->clock);
        seconds = name->time.microseconds / 1000000.0;
        if (seconds > 0.1) {
            move_rect(&sp_name->rect, 110, 330);
            sfClock_restart(name->clock);
        }
        sfRenderWindow_clear(name->window, sfBlack);
        sfSprite_setTextureRect(sp_name->sprite, sp_name->rect);
        sfRenderWindow_drawSprite(name, sp_name->sprite, NULL);
        sfRenderWindow_display(name->window);
        analyse_events(name->window, name->event);
    }
    sfRenderWindow_destroy(name->window);
}

int test(void)
{
    sfRenderWindow *window;
    sfVideoMode video_mode;
    sfEvent event;
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    sfClock *clock;
    sfTime time;
    float seconds;

    clock = sfClock_create();
    rect.top = 0;
    rect.left = 0;
    rect.width = 110;
    rect.height = 110;
    texture = sfTexture_createFromFile("duck.png", NULL);
    sprite = sfSprite_create();
    video_mode.width = 800;
    video_mode.height = 600;
    video_mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(video_mode, "first window", sfDefaultStyle, NULL);
    sfSprite_setTexture(sprite, texture, sfTrue);
    while (sfRenderWindow_isOpen(window)) {
        time = sfClock_getElapsedTime(clock);
        seconds = time.microseconds / 1000000.0;
        if (seconds > 0.1) {
            move_rect(&rect, 110, 330);
            sfClock_restart(clock);
        }
        sfRenderWindow_clear(window, sfBlack);
        sfSprite_setTextureRect(sprite, rect);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_display(window);
        analyse_events(window, event);
    }
    sfRenderWindow_destroy(window);
    sfSprite_destroy(sprite);
    return 0;
}

int main(void)
{
    scene_params_t *main_scene = malloc(sizeof(scene_params_t));
    sprite_params_t *main_sprite = malloc(sizeof(sprite_params_t));

    main_sprite->rect.top = 0;
    main_sprite->rect.left = 0;
    main_sprite->rect.width = 110;
    main_sprite->rect.height = 110;
    main_sprite->texture = sfTexture_createFromFile("duck.png", NULL);
    main_sprite->sprite = sfSprite_create();
    main_scene->video_mode.width = 800;
    main_scene->video_mode.height = 600;
    main_scene->video_mode.bitsPerPixel = 32;
    main_scene->window = sfRenderWindow_create(main_scene->video_mode, "Main scene", sfClose, NULL);


    window_loop(main_scene, main_sprite);
}
