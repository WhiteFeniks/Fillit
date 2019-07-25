/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaurine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 20:09:02 by klaurine          #+#    #+#             */
/*   Updated: 2019/07/12 16:49:57 by klaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	***create_matrix(int num_of_blocks)
{
	int		i;
	int		j;
	char	***matrix;

	i = 0;
	if (!(matrix = (char ***)malloc(sizeof(char **) * (num_of_blocks + 1))))
		return (NULL);
	while (i < num_of_blocks)
	{
		j = 0;
		if (!(matrix[i] = (char **)malloc(sizeof(char *) * 5)))
			return (NULL);
		while (j < 5)
		{
			if (!(matrix[i][j] = (char *)malloc(sizeof(char) * 5)))
				return (NULL);
			j++;
		}
		i++;
	}
	matrix[num_of_blocks] = NULL;
	return (matrix);
}

void	filling_one_matrix(int fd, char **matrix, int num_of_block)
{
	int		i;
	int		j;
	int		b;
	char	buffer[21];

	i = 0;
	b = 0;
	read(fd, buffer, 21);
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (buffer[b] == '#')
				matrix[i][j] = 'A' + num_of_block;
			else
				matrix[i][j] = buffer[b];
			j++;
			b++;
		}
		matrix[i][j] = '\0';
		b++;
		i++;
	}
	matrix[i] = NULL;
}

void	cut_row(char **matrix)
{
	int i;
	int j;

	i = 0;
	while (matrix[i])
	{
		if (ft_strcmp(matrix[i], "....") == 0)
		{
			j = i--;
			while (matrix[j])
			{
				matrix[j] = matrix[j + 1];
				j++;
			}
		}
		i++;
	}
}

int		cut_column(char **matrix, int i, int j)
{
	int k;

	k = 0;
	while (matrix[i])
	{
		if (matrix[i][j] == '.')
			k++;
		i++;
	}
	if (k == i)
	{
		i = 0;
		while (matrix[i])
		{
			k = j;
			while (matrix[i][k])
			{
				matrix[i][k] = matrix[i][k + 1];
				k++;
			}
			i++;
		}
		j--;
	}
	return (j);
}

void	second_part(int fd, int num_of_blocks, char ***matrix)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < num_of_blocks)
	{
		filling_one_matrix(fd, matrix[i], i);
		cut_row(matrix[i]);
		while (matrix[i][j])
		{
			j = cut_column(matrix[i], i, j);
			j++;
		}
		i++;
	}
}

