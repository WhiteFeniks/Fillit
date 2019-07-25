/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaurine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 14:36:18 by klaurine          #+#    #+#             */
/*   Updated: 2019/05/01 16:45:50 by klaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_malloc(int n)
{
	int i;

	i = 0;
	if (n < 0)
	{
		while (n < -9)
		{
			n = n / 10;
			i++;
		}
		i++;
		return (ft_strnew(i + 1));
	}
	else if (n > 9)
	{
		while (n > 9)
		{
			n = n / 10;
			i++;
		}
	}
	return (ft_strnew(i + 1));
}

char			*ft_itoa(int n)
{
	char	*s;
	int		i;
	int		sign;

	i = 0;
	sign = 0;
	if (!(s = ft_malloc(n)))
		return (NULL);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		sign = 1;
		n = (-n);
	}
	if (n >= 0)
		while (n > 9)
		{
			s[i++] = n % 10 + '0';
			n = n / 10;
		}
	s[i] = n + '0';
	if (sign == 1)
		s[i + 1] = '-';
	return (ft_strrev(s));
}
