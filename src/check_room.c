/*
** EPITECH PROJECT, 2022
** args.c
** File description:
** args
*/
#include "../include/libmy.h"

int check_room_pos(char const *str)
{
    int i = 0;
    int phase = 0;

    while (str[i] != '#' && str[i] != '\0') {
        if (str[i] == ' ') {
            phase += 1;
            i += 1;
        }
        if (my_isalnum(str[i]) == 0 && phase < 1)
            return 84;
        if (my_isnum(str[i]) == 0 && phase >= 1)
            return 84;
        if (phase == 2)
            break;
        i += 1;
    }
    if (phase != 2)
        return 84;
    return 0;
}

int check_end_room(char const *str)
{
    int i = 0;

    while (str[i] != '#' && str[i] != '\0') {
        if (str[i] == '-')
            return 1;
        i += 1;
    }
    return 0;
}

int my_strcmp_start_end(char const *s1, char const *s2)
{
    int j = 0;

    for (int i = 2; my_isalnum(s1[i]) == 1; i++) {
        if (s1[i] != s2[j])
            return 0;
        j += 1;
    }
    return 1;
}

void check_start_end(char *str, int *start, int *end)
{
    if (my_strcmp_start_end(str, "start") == 1)
        *start += 1;
    if (my_strcmp_start_end(str, "end") == 1)
        *end += 1;
}

int check_room(lemin *l, int i, int *has)
{
    int start = 0, end = 0, pass = 0;
    l->nb_rooms = 0;

    for (;l->data[i] != NULL; i += 1) {
        if (check_end_room(l->data[i]) == 1) {
            *has = 1;
            break;
        }
        if (l->data[i][0] != '#') {
            pass = check_room_pos(l->data[i]);
            l->nb_rooms += 1;
        }
        if (l->data[i][0] == '#' && l->data[i][1] == '#')
            check_start_end(l->data[i], &start, &end);
        if (pass == 84)
            return 84;
    }
    if (start != 1 || end != 1)
        return 84;
    return 0;
}
