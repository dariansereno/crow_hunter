/*
** EPITECH PROJECT, 2020
** Crow_Hunter
** File description:
** create different things
*/

#include "../include/my.h"

st_info_sprite ft_create_entity(char *filename, int widths,
int heights, sfVector2f pos)
{
    st_info_sprite entity;

    sfIntRect rectangle = {.top = 0, .left = 0, .width = widths,
    .height = heights};
    entity.rect = rectangle;
    entity.sprite = sfSprite_create();
    entity.texture = sfTexture_createFromFile(filename, NULL);
    entity.random_nb = generate_random_nb(generate_random_nb(5, 15),
    generate_random_nb(15, 55));
    if (my_strcmp(filename, "IMG/spritesheet.png") == 0)
        entity = create_pos(entity, pos.x - 400, pos.y - 78, 0, 0);
    else
        entity = create_pos(entity, pos.x, pos.y, 0, 0);
    sfSprite_setTexture(entity.sprite, entity.texture, sfTrue);
    entity.appear = 1;
    entity.position_start_x = pos.x;

    return (entity);
}

st_info_sprite create_pos(st_info_sprite bird, int xpos,
int ypos, float xvelo, float yvelo)
{
    sfVector2f positionbird = {.x = xpos, .y = ypos};
    sfVector2f velocitybird = {.x = xvelo, .y = yvelo};

    bird.position = positionbird;
    bird.velocity = velocitybird;
    bird.deleted = 0;
    bird.death = 0;
    return (bird);
}

st_text text_creator(void)
{
    st_text text;
    sfFont *font = sfFont_createFromFile("IMG/premier.ttf");
    text.score = sfText_create();
    sfText_setFont(text.score, font);
    sfText_setCharacterSize(text.score, 100);
    sfText_setPosition(text.score, (sfVector2f){50, 960});
    text.credit = sfText_create();
    sfText_setFont(text.credit, font);
    sfText_setCharacterSize(text.credit, 50);
    sfText_setPosition(text.credit, (sfVector2f){20, 990});
    sfText_setString(text.credit, "Game by Darian, Design by Sinclair");
    return (text);
}

sfSound *set_buffer(char *filename)
{
    sfSound *sound = sfSound_create();
    sfSoundBuffer *buffer = sfSoundBuffer_createFromFile(filename);
    sfSound_setBuffer(sound, buffer);
    return (sound);
}

st_sounds generate_all_sounds(void)
{
    st_sounds sounds;
    sounds.shoot = set_buffer("son/tir.wav");
    sounds.shot = set_buffer("son/shot.wav");
    sounds.victory = set_buffer("son/victory.wav");
    sounds.game_over = set_buffer("son/gameover.wav");
    sounds.music = sfMusic_createFromFile("son/musique.wav");
    sounds.loop = set_buffer("son/boucle.wav");
    sounds.play = set_buffer("son/play.wav");
    sounds.music = sfMusic_createFromFile("son/musique.wav");
    return (sounds);
}