/*
 * E89 Pedagogical & Technical Lab
 * project:     Cat
 * created on:  2023-12-04 - 14:53 +0100
 * 1st author:  maxime.franchomme - maxime.franchomme
 * description: cat function
 */

#include "../include/stu_cat.h"

int stu_cat (int ac, char **av)
{
    int error;

    if (has_opt(ac, av, 'h')) {
        print_help(av[0]);
        return (0);
    }
    if (has_opt(ac, av, 'E') && has_opt(ac, av, 'T')) {
        error = to_cat(ac, av, 3);
    }
    if (has_opt(ac, av, 'E') && !has_opt(ac, av, 'T')) {
        error = to_cat(ac, av, 1);
    }
    if (!has_opt(ac, av, 'E') && has_opt(ac, av, 'T')) {
        error = to_cat(ac, av, 2);
    }
    if (!has_opt(ac, av, 'E') && !has_opt(ac, av, 'T')) {
        error = to_cat(ac, av, 0);
    }
    if (error > 0) {
        return (1);
    } else {
        return (0);
    }
}
