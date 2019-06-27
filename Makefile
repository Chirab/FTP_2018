##
## EPITECH PROJECT, 2019
## makfile
## File description:
## makefile
##

CC      =	gcc

RM      =	rm -rf

CFLAGS	=	-Wall -Wextra -Werror

NAME    =	myftp

SRCS	=	src/main.c	\
		src/client_1.c	\
		src/get_next_line.c	\
		src/strtowordtab.c

OBJS	=	$(SRCS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS)

clean:
		$(RM) $(OBJS)

fclean: clean

		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
