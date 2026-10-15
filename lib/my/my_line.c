/*
** EPITECH PROJECT, 2021
** my_parser
** File description:
** library
*/
#include "../../include/libmy.h"

int my_wordscount(char *str)
{
    int count = 0;
    int in_word = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') {
            in_word = 0;
        }

        if (!(str[i] == ' ' || !str[i] == '\t' || !str[i] == '\n')
            && !in_word) {
            in_word = 1;
            count++;
        }
    }

    return count;
}

int my_skipline(char *str, int index, char *chars)
{
    int j = 0;

    for (int i = index; str[i]; i++, j = 0) {
        while (chars[j] != '\0' && str[i] != chars[j])
            j++;
        if (chars[j])
            return i;
    }
    return my_strlen(str);
}

// char **my_getwords(char *str)
// {
//     int num_words = my_wordscount(str);

//     char **words = malloc(sizeof(char *) * (num_words + 1));
//     words[0] = NULL;

//     char *word = strtok(str, " \t\n");

//     for (int i = 0; word != NULL; i++) {
//         words[i] = word;
//         word = strtok(NULL, " \t\n");
//     }

//     words[num_words] = NULL;

//     return words;
// }
