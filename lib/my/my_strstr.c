/*
** EPITECH PROJECT, 2020
** Day06
** File description:
** my_strstr.c
*/

#include <stdio.h>

char my_strlen(char *str);

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int len = my_strlen(str);
    int j = 0;

    while (str[i] != to_find[j])
    {
        if (i > len)
            return (0);
        i++;
    }
    if (str[i + 1] != '\0' || to_find[j + 1] != '\0')
    {
        return (str + i);
    }
    return (0);
}
