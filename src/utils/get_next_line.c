/*
** EPITECH PROJECT, 2019
** get_next_line
** File description:
** 2018
*/

#include <stdlib.h>
#include <zconf.h>
#include "../../include/navy.h"

char *do_realloc(char *result, char *buffer, int size, int i)
{
    char *new_alloc = malloc(sizeof(char) * (my_strlen(result) + (size + 1)));
    int	j = 0;

    buffer[size] = '\0';
    result[i] = '\0';
    if (new_alloc == NULL)
        return (NULL);
    while (result[j] != '\0') {
        new_alloc[j] = result[j];
        j++;
    }
    free(result);
    return (new_alloc);
}

int j_egal_zero(int *size, char *buffer, int fd, int *j)
{
    if (buffer[*j] == '\n')
        *j += 1;
    if (*j == 0) {
        *size = read(fd, buffer, READ_SIZE);
        if (*size == -1 || *size == 0)
            return (84);
        buffer[*size] = '\0';
    }
    return (0);
}

int j_sup(int *size, char *buffer, int fd, int *j)
{
    *size = read(fd, buffer, READ_SIZE);
    if (*size == -1 || *size == 0)
        return (84);
    *j = 0;
    return (0);
}

char *get_next_line(int fd)
{
    static char	buffer[READ_SIZE + 1];
    char *result = malloc(sizeof(char) * (READ_SIZE + 1));
    static int	size = 0;
    static int j = 0;
    int	i = 0;

    j_egal_zero(&size, buffer, fd, &j);
    while (buffer[j] != '\n' && size != 0) {
        if (j >= size) {
            j_sup(&size, buffer, fd, &j);
            result = do_realloc(result, buffer, READ_SIZE, i);
        } else if (j < size)
            result[i++] = buffer[j++];
    }
    if (buffer[j] == '\0')
        return (NULL);
    result[i] = '\0';
    j++;
    return (result);
}
