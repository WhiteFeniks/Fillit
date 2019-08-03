/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaurine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 21:25:41 by klaurine          #+#    #+#             */
/*   Updated: 2019/06/26 19:20:17 by klaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
	{
		if (!(s3 = ft_strnew(ft_strlen(s2))))
			return (NULL);
		ft_strcpy(s3, s2);
	}
	else if (!s2)
	{
		if (!(s3 = ft_strnew(ft_strlen(s1))))
			return (NULL);
		ft_strcpy(s3, s1);
	}
	else
	{
		if (!(s3 = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
			return (NULL);
		ft_strcpy(s3, s1);
		ft_strcat(s3, s2);
	}
	return (s3);
}
