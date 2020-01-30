/*
** EPITECH PROJECT, 2019
** struct
** File description:
** struct
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <SFML/Window.h>
#include <SFML/Config.h>
#include <SFML/System.h>

#ifndef STRUCT_H_
#define STRUCT_H_

struct window
{
    sfVideoMode mode;
    sfRenderWindow* window;
    sfMusic* music;
};

struct Texture
{
    sfTexture* tbgd;
    sfTexture* tduck;
};

struct Sprite
{
    sfSprite* sbgd;
    sfSprite* sduck;
};

struct event
{
    sfEvent event;
    sfClock *clock;
    sfTime time;
    float seconds;
    sfVector2f position;
    sfVector2f move;
    sfVector2i position_mouse;
    float x;
    float y;
};

int spandtex(struct Texture *t, struct Sprite *s);
void draw(struct window *w, struct Sprite *s);
void event(struct event *e, struct window *w);
void move_rect(sfIntRect *rect, int offset, int max_value);
void move(struct event *e, struct Sprite *s, sfIntRect *r);
int display_window(struct window *w);
void actio(struct window *w, struct Sprite *s, struct event *e);
void destroy(struct window *w, struct Texture *t, struct Sprite *s);
int set_music(struct window *w);
int	my_strcmp(char *s1, char *s2);
int my_putchar(char c);
int my_putstr(char const *str);

#endif /* !STRUCT_H_ */
