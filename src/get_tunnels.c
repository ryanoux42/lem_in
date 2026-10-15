/*
** EPITECH PROJECT, 2022
** print.c
** File description:
** print
*/
#include "../include/libmy.h"

int get_nb_tunnels(char **data, int start)
{
    int nb = 0;

    while (data[start] != NULL) {
        if (data[start][0] != '#')
            nb += 1;
        start += 1;
    }
    return nb;
}

int len_tunnel(char *src)
{
    int len = 0;
    int i = 0;

    while (src[i] != '\0') {
        if (my_isalnum(src[i]) == 1 || src[i] == '-') {
            len += 1;
            i += 1;
        } else {
            break;
        }
    }
    return len;
}

char *cp_tunnel(char *src)
{
    int len = len_tunnel(src);
    int j = 0;
    int ind = 0;
    char *str = malloc(sizeof(char) * (len + 1));

    while (j < len) {
        str[ind] = src[j];
        j += 1;
        ind += 1;
    }
    str[ind] = '\0';
    return str;
}

void get_tunnel(lemin *l, int *i)
{
    int j = 0;

    l->tunnels = malloc(sizeof(char *) * (l->nb_tunnels + 1));
    while (l->data[(*i)] != NULL) {
        if (l->data[(*i)][0] != '#') {
            l->tunnels[j] = cp_tunnel(l->data[(*i)]);
            j += 1;
        }
        (*i) += 1;
    }
    l->tunnels[l->nb_tunnels] = NULL;
    my_putstr("#tunnels\n");
    my_put_tab(l->tunnels, "\n");
}
