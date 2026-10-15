/*
** EPITECH PROJECT, 2022
** args.c
** File description:
** args
*/
#include "../include/libmy.h"

int check_part(char *str, lemin *l)
{
    int j = 0, i = 0, a = 0, b = 0;
    char *first = cp_part(str, &j);
    char *second = cp_part(str, &j);

    if (my_strcmp(first, second) == 1)
            return 84;
    while (l->order[i] != NULL) {
        if (my_strcmp(l->order[i], first) == 1)
            a = 1;
        if (my_strcmp(l->order[i], second) == 1)
            b = 1;
        i += 1;
    }
    free(first);
    free(second);
    if (a == 1 && b == 1)
        return 0;
    else
        return 84;
}

int check_tunnels(lemin *l, int i)
{
    int pass = 0;
    l->nb_tunnels = 0;

    while (l->data[i] != NULL) {
        if (l->data[i][0] != '#') {
            pass = check_part(l->data[i], l);
            l->nb_tunnels += 1;
        }
        if (pass == 84)
            return 84;
        i++;
    }
    return 0;
}
