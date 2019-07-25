/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   third_part.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaurine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 20:50:13 by klaurine          #+#    #+#             */
/*   Updated: 2019/07/21 18:24:33 by klaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	clean_figure(char **matrix, char **map, int row, int column)
{
	int i;
	int j;

	i = 0;
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j])
		{
			if (matrix[i][j] != '.')
				map[i + row][j + column] = '.';
			j++;
		}
		i++;
	}
}

int		check_insert_figure(char **matrix, char **map, int row, int column)
{
	int i;
	int j;

	i = 0;
	while (matrix[i])
	{
		j = 0;
		if (map[i + row] == 0)
			return (0);
		while (matrix[i][j])
		{
			if (map[i + row][j + column] == 0)
				return (0);
			if (map[i + row][j + column] != '.' && matrix[i][j] != '.')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	insert_figure(char **matrix, char **map, int row, int column)
{
	int i;
	int j;

	i = 0;
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j])
		{
			if (matrix[i][j] != '.')
				map[i + row][j + column] = matrix[i][j];
			j++;
		}
		i++;
	}
}

int		cycle(char ***matrix, char **map, int block)
{
	int i;
	int j;

	i = 0;
	if (matrix[block] == 0)
		return (1);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (check_insert_figure(matrix[block], map, i, j))
			{
				insert_figure(matrix[block], map, i, j);
				if (cycle(matrix, map, block + 1))
					return (1);
				clean_figure(matrix[block], map, i, j);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void third_part(char ***matrix, int num_of_blocks)
{
	int i;
	int side;
	char **map;

	i = 0;
	side = 2;
	while (side * side < num_of_blocks * 4)
		side++;
	map = create_area(side);
	while (cycle(matrix, map, 0) == 0)
	{
		free_map(map);
		create_area(side++);
	}
	while (map[i])
	{
        ft_putendl(map[i]);
        i++;
    }
}

