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

/*src*/
int navy(char **av);

/*map*/
char **add_in_pos(char **tab, int boatSize, char **map);
char **map_navy(void);
char **add_boat_pos(char **map, char **av);

/*utils*/
char **check_files(int fd);
char *get_next_line(int fd);
char *convert_to_string(int nb);
char *my_revstr(char const *str);
char **my_str_to_word_array(char const *str, char separator);
int my_strlen(char const *str);
int check_file_line(char **tab, int boatSize);
char *my_strdup(char const *str);

#endif //PSU_NAVY_2019_NAVY_H
