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

char *get_next_line(int fd);
char **map_navy(void);
char **check_files(int fd);
char *convert_to_string(int nb);
char *my_revstr(char const *str);
char **add_boat_pos(char **map, char **av);
int navy(char **av);
char **my_str_to_word_array(char const *str, char separator);
int my_strlen(char const *str);
int check_file_line(char **tab, int boatSize);
char *my_strdup(char const *str);

#endif //PSU_NAVY_2019_NAVY_H
