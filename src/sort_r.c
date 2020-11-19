/*
** EPITECH PROJECT, 2018
** sort_r
** File description:
** sort_r
*/

#include "my.h"

void sort_rra(ext *list_a, bool rrr)
{
    list *node = malloc(sizeof(list));

    if (list_a->begin && list_a->end) {
        node->nb = list_a->end->nb;
        node->prev = NULL;
        node->next = list_a->begin;
        list_a->begin = node;
        list_a->end = list_a->end->prev;
        free(list_a->end->next);
        list_a->end->next = NULL;
        if (rrr == false)
            my_putstr("rra");
    }
}

void sort_rrb(ext *list_b, bool rrr)
{
    list *node = malloc(sizeof(list));

    if (list_b->begin && list_b->end) {
        node->nb = list_b->end->nb;
        node->prev = NULL;
        node->next = list_b->begin;
        list_b->begin = node;
        list_b->end = list_b->end->prev;
        free(list_b->end->next);
        list_b->end->next = NULL;
        if (rrr == false)
            my_putstr("rrb");
    }
}

void sort_rrr(ext *list_a, ext *list_b)
{
    if (list_a->begin && list_b->begin) {
        sort_rra(list_a, true);
        sort_rrb(list_b, true);
        my_putstr("rrr");
    }
}
