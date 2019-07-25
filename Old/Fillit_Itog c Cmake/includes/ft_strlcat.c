/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaurine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 21:17:35 by klaurine          #+#    #+#             */
/*   Updated: 2019/05/12 18:06:31 by klaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	size_t res;
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	res = 0;
	while (dst[i])
		i++;
	while (src[j])
		j++;
	if (size <= i)
		res = j + size;
	else
		res = j + i;
	j = 0;
	while (src[j] && size > (i + 1))
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (res);
}
