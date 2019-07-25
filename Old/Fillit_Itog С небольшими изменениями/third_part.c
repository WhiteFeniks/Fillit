/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   third_part.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaurine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 20:50:13 by klaurine          #+#    #+#             */
/*   Updated: 2019/07/19 17:08:56 by klaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_map(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map[i]);
	free(map);
	map = NULL;
}	

int		identify_side(int num_of_blocks, int side)
{
	side = 2;
	while (side * side < num_of_blocks * 4)
		side++;
	return (side);
}

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

int		clean_figure(char **matrix, char **map, int row, int column)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (matrix[i])
    {
        while (matrix[i][j])
        {
            if (matrix[i][j] != '.')     // если идем по фигуре и натыкаемся не на точку
            {
                map[i + row][j + column] = '.';    // то заменяем в карте букву на точку
            }
            j++;
        }
        j = 0;
        i++;
    }
    return (0);
}


int		check_insert_figure(char **matrix, char **map, int row, int column)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (matrix[i])
	{
	    if (!(map[i + row]))
            return (0);
		while (matrix[i][j])
		{
		    if (!(map[i + row][j + column]))
                return (0);
			if (map[i + row][j + column] != '.' && matrix[i][j] != '.')
				return (0);
			j++;
		}
        j = 0;
        i++;
	}
	return (1);
}

int	insert_figure(char **matrix, char **map, int row, int column)
{
	int i;
	int j;

	i = 0;
    j = 0;
    while (matrix[i])
	{
		while (matrix[i][j])
		{
		    if (matrix[i][j] != '.')
			    map[i + row][j + column] = matrix[i][j];
			j++;
		}
		j = 0;
		i++;
	}
    return (0);
}

int		third_part(char ***matrix, char **map, int block)
{
    int i;
    int j;

    i = 0;
    j = 0;
    if (matrix[block] == 0)
        return (0);
    while (map[i])
    {
        while (map[i][j])
        {
            if (check_insert_figure(matrix[block], map, i, j))
            {
                insert_figure(matrix[block], map, i, j);
                if (!(third_part(matrix, map, block + 1)))
                    return (0);
                clean_figure(matrix[block], map, i, j);
            }
            j++;
        }
        i++;
        j = 0;
    }
    return (1);
}

int     print_result(char **map)
{
    int i;

    i = 0;
    while (map[i] != 0)
    {
        ft_putendl(map[i]);
        i++;
    }
    return (0);
}
