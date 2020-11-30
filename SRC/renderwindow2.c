/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** renderwindow 2
*/

#include "../include/my.h"

void destroy_bird(st_info_sprite *bird)
{
    sfTexture_destroy(bird->texture);
    sfSprite_destroy(bird->sprite);
    bird->deleted = 1;
}

void destroy_sprite(st_info_sprite *sprite)
{
    sfTexture_destroy(sprite->texture);
    sfSprite_destroy(sprite->sprite);
}

void close_window(sfRenderWindow *window)
{
    sfRenderWindow_close(window);
}

