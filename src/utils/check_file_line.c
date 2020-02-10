/*
** EPITECH PROJECT, 2019
** PSU_navy_2019
** File description:
** check_file_line.c
*/

int check_file_line(char **tab, int boatSize)
{
    int first = tab[1][1] - 48;
    int second = tab[2][1] - 48;

    if (boatSize < 2 || boatSize > 5)
        return 84;
    if (tab[1][0] < 'A' || tab[1][0] > 'H' || tab[2][0] < 'A' || tab[2][0] > 'H'
    || first < 1 || first > 8 || second < 1 || second > 8)
        return 84;
    return 0;
}