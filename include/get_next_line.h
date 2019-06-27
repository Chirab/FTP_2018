/*
** EPITECH PROJECT, 2018
** .h
** File description:
** .h
*/

#ifndef GET_NEXT_LINE_
# define GET_NEXT_LINE_

#ifndef READ_SIZE
# define READ_SIZE 1
#endif /* !READ_SIZE */

char *my_realloc(char *str, int size);
char take_car(const int fd);
char *get_next_line(int const fd);

#endif /*!GET_NEXT_LINE_ */
