/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** navy.h
*/

#ifndef PSU_NAVY_2019_NAVY_H
#define PSU_NAVY_2019_NAVY_H

#ifndef READ_SIZE
#define READ_SIZE 1024
#endif

#include "struct.h"
#include <unistd.h>


/*src*/

int navy(int ac, char **av);
int serveur(utils_t *utils);
int enemy_connection(int argc, char **argv, utils_t *utils);

/*map*/
char **add_in_pos(char **tab, utils_t *utils, char **map);
char **map_navy(void);
char **add_boat_pos(char **map, char **av);
int check_positions_boats(int ac, char **av, int fd, utils_t *utils);
int print_map(utils_t *utils);
int compare_pos(char **tab, int boatSize);

/*utils*/
char **check_files(int fd);
char *convert_to_string(int nb);
int check_file_line(char **tab, int boatSize);

/*lib*/
char *my_revstr(char const *str);
int my_put_nbr(int nb);
int my_putstr(char const *str);
char *my_strdup(char const *str);
int my_strlen(char const *str);
char **my_str_to_word_array(char const *str, char separator);
char *get_next_line(int fd);
int my_putchar(char c);
int my_atoi(char const *stack);
int my_char_isalpha(char a);
int my_char_isnum(char a);
int my_printf(char const *str, ...);

/* game */
int game_loop(utils_t *utils, int ac);
int player_move(utils_t *utils);
int find_position(int *line, int *col);
int display_hit(int hit);
int send_touch(utils_t *utils);
int get_touch(void);
int check_hit(utils_t *utils, char *str);
int touch_board(utils_t *utils, int x, int y);
int waiting_for_player(utils_t *utils);
int hit_or_not(utils_t *utils, int x, int y);

/* Signal game */
int get_signal_usr1(void);
int send_signal(utils_t *utils, char *str);

#endif //PSU_NAVY_2019_NAVY_H
