/*
** EPITECH PROJECT, 2022
** print.c
** File description:
** print
*/

#include "../include/libmy.h"

int len_part(char *src, int i)
{
    int len = 0;

    if (src[i] == '-')
        i += 1;
    while (src[i] != '-' || src[i] != '\0') {
        if (my_isalnum(src[i]) == 1) {
            len += 1;
            i += 1;
        } else {
            break;
        }
    }
    return len;
}

char *cp_part(char *src, int *j)
{
    int len = len_part(src, (*j));
    int ind = 0;
    char *str = malloc(sizeof(char) * (len + 1));

    if (src[(*j)] == '-')
        (*j) += 1;
    while (ind < len) {
        str[ind] = src[(*j)];
        (*j) += 1;
        ind += 1;
    }
    str[ind] = '\0';
    return str;
}

int find_nb_link(char *name, char **tunnels)
{
    int nb = 0;
    int j = 0;
    char *first = NULL;
    char *second = NULL;

    for (int i = 0; tunnels[i] != NULL; i++) {
        j = 0;
        first = cp_part(tunnels[i], &j);
        second = cp_part(tunnels[i], &j);
        if (my_strcmp(name, first) == 1 || my_strcmp(name, second) == 1)
            nb += 1;
        free(first);
        free(second);
    }
    return nb;
}

room* get_node(char *name, room** nodes, lemin *l)
{
    struct room* new = malloc(sizeof(room));

    for (int i = 0; i < l->nb_rooms; i++) {
        if (my_strcmp(name, nodes[i]->name) == 1) {
            new = nodes[i];
            break;
        }
    }
    return new;
}

room** make_link(room** neighbors, char *name, lemin *l, room** nodes)
{
    int nb = 0, j = 0, ind = 0;
    char *first = NULL;
    char *second = NULL;
    for (int i = 0; l->tunnels[i] != NULL; i++) {
        j = 0;
        first = cp_part(l->tunnels[i], &j);
        second = cp_part(l->tunnels[i], &j);
        if (my_strcmp(name, first) == 1) {
            neighbors[ind] = get_node(second, nodes, l);
            ind += 1;
        }
        if (my_strcmp(name, second) == 1) {
            neighbors[ind] = get_node(first, nodes, l);
            ind += 1;
        }
        free(first);
        free(second);
    }
    neighbors[ind] = NULL;
    return neighbors;
}
