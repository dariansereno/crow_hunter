/*
** EPITECH PROJECT, 2020
** Day07
** File description:
** prints a char into stdout
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(2, &c, 1);
}
