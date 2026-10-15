/*
** EPITECH PROJECT, 2023
** Lemin
** File description:
** queue
*/

#include "../include/libmy.h"

queue* create_queue(int size)
{
    queue *q = malloc(sizeof(queue));

    q->items = malloc(sizeof(room *) * size);
    q->front = -1;
    q->rear = -1;
    q->size = size;
    return q;
}

int q_is_full(queue* q)
{
    if (q->rear == q->size - 1)
        return 1;
    else
        return 0;
}

int q_is_empty(queue* q)
{
    if (q->front == -1 && q->rear == -1)
        return 1;
    else
        return 0;
}

void q_enqueue(queue* q, room *room)
{
    if (!q_is_full(q)) {
        int tmp = q_is_empty(q);

        q->rear = (tmp == 1) ? 0 : q->rear + 1;
        q->front = (tmp == 1) ? 0 : q->front;

        q->items[q->rear] = room;
    }
}

room *q_dequeue(queue* q)
{
    room *item;

    if (!q_is_empty(q)) {
        item = q->items[q->front];

        int tmp = (q->front == q->rear);

        q->rear = tmp ? -1 : q->rear;
        q->front = tmp ? -1 : q->front + 1;

        return item;
    } else {
        return NULL;
    }
}
