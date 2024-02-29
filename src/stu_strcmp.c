/*
 * E89 Pedagogical & Technical Lab
 * project:     Cat
 * created on:  2023-12-05 - 15:15 +0100
 * 1st author:  maxime.franchomme - maxime.franchomme
 * description: function needed for cat function
 */

#include "../include/stu_cat.h"

int stu_strcmp(const char *s1, const char *s2)
{
    int compteur;

    compteur = 0;
    while (s1[compteur] != '\0' || s2[compteur] != '\0') {
        if (s1[compteur] != s2[compteur]) {
            return (0);
        }
        compteur = compteur + 1;
    }
    return (1);
}
