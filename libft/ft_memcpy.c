/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplaton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/26 14:17:16 by vplaton           #+#    #+#             */
/*   Updated: 2015/11/03 15:58:36 by vplaton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dp;
	unsigned char	*sp;

	sp = (unsigned char *)src;
	dp = (unsigned char *)dst;
	while (n--)
	{
		*dp = *sp;
		dp++;
		sp++;
	}
	return (dst);
}
