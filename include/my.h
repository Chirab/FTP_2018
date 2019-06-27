/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** ly.h
*/

#ifndef MY_H_
    #define MY_H_

#include <stdio.h>
#include <sys/un.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>

typedef struct struct_s
{
    struct sockaddr_in server;
    pid_t pid;
    int sock;
    char *path;
} struct_t;

typedef struct var_s
{
    int a;
    int b;
    int c;
} var_t;

void initvar(var_t *tmp);
void print_help(void);
int ftp(int a, struct_t *ftp);
int create_socket(int a, struct_t *ftp);
int loop_server(struct_t *ftp);
int gest_command(int launch);
int command(int launch, struct_t *ftp);
char **my_str_to_wordtab1(char *str, char sep);
char **initialize(char **tab);
int len_malloc(char *str, int a);
int command_base5(int launch, char **tab);
int check_directory(char *dir);
#endif /* !MY_H_ */
