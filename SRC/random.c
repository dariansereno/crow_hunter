/*
** EPITECH PROJECT, 2020
** crow_hunter
** File description:
** generate random number
*/

#include "../include/my.h"

int generate_random_nb(int lower, int upper)
{
    int nb = (rand() % (upper - lower + 1)) + lower;
    return (nb);
}

void display_for_menu(sfRenderWindow *window,
st_other_sprite sprites, st_text text)
{
    sfRenderWindow_drawSprite(window, sprites.background.sprite, NULL);
    sfRenderWindow_drawSprite(window, sprites.title.sprite, NULL);
    sfSprite_setTextureRect(sprites.menu_button.sprite,
    sprites.menu_button.rect);
    sfSprite_setPosition(sprites.menu_button.sprite,
    sprites.menu_button.position);
    sfRenderWindow_drawSprite(window, sprites.menu_button.sprite, NULL);
    sfRenderWindow_drawText(window, text.credit, NULL);
}

void destroy_on_screen3(sfRenderWindow **window, st_other_sprite *sprites)
{
    sfRenderWindow_destroy(*window);
    destroy_sprite(&sprites->background);
    destroy_sprite(&sprites->grass);
    destroy_sprite(&sprites->crosshair);
    destroy_sprite(&sprites->fire);
    destroy_sprite(&sprites->game_over);
    destroy_sprite(&sprites->menu_button);
    destroy_sprite(&sprites->title);
    destroy_sprite(&sprites->victory);
}

void display_fire(st_other_sprite *sprites, sfEvent event)
{
    sprites->shot = 1;
    sprites->fire.position.x = event.mouseButton.x;
    sprites->fire.position.y = event.mouseButton.y;
}

void create_certain_entity(st_other_sprite *sprites)
{
    sprites->background = ft_create_entity("IMG/background_entier.png",
    -1, -1, (sfVector2f){0, 0});
    sprites->grass = ft_create_entity("IMG/herbe1.png", -1, -1,
    (sfVector2f){50, 50});
    sprites->bullets = ft_create_entity("IMG/bullets.png", 150, 83,
    (sfVector2f){1920 - 150, 1080 - 83});
}
