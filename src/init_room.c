/*
** EPITECH PROJECT, 2022
** print.c
** File description:
** print
*/

#include "../include/libmy.h"

room* createroom(char *name, bool is_full)
{
    struct room *new = malloc(sizeof(room));

    new->name = name;
    new->is_full = is_full;
    new->visited = false;
    new->dist_to_end = -1;
    return new;
}

room* init_room(lemin *l)
{
    room** nodes = malloc(sizeof(room*) * (l->nb_rooms));
    nodes[0] = createroom(l->order[0], true);

    for (int i = 1; i < l->nb_rooms; i++)
        nodes[i] = createroom(l->order[i], false);

    for (int j = 0; j < l->nb_rooms; j++) {
        nodes[j]->neighbors =
        malloc(sizeof(room *) * (find_nb_link(l->order[j], l->tunnels) + 1));

        nodes[j]->neighbors = make_link(nodes[j]->neighbors, \
        nodes[j]->name,  l,nodes);
    }

    return nodes[0];
}
