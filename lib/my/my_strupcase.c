/*
** EPITECH PROJECT, 2020
** Day06
** File description:
** my_strupcase.c
*/

char *my_strupcase(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 97 && str[i] <= 122)
        {
            str[i] = str[i] - 32;
            i++;
        } else {
            return (0);
        }
    }
    return (str);
}
