/*
** EPITECH PROJECT, 2020
** My_hunter
** File description:
** clock
*/

#include "../include/my.h"

int menu_clock(sfClock *clock, int *button)
{
    st_timer_t timer = create_clock(clock);

    if (*button == 0)
        sfClock_restart(clock);
    if (timer.seconds > 0.4)
        return (1);
}

void handling_bird(st_info_sprite *bird)
{
    if (bird->time.fly.seconds > 0.01)
        change_pos_velo(bird);
    if (bird->time.fly.seconds > 0.12 && bird->appear == 1) {
        change_rect(bird, 135, 405);
        sfClock_restart(bird->clocks.clock_fly);
    }
    if (bird->appear == 1 && bird->position.x < bird->position_start_x) {
        bird->velocity.x = 5;
        bird->velocity.y = 1;
    }
    if (bird->appear == 1 && bird->position.x >= bird->position_start_x) {
        bird->velocity.x = 0;
        bird->velocity.y = 0;
        bird->appear = 0;
        bird->rect.left = 540;
    }
    if (bird->time.fly.seconds > 0.15 && bird->still == 0) {
        change_rect(bird, 135, 405);
        sfClock_restart(bird->clocks.clock_fly);
    }
}

void handling_bird2(st_info_sprite *bird)
{
    if (bird->appear == 1){
        sfClock_restart(bird->clocks.clock_still);}
    if (bird->still == 1 && bird->appear == 0)
        sfClock_restart(bird->clocks.clock_fly);
    if (bird->death != 1)
        sfClock_restart(bird->clocks.clock_death);
    if (bird->time.still.seconds > bird->random_nb && bird->still == 1) {
        bird->still = 0;
        bird->velocity.x = generate_random_nb(15, 30);
        bird->velocity.y = generate_random_nb(-1, 8);
        bird->rect.left = 0;
    }
}

void handling_time_bird(st_all_birds *birds, sfRenderWindow *window,
st_other_sprite *sprites)
{
    generate_time(&birds->bird1);
    generate_time(&birds->bird2);
    generate_time(&birds->bird3);
    generate_time(&birds->bird4);
    generate_time(&birds->bird5);
    generate_time(&birds->bird6);
    sprites->fire.time.death = create_clock(sprites->fire.clocks.clock_death);
    if (birds->bird1.deleted == 0)
        bird_clock_handling(&birds->bird1, window, &sprites->bird_out);
    if (birds->bird2.deleted == 0)
        bird_clock_handling(&birds->bird2, window, &sprites->bird_out);
    if (birds->bird3.deleted == 0)
        bird_clock_handling(&birds->bird3, window, &sprites->bird_out);
    if (birds->bird4.deleted == 0)
        bird_clock_handling(&birds->bird4, window, &sprites->bird_out);
    if (birds->bird5.deleted == 0)
        bird_clock_handling(&birds->bird5, window, &sprites->bird_out);
    if (birds->bird6.deleted == 0)
        bird_clock_handling(&birds->bird6, window, &sprites->bird_out);
}