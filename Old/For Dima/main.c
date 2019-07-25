/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmanzini <nmanzini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:35:16 by nmanzini          #+#    #+#             */
/*   Updated: 2017/11/28 18:10:32 by jroguszk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_fillit.h"

int		main(int argc, char **argv)
{
	char ***matrices;

	if (argc < 2)
		ft_putendl("not found: fillit source_file"); //нужно использовать файл с фигурами
	else if (argc > 2)
		ft_putendl("to much inputting"); //слишком много файлов, остановись
	else
	{
		matrices = set_up(argv[1]); // запустить функцию set_up (из файла read_input.c)
		if (!matrices) 				// если в переменной matrices пусто,
			return (1);				// то вернуть 1
		solve(matrices);			// заупстить функцию solve (из файла solver.c)
		return (0);
	}
	return (1);
}
