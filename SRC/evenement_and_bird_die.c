/*
** EPITECH PROJECT, 2020
** My_hunter
** File description:
** analyse event and if bird is die
*/

#include "../include/my.h"

void touch_a_bird(sfEvent event, st_other_sprite *sprites, st_sounds sounds,
st_hitboxs hitboxs)
{
    if (event.type == sfEvtMouseButtonPressed && event.mouseButton.button
    == sfMouseLeft){
        if (sfFloatRect_contains(&hitboxs.hitbox_bird1, event.mouseButton.x,
        event.mouseButton.y) == 0 && sfFloatRect_contains(&hitboxs.hitbox_bird2,
        event.mouseButton.x, event.mouseButton.y) == 0 &&
        sfFloatRect_contains(&hitboxs.hitbox_bird3, event.mouseButton.x,
        event.mouseButton.y) == 0 && sfFloatRect_contains(&hitboxs.hitbox_bird4,
        event.mouseButton.x, event.mouseButton.y) == 0 &&
        sfFloatRect_contains(&hitboxs.hitbox_bird5, event.mouseButton.x,
        event.mouseButton.y) == 0 && sfFloatRect_contains(&hitboxs.hitbox_bird6,
        event.mouseButton.x, event.mouseButton.y) == 0 &&
        sprites->ammo != 0 && sprites->bird_out != 6) {
            sprites->ammo -= 1;
            sprites->bullets.rect.left += 150;
            sfSound_play(sounds.shot);
        }
        else
            sfSound_play(sounds.shoot);
    }
}

void analyse_events(sfRenderWindow *window, sfEvent event,
st_all_birds *birds, st_other_sprite *sprites, st_sounds sounds)
{
    st_hitboxs hitboxs = generate_all_hitbox(birds);

    if (event.type == sfEvtClosed)
        close_window(window);
    else if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
        sfRenderWindow_close(window);
    if (event.type == sfEvtMouseButtonPressed && event.mouseButton.button
    == sfMouseLeft) {
        event_hitbox(birds, hitboxs, event, sprites);
    }
    touch_a_bird(event, sprites, sounds, hitboxs);
    if (sprites->ammo > 0 && sprites->bird_out == 6){
        sfSound_play(sounds.victory);
        sprites->bird_out += 1;
        }
    if (sprites->ammo == 0){
        sfSound_play(sounds.game_over);
        sprites->ammo -= 1;
        }
}

void bird_is_out(st_info_sprite *bird, int *bird_out)
{
    bird->deleted = 1;
    sfSprite_destroy(bird->sprite);
    sfTexture_destroy(bird->texture);
    sfClock_destroy(bird->clocks.clock_death);
    sfClock_destroy(bird->clocks.clock_still);
    sfClock_destroy(bird->clocks.clock_fly);
    *bird_out += 1;
}

void if_bird_dead(st_info_sprite *bird, sfRenderWindow *window,
float seconds_death, int *bird_out)
{
    sfTexture_destroy(bird->texture);
    bird->texture = sfTexture_createFromFile("IMG/crow_shot1.png", NULL);
    sfSprite_setTexture(bird->sprite, bird->texture, sfTrue);
    sfRenderWindow_drawSprite(window, bird->sprite, NULL);
    bird->velocity.x = 24;
    bird->velocity.y = 8;
    if (seconds_death > 0.2){
        bird->velocity.x = 12;
        bird->velocity.y = 12;
        if (seconds_death > 0.5)
        {
            bird->velocity.x = 8;
            bird->velocity.y = 24;
        }
        if (bird->position.y > HEIGHT || bird->position.x > WIDTH)
            bird_is_out(bird, bird_out);
        return ;
    }
}