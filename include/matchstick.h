/*
** EPITECH PROJECT, 2019
** epitech
** File description:
** matchstick
*/

#ifndef MATCHSTICK_H
#define MATCHSTICK_H

#include "../lib/my/mylib.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


typedef struct info_t info_t;
struct info_t {
    char **board;
    int lines;
    int nb_sticks;
    int max_take;
    int *sticks;
    int player;
    int level;
    size_t characters;
};

/* src/main.c */
int errors_management(int ac, char **av);
void end(info_t *info, int *r);

/* src/board.c */
void set_sticks(int y, int lines, char *str);
char *set_board_line(int y, int lines);
void set_board(info_t *info, char **av);
void destroy_board(char **board);

/* src/sticks.c */
void set_nb_sticks(info_t *info, char **av);

/* src/game.c */
char *read_asks(info_t *info);
int ask_for_line(info_t *info);
int ask_for_matches(info_t *info, int *enter_matches);
void update_map(info_t *info, int enter_line, int enter_matches);
void turns(info_t *info);

/* src/ai_player_medium.c */
int generate_line_medium(info_t *info);
int is_last_line(info_t *info);
int generate_matches_medium(info_t *info, int *enter_matches);
void ai_turn_medium(info_t *info);

/* src/medium_algos.c */
void take_higher_than_max(int *enter_matches, info_t *info);
void take_smaller_than_max(int *enter_matches, info_t *info, int enter_line);
int two_lasts_rev(int *enter_matches, info_t *info, int enter_line,
int test_line);
int two_lasts_lines(int *enter_matches, info_t *info, int enter_line);

/* src/errors.c */
int is_digits_line(char *str, int *enter_line, info_t *info);
int is_digits_matches(char *str, int *enter_line, info_t *info,
int *enter_matches);
void lines_errors(info_t *info, int *enter_line);
void matches_errors_two(info_t *info, int *enter_matches, int *enter_line);
void matches_errors(info_t *info, int *enter_matches, int *enter_line);

#endif