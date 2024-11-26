/*
** EPITECH PROJECT, 2024
** B-MUL-100-TLS-1-1-myhunter-noah.gomes
** File description:
** script_game_loop_base
*/

#include "../../lib/include/my.h"
#include "../my_hunter_lib.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

void do_must_task_in_loop(all_data_t *name_dt, positions_co_t *element_pos)
{
    sfRenderWindow_clear(name_dt->window_name->window, sfBlack);
    my_printf("DEBUTTTTTTTTTT\n");
    //draw_and_anime_sprite(name_dt);
    my_printf("FIIIIIIIIIINNNNNNNNNNN\n");
    sfSprite_setTextureRect(name_dt->sprite_name->sprite,
         name_dt->sprite_name->rect);
    sfRenderWindow_drawSprite(name_dt->window_name->window, name_dt->sprite_name->sprite, NULL);
    sfRenderWindow_display(name_dt->window_name->window);
    analyse_events(name_dt->window_name, element_pos);
}

void fill_mouse_pos(sfMouseButtonEvent event,
    positions_co_t *element_pos)
{
    element_pos->x = event.x;
    element_pos->y = event.y;
}

int check_is_in_the_rec(scene_params_t *scene, positions_co_t *element_pose,
    sfFloatRect *rect_bound_f)
{
    if (scene->event.type == sfEvtMouseButtonPressed) {
        if (sfFloatRect_contains(rect_bound_f,
            element_pose->x, element_pose->y) == sfTrue)
            return 0;
    }
    return 1;
}

void destroy_sprite_out_of_window(sprite_params_t *sp_name)
{
    sfVector2f out_of_screen = {1400.00, 1100.00};
    sfVector2f sprite_pos = sfSprite_getPosition(sp_name->sprite);

    if (sprite_pos.x > out_of_screen.x) {
        my_printf("delete");
        //sfSprite_destroy(sp_name->sprite);
    }
}
