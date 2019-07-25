/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaurine <klaurine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 17:42:21 by klaurine          #+#    #+#             */
/*   Updated: 2019/07/07 16:34:26 by klaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

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

int		check_block(int fd, char **block, char *buffer)
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
			var = *block;
			*block = ft_strjoin(var, string);
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

void	cut_block(char **block, char **f)
{
	int		i;
	int		j;
	int		len;
	char	*for_block;
	char	*for_f;

	i = 0;
	for_block = *block;
	j = ft_strlen(for_block);
	while (for_block[i] != '#')
		i++;
	while (for_block[j] != '#')
		j--;
	free(*f);
	*f = NULL;
	if (!(*f = (char *)malloc(sizeof(char *) * (j - i + 2))))
		return ;
	for_f = *f;
	len = j - i + 1;
	j = 0;
	while (j < len)
		for_f[j++] = for_block[i++];
	for_f[j] = '\0';
	free(*block);
	*block = NULL;
}

int		check_hash(char **block)
{
	int		i;
	char	*string;

	i = 0;
	string = *block;
	while (*string)
	{
		if (*string == '#')
			i++;
		string++;
	}
	if (i != 4)
		return (0);
	return (1);
}

int		check_figure(char **block, char **f)
{
	if (check_hash(block) == 0)
		return (0);
	cut_block(block, f);
	if (ft_strcmp("##...#...#", *f) == 0 || ft_strcmp("#...#..##", *f) == 0 ||
			ft_strcmp("#...#...##", *f) == 0 || ft_strcmp("###.#", *f) == 0 ||
			ft_strcmp("#..###", *f) == 0 || ft_strcmp("#..##...#", *f) == 0 ||
			ft_strcmp("###..#", *f) == 0 || ft_strcmp("#...###", *f) == 0 ||
			ft_strcmp("##...##", *f) == 0 || ft_strcmp("###...#", *f) == 0 ||
			ft_strcmp("#..##..#", *f) == 0 || ft_strcmp("#.###", *f) == 0 ||
			ft_strcmp("#...##..#", *f) == 0 || ft_strcmp("##..##", *f) == 0 ||
			ft_strcmp("##..#...#", *f) == 0 || ft_strcmp("##.##", *f) == 0 ||
			ft_strcmp("#...##...#", *f) == 0 || ft_strcmp("####", *f) == 0 ||
			ft_strcmp("#...#...#...#", *f) == 0)
		return (1);
	return (0);
}

void	alphabet_hash(char **f, int num_of_blocks)
{
	int			i;
	char		*for_f;

	i = 0;
	for_f = *f;
	while (for_f[i])
	{
		if (for_f[i] == '.')
			i++;
		else if (for_f[i] == '#')
		{
			for_f[i] = '@' + num_of_blocks;
			i++;
		}
	}
}

int		check_all_blocks(int fd, int num_of_blocks)
{
	char			*f;
	char			*block;
	char			buffer[5];

	f = ft_strnew(0);
	block = ft_strnew(0);
	if (check_block(fd, &block, buffer))
	{
		if (check_figure(&block, &f))
		{
			num_of_blocks++;
			if (num_of_blocks > 26)
				return (0);
			alphabet_hash(&f, num_of_blocks);
		}
		else
			return (0);
	}
	else
		return (0);
	if (read(fd, buffer, 1) == 0)
		return (1);
	else if (*buffer == '\n')
		return (check_all_blocks(fd, num_of_blocks) == 1 ? 1 : 0);
	return (0);
}

int		main(int argc, char **argv)
{
	int fd;
	int num_of_blocks;

	num_of_blocks = 0;
	if (argc != 2 || (fd = open(argv[1], O_RDONLY)) == -1 ||
			check_all_blocks(fd, num_of_blocks) == 0)
	{
		write(1, "error", 5);
		return (0);
	}
	write(1, "ok", 2);
	return (0);
}
