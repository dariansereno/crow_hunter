/*
** EPITECH PROJECT, 2020
** Day04
** File description:
** my_swap.c
*/

void my_swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;

}
