/*
** EPITECH PROJECT, 2020
** MY_HUNTER
** File description:
** menu of the game
*/

#include "../include/my.h"

int hitbox_menu(sfFloatRect hitbox, sfEvent event)
{
    if (sfFloatRect_contains(&hitbox, event.mouseButton.x, event.mouseButton.y)
    == 1) {
        return (1);
    }
    else
        return (0);
}

int analyse_events_menu(sfRenderWindow *window, sfEvent event,
st_info_sprite *button, st_sounds sounds)
{
    sfFloatRect hitbox_button_menu = sfSprite_getGlobalBounds(button->sprite);

    if (event.type == sfEvtMouseButtonPressed && event.mouseButton.button
    == sfMouseLeft)
        if (hitbox_menu(hitbox_button_menu, event) == 1) {
            sfSound_play(sounds.play);
            button->rect.left = 612;
                return (1);
        }
    if (event.type == sfEvtClosed)
        close_window(window);
    else if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
        sfRenderWindow_close(window);
    return (0);
}

void victory_end_screen(st_all_birds *birds)
{
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

void defeat_end_screen(st_all_birds *birds)
{
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

void menu(sfRenderWindow *window, st_other_sprite sprites,
st_sounds sounds, st_text text)
{
    sfClock *clock = sfClock_create();
    sfEvent event;
    int button = 0;

    while (sfRenderWindow_isOpen(window))
    {
        display_for_menu(window, sprites, text);
        while (sfRenderWindow_pollEvent(window, &event)){
            if (analyse_events_menu(window, event,
            &sprites.menu_button, sounds) == 1)
                button = 1;
        }
        if (menu_clock(clock, &button) == 1)
            return ;
        sfRenderWindow_display(window);
    }
}