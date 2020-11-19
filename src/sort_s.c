/*
** EPITECH PROJECT, 2018
** sort_s
** File description:
** sort_s
*/

#include "my.h"

void sort_sa(ext *list_a, bool sc)
{
    int temp = 0;

    if (list_a->begin && list_a->begin->next) {
        temp = list_a->begin->nb;
        list_a->begin->nb = list_a->begin->next->nb;
        list_a->begin->next->nb = temp;
        if (sc == false)
            my_putstr("sa");
    }
}

void sort_sb(ext *list_b, bool sc)
{
    int temp = 0;

    if (list_b->begin && list_b->begin->next) {
        temp = list_b->begin->nb;
        list_b->begin->nb = list_b->begin->next->nb;
        list_b->begin->next->nb = temp;
        if (sc == false)
            my_putstr("sb");
    }
}

void sort_sc(ext *list_a, ext *list_b)
{
    if (list_a->begin && list_b->begin) {
        sort_sa(list_a, true);
        sort_sb(list_b, true);
        my_putstr("sc");
    }
}
