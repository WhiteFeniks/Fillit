/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 15:15:28 by umoff             #+#    #+#             */
/*   Updated: 2019/06/27 15:15:39 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>    //
# include "libft/libft.h"
# include <fcntl.h>      //
# include <stdlib.h>
# include <stdio.h>    //!!!!!
# include <string.h>   //!!!!


char    *clear(char *s_old);
int    *test_figure_1(char *s);
int    *test_figure_2(char *s);

#endif
