/*
** EPITECH PROJECT, 2019
** epitech
** File description:
** medium_algos
*/

#include "../include/matchstick.h"

void take_higher_than_max(int *enter_matches, info_t *info)
{
    while (*enter_matches > info->max_take)
        *enter_matches = *enter_matches - 1;
}

void take_smaller_than_max(int *enter_matches, info_t *info, int enter_line)
{
    *enter_matches = 1;
    while ((info->sticks[enter_line] - *enter_matches) > 1)
        *enter_matches = *enter_matches + 1;
}

int two_lasts_rev(int *enter_matches, info_t *info, int enter_line,
int test_line)
{
    test_line = test_line + 1;
    while (info->sticks[test_line] < 1)
        test_line = test_line + 1;
    if (info->sticks[test_line] == 1) {
        test_line = enter_line;
        *enter_matches = info->sticks[enter_line];
    } else {
        *enter_matches = 1;
        test_line = enter_line;
    }
    return (test_line);
}

int two_lasts_lines(int *enter_matches, info_t *info, int enter_line)
{
    int test_line = enter_line;

    if (info->sticks[enter_line] == 1) {
        test_line = test_line + 1;
        while (info->sticks[test_line] < 1)
            test_line = test_line + 1;
        if (info->sticks[test_line] <= info->max_take)
            *enter_matches = info->sticks[test_line];
        else
            *enter_matches = 1;
    } else if (info->sticks[enter_line] <= info->max_take) {
        test_line = two_lasts_rev(enter_matches, info, enter_line, test_line);
    } else
        *enter_matches = 1;
    enter_line = test_line;
    return (enter_line);
}