/*
** EPITECH PROJECT, 2018
** my_pushswap
** File description:
** my_pushswap
*/

#include "my.h"

bool check_string(char *str)
{
    for (int i = 0; str[i]; i++)
        if ((str[i] < '0' || str[i] > '9') &&
            str[i] != '-' && str[i] != '\0')
            return (false);
    return (true);
}

bool parse_errors(int ac, char **av)
{
    if (ac < 2)
        return (false);
    for (int i = 1; av[i]; i++) {
        if (check_string(av[i]) == false)
            return (false);
    }
    return (true);
}

ext *init_list(ext *array)
{
    array = malloc(sizeof(ext));
    if (array == NULL)
        return (NULL);
    array->begin = NULL;
    array->end = NULL;
    return (array);
}

bool args_to_list(int ac, char **av, ext *list_a)
{
    for (int i = 1; av[i]; i++) {
        fill_list_end(list_a, my_getnbr(av[i]));
        if (!list_a)
            return (false);
    }
    return (true);
}

int my_pushswap(int ac, char **av)
{
    ext *list_a = init_list(list_a);
    ext *list_b = init_list(list_b);
    list *new;

    if (parse_errors(ac, av) == false ||
        list_a == NULL || list_b == NULL)
        return (MY_EXIT_ERROR);
    if (args_to_list(ac, av, list_a) == false)
        return (MY_EXIT_ERROR);
    while (check_sort(list_a) == false || list_b->begin)
        if (check_cases(list_a, list_b) == false)
            break;
    my_putchar('\n');
    while (list_a->begin) {
        my_put_nbr(list_a->begin->nb);
        my_putchar(' ');
        list_a->begin = list_a->begin->next;
    }
    return (MY_EXIT_SUCCESS);
}
