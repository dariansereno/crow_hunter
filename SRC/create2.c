/*
** EPITECH PROJECT, 2020
** My_hunter
** File description:
** create 2
*/

#include "../include/my.h"

void sprite_set_texture(st_all_birds *birds, st_info_sprite *bullets, int ammo)
{
    if (birds->bird1.deleted != 1)
        sfSprite_setTextureRect(birds->bird1.sprite, birds->bird1.rect);
    if (birds->bird2.deleted != 1)
        sfSprite_setTextureRect(birds->bird2.sprite, birds->bird2.rect);
    if (birds->bird3.deleted != 1)
        sfSprite_setTextureRect(birds->bird3.sprite, birds->bird3.rect);
    if (birds->bird4.deleted != 1)
        sfSprite_setTextureRect(birds->bird4.sprite, birds->bird4.rect);
    if (birds->bird5.deleted != 1)
        sfSprite_setTextureRect(birds->bird5.sprite, birds->bird5.rect);
    if (birds->bird6.deleted != 1)
        sfSprite_setTextureRect(birds->bird6.sprite, birds->bird6.rect);
    if (ammo != 0)
        sfSprite_setTextureRect(bullets->sprite, bullets->rect);
    sfSprite_setPosition(bullets->sprite, bullets->position);
}

st_all_birds generate_all_birds(void)
{
    st_all_birds birds;
    birds.bird1 = ft_create_entity("IMG/spritesheet.png", 135, 110,
    (sfVector2f){190, 240});
    birds.bird2 = ft_create_entity("IMG/spritesheet.png", 135, 110,
    (sfVector2f){143, 485});
    birds.bird3 = ft_create_entity("IMG/spritesheet.png", 135, 110,
    (sfVector2f){253, 555});
    birds.bird4 = ft_create_entity("IMG/spritesheet.png", 135, 110,
    (sfVector2f){43, 678});
    birds.bird5 = ft_create_entity("IMG/spritesheet.png", 135, 110,
    (sfVector2f){50, 448});
    birds.bird6 = ft_create_entity("IMG/spritesheet.png", 135, 110,
    (sfVector2f){0, 148});
    return (birds);
}

st_other_sprite generate_other_sprites(void)
{
    st_other_sprite sprites;
    create_certain_entity(&sprites);
    sprites.game_over = ft_create_entity("IMG/gameover.png", -1, -1,
    (sfVector2f){-1, -1});
    sprites.victory = ft_create_entity("IMG/victory.png", -1, -1,
    (sfVector2f){-1, -1});
    sprites.crosshair = ft_create_entity("IMG/crosshair.png", -1, -1,
    (sfVector2f){-1, -1});
    sprites.menu_button = ft_create_entity("IMG/button_play.png",
    612, 210, (sfVector2f){650, 450});
    sprites.title = ft_create_entity("IMG/logo_menu.png",
    612, 210, (sfVector2f){0, 0});
    sprites.fire = ft_create_entity("IMG/fire.png", 60, 60,
    (sfVector2f){-100, -100});
    sprites.bird_out = 0;
    sprites.ammo = 3;
    return (sprites);
}

void clock_initizalition_sprite(st_all_birds *birds)
{
    initialize_clock(&birds->bird1);
    initialize_clock(&birds->bird2);
    initialize_clock(&birds->bird3);
    initialize_clock(&birds->bird4);
    initialize_clock(&birds->bird5);
    initialize_clock(&birds->bird6);
}

sfVector2f set_cursor(sfRenderWindow **window)
{
    sfVector2i cursor_coord;
    sfVector2f cursor;
    cursor_coord.x = 0;
    cursor_coord.y = 0;
    cursor_coord = sfMouse_getPosition(*window);
    cursor.x = cursor_coord.x;
    cursor.y = cursor_coord.y;
    return (cursor);
}