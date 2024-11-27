/*
** EPITECH PROJECT, 2024
** B-MUL-100-TLS-1-1-myhunter-noah.gomes
** File description:
** my_strcpr
*/

#include "../../lib/include/my.h"

int my_strcpr(char *str1, char *str2)
{
    int i = 0;
    int goal = my_strlen(str2);
    int verif = my_strlen(str1);
    int answer = 0;

    if (goal != verif)
        return 1;
    while (str1[i] != '\0' || str2[i] != '\0') {
        if (str1[i] == str2[i]) {
            answer++;
        }
        i++;
    }
    if (answer == goal)
        return 0;
    return 1;
}
