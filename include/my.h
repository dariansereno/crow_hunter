/*
** EPITECH PROJECT, 2020
** CSFML header
** File description:
** this file cointains all file prototypes
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <stdlib.h> 
#include <time.h>
#include <stdio.h>

typedef struct st_sfstruct_s st_info_sprite;
typedef struct st_timer_s st_timer_t;
typedef struct clock_entity_s clock_entity;
typedef struct st_timer_entity_s st_timer_entity;
typedef struct st_all_birds_s st_all_birds;
typedef struct st_hitboxs_s st_hitboxs;
typedef struct st_victory_condition_s st_victory;
typedef struct test_bird test_bird;
typedef struct st_other_sprites_s st_other_sprite;
typedef struct sounds_s st_sounds;
typedef struct text_s st_text;

struct text_s
{
    sfText *score;
    sfText *credit;
};

struct sounds_s
{
    sfSound *shot;
    sfSound *shoot;
    sfSound *victory;
    sfSound *game_over;
    sfSound *loop;
    sfSound *play;
    sfMusic *music;
};

struct clock_entity_s
{
    sfClock *clock_fly;
    sfClock *clock_death;
    sfClock *clock_still;
    sfClock *clock_appear;
};

struct st_timer_s
{
    sfTime time;
    sfClock *clock;
    float seconds;
};

struct st_timer_entity_s
{
    st_timer_t fly;
    st_timer_t still;
    st_timer_t death;
    st_timer_t appear;
};

struct st_sfstruct_s
{
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    sfVector2f position;
    sfVector2f velocity;
    clock_entity clocks;
    st_timer_entity time;
    int death;
    int deleted;
    int still;
    int random_nb;
    int appear;
    int position_start_x;
};

struct st_hitboxs_s
{
    sfFloatRect hitbox_bird1;
    sfFloatRect hitbox_bird2;
    sfFloatRect hitbox_bird3;
    sfFloatRect hitbox_bird4;
    sfFloatRect hitbox_bird5;
    sfFloatRect hitbox_bird6;
};

struct st_all_birds_s
{
    st_info_sprite bird1;
    st_info_sprite bird2;
    st_info_sprite bird3;
    st_info_sprite bird4;
    st_info_sprite bird5;
    st_info_sprite bird6;
};

struct st_other_sprites_s
{
    st_info_sprite background;
    st_info_sprite grass;
    st_info_sprite bullets;
    st_info_sprite game_over;
    st_info_sprite victory;
    st_info_sprite crosshair;
    st_info_sprite title;
    st_info_sprite menu_button;
    st_info_sprite fire;
    st_info_sprite icon;
    int bird_out;
    int ammo;
    int shot;
    int bird_shot;
};

struct st_victory_condition_s
{
    int *birds_out;
    int *ammo;
    st_info_sprite *bullets;
};


#define WIDTH 1920
#define HEIGHT 1080

int my_strcmp(char const *s1, char const *s2);
void close_window(sfRenderWindow *window);
void analyse_events(sfRenderWindow *window, sfEvent event, st_all_birds *birds,
st_other_sprite *sprites, st_sounds sounds);
st_timer_t create_clock(sfClock *clock);
void ft_clock(sfRenderWindow *window, st_all_birds *birds,
st_other_sprite *sprites);
void display_on_screen(st_all_birds birds, st_other_sprite sprites,
sfRenderWindow *window, st_text text);
void destroy_on_screen(st_all_birds *birds, st_other_sprite *sprites,
sfRenderWindow **window, st_text *text, st_sounds *sounds);
void if_bird_dead(st_info_sprite *bird, sfRenderWindow *window,
float seconds_death, int *bird_out);
void change_rect(st_info_sprite *bird, int x, int max);
st_info_sprite create_pos(st_info_sprite bird, int xpos, int ypos,
float xvelo, float yvelo);
int generate_random_nb(int lower, int upper);
st_info_sprite ft_create_entity(char *filename, int widths,
int heights, sfVector2f pos);
void initialize_clock(st_info_sprite *bird);
st_all_birds generate_all_birds(void);
void generate_time(st_info_sprite *bird);
void menu(sfRenderWindow *window, st_other_sprite sprites,
st_sounds sounds, st_text text);
int menu_clock(sfClock *clock, int *button);
void defeat_end_screen(st_all_birds *birds);
void victory_end_screen(st_all_birds *birds);
void destroy_bird(st_info_sprite *bird);
void change_pos_velo(st_info_sprite *bird);
void display_bird(st_info_sprite bird, sfRenderWindow *window);
sfVector2f set_cursor(sfRenderWindow **window);
void handling_bird(st_info_sprite *bird);
void handling_bird2(st_info_sprite *bird);
void handling_time_bird(st_all_birds *birds, sfRenderWindow *window,
st_other_sprite *sprites);
void bird_clock_handling(st_info_sprite *bird, sfRenderWindow *window,
int *bird_out);
st_hitboxs generate_all_hitbox(st_all_birds *birds);
void hitbox_is_touched(st_info_sprite *bird, sfFloatRect hitbox, sfEvent event,
st_other_sprite *sprites);
void hitbox_is_not_touched(sfFloatRect hitbox, sfEvent event, int *ammo,
st_info_sprite *bullets);
void event_hitbox(st_all_birds *birds, st_hitboxs hitboxs, sfEvent event,
st_other_sprite *sprites);
st_text text_creator(void);
st_sounds generate_all_sounds(void);
void sprite_set_texture(st_all_birds *birds, st_info_sprite *bullets, int ammo);
st_other_sprite generate_other_sprites(void);
void clock_initizalition_sprite(st_all_birds *birds);
void bird_is_out(st_info_sprite *bird, int *bird_out);
void destroy_sprite(st_info_sprite *sprite);
void display_for_menu(sfRenderWindow *window,
st_other_sprite sprites, st_text text);
void destroy_on_screen3(sfRenderWindow **window, st_other_sprite *sprites);
void display_fire(st_other_sprite *sprites, sfEvent event);
void create_certain_entity(st_other_sprite *sprites);