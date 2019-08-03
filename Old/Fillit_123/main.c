/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaurine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 21:22:33 by klaurine          #+#    #+#             */
/*   Updated: 2019/07/25 14:06:47 by klaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

char	***create_matrix(int num_of_blocks)
{
	int		i;
	int		j;
	char	***matrix;

	i = 0;
	matrix = (char ***)malloc(sizeof(char **) * (num_of_blocks + 1));
	if (matrix == NULL)
		return (NULL);
	while (i < num_of_blocks)
	{
		j = 0;
		if (!(matrix[i] = (char **)malloc(sizeof(char *) * 5)))
			return (NULL);
		while (j < 4)
		{
			if (!(matrix[i][j] = malloc(sizeof(char) * 5)))
				return (NULL);
			j++;
		}
		matrix[i][j] = NULL;
		i++;
	}
	matrix[i] = NULL;
	return (matrix);
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

int		main(int argc, char **argv)
{
	int		fd;
	int		*number;
	char	***matrix;
	int		num_of_blocks;

	if (argc < 2)
		ft_putendl("You need to add the source of the shape file");
	else if (argc > 2)
		ft_putendl("You have too many input files");
	num_of_blocks = 0;
	number = &num_of_blocks;
	if ((fd = open(argv[1], O_RDONLY)) == -1 ||
			first_part(fd, number) == 0)
	{
		ft_putendl("error");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	matrix = create_matrix(num_of_blocks);
	second_part(fd, num_of_blocks, matrix);
	third_part(matrix, num_of_blocks);
	return (0);
}
