/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmanzini <nmanzini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 17:26:42 by nmanzini          #+#    #+#             */
/*   Updated: 2019/07/04 19:25:48 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_fillit.h"

/*

 Функция выделяет место для всех блоков и заполняет выделенные места (матрицы) точками

*/

char	***gen_matrices(int size, int m, int n, char c) 				// Функция выделяет место для всех блоков и заполняет выделенные метса (матрицы) точками

{
	char	***matrix;
	int		b;
	int		i;
	int		j;

	b = 0;
	i = 0;
	matrix = (char***)malloc(sizeof(char**) * (size + 1));    			// выделяем место для двумерного массива размером size = counter (количество блоков в файле)
	while (b < size)
	{
		matrix[b] = (char**)malloc(sizeof(char*) * (m + 1));            // заполняет matrix[0] (4 строки x 4 столбца), matrix[1] (4 строки x 4 столбца)и так до matrix[n == количество блоков]
		while (i < m)
		{
			j = 0;
			matrix[b][i] = ft_strnew(n);                                //создает строку под 4 символа
			while (j < n)
				matrix[b][i][j++] = c;                                  // заполняет эту строку точками
			i++;
		}
		matrix[b][i] = NULL;                                           // создает после блока пустую строку
		b++;
		i = 0;
	}
	matrix[b] = NULL;                                                   // создает после всех блоков пустую - нулевую матрицу
	return (matrix);
}

/*

Функция для переписи из двумерного массива строк str (блоки в строчку) в выделенное и заполненное точками места для каждого блока matrix без \n

*/

int		fill_matrices(char ***matrix, char **str)    //  функция для переписи из двумерного массива строк str (блоки в строчку) в выделенное и заполненное точками места для каждого блока matrix без \n
{													 //  str[0] в массив строк matrix[0][0], matrix[0][1], matrix[0][2],matrix[0][3]. str[1] в matrix[1][0], matrix[1][1], matrix[1][2],matrix[1][3] и т.д.
	int b;
	int i;
	int j;

	b = 0;
	i = 0;
	j = 0;
	while (matrix[b] != 0)
	{
		while (matrix[b][i] != 0)
		{
			while (matrix[b][i][j] != 0)
			{
				if (str[b][i * 5 + j++] == '#')  								//если наткнулись на решетку
					matrix[b][i][j - 1] = str[b][i * 5 + j - 1] + 30 + b;      // то переписываем по символьно при этом меняем на букву == 35 (#) + 30 + 0(b = [0,1,2,3 ... количества строк] = А ... Z)
			}
			i++;
			j = 0;
		}
		b++;
		i = 0;
	}
	return (0);
}

/*

Фунция очистки строки которая заполнена только точками

*/

int		clean_row_matrices(char ***matrix)              // Фунция очистки строки которая заполнена только точками
{
	int b;
	int i;
	int i2;

	b = 0;
	i = 0;
	while (matrix[b] != 0)
	{
		while (matrix[b][i] != 0)
		{
			if (!strcmp(matrix[b][i], "...."))          // если строка matrix[b][i] заполнена только точками
			{
				i2 = i--;
				while (matrix[b][i2] != 0)
				{
					matrix[b][i2] = matrix[b][i2 + 1];   // в исходную строку копирую следущую, так 4 строку == NULL, копируем в 3 строку (в том случае если она заполнена только точками)
					i2++;
				}
			}
			i++;
		}
		b++;
		i = 0;
	}
	return (0);
}

/*

Фунция очистки только одной колонны которая заполнена только точками

*/

int		clean_single_column(char ***matrix, int b, int i, int j)
{
	int j2;

	j2 = 0;
	while (matrix[b][i] != 0)
	{
		if (matrix[b][i][j] == '.')
			j2++;
		i++;
	}
	if (j2 == i)
	{
		i = 0;
		while (matrix[b][i] != 0)
		{
			j2 = j;
			while (matrix[b][i][j2] != 0)
			{
				matrix[b][i][j2] = matrix[b][i][j2 + 1];     // копируем ячейку справа в исходную, например из ячейки 4 в которой ничего нет переписываем ее в 3-ю
				j2++;
			}
			i++;
		}
		j--;
	}
	return (j);
}

/*

Функция очистки сразу всех колонн заполненных только точками

*/

int		clean_column_matrices(char ***matrix)
{
	int b;
	int i;
	int j;

	b = 0;
	i = 0;
	j = 0;
	while (matrix[b] != 0)
	{
		while (matrix[b][i][j] != 0)
		{
			j = clean_single_column(matrix, b, i, j);   // запустить функцию очистки одной колонны заполненных только точками
			j++;
		}
		b++;
		j = 0;
	}
	return (0);
}
