/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplaton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/26 15:28:35 by vplaton           #+#    #+#             */
/*   Updated: 2015/11/09 13:19:41 by vplaton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	n -= 1;
	while (*p1 == *p2 && n--)
	{
		if ((*p1 == *p2) && (*p1 == '\0'))
			return (0);
		p1++;
		p2++;
	}
	return ((int)*p1 - (int)*p2);
}
