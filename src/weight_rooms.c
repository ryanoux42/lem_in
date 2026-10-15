/*
** EPITECH PROJECT, 2023
** Lemin
** File description:
** weight_rooms
*/
#include "../include/libmy.h"

void enqueue_neighbours_distance(room *r, queue *q, int distance)
{
    for (int i = 0; r->neighbors[i] != NULL; i++) {
        if (r->neighbors[i]->dist_to_end == -1) {
            r->neighbors[i]->dist_to_end = distance;
            q_enqueue(q, r->neighbors[i]);
        }
    }
}

void empty_one_fill_two(queue *q1, queue *q2, int distance)
{
    while (!q_is_empty(q1)) {
        room *temp = q_dequeue(q1);
        enqueue_neighbours_distance(temp, q2, distance);
    }
}

void add_distance(lemin *l)
{
    queue *q1 = create_queue(l->nb_rooms);
    queue *q2 = create_queue(l->nb_rooms);
    int distance = 1;

    q_enqueue(q1, l->current);
    while (!q_is_empty(q1) || !q_is_empty(q2)) {
        empty_one_fill_two(q1, q2, distance);
        distance++;
        queue *temp = q1;
        q1 = q2;
        q2 = temp;
    }
}
