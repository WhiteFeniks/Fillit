/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaurine <klaurine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 17:42:21 by klaurine          #+#    #+#             */
/*   Updated: 2019/07/09 18:20:33 by klaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_string(int fd, char *buffer)
{
	int i;

	i = 0;
	read(fd, buffer, 5);
	while (i < 4)
	{
		if (buffer[i] != '.' && buffer[i] != '#')
			return (0);
		i++;
	}
	if (buffer[4] == '\n')
		return (1);
	return (0);
}

int		check_block(int fd, char **bk, char *buffer)
{
	int		i;
	char	*var;
	char	*string;
	int		counter;

	i = 0;
	counter = 0;
	while (i < 4)
	{
		if (check_string(fd, buffer) == 0)
			break ;
		else
		{
			string = ft_strsub(buffer, 0, 4);
			var = *bk;
			*bk = ft_strjoin(var, string);
			free(var);
			var = NULL;
			free(string);
			string = NULL;
			counter++;
		}
		i++;
	}
	return (counter == 4 ? 1 : 0);
}

int		in_str(const char *haystack, const char *needle)
{
	int i;
	int j;

	i = 0;
	while (haystack[i])
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			while (haystack[i + j] == needle[j] && needle[j])
				j++;
			if (needle[j] == '\0')
				return (1);
		}
		i++;
	}
	return (0);
}

int		check_figure(char **bk)
{
	if (in_str(*bk, "##...#...#") == 1 || in_str(*bk, "#...#..##") == 1 ||
			in_str(*bk, "#...#...##") == 1 || in_str(*bk, "###.#") == 1 ||
			in_str(*bk, "#..###") == 1 || in_str(*bk, "#..##...#") == 1 ||
			in_str(*bk, "###..#") == 1 || in_str(*bk, "#...###") == 1 ||
			in_str(*bk, "##...##") == 1 || in_str(*bk, "###...#") == 1 ||
			in_str(*bk, "#..##..#") == 1 || in_str(*bk, "#.###") == 1 ||
			in_str(*bk, "#...##..#") == 1 || in_str(*bk, "##..##") == 1 ||
			in_str(*bk, "##..#...#") == 1 || in_str(*bk, "##.##") == 1 ||
			in_str(*bk, "#...##...#") == 1 || in_str(*bk, "####") == 1 ||
			in_str(*bk, "#...#...#...#") == 1)
		return (1);
	return (0);
}

int		main(int argc, char **argv)
{
	int		fd;
	int		*number;
	int		num_of_blocks;

	num_of_blocks = 0;
	number = &num_of_blocks;
	if (argc != 2 || (fd = open(argv[1], O_RDONLY)) == -1 ||
			first_part(fd, number) == 0)
	{
		write(1, "error", 5);
		return (0);
	}
	printf("%d", *number);
	fd = open(argv[1], O_RDONLY);
	second_part(fd, num_of_blocks);
	return (0);
}
