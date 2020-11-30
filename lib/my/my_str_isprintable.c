/*
** EPITECH PROJECT, 2020
** Day06
** File description:
** my_str_isprintable.c
*/

int my_str_isprintable(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < 32 || str[i] > 127)
            return (0);
        i++;
    }
    return (1);
}
