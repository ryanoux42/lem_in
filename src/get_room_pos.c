/*
** EPITECH PROJECT, 2022
** print.c
** File description:
** print
*/
#include "../include/libmy.h"

int my_isalnum(char const letter)
{
    int answer = 0;
    if (('a' <= letter && letter <= 'z') || ('A' <= letter && letter <= 'Z')
        || ('0' <= letter && letter <= '9')) {
        answer = 1;
    } else {
        answer = 0;
    }
    return answer;
}

int len_rooms_pos(char *src)
{
    int i = 0;
    int nb = 0;

    while (nb != 3) {
        if (my_isalnum(src[i]) == 0)
            nb += 1;
        i += 1;
    }
    return i;
}

char *cp_room_pos(char *src)
{
    int len = len_rooms_pos(src);
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

void file_room_pos(lemin *l, int i, int *ind)
{
    if (l->data[i][0] == '#' && l->data[i][1] == '#'
        && l->data[i][2] == 's') {
            l->rooms_pos[(*ind)] = my_strdup("##start");
            (*ind) += 1;
        }
        if (l->data[i][0] == '#' && l->data[i][1] == '#'
        && l->data[i][2] == 'e') {
            l->rooms_pos[(*ind)] = my_strdup("##end");
            (*ind) += 1;
        }
        if (l->data[i][0] != '#') {
            l->rooms_pos[(*ind)] = cp_room_pos(l->data[i]);
            (*ind) += 1;
        }
}

void get_rooms_pos(lemin *l, int *i)
{
    l->rooms_pos = malloc(sizeof(char *) * (l->nb_rooms + 3));
    int ind = 0;

    while (l->data[(*i)] != NULL) {
        if (check_end_room(l->data[(*i)]) == 1) {
            break;
        }
        file_room_pos(l, (*i), &ind);
        (*i)++;
    }
    l->rooms_pos[ind] = NULL;
    my_putstr("#rooms\n");
    my_put_tab(l->rooms_pos, "\n");
}
