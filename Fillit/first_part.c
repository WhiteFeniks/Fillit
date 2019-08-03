/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_part.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaurine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 15:05:21 by klaurine          #+#    #+#             */
/*   Updated: 2019/08/03 17:20:09 by klaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_block(int fd, char *buffer)
{
	int i;
	int dot;
	int hash;

	i = 0;
	dot = 0;
	hash = 0;
	ft_bzero(buffer, 20);
	read(fd, buffer, 20);
	while (i < 20)
	{
		if (buffer[i] == '.')
			dot++;
		if (buffer[i] == '#')
			hash++;
		if ((i + 1) % 5 == 0)
			if (buffer[i] != '\n')
				return (0);
		i++;
	}
	if (hash == 4 && dot == 12)
		return (1);
	return (0);
}

int		touch_test(char *buffer)
{
	int i;
	int touch;

	i = 0;
	touch = 0;
	while (i < 20)
	{
		if (buffer[i] == '#')
		{
			if (i < 19)
				if (buffer[i] == buffer[i + 1])
					touch++;
			if (i > 0)
				if (buffer[i] == buffer[i - 1])
					touch++;
			if (i < 14)
				if (buffer[i] == buffer[i + 5])
					touch++;
			if (i > 4)
				if (buffer[i] == buffer[i - 5])
					touch++;
		}
		i++;
	}
	return (touch < 6 ? 0 : 1);
}

int		first_part(int fd, int *number)
{
	char buffer[20];

	if (check_block(fd, buffer) && touch_test(buffer))
	{
		(*number)++;
		if (*number > 26)
			return (0);
	}
	else
		return (0);
	if (read(fd, buffer, 1) == 0)
		return (1);
	else if (*buffer == '\n')
		return (first_part(fd, number) == 1 ? 1 : 0);
	return (0);
}

int		main(int argc, char **argv)
{
	int		fd;
	int		*number;
	char	***matrix;
	int		num_of_blocks;

	if (argc < 2)
		ft_putendl("You should to add the source file");
	else if (argc > 2)
		ft_putendl("Too many input files");
	else
	{
		num_of_blocks = 0;
		number = &num_of_blocks;
		if ((fd = open(argv[1], O_RDONLY)) == -1 ||
				first_part(fd, number) == 0 || close(fd) == -1)
		{
			ft_putendl("error");
			return (0);
		}
		matrix = create_matrix(num_of_blocks);
		fd = open(argv[1], O_RDONLY);
		second_part(fd, num_of_blocks, matrix);
		third_part(matrix, num_of_blocks);
	}
	return (0);
}
