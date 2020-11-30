/*
** EPITECH PROJECT, 2020
** Day05
** File description:
** my_compute_square_root.c
*/

int my_compute_square_root(int nb)
{
    int i = nb;

    while (i >= 0) {
        if (i * i == nb)
            return (i);
        i--;
    }
    return (0);
}
