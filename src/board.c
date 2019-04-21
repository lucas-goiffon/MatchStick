/*
** EPITECH PROJECT, 2019
** epitech
** File description:
** board
*/

#include "../include/matchstick.h"

void set_sticks(int y, int lines, char *str)
{
    int i = 1;

    for (int x = 0; x < lines - y; x = x + 1) {
        str[i] = ' ';
        i = i + 1;
    }
    for (int x = 0; x < y * 2 - 1; x = x + 1) {
        str[i] = '|';
        i = i + 1;
    }
    for (int x = 0; x < lines - y; x = x + 1) {
        str[i] = ' ';
        i = i + 1;
    }
}

char *set_board_line(int y, int lines)
{
    char *str = malloc(sizeof(char) * (lines * 2 + 3));
    int i = 1;

    fill_str(str, (lines * 2 + 3));
    if (y == 0 || y == lines + 1) {
        for (int x = 0; x < (lines * 2 + 1); x = x + 1)
            str[x] = '*';
    } else {
        set_sticks(y, lines, str);
    }
    str[0] = '*';
    str[lines * 2] = '*';
    str[lines * 2 + 1] = '\n';
    return (str);
}

void set_board(info_t *info, char **av)
{
    info->lines = my_getnbr(av[1]);
    info->board = malloc(sizeof(char *) * (info->lines + 3));
    info->nb_sticks = 0;
    for (int y = 0; y < (info->lines + 2); y = y + 1)
        info->board[y] = set_board_line(y, info->lines);
    info->board[info->lines + 2] = NULL;
}

void destroy_board(char **board)
{
    for (int y = 0; board[y] != NULL; y = y + 1)
        free(board[y]);
    free(board);
}