/*
 * E89 Pedagogical & Technical Lab
 * project:     Cat
 * created on:  2023-12-06 - 15:40 +0100
 * 1st author:  maxime.franchomme - maxime.franchomme
 * description: function when helper option is used
 */

#include <unistd.h>
#include "../include/stu_cat.h"

void print_help(char *name)
{
    char *str;

    str = " [OPTION]... [FILE]...\n"
        "Concatenate FILE(s) to standard output.\n\n"
        "With no FILE, or when FILE is -, read standard input.\n\n"
        "  -E   display $ at end of each line\n"
        "  -T   display TAB characters as ^I\n"
        "  -h   display this help and exit\n\0";

    write(1, "Usage: ", 7);
    write(1, name, stu_strlen(name));
    write(1, str, stu_strlen(str));
}
