/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main.c
*/

#include "../include/my.h"

int create_socket(int a, struct_t *ftp)
{
    ftp->sock = socket(AF_INET, SOCK_STREAM, 0);
    if (ftp->sock == -1)
        return (84);
    ftp->server.sin_addr.s_addr = htonl(INADDR_ANY);
    ftp->server.sin_port = htons(a);
    ftp->server.sin_family = AF_INET;
    if (bind(ftp->sock, (struct sockaddr *) &ftp->server,
            sizeof(struct sockaddr_in)) == -1) {
        return (84);
    }
    if (listen(ftp->sock, 10) == -1)
        return (84);
    return (ftp->sock);
}

int loop_server(struct_t *ftp)
{
    int launch;
    struct sockaddr_in client;
    unsigned int size = sizeof(client);
    int a = 0;

    while (1) {
        launch = accept(ftp->sock, (struct sockaddr *) &client, &size);
        ftp->pid = fork();
        if (ftp->pid == 0) {
            close(ftp->sock);
            if (a == 0) {
                dprintf(launch, "220\r\n");
                a = 1;
            }
            if (command(launch, ftp) == 84)
                return (84);
            close(launch);
        }
    }
    return (0);
}

int ftp(int a, struct_t *ftp)
{
    if (create_socket(a, ftp) != 84) {
        loop_server(ftp);
    }
    return (0);
}

void print_help(void)
{
    printf("%s\n", "USAGE: ./myftp port path");
    printf("\t%s", "port is the port number");
    printf("%s\n", "on which the server socket listens");
    printf("\t%s", "path is the path to the home director");
    printf("%s\n", "y for the Anonymous user");
}

int main(int ac, char **av)
{
    struct_t *ftp1 = malloc(1000);

    if (ac == 1) {
        printf("%s\n", "Need port and path");
        return (84);
    }
    if (av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == 'e'
        && av[1][3] == 'l' && av[1][4] == 'p')
        print_help();
    if (ac == 3) {
        if (check_directory(av[2]) == 84)
            return (84);
        ftp1->path = av[2];
        ftp(atoi(av[1]), ftp1);
    }
    else
        return (84);
    return (0);
}
