/*
** EPITECH PROJECT, 2022
** my_str6.c
** File description:
** my_str6
*/
#include "../../include/libmy.h"

char *my_isolatechars(char *line, char *chars)
{
    int len = my_strlen(line), k = 0, found = 0;
    for (int j = 0; chars[j]; j++)
        for (int i = 0; line[i]; i++)
            len += (line[i] == chars[j]) ? 2 : 0;

    char *str = malloc(sizeof(char) * (len + 1));
    for (int i = 0; line[i]; i++, k++) {
        for (int j = 0; chars[j]; j++)
            found += (line[i] == chars[j]) ? 1 : 0;
        if (found) {
            str[k] = ' ';
            str[k + 1] = line[i];
            str[k + 2] = ' ';
            k += 2;
        } else {
            str[k] = line[i];
        } found = 0;
    } str[len] = '\0';

    return str;
}
