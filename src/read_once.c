/*
 * E89 Pedagogical & Technical Lab
 * project:     Cat
 * created on:  2023-12-06 - 16:15 +0100
 * 1st author:  maxime.franchomme - maxime.franchomme
 * description: functions used to read once a file and stock in a char*
 */

#include <stdlib.h>
#include <unistd.h>
#include "../include/stu_cat.h"

static char *read_short(char *new_str, int fd)
{
    int size_read;
    char *temp_str;
    char *old_str;

    old_str = NULL;
    size_read = read(fd, new_str, 10);
    if (size_read != -1) {
        new_str[size_read] = '\0';
    }
    while (size_read > 0) {
        temp_str = old_str;
        old_str = strdupcat(old_str, new_str);
        free(temp_str);
        size_read = read(fd, new_str, 10);
        if (!old_str || size_read == -1) {
            return (NULL);
        }
        new_str[size_read] = '\0';
    }
    return (old_str);
}

char *read_once(int fd)
{
    char *old_str;
    char *new_str;

    old_str = NULL;
    new_str = malloc(sizeof(char) * 11);
    if (!new_str) {
        return (NULL);
    }
    old_str = read_short(new_str, fd);
    free(new_str);
    return (old_str);
}
