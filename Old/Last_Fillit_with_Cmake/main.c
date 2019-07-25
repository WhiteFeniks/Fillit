/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaurine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 21:22:33 by klaurine          #+#    #+#             */
/*   Updated: 2019/07/21 18:24:37 by klaurine         ###   ########.fr       */
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

int		main(int argc, char **argv)
{
	int		fd;
	int		*number;
	char	***matrix;
	int		num_of_blocks;

	num_of_blocks = 0;
	number = &num_of_blocks;
	if (argc != 2 || (fd = open(argv[1], O_RDONLY)) == -1 ||
			first_part(fd, number) == 0)
	{
		write(1, "error", 5);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	matrix = create_matrix(num_of_blocks);
	second_part(fd, num_of_blocks, matrix);
	third_part(matrix, num_of_blocks);
	return (0);
}
