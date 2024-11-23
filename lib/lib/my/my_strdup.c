/*
** EPITECH PROJECT, 2024
** my_strdup.c
** File description:
** task01
*/

#include <stdlib.h>
#include "../../include/my.h"

int my_strdup(char const *src, char *dest)
{
    int i = 0;

    if (dest == NULL)
        return 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return 1;
}
