/*
** EPITECH PROJECT, 2022
** my_str5.c
** File description:
** my_str5
*/
#include "../../include/libmy.h"

char **my_tabdup(char **input)
{
    int size = 0;

    while (input[size] != NULL) {
        size++;
    }

    char **result = (char **)malloc((size + 1) * sizeof(char *));

    for (int i = 0; i < size; i++) {
        result[i] = my_strdup(input[i]);
    }

    result[size] = NULL;

    return result;
}

int my_tabcontains(char **tab, char *str)
{
    for (int i = 0; tab[i]; i++) {
        if (my_strcmp(tab[i], str))
            return 1;
    }

    return 0;
}

int my_tabcontainstimes(char **tab, char *str)
{
    int times = 0;

    for (int i = 0; tab[i]; i++)
        if (my_strcmp(tab[i], str))
            times += 1;

    return times;
}

char **my_tabsplit(char **tab, int begin, int end)
{
    int len = end - begin;

    char **result = malloc(sizeof(char *) * (len + 1));

    for (int i = 0; i < len; i++)
        result[i] = my_strdup(tab[begin + i]);

    result[len] = NULL;

    return result;
}

char **my_tabswap(char **tab, int index1, int index2)
{
    int size = my_tablen(tab);
    char **new_tab = (char **) malloc(size * sizeof(char *));

    for (int i = 0; i < size; i++) {
        if (i == index1) {
            new_tab[i] = my_strdup(tab[index2]);
        }
        if (i == index2) {
            new_tab[i] = my_strdup(tab[index1]);
        }
        if (i != index1 && i != index2){
            new_tab[i] = my_strdup(tab[i]);
        }
    }

    return new_tab;
}
