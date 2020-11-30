/*
** EPITECH PROJECT, 2020
** Crow_Hunter
** File description:
** Time Handling
*/

#include "../include/my.h"

void initialize_clock(st_info_sprite *bird)
{
    sfClock *clock_bird = sfClock_create();
    sfClock *clock_death = sfClock_create();
    sfClock *clock_still = sfClock_create();
    sfClock *clock_appear = sfClock_create();
    bird->clocks.clock_fly = clock_bird;
    bird->clocks.clock_death = clock_death;
    bird->clocks.clock_still = clock_still;
    bird->clocks.clock_appear = clock_appear;
    bird->still = 1;
    bird->rect.left = 540;
}

st_timer_t create_clock(sfClock *clock)
{
    st_timer_t timer;

    timer.seconds = 0;
    timer.time = sfClock_getElapsedTime(clock);
    timer.seconds = timer.time.microseconds / 1000000.0;
    return (timer);
}

void generate_time(st_info_sprite *bird)
{
    bird->time.fly = create_clock(bird->clocks.clock_fly);
    bird->time.death = create_clock(bird->clocks.clock_death);
    bird->time.still = create_clock(bird->clocks.clock_still);
    bird->time.appear = create_clock(bird->clocks.clock_appear);
}

void bird_clock_handling(st_info_sprite *bird,
sfRenderWindow *window, int *bird_out)
{
    handling_bird(bird);
    handling_bird2(bird);
    if ((bird->position.x > WIDTH || bird->position.y > HEIGHT)
    && bird->death == 0) {
        sfSprite_destroy(bird->sprite);
        sfTexture_destroy(bird->texture);
        sfClock_destroy(bird->clocks.clock_death);
        sfClock_destroy(bird->clocks.clock_still);
        sfClock_destroy(bird->clocks.clock_fly);
        *bird_out += 1;
        bird->deleted = 1;
    }
    if (bird->death == 1 && bird->still == 0) {
        if_bird_dead(bird, window, bird->time.death.seconds, bird_out);
    }
}

void ft_clock(sfRenderWindow *window, st_all_birds *birds,
st_other_sprite *sprites)
{
    handling_time_bird(birds, window, sprites);
    if (sprites->shot == 0)
        sfClock_restart(sprites->fire.clocks.clock_death);
    else {
        if (sprites->fire.time.death.seconds > 0.03) {
            sprites->fire.rect.left += 60;
            if (sprites->fire.rect.left >= 420){
                sprites->fire.rect.left = 0;
                sprites->fire.position.x = -200;
                sprites->fire.position.y = -200;
                sprites->shot = 0;
                }
            sfClock_restart(sprites->fire.clocks.clock_death);
        }
    }
}