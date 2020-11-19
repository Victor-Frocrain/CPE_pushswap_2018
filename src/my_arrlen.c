/*
** EPITECH PROJECT, 2018
** my_arrlen
** File description:
** my_arrlen
*/

#include "my.h"

int my_arrlen(int *arr)
{
    int i = 0;

    for (; arr[i]; i++);
    return (i);
}
