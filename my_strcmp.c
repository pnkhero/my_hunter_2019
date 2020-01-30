/*
** EPITECH PROJECT, 2019
** my_strcmp.c
** File description:
** my_strcmp
*/

#include "./include/struct.h"

int	my_strcmp(char *s1, char *s2)
{
    int i = 0;

    while (s1[i] == s2[i] && s1[i] != '\0')
        i = i + 1;
    return s1[i] - s2[i];
}