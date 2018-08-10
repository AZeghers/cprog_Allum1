##
## Makefile for  in /home/zegher_a/bin
## 
## Made by alexis zeghers
## Login   <zegher_a@epitech.net>
## 
## Started on  Fri Nov 20 13:42:25 2015 alexis zeghers
## Last update Fri Feb 19 18:16:25 2016 alexis zeghers
##

CC	=	gcc

SRCS	=	allum.c \
		get_next_line.c \
		getnbr.c \
		display.c \
		player.c \
		ai.c

OBJS	=	$(SRCS:.c=.o)

CFLAGS	+=	-W -Wall -Wextra -ansi -pedantic

NAME	=	allum1

all	:	$(NAME)

$(NAME)	:	$(OBJS)
		$(CC) -o $(NAME) $(SRCS)

clean	:
		rm -f $(OBJS)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
