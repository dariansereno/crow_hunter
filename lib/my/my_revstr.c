/*
** EPITECH PROJECT, 2020
** Day06
** File description:
** my_revstr.c
*/

#include <stdio.h>

int my_strlen(char *str);

char *my_revstr(char *str)
{
    char temp = 0;
    int start = 0;
    int end = my_strlen(str) - 1;

    while (str[end] != '\0')
        end++;
    end--;
    while (start <= end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
    return (str);
}
