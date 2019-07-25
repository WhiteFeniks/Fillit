/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaurine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 14:15:17 by klaurine          #+#    #+#             */
/*   Updated: 2019/04/22 15:46:14 by klaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	if (s[i] == '\0' && (char)c == '\0')
		return ((char *)&s[i]);
	while (--i >= 0)
	{
		if (s[i] == c)
			return ((char *)&s[i]);
	}
	return (NULL);
}
