/*
** EPITECH PROJECT, 2023
** my_str_to_word_array
** File description:
** lib
*/
#include "../include/libmy.h"

static int nb_word(char const *str, char del)
{
    int i = 0;
    int count = 0;

    while (str[i] != '\0') {
        if (str[i] != del && str[i] != '\t' &&
            (str[i + 1] == del || str[i + 1] == '\t' || str[i + 1] == '\0')) {
            count += 1;
        }
        i += 1;
    }
    return count;
}

static int nb_letter(char const *str, char del, int index)
{
    int i = index;
    int count = 0;

    while (str[i] != del && str[i] != '\t' && str[i] != '\0') {
        count += 1;
        i += 1;
    }
    return count;
}

static char *file_line(char const *str, char del, int *index)
{
    int j = 0;
    char *line = malloc(sizeof(char) * (nb_letter(str, del, (*index)) + 1));

    if (line == NULL)
        return NULL;
    while (str[(*index)] != del && str[(*index)] != '\t' &&
        str[(*index)] != '\0') {
        line[j] = str[(*index)];
        (*index) += 1;
        j += 1;
    }
    line[j] = '\0';
    return line;
}

char **my_str_to_word_array(char const *str, char del)
{
    int i = 0;
    int index = 0;
    int total = nb_word(str, del);
    char ** tab = malloc(sizeof(char*) * (total + 1));

    if (tab == NULL)
        return NULL;
    while (i < total) {
        while (str[index] == del || str[index] == '\t') {
            index += 1;
        }
        tab[i] = file_line(str, del, &index);
        if (tab[i] == NULL)
            return NULL;
        i += 1;
    }
    tab[total] = NULL;
    return tab;
}
