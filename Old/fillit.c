
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 18:13:42 by umoff             #+#    #+#             */
/*   Updated: 2019/06/27 16:55:33 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char    *clear(char *s_old)
{
    int        i;
    int        j;
    int        k;
    char    *s_new;

    i = 0;
    j = 0;
    while (s_old[i] != '#')
        i++;
    while (s_old[j] != '\0')
        j++;
    while (s_old[j] != '#')
        j--;
    s_new = (char*)malloc(sizeof(*s_new) * (j - i + 2));
    if (s_new == 0)
        return (0);
    k = 0;
    while (k < j - 1)
    {
        s_new[k] = s_old[i];
        k++;
        i++;
    }
    s_new[k] = '\0';
    return (s_new);
}

int main()                     //
{                                             //
    char str[] = "..#...#...#...#....";       //
    printf("%s", clear(str));                 //
}                                             //




#include "libft.h"

int    *test_figure_1(char *s)
{
    char *s1 = "####";
    char *s2 = "#.###";
    char *s3 = "##.##";
    char *s4 = "###.#";
    char *s5 = "#..###";
    char *s6 = "##..##";
    char *s7 = "###..#";
    char *s8 = "#...###";
    char *s9 = "##...##";

    if (ft_strcmp(s1, s) == 0 || ft_strcmp(s2, s) == 0 ||
        ft_strcmp(s3, s) == 0 || ft_strcmp(s4, s) == 0 ||
        ft_strcmp(s5, s) == 0 || ft_strcmp(s6, s) == 0 ||
        ft_strcmp(s7, s) == 0 || ft_strcmp(s8, s) == 0 ||
        ft_strcmp(s9, s) == 0)
        return (1);
    else
        return (0);
}

int    *test_figure_2(char *s)
{
    char *s10 = "###...#";
    char *s11 = "#..##..#";
    char *s12 = "#...#..##";
    char *s13 = "#...##..#";
    char *s14 = "#..##...#";
    char *s15 = "##..#...#";
    char *s16 = "#...#...##";
    char *s17 = "#...##...#";
    char *s18 = "##...#...#";
    char *s19 = "#...#...#...#";

    if (ft_strcmp(s10, s) == 0 ||
        ft_strcmp(s11, s) == 0 || ft_strcmp(s12, s) == 0 ||
        ft_strcmp(s13, s) == 0 || ft_strcmp(s14, s) == 0 ||
        ft_strcmp(s15, s) == 0 || ft_strcmp(s16, s) == 0 ||
        ft_strcmp(s17, s) == 0 || ft_strcmp(s18, s) == 0 ||
        ft_strcmp(s19, s) == 0)
        return (1);
    else
        return (0);
}

int main()    //
{
    char str[] = "#...#...#...#";              //
    if ((test_figure_1(str) == 1) || (test_figure_2(str) == 1))        //
        printf("фигура нормальная");         //
    else                                     //
        printf("фигура не подходит");        //
}

























