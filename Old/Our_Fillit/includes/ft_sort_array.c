/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaurine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 20:04:58 by klaurine          #+#    #+#             */
/*   Updated: 2019/05/01 18:01:35 by klaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_sort_array(int *s, int size)
{
	int i;
	int max;
	int obmen;

	i = 0;
	max = 0;
	if (!s || s == 0)
		return (0);
	while (i <= (size - 1))
	{
		while (i <= (size - 1))
		{
			if (s[i] >= s[max])
				max = i;
			i++;
		}
		obmen = s[size - 1];
		s[size - 1] = s[max];
		s[max] = obmen;
		size--;
		i = 0;
		max = 0;
	}
	return (s);
}
