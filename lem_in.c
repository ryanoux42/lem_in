/*
** EPITECH PROJECT, 2022
** lem_in.c
** File description:
** lem_in
*/
#include "include/libmy.h"

void lem_in(lemin *l)
{
    algorithm(l);
}

void free_all(lemin *l)
{
    free_tab(l->data);
    free_tab(l->rooms_pos);
    free_tab(l->tunnels);
    free_tab(l->order);
}

int main(int ac, char **av)
{
    lemin *l = malloc(sizeof(lemin));

    if (check(ac, av, l) == 84)
        return 84;
    lem_in(l);
    free_all(l);
    return 0;
}
