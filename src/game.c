/*
** EPITECH PROJECT, 2019
** epitech
** File description:
** game
*/

#include "../include/matchstick.h"

char *read_asks(info_t *info)
{
    char *str;
    size_t bufsize = 3;

    str = (char *)malloc((bufsize) * sizeof(char));
    info->characters = getline(&str, &bufsize, stdin);
    return (str);
}

int ask_for_line(info_t *info)
{
    char *str;
    int enter_line = 0;
    int error = 0;

    my_printf("Line: ");
    str = read_asks(info);
    if (info->characters != -1) {
        error = is_digits_line(str, &enter_line, info);
        if (error == 0) {
            enter_line = my_getnbr(str);
            free(str);
            lines_errors(info, &enter_line);
        }
    }
    return (enter_line);
}

int ask_for_matches(info_t *info, int *enter_matches)
{
    char *str;
    int enter_line = ask_for_line(info);
    int error = 0;

    if (info->characters != -1) {
        my_printf("Matches: ");
        str = read_asks(info);
    } if (info->characters != -1) {
        error = is_digits_matches(str, &enter_line, info, enter_matches);
        if (error == 0) {
            *enter_matches = my_getnbr(str);
            free(str);
            matches_errors(info, enter_matches, &enter_line);
        }
    }
    return (enter_line);
}

void update_map(info_t *info, int enter_line, int enter_matches)
{
    info->nb_sticks = info->nb_sticks - enter_matches;
    for (int i = info->sticks[enter_line] - enter_matches;
    info->sticks[enter_line] > i; info->sticks[enter_line] =
    info->sticks[enter_line] - 1)
    info->board[enter_line][info->sticks[enter_line] +
    (info->lines - enter_line)] = ' ';
}

void turns(info_t *info)
{
    int enter_line = 0;
    int enter_matches = 0;

    if (info->player == 1) {
        my_printf("\nYour turn:\n");
        enter_line = ask_for_matches(info, &enter_matches);
        if (info->characters != -1) {
            my_printf("Player removed %d match(es) from line %d\n",
            enter_matches, enter_line);
            update_map(info, enter_line, enter_matches);
        }
    } else
        ai_turn_medium(info);
    for (int i = 0; i < (info->lines + 2) && info->characters != -1;
    i = i + 1)
        my_printf(info->board[i]);
    if (info->nb_sticks > 0 && info->characters != -1) {
        info->player = info->player * -1;
        turns(info);
    }
}