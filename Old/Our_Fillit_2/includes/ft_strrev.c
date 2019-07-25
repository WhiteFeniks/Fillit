/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaurine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 19:40:41 by klaurine          #+#    #+#             */
/*   Updated: 2019/05/01 16:37:12 by klaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *s)
{
	size_t	i;
	size_t	len;
	char	buf;

	i = 0;
	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	while (len - 1 > i)
	{
		buf = s[i];
		s[i] = s[len - 1];
		s[len - 1] = buf;
		len--;
		i++;
	}
	return (s);
}
