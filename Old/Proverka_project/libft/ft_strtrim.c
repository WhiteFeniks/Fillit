/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klaurine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 18:35:42 by klaurine          #+#    #+#             */
/*   Updated: 2019/05/10 16:28:08 by klaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t i;
	size_t j;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' || s[i] == '\0')
	{
		if (s[i] == '\0')
			return (ft_strnew(0));
		i++;
	}
	j = ft_strlen(s);
	while (s[j - 1] == ' ' || s[j - 1] == '\t' || s[j - 1] == '\n')
		j--;
	return (ft_strsub(s, i, j - i));
}
