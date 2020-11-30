/*
** EPITECH PROJECT, 2020
** CSFML header
** File description:
** this file cointains all file prototypes
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>

typedef struct st_sfstruct_s st_info_sprite;
typedef struct st_timer_s st_timer_t;
typedef struct clock_entity_s clock_entity;
typedef struct st_timer_entity_s st_timer_entity;
typedef struct st_all_birds_s st_all_birds;
typedef struct st_hitboxs_s st_hitboxs;
typedef struct st_victory_condition_s st_victory;

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
    st_info_sprite *bird1;
    st_info_sprite *bird2;
    st_info_sprite *bird3;
    st_info_sprite *bird4;
    st_info_sprite *bird5;
    st_info_sprite *bird6;
    int appear;
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
void analyse_events(sfRenderWindow *window, sfEvent event, st_all_birds *birds, int *ammo, st_info_sprite *bullets);
st_timer_t create_clock(sfClock *clock);
void ft_clock(sfRenderWindow *window, st_all_birds *birds, int *bird_out);
void display_on_screen(st_all_birds birds, st_info_sprite background, st_info_sprite grass, sfRenderWindow *window, st_info_sprite *bullets, int ammo, st_info_sprite gameover);
void destroy_on_screen(st_all_birds *birds, st_info_sprite *background, st_info_sprite *grass,sfRenderWindow **window, int ammo, st_info_sprite *bullets);
void if_bird_dead(st_info_sprite *bird, sfRenderWindow *window, float seconds_death, int *bird_out);
void change_rect(st_info_sprite *bird, int x, int max);
st_info_sprite create_pos(st_info_sprite bird, int xpos, int ypos, float xvelo, float yvelo);
int generate_random_nb(int lower, int upper);
st_info_sprite ft_create_entity(char *filename, int widths, int heights, int x, int y);
void initialize_clock(st_info_sprite *bird);
void generate_all_birds(st_all_birds *birds);
void generate_time(st_info_sprite *bird);
int analyse_events_menu(sfRenderWindow *window, sfEvent event, st_info_sprite *button, int *button_touched);
void menu(sfRenderWindow *window, st_info_sprite background);
int menu_clock(sfClock *clock, int *button);
void defeat_end_screen(st_all_birds *birds, st_info_sprite *bullets, st_info_sprite game_over, sfRenderWindow *window);
void destroy_bird(st_info_sprite *bird);
void change_pos_velo(st_info_sprite *bird);