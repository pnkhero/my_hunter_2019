/*
** EPITECH PROJECT, 2019
** music.c
** File description:
** musique
*/

#include "./include/struct.h"

int set_music(struct window *w)
{
    w->music = sfMusic_createFromFile("logobi.ogg");
    if (!w->music)
        return (84);
    sfMusic_play(w->music);
}