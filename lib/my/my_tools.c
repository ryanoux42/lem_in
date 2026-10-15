/*
** EPITECH PROJECT, 2022
** my_tools
** File description:
** library
*/
#include "../../include/libmy.h"

void free_tab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++)
        free(tab[i]);
    free(tab);
}

void pass(void)
{

}

void space(void)
{
    my_putchar(' ');
}

void back(void)
{
    my_putchar('\n');
}

char *my_stdinstr(void)
{
    char *contents = NULL;
    size_t len = 0;
    ssize_t read;
    char *str = malloc(sizeof(char));

    str[0] = '\0';
    while ((read = getline(&contents, &len, stdin)) != -1)
        str = my_strfuse(str, contents);

    return str;
}
