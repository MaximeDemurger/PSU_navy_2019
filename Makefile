##
## EPITECH PROJECT, 2020
## makefile
## File description:
## makefile
##

NAME	= navy

CC	= gcc

RM	= rm -f

SRCS	= 	$(wildcard ./src/*.c) \
			$(wildcard ./src/*/*.c) \
			$(wildcard ./src/utils/*/*.c) \

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/ -g
CFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
