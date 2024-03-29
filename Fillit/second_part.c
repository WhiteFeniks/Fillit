/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_part.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaurine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 15:21:46 by klaurine          #+#    #+#             */
/*   Updated: 2019/08/03 17:32:37 by klaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

void	filling_one_matrix(int fd, char **matrix, int number, int b)
{
	int		i;
	int		j;
	char	buffer[21];

	i = 0;
	ft_bzero(buffer, 21);
	read(fd, buffer, 21);
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (buffer[b] == '#')
				matrix[i][j] = 'A' + number;
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
			j = i;
			free(matrix[i]);
			matrix[i] = NULL;
			while (j < 4)
			{
				matrix[j] = matrix[j + 1];
				j++;
			}
			i--;
		}
		i++;
	}
}

int		cut_column(char **matrix, int i, int j, int counter)
{
	int k;

	i = 0;
	while (matrix[i])
	{
		if (matrix[i][j] == '.')
			counter++;
		i++;
	}
	if (counter == i)
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
		return (0);
	}
	return (1);
}

void	second_part(int fd, int num_of_blocks, char ***matrix)
{
	int i;
	int j;
	int b;
	int k;
	int counter;

	i = 0;
	counter = 0;
	while (i < num_of_blocks)
	{
		j = 0;
		b = 0;
		k = 0;
		filling_one_matrix(fd, matrix[i], i, b);
		cut_row(matrix[i]);
		while (k < 4)
		{
			if (cut_column(matrix[i], i, j, counter))
				j++;
			k++;
		}
		i++;
	}
}
