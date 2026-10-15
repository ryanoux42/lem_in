/*
** EPITECH PROJECT, 2022
** args.c
** File description:
** args
*/
#include "../include/libmy.h"


int my_isnum(char const letter)
{
    int answer = 0;
    if (('0' <= letter && letter <= '9')) {
        answer = 1;
    } else {
        answer = 0;
    }
    return answer;
}

int  check_nb_num(char const *str)
{
    int i = 0;
    int nb = 0;
    int ok = 0;

    while (str[i] != '#' && str[i] != '\0') {
        if (my_isnum(str[i]) == 1 && my_isnum(str[i + 1]) == 0) {
            nb += 1;
        }
        i += 1;
    }
    return (nb);
}

int  my_getnbr(char const *str)
{
    int i = 0;
    int nb = 0;
    int ok = 0;

    if (str[0] == '-') {
            ok = 1;
            i += 1;
    }
    while (my_isnum(str[i]) == 1) {
        if ('0' <= str[i] && str[i] <= '9') {
            nb = nb * 10;
            nb = nb + str[i] - '0';
        }
        i += 1;
    }
    if (ok == 1)
        nb = -nb;
    return (nb);
}

int check_ant(lemin *l, int *i)
{
    l->nb_ants = 0;
    while (l->data[(*i)] != NULL) {
        if (l->data[(*i)][0] != '#') {
            l->nb_ants = my_getnbr(l->data[(*i)]);
            break;
        }
        (*i)++;
    }
    if (l->nb_ants <= 0 || check_nb_num(l->data[(*i)]) != 1)
        return 84;
    my_putstr("#number_of_ants\n");
    my_put_nbr(l->nb_ants);
    back();
    return 0;
}

int check(int ac, char **av, lemin *l)
{
    int i = 0, has = 0;
    char *str = NULL;

    if (ac != 1)
        return my_put_error("error: no arguments are expected\n");
    str = my_stdinstr();
    l->data = my_str_to_word_array(str, '\n');
    if (check_ant(l, &i) == 84)
        return 84;
    i += 1;
    if (check_room(l, i, &has) == 84)
        return 84;
    get_rooms_pos(l, &i);
    make_order_room(l, 1);
    if (has != 1 || check_tunnels(l, i) == 84)
        return 84;
    get_tunnel(l, &i);
    l->current = malloc(sizeof(room));
    l->current = init_room(l);
    return 0;
}
