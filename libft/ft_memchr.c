/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplaton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/26 15:25:07 by vplaton           #+#    #+#             */
/*   Updated: 2015/11/09 15:15:32 by vplaton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;
	size_t			index;

	index = 0;
	p = (unsigned char*)s;
	while (index < n)
	{
		if (p[index] == (unsigned char)c)
			return (p + index);
		index++;
	}
	return (NULL);
}
