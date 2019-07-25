/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaurine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 21:18:52 by klaurine          #+#    #+#             */
/*   Updated: 2019/04/24 17:36:49 by klaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*s2;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	s2 = (char *)malloc(sizeof(*s2) * (ft_strlen(s) + 1));
	if (s2 == NULL)
		return (NULL);
	while (s[i])
	{
		s2[i] = (*f)((char)s[i]);
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
