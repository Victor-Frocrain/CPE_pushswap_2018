/*
** EPITECH PROJECT, 2018
** tests_pushswap
** File description:
** tests_pushswap
*/

#include "my.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <ctype.h>

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(sort_sa, swap_1, .init = redirect_all_std)
{
    ext *list_a = malloc(sizeof(ext));

    list_a->begin = malloc(sizeof(list));
    list_a->end = malloc(sizeof(list));
    list_a->begin->nb = 42;
    list_a->begin->prev = NULL;
    list_a->begin->next = list_a->end;
    list_a->end->nb = 7;
    list_a->end->next = NULL;
    sort_sa(list_a, false);
    cr_assert_stdout_eq_str("sa");
    cr_assert_eq(list_a->begin->nb, 7);
    cr_assert_eq(list_a->end->nb, 42);
    free(list_a->end);
    free(list_a->begin);
    free(list_a);
}

Test(sort_sb, swap_2, .init = redirect_all_std)
{
    ext *list_a = malloc(sizeof(ext));

    list_a->begin = malloc(sizeof(list));
    list_a->end = malloc(sizeof(list));
    list_a->begin->nb = 42;
    list_a->begin->prev = NULL;
    list_a->begin->next = list_a->end;
    list_a->end->nb = 7;
    list_a->end->next = NULL;
    sort_sb(list_a, false);
    cr_assert_stdout_eq_str("sb");
    cr_assert_eq(list_a->begin->nb, 7);
    cr_assert_eq(list_a->end->nb, 42);
}

Test(sort_ra, rotate_1, .init = redirect_all_std)
{
    ext *list_a = malloc(sizeof(ext));
    list *node = malloc(sizeof(list));

    list_a->begin = malloc(sizeof(list));
    list_a->end = malloc(sizeof(list));
    node->nb = 454;
    node->prev = list_a->begin;
    node->next = list_a->end;
    list_a->begin->nb = 42;
    list_a->begin->prev = NULL;
    list_a->begin->next = node;
    list_a->end->nb = 7;
    list_a->end->next = NULL;
    sort_ra(list_a, false);
    cr_assert_stdout_eq_str("ra");
    cr_assert_eq(list_a->begin->nb, 454);
    cr_assert_eq(list_a->end->nb, 42);
}

Test(sort_rb, rotate_2, .init = redirect_all_std)
{
    ext *list_a = malloc(sizeof(ext));
    list *node = malloc(sizeof(list));

    list_a->begin = malloc(sizeof(list));
    list_a->end = malloc(sizeof(list));
    node->nb = 454;
    node->prev = list_a->begin;
    node->next = list_a->end;
    list_a->begin->nb = 42;
    list_a->begin->prev = NULL;
    list_a->begin->next = node;
    list_a->end->nb = 7;
    list_a->end->next = NULL;
    sort_rb(list_a, false);
    cr_assert_stdout_eq_str("rb");
    cr_assert_eq(list_a->begin->nb, 454);
    cr_assert_eq(list_a->end->nb, 42);
}

Test(sort_rra, rotate_reverse_1, .init = redirect_all_std)
{
    ext *list_a = malloc(sizeof(ext));
    list *node = malloc(sizeof(list));

    list_a->begin = malloc(sizeof(list));
    list_a->end = malloc(sizeof(list));
    node->nb = 454;
    node->prev = list_a->begin;
    node->next = list_a->end;
    list_a->begin->nb = 42;
    list_a->begin->prev = NULL;
    list_a->begin->next = node;
    list_a->end->nb = 7;
    list_a->end->prev = list_a->begin->next;
    list_a->end->next = NULL;
    sort_rra(list_a, false);
    cr_assert_stdout_eq_str("rra");
    cr_assert_eq(list_a->begin->nb, 7);
    cr_assert_eq(list_a->end->nb, 454);
}

Test(sort_rrb, rotate_reverse_2, .init = redirect_all_std)
{
    ext *list_a = malloc(sizeof(ext));
    list *node = malloc(sizeof(list));

    list_a->begin = malloc(sizeof(list));
    list_a->end = malloc(sizeof(list));
    node->nb = 454;
    node->prev = list_a->begin;
    node->next = list_a->end;
    list_a->begin->nb = 42;
    list_a->begin->prev = NULL;
    list_a->begin->next = node;
    list_a->end->nb = 7;
    list_a->end->prev = list_a->begin->next;
    list_a->end->next = NULL;
    sort_rrb(list_a, false);
    cr_assert_stdout_eq_str("rrb");
    cr_assert_eq(list_a->begin->nb, 7);
    cr_assert_eq(list_a->end->nb, 454);
}

Test(parse_errors, invalid_ac)
{
    bool parse = false;
    char *av[1];

    av[0] = my_strdup("./push_swap");
    parse = parse_errors(1, av);
    cr_assert_eq(parse, false);
}

Test(check_string, invalid_string1)
{
    bool parse = false;

    parse = check_string("1a");
    cr_assert_eq(parse, false);
}

Test(check_string, invalid_string2)
{
    bool parse = false;

    parse = check_string("2000000000");
    cr_assert_eq(parse, true);
}

Test(check_string, valid_string1)
{
    bool parse = false;

    parse = check_string("12");
    cr_assert_eq(parse, true);
}

Test(check_string, valid_string2)
{
    bool parse = false;

    parse = check_string("1000000000");
    cr_assert_eq(parse, true);
}

Test(init_list, init_array)
{
    ext *array = init_list(array);

    cr_assert_neq(array, NULL);
    cr_assert_eq(array->begin, NULL);
    cr_assert_eq(array->end, NULL);
}

Test(my_getnbr, invalid_string)
{
    int nb = my_getnbr("2000000000");

    cr_assert_eq(nb, 0);
}

Test(my_getnbr, valid_string1)
{
    int nb = my_getnbr("1000000000");

    cr_assert_eq(nb, 1000000000);
}

Test(my_getnbr, valid_string2)
{
    int nb = my_getnbr("10456");

    cr_assert_eq(nb, 10456);
}

Test(check_string, valid_string3)
{
    bool parse = false;

    parse = check_string("0000000");
    cr_assert_eq(parse, true);
}

Test(check_string, valid_string4)
{
    bool parse = false;

    parse = check_string("00000001");
    cr_assert_eq(parse, true);
}

Test(check_string, valid_string5)
{
    bool parse = false;

    parse = check_string("-00000001");
    cr_assert_eq(parse, true);
}

Test(args_to_list, fill_list)
{
    bool fill = false;
    ext *array = init_list(array);
    char *av[3];

    av[0] = my_strdup("./push_swap");
    av[1] = my_strdup("400");
    av[2] = my_strdup("42");
    fill = args_to_list(3, av, array);
    cr_assert_neq(array, NULL);
    cr_assert_eq(array->begin->nb, 400);
    cr_assert_eq(array->begin->next->nb, 42);
    cr_assert_eq(fill, true);
}

Test(args_to_list, fill_list2)
{
    bool fill = false;
    ext *array = init_list(array);
    char *av[3];

    av[0] = my_strdup("./push_swap");
    av[1] = my_strdup("-00000001");
    av[2] = my_strdup("42");
    fill = args_to_list(3, av, array);
    cr_assert_neq(array, NULL);
    cr_assert_eq(array->begin->nb, -1);
    cr_assert_eq(array->begin->next->nb, 42);
    cr_assert_eq(fill, true);
}

Test(args_to_list, fill_list3)
{
    bool fill = false;
    ext *array = init_list(array);
    char *av[3];

    av[0] = my_strdup("./push_swap");
    av[1] = my_strdup("-00000000");
    av[2] = my_strdup("42");
    fill = args_to_list(3, av, array);
    cr_assert_neq(array, NULL);
    cr_assert_eq(array->begin->nb, 0);
    cr_assert_eq(array->begin->next->nb, 42);
    cr_assert_eq(fill, true);
}

Test(args_to_list, fill_list4)
{
    bool fill = false;
    ext *array = init_list(array);
    char *av[3];

    av[0] = my_strdup("./push_swap");
    av[1] = my_strdup("-123456");
    av[2] = my_strdup("987654");
    fill = args_to_list(3, av, array);
    cr_assert_neq(array, NULL);
    cr_assert_eq(array->begin->nb, -123456);
    cr_assert_eq(array->begin->next->nb, 987654);
    cr_assert_eq(fill, true);
}
