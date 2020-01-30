/*
** EPITECH PROJECT, 2019
** movr
** File description:
** move fonction
*/

#include "./include/struct.h"
#include <stdio.h>

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    rect->left += offset;
    if (rect->left == max_value)
        rect->left = 0;
}

void move(struct event *e, struct Sprite *s, sfIntRect *r)
{
    e->time = sfClock_getElapsedTime(e->clock);
    e->seconds = e->time.microseconds / 100000.0;
        if (e->seconds > 1.0) {
            move_rect(r, 110, 330);
            sfSprite_setTextureRect(s->sduck, *r);
            sfClock_restart(e->clock);
        }
        if (e->position.x == 1920) {
            e->position.x = -100;
            e->position.y = rand() % 600;
            sfSprite_move(s->sduck, e->move);
        }
        sfSprite_setPosition(s->sduck, e->position);
        e->position.x++;
}