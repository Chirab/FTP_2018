/*
** EPITECH PROJECT, 2018
** my_str_to_word_tab
** File description:
** my_str_to_word_tab
*/

#include "../include/my.h"
#include <stdlib.h>
#include <unistd.h>

int command_base5(int launch, char **tab)
{
    if (strcmp(tab[0], "PASV\r") == 0) {
        dprintf(launch, "227\r\n");
        return (0);
    }
    if (strncmp(tab[0], "PORT ", 4) == 0) {
        dprintf(launch, "200\r\n");
        return (0);
    }
    if (strncmp(tab[0], "STOR ", 4) == 0) {
        dprintf(launch, "150\r\n");
        return (0);
    }
    if (strncmp(tab[0], "RETR ", 4) == 0) {
        dprintf(launch, "150\r\n");
        return (0);
    }
    return (1);
}

void initvar(var_t *tmp)
{
    tmp->a = 0;
    tmp->b = 0;
    tmp->c = 0;
}

char **my_str_to_wordtab1(char *str, char sep)
{
    var_t *tmp = malloc(100);
    char **tab = 0;

    tab = initialize(tab);
    initvar(tmp);
    while (str[tmp->a] != '\0') {
        if (str[tmp->a] == sep || str[tmp->a] == '\t') {
            tmp->a++;
            while (str[tmp->a] == ' ' || str[tmp->a] == '\t')
                tmp->a++;
            tab[tmp->b++][tmp->c] = '\0';
            tmp->c = 0;
            tab[tmp->b] = malloc(len_malloc(str, tmp->a) * sizeof(char));
        }
        else
            tab[tmp->b][tmp->c++] = str[tmp->a++];
    }
    tab[tmp->b + 1] = NULL;
    return (tab);
}

char **initialize(char **tab)
{
    int i = 0;

    tab = malloc(10000);
    while (i < 1000) {
        tab[i] = malloc(1000 * sizeof(char *));
        i++;
    }
    if (tab == NULL)
        exit(EXIT_FAILURE);
    return (tab);
}

int len_malloc(char *str, int a)
{
    int len = 0;

    while (str[a] && str[a] != '\n') {
        len++;
        a++;
    }
    len++;
    return (len);
}