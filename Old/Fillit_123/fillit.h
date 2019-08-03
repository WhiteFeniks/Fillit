/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 15:15:28 by umoff             #+#    #+#             */
/*   Updated: 2019/07/25 13:47:19 by klaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include "./includes/libft.h"
# include <fcntl.h>
# include <stdlib.h>

char	*create_string(int fd, char *bk, char *buffer);
int		cut_string(char *bk);
int		check_figure(char *f);
int		first_part(int fd, int *number);
int		check_block(char *bk);
char	***create_matrix(int num_of_blocks);
void	filling_one_matrix(int fd, char **matrix, int num_of_block);
void	cut_row(char **matrix);
int		cut_column(char **matrix, int i, int j);
void	cut_all_column(char ***matrix);
void	second_part(int fd, int num_of_blocks, char ***matrix);
void	free_map(char ***map);
char	**create_area(int side);
void	clean_figure(char **matrix, char **map, int row, int column);
int		check_insert_figure(char **matrix, char **map, int row, int column);
void	insert_figure(char **matrix, char **map, int row, int column);
int		cycle(char ***matrix, char **map, int block);
void	third_part(char ***matrix, int num_of_blocks);
void	free_matrix(char ****matrix);

#endif
