/*
 * E89 Pedagogical & Technical Lab
 * project:     Cat
 * created on:  2023-12-05 - 15:01 +0100
 * 1st author:  maxime.franchomme - maxime.franchomme
 * description: function needed for cat function
 */

#include "../include/stu_cat.h"

int has_opt(int ac, char **av, char str)
{
    int cmpt1;
    int cmpt2;
    int len_arg;

    cmpt1 = 0;
    while (cmpt1 < ac) {
        if (av[cmpt1][0] == '-') {
            cmpt2 = 1;
            len_arg = stu_strlen(av[cmpt1]);
            while (cmpt2 < len_arg) {
                if (av[cmpt1][cmpt2] == str) {
                    return (1);
                }
                cmpt2 = cmpt2 + 1;
            }
        }
        cmpt1 = cmpt1 + 1;
    }
    return (0);
}
