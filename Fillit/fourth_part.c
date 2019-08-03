/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fourth_part.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaurine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 15:30:37 by klaurine          #+#    #+#             */
/*   Updated: 2019/08/03 17:36:56 by klaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**create_area(int side)
{
	int		i;
	int		j;
	char	**area;

	i = 0;
	if (!(area = (char **)malloc(sizeof(char *) * (side + 1))))
		return (NULL);
	while (i < side)
	{
		j = 0;
		if (!(area[i] = (char *)malloc(sizeof(char) * (side + 1))))
			return (NULL);
		while (j < side)
		{
			area[i][j] = '.';
			j++;
		}
		area[i][j] = '\0';
		i++;
	}
	area[i] = NULL;
	return (area);
}

void	free_map(char ***map)
{
	int		i;
	char	**nemap;

	i = 0;
	nemap = *map;
	while (nemap[i])
	{
		free(nemap[i]);
		i++;
	}
	free(nemap);
	nemap = NULL;
}

void	free_matrix(char ****matrix)
{
	int		i;
	int		j;
	char	***nematrix;

	i = 0;
	nematrix = *matrix;
	while (nematrix[i])
	{
		j = 0;
		while (j < 5)
		{
			free(nematrix[i][j]);
			j++;
		}
		free(nematrix[i]);
		i++;
	}
	free(nematrix[i]);
	free(nematrix);
	nematrix = NULL;
}
