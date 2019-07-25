/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaurine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 18:26:29 by klaurine          #+#    #+#             */
/*   Updated: 2019/05/12 17:23:30 by klaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		isspace(int c)
{
	if (c == '\n' || c == '\t' || c == '\v' || c == '\f' || c == '\r'
			|| c == ' ')
		return (1);
	return (0);
}

int				ft_atoi(const char *str)
{
	int						i;
	int						sign;
	unsigned long long int	number;

	i = 0;
	sign = 1;
	number = 0;
	while (isspace(str[i]))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + (str[i] - '0');
		if (number > ATOI_MAX && sign == 1)
			return (-1);
		else if ((number + 1) > ATOI_MAX && sign == -1)
			return (0);
		i++;
	}
	return ((int)number * sign);
}
