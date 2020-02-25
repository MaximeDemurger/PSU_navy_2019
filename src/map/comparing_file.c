/*
** EPITECH PROJECT, 2020
** comparing file
** File description:
** compare
*/

int compare_letter(char a, char b, int boatSize)
{
    int ascii_table = 0;

    if (a < b) {
        while (a < b) {
            a++;
            ascii_table++;
        }
        if (ascii_table + 1 != boatSize)
            return 84;
    } else if (a > b) {
        while (a > b) {
            b++;
            ascii_table++;
        }
        if (ascii_table + 1 != boatSize)
            return 84;
    }
    return 0;
}

int compare_nbr(int first, int second, int boatSize)
{
    int count = 1;

    if (first < second) {
        while (first < second) {
            count++;
            first++;
        }
        if (count != boatSize)
            return 84;
    } else if (first > second) {
        while (first > second) {
            count++;
            second++;
        }
        if (count != boatSize)
            return 84;
    }
    return 0;
}

int compare_pos(char **tab, int boatSize)
{
    int first = tab[1][1] - 48;
    int second = tab[2][1] - 48;

    if (!tab)
        return 84;
    if ((tab[1][0] == tab[2][0]) && first != second) {
        if (compare_nbr(first, second, boatSize) == 84)
            return 84;
    } else if ((tab[1][0] != tab[2][0]) && first == second) {
        if (compare_letter(tab[1][0], tab[2][0], boatSize) == 84)
            return 84;
    } else if ((tab[1][0] == tab[2][0]) && (first == second))
        return 84;
    return 0;
}