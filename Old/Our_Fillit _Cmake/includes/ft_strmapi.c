/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaurine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 17:36:41 by klaurine          #+#    #+#             */
/*   Updated: 2019/04/24 20:02:05 by klaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*s2;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	s2 = (char *)malloc(sizeof(*s2) * (ft_strlen(s) + 1));
	if (s2 == NULL)
		return (NULL);
	while (s[i])
	{
		s2[i] = (*f)(i, (char)s[i]);
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
