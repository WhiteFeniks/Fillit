/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaurine <klaurine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 17:42:21 by klaurine          #+#    #+#             */
/*   Updated: 2019/07/24 15:54:26 by klaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*create_string(int fd, char *bk, char *buffer)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (i < 4)
	{
		j = 0;
		ft_bzero(buffer, 5);
		if (read(fd, buffer, 5) <= 0)
			return (NULL);
		while (j < 4)
		{
			bk[k] = buffer[j];
			k++;
			j++;
		}
		i++;
	}
	if (buffer[j] != '\n')
		return (NULL);
	bk[k] = '\0';
	return (bk);
}

int		check_block(char *bk)
{
	int i;
	int hash;
	int dot;

	i = 0;
	dot = 0;
	hash = 0;
	while (bk[i])
	{
		if (bk[i] == '#')
			hash++;
		if (bk[i] == '.')
			dot++;
		i++;
	}
	if (hash == 4 && dot == 12)
		return (1);
	return (0);
}

int		cut_string(char *bk)
{
	int		i;
	int		j;
	int		len;
	char	*f;

	i = 0;
	j = 21;
	while (bk[i] != '#')
		i++;
	while (bk[j] != '#')
		j--;
	if (!(f = (char *)malloc(sizeof(char) * (j - i + 2))))
		return (0);
	len = j - i + 1;
	j = 0;
	while (j < len)
		f[j++] = bk[i++];
	f[j] = '\0';
	if (!check_figure(f))
		return (0);
	free(f);
	f = NULL;
	return (1);
}

int		check_figure(char *f)
{
	if (ft_strcmp("##...#...#", f) == 0 || ft_strcmp("#...#..##", f) == 0 ||
			ft_strcmp("#...#...##", f) == 0 || ft_strcmp("###.#", f) == 0 ||
			ft_strcmp("#..###", f) == 0 || ft_strcmp("#..##...#", f) == 0 ||
			ft_strcmp("###..#", f) == 0 || ft_strcmp("#...###", f) == 0 ||
			ft_strcmp("##...##", f) == 0 || ft_strcmp("###...#", f) == 0 ||
			ft_strcmp("#..##..#", f) == 0 || ft_strcmp("#.###", f) == 0 ||
			ft_strcmp("#...##..#", f) == 0 || ft_strcmp("##..##", f) == 0 ||
			ft_strcmp("##..#...#", f) == 0 || ft_strcmp("##.##", f) == 0 ||
			ft_strcmp("#...##...#", f) == 0 || ft_strcmp("####", f) == 0 ||
			ft_strcmp("#...#...#...#", f) == 0)
		return (1);
	return (0);
}

int		first_part(int fd, int *number)
{
	char bk[21];
	char buffer[5];

	if (create_string(fd, bk, buffer) && check_block(bk))
	{
		if (cut_string(bk))
		{
			(*number)++;
			if (*number > 26)
				return (0);
		}
		else
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
