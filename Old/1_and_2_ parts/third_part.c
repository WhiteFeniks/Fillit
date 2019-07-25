/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   third_part.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaurine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 20:50:13 by klaurine          #+#    #+#             */
/*   Updated: 2019/07/10 21:53:15 by klaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int minimal_square(int num_of_blocks)
{
    int i;
    int res_i;

    i = 1;
    while (num_of_blocks * 4 > i * i)
        i++;
    res_i = i;
    return (res_i);
}

char	***create_place(int res_i)
{
    int		i;
    int		j;
    char	***place;

    i = 0;
    if (!(place  = (char ***)malloc(sizeof(char **) * (2))))
        return (NULL);
    while (i < res_i)
    {
        j = 0;
        if (!(place[i] = (char **)malloc(sizeof(char *) * (res_i + 1))))
            return (NULL);
        while (j < res_i + 1)
        {
            if (!(place[i][j] = (char *)malloc(sizeof(char) * (res_i + 1))))
                return (NULL);
            j++;
        }
        i++;
    }
    place[res_i] = NULL;
    return (place);
}

char	**filling_place(char **place, int res_i)
{
    int		i;
    int		j;

    i = 0;
    while (i < res_i)
    {
        j = 0;
        while (j < res_i)
        {
            place[i][j] = '.';
            j++;
        }
        place[i][j] = '\0';
        i++;
    }
    place[i] = NULL;
    return (place);
}

