/*
** EPITECH PROJECT, 2019
** epitech
** File description:
** ai_player_medium
*/

#include "../include/matchstick.h"

int generate_line_medium(info_t *info)
{
    int enter_line = 1;

    while (info->sticks[enter_line] < 1)
        enter_line = enter_line + 1;
    return (enter_line);
}

int is_last_line(info_t *info)
{
    int last_line = 0;

    for (int i = 1; i <= info->lines; i = i + 1) {
        if (info->sticks[i] >= 1)
            last_line = last_line + 1;
    }
    return (last_line);
}

int generate_matches_medium(info_t *info, int *enter_matches)
{
    int enter_line = generate_line_medium(info);

    if (is_last_line(info) == 1 && info->sticks[enter_line] > 1) {
        if ((info->sticks[enter_line] - info->max_take) == 1)
            *enter_matches = info->max_take;
        else if ((info->sticks[enter_line] - info->max_take) > 1) {
            *enter_matches = (info->sticks[enter_line] - info->max_take) - 1;
            take_higher_than_max(enter_matches, info);
        } else
            take_smaller_than_max(enter_matches, info, enter_line);
    } else if (is_last_line(info) == 2)
        enter_line = two_lasts_lines(enter_matches, info, enter_line);
    else {
        *enter_matches = info->sticks[enter_line];
        if (*enter_matches > info->max_take)
            *enter_matches = info->max_take;
    }
    return (enter_line);
}

void ai_turn_medium(info_t *info)
{
    int enter_matches = 0;
    int enter_line = generate_matches_medium(info, &enter_matches);

    my_printf("\nAI's turn...\n");
    my_printf("AI removed %d match(es) from line %d\n", enter_matches,
    enter_line);
    update_map(info, enter_line, enter_matches);
}