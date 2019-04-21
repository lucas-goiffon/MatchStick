/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main file for my_ls project
*/

#include "../include/matchstick.h"

int errors_management(int ac, char **av)
{
    int r = 0;

    if (ac != 3) {
        write(2, "Wrong number of arguments.\n", 27);
        r = 84;
    } else if (my_getnbr(av[1]) <= 1 || my_getnbr(av[1]) >= 100 ||
    my_getnbr(av[2]) < 1) {
        write(2, "Invalid map size or number of matches.\n", 39);
        r = 84;
    }
    return (r);
}

void end(info_t *info, int *r)
{
    if (info->characters != -1) {
        if (info->player == 1) {
            my_printf("You lost, too bad...\n");
            *r = 2;
        } else {
            my_printf("I lost... snif... but I'll get you next time!!\n");
            *r = 1;
        }
    } else
        *r = 0;
}

int main(int ac, char **av)
{
    info_t *info = malloc(sizeof(info_t));
    int r = 0;

    if (info == NULL || errors_management(ac, av) == 84)
        return (84);
    srandom(time(NULL));
    info->level = 2;
    info->characters = 0;
    set_board(info, av);
    set_nb_sticks(info, av);
    info->player = 1;
    for (int i = 0; i < (info->lines + 2); i = i + 1)
        my_printf(info->board[i]);
    turns(info);
    destroy_board(info->board);
    free(info->sticks);
    end(info, &r);
    free(info);
    return (r);
}