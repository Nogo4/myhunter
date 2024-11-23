/*
** EPITECH PROJECT, 2024
** my_getnbr.c
** File description:
** task05
*/

int test_ascii_code(const char *the_str, int i_fa, long *nbr_fa, int testor_a)
{
    if (the_str[i_fa] >= '0' && the_str[i_fa] <= '9') {
        *nbr_fa = (*nbr_fa * 10) + the_str[i_fa] - 48;
        if (the_str[i_fa + 1] > 58 || the_str[i_fa + 1] < 48) {
            return 1;
        }
    }
    return 0;
}

int final_test(long nbr_ft, int final_nbr_ft)
{
    if (nbr_ft > 2147483647 || nbr_ft < -2147483648) {
        final_nbr_ft = 0;
        return final_nbr_ft;
    } else {
        final_nbr_ft = nbr_ft;
        return final_nbr_ft;
    }
}

int my_getnbr(char const *str)
{
    int i = 0;
    int i_negative = 0;
    int testor = 0;
    long nbr = 0;
    int final_nbr = 0;
    int zebi = 0;

    while (str[i] != '\0' && testor == 0) {
        if (str[i] == '-') {
            i_negative++;
        }
        testor = test_ascii_code(str, i, &nbr, testor);
        i++;
    }
    if (i_negative % 2 != 0) {
        nbr = nbr * (-1);
    }
    return final_test(nbr, final_nbr);
}
