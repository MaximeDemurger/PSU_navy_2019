/*
** EPITECH PROJECT, 2019
** get_next_line
** File description:
** 2018
*/

#include <stdlib.h>
#include <zconf.h>
#include "navy.h"

char *my_realloc(char *ptr, size_t size)
{
    char *temp = ptr;
    int i = 0;

    ptr = malloc(sizeof(char) * size);
    if (ptr == NULL)
        return NULL;
    while (temp[i] != '\0') {
        ptr[i] = temp[i];
        i++;
    }
    free(temp);
    return ptr;
}

char get_char(const int fd)
{
    static char buff[READ_SIZE];
    static char *ptr_buff;
    static int len = 0;
    char c;

    if (len == 0) {
        len = read(fd, buff, READ_SIZE);
        ptr_buff = (char *)buff;
        if (len == 0)
            return 0;
    }
    c = *ptr_buff;
    ptr_buff++;
    len--;
    return c;
}

char *get_next_line(int fd)
{
    char c = get_char(fd);
    char *str = malloc(sizeof(char) *(READ_SIZE + 1));
    int len = 0;

    if (str == NULL)
        return NULL;
    while (c != '\n' && c != '\0') {
        str[len] = c;
        c = get_char(fd);
        len++;
        if (len % (READ_SIZE+1) == 0)
            str = my_realloc(str, len + READ_SIZE + 1);
    }
    str[len] = '\0';
    if (c == 0 && str[0] == 0)
        return 0;
    return str;
}
