/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include <stdlib.h>
#include <unistd.h>
#include "../include/get_next_line.h"
#include <fcntl.h>
#include <dirent.h>
#include "../include/my.h"

int check_directory(char *dir)
{
    DIR *fd;

    fd = opendir(dir);
    if (fd == NULL)
        return (84);
    closedir(fd);
    return (0);
}

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i = i + 1;
    return (i);
}

char *my_realloc(char *str, int size)
{
    int a = 0;
    char *str2;
    int count = my_strlen(str) + 1;

    str2 = malloc(sizeof(char) * (size + count));
    if (str2 == NULL)
        return (NULL);
    while (str[a] != '\0') {
        str2[a] = str[a];
        a = a + 1;
    }
    free(str);
    return (str2);
}

char take_car(int fd)
{
    char carac;
    static char buff[READ_SIZE];
    static int done = 0;
    static int a;

    if (done == a) {
        if ((a = read(fd, buff, READ_SIZE)) < 1)
            return (a);
        buff[a] = '\0';
        done = 0;
    }
    carac = buff[done];
    done = done + 1;
    return (carac);
}

char *get_next_line(const int fd)
{
    char *str;
    int i = 0;
    char get = take_car(fd);

    str = malloc(sizeof(char *) * 2);
    if (str == NULL || fd < 0)
        return (NULL);
    if (get == 0)
        return (NULL);
    while (get != '\n' && get != '\0') {
        str[i] = get;
        if (!(str = my_realloc(str, 2)))
            return (NULL);
        get = take_car(fd);
        if (get == 1)
            return (NULL);
        i = i + 1;
    }
    return (str);
}
