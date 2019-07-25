/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaurine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 21:22:33 by klaurine          #+#    #+#             */
/*   Updated: 2019/07/19 16:36:01 by klaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int		fd;
	int		side;
	char	**map;
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
	map = create_area(identify_side(num_of_blocks));
	while (third_part(matrix, map, 0))
	{
		create_area(side++);
		free_map(map);
	}
	print_result(map);
	return (0);
}
