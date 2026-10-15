/*
** EPITECH PROJECT, 2022
** my_strrr
** File description:
** library
*/
#include "../../include/libmy.h"

int my_strocc(char *str, char *sub)
{
    int count = 0;
    int substring_length = my_strlen(sub);

    for (int i = 0; str[i] != '\0'; i++) {
        if (my_strncmp(&str[i], sub, substring_length) == 0) {
            count++;
            i += substring_length - 1;
        }
    }

    return count;
}

int my_charocc(char *str, char c)
{
    int n = 0;
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == c)
            n += 1;
    return n;
}

int my_onlycontains(char *str, char *chars)
{
    int len = my_strlen(str);
    int occurences = 0;

    for (int i = 0; chars[i] != '\0'; i++)
        occurences += my_charocc(str, chars[i]);

    return (len == occurences) ? 1 : 0;
}

int my_strcontains(char *str, char *chars)
{
    int contains = -1;

    for (int i = 0; chars[i]; i++)
        for (int j = 0; str[j]; j++)
            contains += (str[j] == chars[i]) ? i : 0;

    return contains;
}

int my_isoneof(char c, char *chars, int len)
{
    for (int i = 0; i < len; i++)
        if (chars[i] == c)
            return 1;

    return 0;
}
