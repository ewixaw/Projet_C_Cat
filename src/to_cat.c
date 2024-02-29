/*
 * E89 Pedagogical & Technical Lab
 * project:     Cat
 * created on:  2023-12-06 - 15:31 +0100
 * 1st author:  maxime.franchomme - maxime.franchomme
 * description: send the texts to the writing function
 */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "../include/stu_cat.h"

static void to_print(char *buffer, int options)
{
    if (options == 3) {
        do_print(buffer, "\n\t");
    }
    if (options == 2) {
        do_print(buffer, "\t");
    }
    if (options == 1) {
        do_print(buffer, "\n");
    }
    if (options == 0) {
        write(1, buffer, stu_strlen(buffer));
    }
}

static int print_file(char **av, int cnt, int opts)
{
    int fd;
    char *buffer;

    fd = open(av[cnt], O_RDONLY);
    if (fd == -1) {
        print_error(av[0], av[cnt]);
        return (1);
    }
    buffer = read_once(fd);
    if (!buffer) {
        print_error(av[0], av[cnt]);
        return (1);
    }
    to_print(buffer, opts);
    free(buffer);
    close(fd);
    return (0);
}

static int print_stdin(char **av, int opts)
{
    int size_read;
    char *buffer;

    buffer = malloc(sizeof(char) * 51);
    if (!buffer) {
        print_error(av[0], "stdin");
        return (1);
    }
    size_read = read(0, buffer, 50);
    if (size_read == -1) {
        print_error(av[0], "stdin");
        return (1);
    }
    while (size_read != 0) {
        buffer[size_read] = '\0';
        to_print(buffer, opts);
        size_read = read(0, buffer, 50);
        if (size_read == -1) {
            print_error(av[0], "stdin");
            return (1);
        }
    }
    free(buffer);
    return (0);
}

int to_cat(int ac, char **av, int opts)
{
    int error;
    int cnt;

    error = 0;
    cnt = 1;
    if (ac == 1) {
        return (print_stdin(av, opts));
    }
    if (ac == 2 && av[cnt][0] == '-') {
        return (print_stdin(av, opts));
    }
    while (cnt < ac) {
        if (stu_strcmp(av[cnt], "-")) {
            error = error + print_stdin(av, opts);
        } else {
            if (av[cnt][0] != '-') {
                error = error + print_file(av, cnt, opts);
            }
        }
        cnt = cnt + 1;
    }
    return (error);
}
