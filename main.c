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
#include <math.h>
#include <time.h>

static void close_window(sfRenderWindow *window)
{
    sfRenderWindow_close(window);
}

void analyse_events(scene_params_t *scene, positions_co_t *mouse_pos)
{
    while (sfRenderWindow_pollEvent(scene->window, &scene->event)) {
        fill_mouse_pos(scene->event.mouseButton, mouse_pos);
        if (scene->event.type == sfEvtClosed)
            close_window(scene->window);
    }
}

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    rect->left += offset;
    if (rect->left >= max_value)
        rect->left = 0;
}

void window_loop(all_data_t *dt_name, sfText *text)
{
    sfFloatRect rect_bound_f =
        sfSprite_getGlobalBounds(dt_name->sprite_name->sprite);
    positions_co_t mouse_pos = {0};
    char score_str[] = "0   ";

    dt_name->window_name->clock = sfClock_create();
    while (sfRenderWindow_isOpen(dt_name->window_name->window)) {
        srand(time(NULL));
        do_must_task_in_loop(dt_name, &mouse_pos, score_str);
        rect_bound_f =
            sfSprite_getGlobalBounds(dt_name->sprite_name->sprite);
        if (check_is_in_the_rec(dt_name->window_name,
            &mouse_pos, &rect_bound_f) == 0)
            actions_when_duck_is_shot(dt_name, score_str, text);
        sfText_setString(text, score_str);
        sfRenderWindow_drawText(dt_name->window_name->window, text, NULL);
        sfRenderWindow_display(dt_name->window_name->window);
    }
    free_all(dt_name, text);
}

void create_scene_with_sprite(void)
{
    all_data_t *main_data = malloc(sizeof(all_data_t));
    sfText *text;
    sfFont *font;
    sfVector2f text_pos = {10.0, 660.00};

    font = sfFont_createFromFile("arial.ttf");
    text = sfText_create();
    sfText_setString(text, "0   ");
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 50);
    sfText_setPosition(text, text_pos);
    create_bg(main_data);
    create_hud_player(main_data);
    set_main_data(main_data);
    sfSprite_setTexture(main_data->sprite_name->sprite,
        sfTexture_createFromFile(PATH_DUCK, NULL), sfTrue);
    create_window(main_data);
    sfRenderWindow_setFramerateLimit(main_data->window_name->window, 60);
    window_loop(main_data, text);
}

int main(int argc, char **argv)
{
    if (argc == 1) {
        create_scene_with_sprite();
        return 0;
    }
    if (argc == 2 && my_strcpr("-h", argv[1]) == 0) {
        my_printf("This game is a aim game, the goal is : shot the duck");
        my_printf(" and get the best score has possible\n");
        my_printf("\nEntry :\n-h, print this message\n");
        my_printf("\nExit :\n0, all is good\n84, an error occured\n");
        return 0;
    }
    return 84;
}
