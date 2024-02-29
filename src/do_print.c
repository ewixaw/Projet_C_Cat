/*
 * E89 Pedagogical & Technical Lab
 * project:     Cat
 * created on:  2023-12-07 - 09:29 +0100
 * 1st author:  maxime.franchomme - maxime.franchomme
 * description: function writing the text
 */

#include <stdlib.h>
#include <unistd.h>
#include "../include/stu_cat.h"

static int find_char_index(char *msg, char *wanted)
{
    int cnt;
    int cnt2;

    cnt = 0;
    cnt2 = 0;
    while (msg[cnt] != '\0') {
        while (wanted[cnt2] != '\0') {
            if (msg[cnt] == wanted[cnt2]) {
                return (cnt);
            }
            cnt2 = cnt2 + 1;
        }
        cnt = cnt + 1;
        cnt2 = 0;
    }
    return (cnt);
}

char *do_print(char *msg, char *wanted)
{
    int nb;

    while (msg[0] != '\0') {
        nb = find_char_index(msg, wanted);
        write(1, msg, nb);
        msg = msg + nb;
        if (msg[0] == '\n') {
            write(1, "$\n", 2);
            msg = msg + 1;
        } else {
            if (msg[0] == '\t') {
                write(1, "^I", 2);
                msg = msg + 1;
            }
        }
    }
    return (msg);
}
