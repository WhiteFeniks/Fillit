/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaurine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 19:30:50 by klaurine          #+#    #+#             */
/*   Updated: 2019/05/16 20:20:59 by klaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t					i;
	unsigned char			*dest;
	const unsigned char		*source;

	i = 0;
	dest = (unsigned char *)dst;
	source = (const unsigned char *)src;
	if (dest == NULL && source == NULL)
		return (NULL);
	else if (source >= dest || dest >= (source + len))
	{
		while (i < len)
		{
			dest[i] = source[i];
			i++;
		}
	}
	else
		while (i < len)
		{
			dest[len - 1] = source[len - 1];
			len--;
		}
	return (dst);
}
