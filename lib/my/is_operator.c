/*
** EPITECH PROJECT, 2020
** Libmy
** File description:
** is operator
*/

int is_operator(char c, char *operator)
{
    if (c == operator[0] || c == operator[1] || c == operator[2] ||
        c == operator[3] || c == operator[4] ||
        c == operator[5] || c == operator[6])
        return (1);
    return (0);
}