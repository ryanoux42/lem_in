/*
** EPITECH PROJECT, 2022
** my_strn
** File description:
** library
*/
#include "../../include/libmy.h"

char *my_strncpy(char *dest, const char *src, int n)
{
    int i;
    for (i = 0; i < n && src[i] != '\0'; i++)
        dest[i] = src[i];

    for (; i < n; i++)
        dest[i] = '\0';

    return dest;
}

int my_strncmp(const char* s1, const char* s2, size_t n)
{
    for (size_t i = 0; i < n; i++)
        if (s1[i] != s2[i])
            return s1[i] - s2[i];

    return 0;
}

char *my_strndup(const char *src, int n)
{
    size_t len = n + 1;

    char *dest = malloc(sizeof(char) * len);

    my_strncpy(dest, src, n);

    return dest;
}

int my_strnlen(char const *str, int index, char delim)
{
    int i = index;

    while (str[i] != delim && str[i] != '\0')
        i++;

    return (i);
}
