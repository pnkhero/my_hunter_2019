/*
** EPITECH PROJECT, 2018
** my_putchar
** File description:
** No file there , just an epitech header example
*/

#include <unistd.h>
#include "./include/struct.h"

int my_putchar(char c)
{
    write(1, &c, 1);
}
