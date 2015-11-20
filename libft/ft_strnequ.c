/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplaton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/02 16:10:06 by vplaton           #+#    #+#             */
/*   Updated: 2015/11/04 12:36:52 by vplaton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int		index;

	index = 0;
	while (s1[index] == s2[index] && n--)
	{
		if (s1[index] == s2[index] && s1[index] == '\0')
			return (1);
		index++;
	}
	if (n == 0)
		return (1);
	return (0);
}
