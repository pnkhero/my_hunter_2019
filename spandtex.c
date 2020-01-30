/*
** EPITECH PROJECT, 2019
** sprand tex
** File description:
** create sprite and texture
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

int spandtex(struct Texture *t, struct Sprite *s)
{
    sfIntRect r = {.left = 0, .top = 0, .width = 110, .height = 110};

    t->tbgd = sfTexture_createFromFile("policebg.png", NULL);
    if (!t->tbgd) {
        return (84);
    }
    s->sbgd = sfSprite_create();
    sfSprite_setTexture(s->sbgd, t->tbgd, sfTrue);
    t->tduck = sfTexture_createFromFile("canard.png", NULL);
    if (!t->tduck)
        return (84);
    s->sduck = sfSprite_create();
    sfSprite_setTexture(s->sduck, t->tduck, sfTrue);
    sfSprite_setTextureRect(s->sduck, r);
}

void draw(struct window *w, struct Sprite *s)
{
    sfRenderWindow_drawSprite(w->window, s->sbgd, NULL);
    sfRenderWindow_drawSprite(w->window, s->sduck, NULL);
}