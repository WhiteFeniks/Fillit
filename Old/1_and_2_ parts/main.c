/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaurine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 21:22:33 by klaurine          #+#    #+#             */
/*   Updated: 2019/07/10 21:57:48 by klaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
	matrix = create_matrix(num_of_blocks); //esli ne poluchim mesta na diske oshibka
	second_part(fd, num_of_blocks, matrix);
	//third_part(num_of_blocks)
	return (0);
}
