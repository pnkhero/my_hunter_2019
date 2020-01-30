/*
** EPITECH PROJECT, 2019
** event.c
** File description:
** event
*/

#include "./include/struct.h"

void event(struct event *e, struct window *w)
{
    if (e->event.type == sfEvtMouseButtonPressed) {
        e->position_mouse = sfMouse_getPositionRenderWindow(w->window);
        if (e->position_mouse.x > e->position.x && e->position_mouse.x < e->position.x + 110 && e->position_mouse.y > e->position.y && e->position_mouse.y < e->position.y + 110) {
            e->position.x = -150;
            e->position.y = rand() % 600;
            }
        }
    while (sfRenderWindow_pollEvent(w->window, &e->event)) {
        if (e->event.type == sfEvtKeyPressed && e->event.key.code == sfKeyEscape) {
            sfRenderWindow_close(w->window);
        } else if (e->event.type == sfEvtClosed) {
            sfRenderWindow_close(w->window);
        }
    }
}
