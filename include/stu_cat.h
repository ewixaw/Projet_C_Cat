/*
 * E89 Pedagogical & Technical Lab
 * project:     Cat
 * created on:  2023-12-05 - 14:48 +0100
 * 1st author:  maxime.franchomme - maxime.franchomme
 * description: includes for cat function
 */

#ifndef STU_CAT_
#define STU_CAT_

unsigned int stu_strlen(const char *str);
int stu_strcmp(const char *s1, const char *s2);
int has_opt(int ac, char **av, char str);
char *strdupcat(char *str1, char *str2);
void print_help(char *name);
void print_error(char *name, char *file);
char *read_once(int fd);
char *do_print(char *msg, char *wanted);
int to_cat(int ac, char **av, int opts);
int stu_cat (int ac, char **av);

#endif
