/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 15:15:28 by umoff             #+#    #+#             */
/*   Updated: 2019/07/07 18:50:15 by klaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>    //
# include "./includes/libft.h"
# include <fcntl.h>      //
# include <stdlib.h>
# include <stdio.h>    //!!!!!
# include <string.h>   //!!!!


/* first_par.c */

int		check_string(int fd, char *buffer);
int		check_block(int fd, char **bk, char *buffer);
int		in_str(const char *haystack, const char *needle);
int		check_figure(char **bk);
int		first_part(int fd, int *number);

/* second_part.c */

char	***create_matrix(int num_of_blocks);
void	filling_one_matrix(int fd, char **matrix, int num_of_block);
void	cut_row(char **matrix);
int		cut_column(char **matrix, int i, int j);
void	second_part(int fd, int num_of_blocks, char ***matrix);

/* third_part.c */

void	free_map(char **map);
int		identify_side(int num_of_blocks);
char	**create_area(int side);
int		clean_figure(char **map, char **matrix, int row, int column);
int		check_insert_figure(char **matrix, char **map, int row, int column);
int     insert_figure(char **matrix, char **map, int row, int column);
int		third_part(char ***matrix, char **map, int block);
int     print_result(char **map);
void    my_cycle(char ***matrix, char **map, int num_of_blocks);







#endif
