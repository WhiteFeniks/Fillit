/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaurine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 20:09:02 by klaurine          #+#    #+#             */
/*   Updated: 2019/07/09 19:04:25 by klaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>    //
# include "libft/libft.h"
# include <fcntl.h>      //
# include <stdlib.h>
# include <stdio.h>    //!!!!!
# include <string.h>   //!!!!

char	***create_matrix(int num_of_blocks)
{
	int		i;
	int		j;
	char	***matrix;

	i = 0;
	if (!(matrix  = (char ***)malloc(sizeof(char **) * (num_of_blocks + 1))))
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

char	**filling_one_matrix(int fd, char **matrix, int num_of_block)
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
	return (matrix);
}

void	cut_row(char **matrix)
{
	int i;
	int j;
	
	i = 0;
	while(matrix[i])
	{
		if (!ft_strcmp(matrix[i], "...."))
		{
			j = i--;
			while(matrix[j])
			{
				matrix[j] = matrix[j + 1];
				j++;
			}
		}
		i++;
	}
}

int		cut_one_column(char **matrix, int i, int j)
{
	int j2;
	
	j2 = 0;
	while (matrix[i])
	{
		if (matrix[i][j] == '.')
			j2++;
		i++;
	}
	if (j2 == i)
	{
		i = 0;
		while (matrix[i] != 0)
		{
			j2 = j;
			while (matrix[i][j2] != '\0')
			{
				matrix[i][j2] = matrix[i][j2 + 1];
				j2++;
			}
			i++;
		}
		j--;
	}
	return (j);
}

int		cut_all_columns(char **matrix)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	while (matrix[i][j])
	{
		j = cut_one_column(matrix, i, j);
		j++;
	}
	return (0);
}

char	***second_part(int fd, int num_of_blocks)
{
	int i;
    char ***matrix;

	i = 0;
	matrix = create_matrix(num_of_blocks);
	while (i < num_of_blocks)
	{
		matrix[i] = filling_one_matrix(fd, matrix[i], i);
		cut_row(matrix[i]);
		cut_all_columns(matrix[i]);
		i++;
	}
	return (matrix);
}

int		main(int argc, char **argv)
{
	int		fd;
	int		num_of_blocks;

	num_of_blocks = 4;
	if (argc != 2)
	{
		write(1, "error", 5);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	second_part(fd, num_of_blocks);
	return (0);
}
