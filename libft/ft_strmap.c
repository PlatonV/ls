/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplaton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/02 18:25:12 by vplaton           #+#    #+#             */
/*   Updated: 2015/11/03 15:25:04 by vplaton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t		index;
	size_t		len;
	char		*result;

	index = 0;
	while (s[index] != '\0')
		index++;
	len = index;
	result = (char*)malloc(len + 1);
	index = 0;
	while (index < len)
	{
		result[index] = f(s[index]);
		index++;
	}
	result[len] = '\0';
	return (result);
}
