/*
** EPITECH PROJECT, 2020
** Day06
** File description:
** my_strcmp.c
*/

#include <stdio.h>

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] != '\0' || s2[i] != '\0') {
        if (s1[i] < s2[i])
            return (s1[i] - s2[i]);
        if (s1[i] > s2[i])
            return (s1[i] - s2[i]);
        i++;
    }
    return (0);
}
