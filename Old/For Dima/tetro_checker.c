/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetro_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmanzini <nmanzini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:32:15 by jroguszk          #+#    #+#             */
/*   Updated: 2017/11/28 19:42:42 by nmanzini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

/*

Функция проверки соединений тетрамино: берется ячейка, если с одной из сторон(сверху, снизу, слева, справа) находится буква, то k увеличивается

*/

int		validate_tetro(char **str, int i, int j)
{
	int		k;

	k = 0;
	if (j < 3)                                                  // проверка на совпадение справа
	{
		if (str[i][j + 1] == str[i][j])
			k++;
	}
	if (i < 3)                                                  // проверка на совпадение снизу
	{
		if (str[i + 1][j] == str[i][j])
			k++;
	}
	if (j > 0)                                                  // проверка на совпадение слева
	{
		if (str[i][j - 1] == str[i][j])
			k++;
	}
	if (i > 0)                                                  // проверка на совпадение сверху
	{
		if (str[i - 1][j] == str[i][j])
			k++;
	}
	return (k);
}

/*

Функция проверки записанных фигур в matrix на разрывы

*/
int		tetro_checker(char ***str, int i, int j)  // подается сюда matrix c заполненными фигурами, i == 0, j == 0
{
	int		b;
	int		k;

	b = 0;
	k = 0;
	while (str[b] != 0)
	{
		while (str[b][i] != 0)
		{
			while (str[b][i][j] != 0)
			{
				if (str[b][i][j] >= 65 && str[b][i][j] <= 90)    // если наткнулись на букву, то заходим в функцию проверки тетрамино, которая считает количество соединений
					k += validate_tetro(str[b], i, j);
				j++;
			}
			j = 0;
			i++;
		}
		if (k < 6)                                              // любое правильное тетрамино имеет 6 соединений, если меньше то ошибка
			return (0);
		k = 0;
		i = 0;
		b++;
	}
	return (1);                                                // если все фигуры без разрывов, то выводим 1
}