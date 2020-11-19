/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my.h
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdarg.h>
#include <SFML/Graphics.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#ifndef MY_H_
#define MY_H_
#define MY_EXIT_ERROR (84)
#define MY_EXIT_SUCCESS (0)

struct option_s {
    char *op;
    void(*func)(int, int);
};

typedef struct linked_list_t
{
    int nb;
    struct linked_list_t *next;
    struct linked_list_t *prev;
} list;

typedef struct extern_t {
    list *begin;
    list *end;
} ext;

struct lists_s {
    int *list_a;
    int *list_b;
};

typedef struct option_s option;
typedef struct lists_s lists;
int my_pushswap(int ac, char **av);
void sort_sa(ext *list_a, bool sc);
void sort_sb(ext *list_b, bool sc);
bool sort_pa(ext *list_a, ext *list_b);
bool sort_pb(ext *list_a, ext *list_b);
void sort_ra(ext *list_a, bool rr);
void sort_rb(ext *list_b, bool rr);
void sort_rr(ext *list_a, ext *list_b);
void sort_rra(ext *list_a, bool rrr);
void sort_rrb(ext *list_a, bool rrr);
void sort_rrr(ext *list_a, ext *list_b);
int my_arrlen(int *arr);
bool check_cases(ext *list_a, ext *list_b);
bool check_sort(ext *list_a);
bool fill_list_begin(ext *array, int data);
bool fill_list_end(ext *array, int data);
ext *init_list(ext *array);
bool parse_errors(int ac, char **av);
bool check_string(char *str);
bool args_to_list(int ac, char **av, ext *list_a);

void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
int my_show_word_array(char * const *tab);
char **my_str_to_word_array(char const *str);
struct info_param *my_params_to_array(int ac, char **av);
int my_show_param_array(struct info_param const *par);
char *my_strdup(char *str);

#endif /* MY_H_ */
