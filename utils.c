/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 00:44:07 by                   #+#    #+#             */
/*   Updated: 2016/01/07 13:21:48 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char			*get_filename(char *s)
{
	char		*result;
	char		*it;

	it = s;
	result = NULL;
	while (*it)
	{
		if (*it == '/')
			result = it + 1;
		it++;
	}
	if (!result)
		return (s);
	else
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
