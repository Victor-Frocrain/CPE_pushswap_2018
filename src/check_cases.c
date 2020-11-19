/*
** EPITECH PROJECT, 2018
** check_cases
** File description:
** check cases
*/

#include "my.h"

bool check_sort(ext *list_a)
{
    list *node = list_a->begin;

    while (node && node->next) {
        if (node->nb > node->next->nb)
            return (false);
        node = node->next;
    }
    return (true);
}

void display_spaces(ext *list_a, ext *list_b)
{
    if (check_sort(list_a) == false || list_b->begin)
        my_putchar(' ');
}

void manage_lists(ext *list_a, ext *list_b)
{
    list *node = list_b->begin;

    if (check_sort(list_a) == true) {
        sort_pa(list_a, list_b);
        display_spaces(list_a, list_b);
    }
    else {
        sort_pb(list_a, list_b);
        display_spaces(list_a, list_b);
    }
}

void check_operation(ext *list_a, ext *list_b)
{
    if (list_a->begin && list_a->end && list_a->end->prev != NULL &&
    list_a->begin->nb > list_a->end->nb) {
        sort_rra(list_a, false);
        display_spaces(list_a, list_b);
    }
    if (list_a->begin && list_a->begin->next &&
    list_a->begin->nb > list_a->begin->next->nb) {
        sort_ra(list_a, false);
        display_spaces(list_a, list_b);
    }
    manage_lists(list_a, list_b);
    if (list_a->begin && list_a->begin->next &&
    list_a->begin->nb > list_a->begin->next->nb) {
        sort_sa(list_a, false);
        display_spaces(list_a, list_b);
    }
}

bool check_cases(ext *list_a, ext *list_b)
{
    list *node = list_a->begin;

    while (node) {
        check_operation(list_a, list_b);
        node = node->next;
    }
    return (true);
}
