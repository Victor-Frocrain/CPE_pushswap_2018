/*
** EPITECH PROJECT, 2018
** sort_p
** File description:
** sort_p
*/

#include "my.h"

bool sort_pa(ext *list_a, ext *list_b)
{
    if (list_a->begin == NULL) {
        list_a->begin = NULL;
        list_a->end = NULL;
    }
    if (list_b->begin) {
        if (fill_list_begin(list_a, list_b->begin->nb) == false)
            return (false);
        list_b->begin = list_b->begin->next;
        if (list_b->begin)
            list_b->begin->prev = NULL;
        my_putstr("pa");
    }
    return (true);
}

bool sort_pb(ext *list_a, ext *list_b)
{
    if (list_b->begin == NULL) {
        list_b->begin = NULL;
        list_b->end = NULL;
    }
    if (list_a->begin) {
        if (fill_list_begin(list_b, list_a->begin->nb) == false)
            return (false);
        list_a->begin = list_a->begin->next;
        if (list_a->begin)
            list_a->begin->prev = NULL;
        my_putstr("pb");
    }
    return (true);
}
