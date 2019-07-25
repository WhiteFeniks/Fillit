/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmanzini <nmanzini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 17:29:53 by nmanzini          #+#    #+#             */
/*   Updated: 2017/11/28 17:51:56 by nmanzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_fillit.h"

/*

Функция подчитывающая ближайший квадрат минимальной площади: если количество блоков 5, то value = 25; 6 блоков -> value = 25; 7 блоков -> value = 36 и т.д.

*/

int		ft_floor_sqrt(int value)
{
	int i;

	while (value > 1)
	{
		i = 1;
		while (i * i <= value)
		{
			if (i * i == value)
				return (i);
			i++;
		}
		value++;
	}
	return (0);
}

/*

Функция подсчитывающая количество блоков

*/

int		num_tetra(char ***tetra)
{
	int b;

	b = 0;
	while (tetra[b] != 0)
		b++;
	return (b);
}

/*

Функция создает квадрат, заполненный точками размером min_size * min_size,
При этом каждая строка заканчивается нулем, а последняя строка равна NULL;

*/

char	**gen_row(int m, int n, char c)
{
	int		i;
	int		j;
	char	**row;

	i = 0;
	j = 0;
	row = (char**)malloc(sizeof(char*) * (n + 1));
	while (i < n)
	{
		row[i] = (char*)malloc(sizeof(char) * (m + 1));
		while (j < m)
			row[i][j++] = c;
		row[i][j] = 0;
		j = 0;
		i++;
	}
	row[i] = NULL;
	return (row);
}

/*

Функция очищает карту для увеличения в последующем стороны карты на +1

 */

int		**free_row(char **row)
{
	int	i;

	i = 0;
	while (row[i] != 0)   // идет по карте по строкам сверху вниз
	{
		free(row[i]);    // очищает сразу строку
		i++;
	}
	free(row[i]);      // после
	row = NULL;
	return (0);
}

/*

Функция выводит карту заполненнуб фигурами

*/

int		print_row(char **row)
{
	int i;

	i = 0;
	while (row[i] != 0)
	{
		ft_putendl(row[i]);
		i++;
	}
	return (0);
}
