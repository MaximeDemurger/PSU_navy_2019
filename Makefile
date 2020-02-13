##
## EPITECH PROJECT, 2020
## makefile
## File description:
## makefile
##

NAME	= navy

CC	= gcc

RM	= rm -f

SRCS	= ./src/main.c \
	  ./src/map/add_boat_pos.c \
	  ./src/map/map.c \
	  ./src/map/map_navy.c \
	  ./src/navy.c \
	  ./src/utils/check_file_line.c \
	  ./src/utils/check_files.c \
	  ./src/utils/convert.c \
	  ./src/utils/get_next_line.c \
	  ./src/utils/my_atoi.c \
	  ./src/utils/my_revstr.c \
	  ./src/utils/my_str_to_word_array.c \
	  ./src/utils/my_strdup.c

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
