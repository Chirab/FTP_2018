/*
** EPITECH PROJECT, 2019
** client_1
** File description:
** client_1
*/

#include "../include/my.h"
#include "../include/get_next_line.h"

int command_base(int launch, char **tab)
{
    if (strncmp(tab[0], "USER ", 5) == 0) {
        dprintf(launch, "331\r\n");
        return (0);
    }
    if (strcmp(tab[0], "PASS \r") == 0) {
        dprintf(launch, "230\r\n");
        return (0);
    }
    if (strcmp(tab[0], "QUIT\r") == 0) {
        dprintf(launch, "221\r\n");
        shutdown(launch, SHUT_RDWR);
        return (0);
    }
    return (1);
}

int command_base3(int launch, char **tab, struct_t *ftp)
{
    if (strcmp(tab[0], "HELP\r") == 0) {
        dprintf(launch, "214\r\n");
        return (0);
    }
    if (strcmp(tab[0], "PWD\r") == 0) {
        dprintf(launch, "257 Path Name -> %s\r\n", ftp->path);
        return (0);
    }
    if (strcmp(tab[0], "CDUP\r") == 0) {
        dprintf(launch, "200 Path Name -> %s\r\n", ftp->path);
        return (0);
    }
    return (1);
}

int command_base4(int launch, char **tab)
{
    char *str = malloc(100);
    char *tmp = malloc(100);

    if (strcmp(tab[0], "NOOP\r") == 0) {
        dprintf(launch, "200\r\n");
        return (0);
    }
    if (strncmp(tab[0], "LIST ", 5) == 0) {
        dprintf(launch, "150\r\n");
        tmp = strcpy(tmp, &tab[0][5]);
        str = strcpy(str, "ls ");
        strcat(str, tmp);
        system(str);
        return (0);
    }
    return (1);
}

int command_base2(int launch, char **tab)
{
    char *str = malloc(100);
    char *tp = malloc(100);
    char *cwd = malloc(sizeof(char) * 100);

    if (strncmp(tab[0], "DELE ", 4) == 0) {
        dprintf(launch, "250\r\n");
        str = strcpy(str, &tab[0][5]);
        tp = strcpy(tp, "rm -rf ");
        strcat(tp, str);
        system(tp);
        return (0);
    }
    if (strncmp(tab[0], "CWD ", 3) == 0) {
        dprintf(launch, "250\r\n");
        strcpy(cwd, &tab[0][4]);
        chdir(cwd);
        return (0);
    }
    return (1);
}

int command(int launch, struct_t *ftp)
{
    char *buffer = malloc(sizeof(buffer) * 1000);
    char **tab;

    while (1) {
        buffer = get_next_line(launch);
        if (buffer == NULL)
            return (84);
        tab = my_str_to_wordtab1(buffer, '\n');
        if (tab == NULL)
            return (84);
        if (command_base2(launch, tab) != 0
            && command_base(launch, tab) != 0
            && command_base3(launch, tab, ftp) != 0
            && command_base4(launch, tab) != 0
            && command_base5(launch, tab) != 0)
            dprintf(launch, "500\r\n");
    }
    return (0);
}
