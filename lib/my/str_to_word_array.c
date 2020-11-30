/*
** EPITECH PROJECT, 2020
** str_to_word_array
** File description:
** str_to_word_array
*/

#include <stdio.h>
#include <stdlib.h>

int is_separator(char c, const char *separator)
{
    int i = 0;

    while (separator[i] != '\0')
    {
        if (c == separator[i])
            return (1);
        i++;
    }
    return (0);
}

int word_size(const char *str, const char *separator)
{
    int j = 0;

    while (is_separator(*str, separator) == 0 && *str != '\0') {
        str += 1;
        j++;
    }
    return (j);
}

char *my_strncpy(char *dest, const char *src, int n)
{
    int i = 0;

    while (src[i] != '\0' && i < n)
    {
        dest[i] = src[i];
        i++;
    }
    if (n > i)
        dest[i] = '\0';
    return (dest);
}

int get_nb_words(const char *str, const char *separator)
{
    int i = 0;
    int charset = 0;

    while (str[i] != '\0')
    {
        if (is_separator(str[i], separator) == 0
        && (is_separator(str[i + 1], separator) == 1 || str[i + 1] == '\0'))
            charset++;
        i++;
    }
    return (charset);
}

char **my_str_to_word_array(const char *str, const char *separator)
{
    int j = 0;
    int i = 0;
    char **final_array = malloc((sizeof(int *)) *
    get_nb_words(str, separator) + 1);
    final_array[get_nb_words(str, separator)] = NULL;

    while (*str != '\0')
    {
        if ((is_separator(*(str - 1), separator) == 1 &&
        is_separator(*str, separator) == 0) || (i == 0
        && is_separator(*str, separator) == 0)) {
            final_array[j] = malloc((sizeof(int) *
            word_size(str, separator)) + 1);
            my_strncpy(final_array[j], str, word_size(str, separator));
            j++;
        }
        str += 1;
        i++;
    }
    return (final_array);
}