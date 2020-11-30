/*
** EPITECH PROJECT, 2020
** Day04
** File description:
** my_sort_int_array.c
*/

#include <stdio.h>

void my_sort_int_array(int *array, int size)
{

    int i = 0;
    int j = 0;
    int temp = 0;

    while (i < size) {
        j = 0;
        while (j < size - i) {
            if (array[j] > array[j+1])
            {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
            j++;
        }
        i++;
    }
}
