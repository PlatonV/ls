/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplaton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/21 13:13:09 by vplaton           #+#    #+#             */
/*   Updated: 2015/11/09 14:06:37 by vplaton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	char	*c;
	int		l;
	int		index;

	l = ft_strlen(s2);
	if (l == 0)
		return ((char*)s1);
	index = 0;
	while (s1[index] != '\0')
	{
		c = ft_strnstr(&s1[index], s2, l);
		if (c)
			return (c);
		index++;
	}
	return (0);
}
