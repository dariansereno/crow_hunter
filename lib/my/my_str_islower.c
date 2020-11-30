/*
** EPITECH PROJECT, 2020
** Day06
** File description:
** my_str_islower.c
*/

int my_str_islower(char const *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if ((str[i] < 'a' || str[i] > 'z') && (str[i] < '0' || str[i] > '9'))
            return (0);
        i++;
    }
    return (1);
}
