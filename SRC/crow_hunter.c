/*
** EPITECH PROJECT, 2020
** My_hunter
** File description:
** My_hunter
*/

#include "../include/my.h"

void change_rect(st_info_sprite *bird, int x, int max)
{
    bird->rect.left += x;
    if (bird->rect.left > max)
        bird->rect.left = 0;
}

void change_pos_velo(st_info_sprite *bird)
{
    bird->position.x += bird->velocity.x;
    bird->position.y += bird->velocity.y;
}

void print_sprite_loop(st_other_sprite sprites,
st_all_birds birds, sfVector2f cursor)
{
    sfSprite_setTextureRect(sprites.fire.sprite, sprites.fire.rect);
    sprite_set_texture(&birds, &sprites.bullets, sprites.ammo);
    sfSprite_setTexture(sprites.crosshair.sprite,
    sprites.crosshair.texture, sfTrue);
    sfSprite_setPosition(sprites.crosshair.sprite, cursor);
}

void display_game(sfRenderWindow *window, st_all_birds birds,
st_other_sprite sprites, st_sounds *sounds, st_text *text)
{
    sfVector2f cursor = set_cursor(&window);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    sprites.fire.clocks.clock_death = sfClock_create();
    sfSound_setLoop(sounds->loop, sfTrue);
    sfSound_play(sounds->loop);
    while (sfRenderWindow_isOpen(window)) {
            cursor = set_cursor(&window);
            sfEvent event;
            print_sprite_loop(sprites, birds, cursor);
            while (sfRenderWindow_pollEvent(window, &event))
                analyse_events(window, event, &birds, &sprites, *sounds);
            if (sprites.ammo > 0 && sprites.bird_out >= 6)
                victory_end_screen(&birds);
            if (sprites.ammo <= 0)
                defeat_end_screen(&birds);
            ft_clock(window, &birds, &sprites);
            display_on_screen(birds, sprites, window, *text);
        }
    destroy_on_screen(&birds, &sprites, &window, text, sounds);
}

int main(void)
{
    st_all_birds birds = generate_all_birds();
    st_text text = text_creator();
    st_other_sprite sprites = generate_other_sprites();
    sfVideoMode mode = {WIDTH, HEIGHT, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode,
    "Crow Hunter", sfTitlebar | sfClose, NULL);
    sfImage *icon = sfImage_createFromFile("IMG/icon.png");
    st_sounds sounds = generate_all_sounds();

    sfMusic_play(sounds.music);
    const sfUint8* iconptr = sfImage_getPixelsPtr(icon);
    sfRenderWindow_setIcon(window, 256, 256, iconptr);
    sprites.bird_shot = 0;
    srand(time(NULL));
    clock_initizalition_sprite(&birds);
    sfRenderWindow_setFramerateLimit(window, 60);
    menu(window, sprites, sounds, text);
    sfMusic_stop(sounds.music);
    display_game(window, birds, sprites, &sounds, &text);
    return (0);
}