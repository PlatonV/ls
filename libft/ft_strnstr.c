/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplaton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/21 11:42:39 by vplaton           #+#    #+#             */
/*   Updated: 2015/11/09 15:32:48 by vplaton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		index;
	size_t		index2;

	if (*s2 == '\0')
		return ((char*)s1);
	index = 0;
	while (s1[index] && index < n)
	{
		index2 = 0;
		if (s1[index] == s2[0] && index < n)
		{
			while (s1[index] == s2[index2] && index < n)
			{
				index++;
				index2++;
				if (s2[index2] == '\0')
					return ((char*)(s1 + index - index2));
			}
		}
		index = index - index2 + 1;
	}
	return (NULL);
}
