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
int check_files(char **av);
int navy(char **av);
char **my_str_to_word_array(char const *str, char separator);
int my_strlen(char const *str);
int check_file_line(char **tab, int boatSize);

#endif //PSU_NAVY_2019_NAVY_H
