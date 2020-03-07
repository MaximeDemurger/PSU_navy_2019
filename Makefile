##
## EPITECH PROJECT, 2020
## navy
## File description:
## makefile
##

NAME	= navy

CC	= gcc

RM	= rm -f

SRCS	= ./src/game/find_position.c \
	  ./src/game/game_loop.c \
	  ./src/game/player_move.c \
	  ./src/game/waiting_for_player.c \
	  ./src/main.c \
	  ./src/map/add_boat_pos.c \
	  ./src/map/comparing_file.c \
	  ./src/map/map.c \
	  ./src/map/map_navy.c \
	  ./src/navy.c \
	  ./src/signal/hit_or_not.c \
	  ./src/signal/signal_connexion.c \
	  ./src/signal/signal_game.c \
	  ./src/utils/check_file_line.c \
	  ./src/utils/check_files.c \
	  ./src/utils/convert.c \
	  ./src/utils/descriptor.c \
	  ./src/utils/lib/get_next_line.c \
	  ./src/utils/lib/my_atoi.c \
	  ./src/utils/lib/my_char_isalpha.c \
	  ./src/utils/lib/my_char_isnum.c \
	  ./src/utils/lib/my_printf.c \
	  ./src/utils/lib/my_put_nbr.c \
	  ./src/utils/lib/my_putchar.c \
	  ./src/utils/lib/my_puterror.c \
	  ./src/utils/lib/my_putstr.c \
	  ./src/utils/lib/my_revstr.c \
	  ./src/utils/lib/my_str_to_word_array.c \
	  ./src/utils/lib/my_strdup.c \
	  ./src/win/win_player.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/
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
