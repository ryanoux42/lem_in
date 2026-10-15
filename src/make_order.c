/*
** EPITECH PROJECT, 2022
** parsing.c
** File description:
** parsing
*/
#include "../include/libmy.h"

int len_rooms_name(char *src)
{
    int i = 0;

    while (my_isalnum(src[i]) != 0) {
        i += 1;
    }
    return i;
}

char *get_room_name(char *src)
{
    int len = len_rooms_name(src);
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

void make_order_room(lemin *l, int ind)
{
    int i = 0;
    l->order = malloc(sizeof(char *) * (l->nb_rooms + 1));

    while (l->rooms_pos[i] != NULL) {
        if (my_strcmp(l->rooms_pos[i], "##end") == 0 &&
        my_strcmp(l->rooms_pos[i], "##start") == 0) {
            l->order[ind] = get_room_name(l->rooms_pos[i]);
            ind += 1;
        }
        if (my_strcmp(l->rooms_pos[i], "##start") == 1) {
            l->order[0] = get_room_name(l->rooms_pos[i + 1]);
            i += 1;
        }
        if (my_strcmp(l->rooms_pos[i], "##end") == 1) {
            l->order[l->nb_rooms - 1] = get_room_name(l->rooms_pos[i + 1]);
            i += 1;
        }
        i += 1;
    }
    l->order[l->nb_rooms] = NULL;
}
