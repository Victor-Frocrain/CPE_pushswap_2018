/*
** EPITECH PROJECT, 2018
** sort
** File description:
** sort
*/

#include "my.h"

void sort_ra(ext *list_a, bool rr)
{
    list *node = malloc(sizeof(list));

    if (list_a->begin && list_a->end) {
        node->nb = list_a->begin->nb;
        node->next = NULL;
        node->prev = list_a->end;
        list_a->end->next = node;
        list_a->end = list_a->end->next;
        list_a->begin = list_a->begin->next;
        free(list_a->begin->prev);
        list_a->begin->prev = NULL;
        if (rr == false)
            my_putstr("ra");
    }
}

void sort_rb(ext *list_b, bool rr)
{
    list *node = malloc(sizeof(list));

    if (list_b->begin && list_b->end) {
        node->nb = list_b->begin->nb;
        node->next = NULL;
        node->prev = list_b->end;
        list_b->end->next = node;
        list_b->end = list_b->end->next;
        list_b->begin = list_b->begin->next;
        free(list_b->begin->prev);
        list_b->begin->prev = NULL;
        if (rr == false)
            my_putstr("rb");
    }
}

void sort_rr(ext *list_a, ext *list_b)
{
    if (list_a->begin && list_b->begin) {
        sort_ra(list_a, true);
        sort_rb(list_b, true);
        my_putstr("rr");
    }
}
