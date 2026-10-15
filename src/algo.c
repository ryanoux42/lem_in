/*
** EPITECH PROJECT, 2022
** args.c
** File description:
** args
*/
#include "../include/libmy.h"

void add_neighbors_to_q(queue *q, room *current)
{
    for (int i = 0; current->neighbors[i] != NULL; i++) {
        if (!current->neighbors[i]->visited) {
            q_enqueue(q, current->neighbors[i]);
            current->neighbors[i]->visited = true;
        }
    }
}

void find_end_room(lemin *l)
{
    queue *q = create_queue(l->nb_rooms);
    q_enqueue(q, l->current);

    while (!my_strcmp(l->current->name, l->order[l->nb_rooms - 1])) {
        l->current = q_dequeue(q);
        add_neighbors_to_q(q, l->current);
    }
    l->current->dist_to_end = 0;
}

room *find_min_dist(room *r)
{
    room *temp = NULL;
    for (int i = 0; r->neighbors[i] != NULL; i++) {
        if (!r->neighbors[i]->is_full && (temp == NULL ||
        r->neighbors[i]->dist_to_end < temp->dist_to_end)) {
            temp = r->neighbors[i];
        }
    }
    return temp;
}

room **create_path(lemin *l)
{
    room *closest = find_min_dist(l->current);
    if (closest == NULL)
        return NULL;
    int size = closest->dist_to_end;
    room **path = malloc(sizeof(room *) * (size + 2));
    closest->is_full = true;
    path[0] = closest;
    int i = 1;
    while (closest->dist_to_end != 0) {
        closest = find_min_dist(closest);
        closest->is_full = true;
        path[i] = closest;
        i++;
    }
    path[i] = NULL;
    return path;
}

void algorithm(lemin *l)
{
    room *temp = l->current;
    find_end_room(l);
    add_distance(l);
    l->current = temp;
    room **path = create_path(l);
    print_moves(path, l);
}
