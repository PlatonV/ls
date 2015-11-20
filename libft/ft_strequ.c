/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplaton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/02 16:08:33 by vplaton           #+#    #+#             */
/*   Updated: 2015/11/02 19:35:04 by vplaton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int		index;

	index = 0;
	while (s1[index] == s2[index])
	{
		if (s1[index] == s2[index] && s1[index] == '\0')
			return (1);
		index++;
	}
	return (0);
}
