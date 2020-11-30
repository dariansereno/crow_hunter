/*
** EPITECH PROJECT, 2020
** Day05
** File description:
** my is prime
*/

int my_is_prime(int nb)
{
    int i = 2;

    while (i < nb) {
        if (nb % i == 0)
            return (0);
        i++;
    }
    return (1);
}
