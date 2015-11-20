/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplaton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/02 19:10:10 by vplaton           #+#    #+#             */
/*   Updated: 2015/11/02 19:15:18 by vplaton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*result;
	size_t	index;

	if (!(result = (char*)malloc(size)))
		return (NULL);
	index = 0;
	while (index < size)
	{
		result[index] = '\0';
		index++;
	}
	return (result);
}
