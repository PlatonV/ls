/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 00:44:07 by                   #+#    #+#             */
/*   Updated: 2015/12/28 20:41:00 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char			*get_filename(char *s)
{
	char		*result;
	char		*it;

	it = s;
	while (*it)
	{
		if (*it == '/')
			result = it + 1;
		it++;
	}
	return (result);
}

unsigned int	ft_numsize(unsigned long n)
{
	unsigned int	result;

	result = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		result++;
	}
	return (result);
}
