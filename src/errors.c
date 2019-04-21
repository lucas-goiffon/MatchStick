/*
** EPITECH PROJECT, 2019
** epitech
** File description:
** errors
*/

#include "../include/matchstick.h"

int is_digits_line(char *str, int *enter_line, info_t *info)
{
    int error = 0;

    for (int i = 0; str[i] != '\n' && str[i] != '\0' && error == 0;
    i = i + 1) {
        if (str[i] < 48 || str[i] > 57) {
            my_printf("Error: invalid input (positive number expected)\n");
            error = 1;
        }
    }
    if (error == 1)
        *enter_line = ask_for_line(info);
    return (error);
}

int is_digits_matches(char *str, int *enter_line, info_t *info,
int *enter_matches)
{
    int error = 0;

    for (int i = 0; str[i] != '\n' && str[i] != '\0' && error == 0;
    i = i + 1) {
        if (str[i] < 48 || str[i] > 57) {
            my_printf("Error: invalid input (positive number expected)\n");
            error = 1;
        }
    }
    if (error == 1)
        *enter_line = ask_for_matches(info, enter_matches);
    return (error);
}

void lines_errors(info_t *info, int *enter_line)
{
    int el = *enter_line;

    if (*enter_line < 1 || *enter_line > info->lines) {
        my_printf("Error: this line is out of range\n");
        *enter_line = ask_for_line(info);
    } else if (info->sticks[el] < 1) {
        my_printf("Error: not enough matches on this line\n");
        *enter_line = ask_for_line(info);
    }
}

void matches_errors_two(info_t *info, int *enter_matches, int *enter_line)
{
    int el = *enter_line;

    if (*enter_matches > info->sticks[el]) {
        my_printf("Error: not enough matches on this line\n");
        *enter_line = ask_for_matches(info, enter_matches);
    }
}

void matches_errors(info_t *info, int *enter_matches, int *enter_line)
{
    if (*enter_matches > info->max_take) {
        my_printf("Error: you cannot remove more than %d matches per turn\n",
        info->max_take);
        *enter_line = ask_for_matches(info, enter_matches);
    } else if (*enter_matches < 1) {
        my_printf("Error: you have to remove at least one match\n");
        *enter_line = ask_for_matches(info, enter_matches);
    } else
        matches_errors_two(info, enter_matches, enter_line);
}