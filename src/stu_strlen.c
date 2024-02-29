/*
 * E89 Pedagogical & Technical Lab
 * project:     Cat
 * created on:  2023-12-05 - 14:53 +0100
 * 1st author:  maxime.franchomme - maxime.franchomme
 * description: function needed for cat function
 */

#include "../include/stu_cat.h"

unsigned int stu_strlen(const char *str)
{
    int counter;

    counter = 0;
    while (str[counter] != '\0') {
        counter = counter + 1;
    }
    return (counter);
}
