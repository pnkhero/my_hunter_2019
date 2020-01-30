/*
** EPITECH PROJECT, 2019
** display_window.c
** File description:
** display window
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <SFML/Window.h>
#include <SFML/Config.h>
#include <SFML/System.h>
#include "./include/struct.h"
#include <SFML/Window/Export.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Vector2.h>
#include <unistd.h>
#include <string.h>

void descriptor(void)
{
    my_putstr("Finite hunter created with CSFML.\n");
    my_putchar('\n');
    my_putstr("USAGE\n");
    my_putstr("./hunter\n");
    my_putchar('\n');
    my_putstr("OPTIONS\n");
    my_putstr("-h       print the usage and quit.\n");
    my_putchar('\n');
    my_putstr("USER INTERACTIONS\n");
    my_putstr("MOUSE_KEY_LEFT     shoot.\n");
}

int display_window(struct window *w)
{
    w->mode = (sfVideoMode) {1920, 1080, 32};
    w->window = sfRenderWindow_create(w->mode, "Test", sfResize | sfClose, NULL);
    if (!w->window) {
        return (84);
    }
}

void actio(struct window *w, struct Sprite *s, struct event *e)
{
    sfIntRect  r = {.left = 0, .top = 0, .width = 110, .height = 110};

    e->position.x = 0;
    e->position.y = rand() % 700;

    e->clock = sfClock_create();
    while (sfRenderWindow_isOpen(w->window)) {
        move(e, s, &r);
        event(e, w);
        sfRenderWindow_clear(w->window, sfBlack);
        draw(w, s);
        sfRenderWindow_display(w->window);
    }
}

void destroy(struct window *w, struct Texture *t, struct Sprite *s)
{
    sfMusic_destroy(w->music);
    sfSprite_destroy(s->sbgd);
    sfTexture_destroy(t->tbgd);
    sfSprite_destroy(s->sduck);
    sfTexture_destroy(t->tduck);
    sfRenderWindow_destroy(w->window);
}

int main(int argc, char **argv)
{
    struct window w;
    struct Texture t;
    struct Sprite s;
    struct event e;
    char *str = "-h";

    if (argc == 2 && my_strcmp(argv[1], str) == 0) {
        descriptor();
        return (0);
    }
    display_window(&w);
    set_music(&w);
    spandtex(&t, &s);
    actio(&w, &s, &e);
    destroy(&w, &t, &s);
}