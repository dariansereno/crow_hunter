/*
** EPITECH PROJECT, 2020
** Day04
** File description:
** my_getnbr.c
*/

#include <unistd.h>

int my_put_nbr(int nb);

int my_getnbr(char const *str)
{
    int n = 0;
    int resultat = 0;
    int a = 0;

    while (str[n] == 43 || str[n] == 45) {
        if (str[n] == 45)
            a++;
        n++;
    }
    if (a % 2 != 0)
        a = -1;
    else
        a = 1;
    while ((str[n] > 47 && str[n] < 58)  || str[n] == 43 || str[n] == 45) {
        resultat = resultat * 10 + str[n] - 48;
        n++;
    }
    return (resultat * a);
}
