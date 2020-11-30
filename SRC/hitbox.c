/*
** EPITECH PROJECT, 2020
** My_hunter
** File description:
** hitbox
*/

#include "../include/my.h"

st_hitboxs generate_all_hitbox(st_all_birds *birds)
{
    st_hitboxs hitboxs;
    hitboxs.hitbox_bird1 = sfSprite_getGlobalBounds(birds->bird1.sprite);
    hitboxs.hitbox_bird2 = sfSprite_getGlobalBounds(birds->bird2.sprite);
    hitboxs.hitbox_bird3 = sfSprite_getGlobalBounds(birds->bird3.sprite);
    hitboxs.hitbox_bird4 = sfSprite_getGlobalBounds(birds->bird4.sprite);
    hitboxs.hitbox_bird5 = sfSprite_getGlobalBounds(birds->bird5.sprite);
    hitboxs.hitbox_bird6 = sfSprite_getGlobalBounds(birds->bird6.sprite);
    return (hitboxs);
}

void hitbox_is_touched(st_info_sprite *bird, sfFloatRect hitbox,
sfEvent event, st_other_sprite *sprites)
{
    if (bird->deleted == 0 && bird->still == 0){
        if (sfFloatRect_contains(&hitbox, event.mouseButton.x,
        event.mouseButton.y) == 1){
            bird->death = 1;
            sprites->bird_shot += 1;
            }
    }
}

void hitbox_is_not_touched(sfFloatRect hitbox, sfEvent event,
int *ammo, st_info_sprite *bullets)
{
    if (sfFloatRect_contains(&hitbox, event.mouseButton.x,
    event.mouseButton.y) == 0) {
        *ammo -= 1;
        bullets->rect.left += 150;
    }
}

void event_hitbox(st_all_birds *birds, st_hitboxs hitboxs,
sfEvent event, st_other_sprite *sprites)
{
        hitbox_is_touched(&birds->bird1, hitboxs.hitbox_bird1, event, sprites);
        hitbox_is_touched(&birds->bird2, hitboxs.hitbox_bird2, event, sprites);
        hitbox_is_touched(&birds->bird3, hitboxs.hitbox_bird3, event, sprites);
        hitbox_is_touched(&birds->bird4, hitboxs.hitbox_bird4, event, sprites);
        hitbox_is_touched(&birds->bird5, hitboxs.hitbox_bird5, event, sprites);
        hitbox_is_touched(&birds->bird6, hitboxs.hitbox_bird6, event, sprites);
}
