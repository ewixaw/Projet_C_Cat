/*
 * E89 Pedagogical & Technical Lab
 * project:     Cat
 * created on:  2023-12-08 - 11:02 +0100
 * 1st author:  maxime.franchomme - maxime.franchomme
 * description: function printing the errors
 */

#include <unistd.h>
#include <string.h>
#include <errno.h>
#include "../include/stu_cat.h"

void print_error(char *name, char *file)
{
    char *error;

    error = strerror(errno);
    write(1, name, stu_strlen(name));
    write(1, ": ", 2);
    write(1, file, stu_strlen(file));
    write(1, ": ", 2);
    write(1, error, stu_strlen(error));
    write(1, "\n", 1);
}
