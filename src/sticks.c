/*
** EPITECH PROJECT, 2019
** epitech
** File description:
** sticks
*/

#include "../include/matchstick.h"

void set_nb_sticks(info_t *info, char **av)
{
    int i = 0;

    info->nb_sticks = 1;
    info->sticks = malloc(sizeof(int) * (info->lines + 2));
    while (i < info->lines + 1) {
        info->sticks[i] = i * 2 - 1;
        info->nb_sticks = info->nb_sticks + (i * 2 - 1);
        i = i + 1;
    }
    info->max_take = my_getnbr(av[2]);
}