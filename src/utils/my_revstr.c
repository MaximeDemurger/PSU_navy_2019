/*
** EPITECH PROJECT, 2019
** revstr
** File description:
** revstr
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i])
        i++;
    return i;
}

char *my_revstr(char *str)
{
    int i = 0;
    int len = my_strlen(str) - 1;
    char c;

    while (i < len) {
        c = str[i];
        str[i] = str[len];
        str[len] = c;
        i++;
        len--;
    }
    return str;
}
