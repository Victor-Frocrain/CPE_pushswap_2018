/*
** EPITECH PROJECT, 2018
** fill_lists
** File description:
** fill_lists
*/

#include "my.h"

bool begin_fill(ext *array, list *node, int data)
{
    if (node == NULL)
        return (false);
    if (array == NULL)
        return (false);
    node->nb = data;
    return (true);
}

bool fill_list_begin(ext *array, int data)
{
    list *node = malloc(sizeof(list));

    if (begin_fill(array, node, data) == false)
        return (false);
    node->prev = NULL;
    if (!array->end) {
        node->next = NULL;
        array->begin = node;
        array->end = node;
    }
    else {
        array->begin->prev = node;
        node->next = array->begin;
        array->begin = node;
    }
    return (true);
}

bool fill_list_end(ext *array, int data)
{
    list *node = malloc(sizeof(list));

    if (begin_fill(array, node, data) == false)
        return (false);
    node->next = NULL;
    if (!array->begin) {
        node->prev = NULL;
        array->begin = node;
        array->end = node;
    }
    else {
        array->end->next = node;
        node->prev = array->end;
        array->end = node;
    }
    return (true);
}
