/*
** EPITECH PROJECT, 2020
** Crow Hunter
** File description:
** renderwindow
*/

#include "../include/my.h"

void display_sprite(st_info_sprite bird, sfRenderWindow *window)
{
    sfSprite_setPosition(bird.sprite, bird.position);
    sfRenderWindow_drawSprite(window, bird.sprite, NULL);
}

void display_birds_condition(st_all_birds birds, st_other_sprite sprites,
sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, sprites.background.sprite, NULL);
    if (birds.bird1.deleted != 1)
        display_sprite(birds.bird1, window);
    if (birds.bird2.deleted != 1)
        display_sprite(birds.bird2, window);
    if (birds.bird3.deleted != 1)
        display_sprite(birds.bird3, window);
    if (birds.bird4.deleted != 1)
        display_sprite(birds.bird4, window);
    if (birds.bird5.deleted != 1)
        display_sprite(birds.bird5, window);
    if (birds.bird6.deleted != 1)
        display_sprite(birds.bird6, window);
    sfRenderWindow_drawSprite(window, sprites.grass.sprite, NULL);
}

void display_on_screen(st_all_birds birds, st_other_sprite sprites,
sfRenderWindow *window, st_text text)
{
    char score[2];
    score[0] = sprites.bird_shot + '0';
    score[1] = '\0';
    display_birds_condition(birds, sprites, window);
    if (sprites.ammo >= 0)
        sfRenderWindow_drawSprite(window, sprites.bullets.sprite, NULL);
    if (sprites.ammo <= 0)
        sfRenderWindow_drawSprite(window, sprites.game_over.sprite, NULL);
    if (sprites.ammo > 0 && sprites.bird_out >= 6) {
        sfText_setPosition(text.score, (sfVector2f){920, 550});
        sfText_setCharacterSize(text.score, 250);
        sfRenderWindow_drawSprite(window, sprites.victory.sprite, NULL);
        }
    sfSprite_setPosition(sprites.fire.sprite, sprites.fire.position);
    sfRenderWindow_drawSprite(window, sprites.crosshair.sprite, NULL);
    sfRenderWindow_drawSprite(window, sprites.fire.sprite, NULL);
    sfText_setString(text.score, &score);
    sfRenderWindow_drawText(window, text.score, NULL);
    sfRenderWindow_display(window);
}

void destroy_on_screen2(st_all_birds *birds, st_other_sprite *sprites,
sfRenderWindow **window)
{
    destroy_on_screen3(window, sprites);
    if (birds->bird1.deleted == 0)
        destroy_bird(&birds->bird1);
    if (birds->bird2.deleted == 0)
        destroy_bird(&birds->bird2);
    if (birds->bird3.deleted == 0)
        destroy_bird(&birds->bird3);
    if (birds->bird4.deleted == 0)
        destroy_bird(&birds->bird4);
    if (birds->bird5.deleted == 0)
        destroy_bird(&birds->bird5);
    if (birds->bird6.deleted == 0)
        destroy_bird(&birds->bird6);
}

void destroy_on_screen(st_all_birds *birds, st_other_sprite *sprites,
sfRenderWindow **window, st_text *text, st_sounds *sounds)
{
    destroy_on_screen2(birds, sprites, window);
    if (sprites->ammo != 0)
    {
        sfTexture_destroy(sprites->bullets.texture);
        sfSprite_destroy(sprites->bullets.sprite);
    }
    sfText_destroy(text->credit);
    sfText_destroy(text->score);
    sfSound_destroy(sounds->game_over);
    sfSound_destroy(sounds->loop);
    sfMusic_destroy(sounds->music);
    sfSound_destroy(sounds->play);
    sfSound_destroy(sounds->shoot);
    sfSound_destroy(sounds->shot);
    sfSound_destroy(sounds->victory);
}

