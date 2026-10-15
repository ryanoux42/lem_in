/*
** EPITECH PROJECT, 2022
** my_str
** File description:
** library
*/
#include "../../include/libmy.h"

char *my_strcat(char *dest, char const *src)
{
    int j = my_strlen(dest);
    int i = 0;

    while (src[i] != '\0') {
        dest[j + i] = src[i];
        i++;
    }

    dest[j + i] = '\0';
    return (dest);
}

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }

    dest[i] = '\0';
    return (dest);
}

int my_strcmp(char const *s1, char const *s2)
{
    if (my_strlen(s2) != my_strlen(s1))
        return 0;

    for (int i = 0; s1[i] != '\0'; i++)
        if (s1[i] != s2[i])
            return 0;

    return 1;
}

char *my_strdup(const char *src)
{
    size_t len = my_strlen(src) + 1;

    char *dest = malloc(sizeof(char) * len);

    my_strcpy(dest, src);

    return dest;
}

char *my_strfuse(char *src1, char const *src2)
{
    int len_src1 = 1;
    char *tmp = NULL;
    int i = 0;
    int j = 0;

    if (src1[0] != '\0')
        len_src1 = my_strlen(src1);
    tmp = malloc(sizeof(char) * (len_src1 + my_strlen(src2) + 1));
    for (; src1[i] != '\0'; i++)
        tmp[j + i] = src1[i];

    for (; src2[j] != '\0'; j++)
        tmp[j + i] = src2[j];

    tmp[j + i] = '\0';

    free(src1);
    return tmp;
}
