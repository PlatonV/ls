/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplaton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/20 10:11:26 by vplaton           #+#    #+#             */
/*   Updated: 2016/02/18 14:29:49 by vplaton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		check_flagstrval(char *str)
{
	t_stat		s;

	if (lstat(str, &s) == 0)
		return (0);
	else
	{
		errno = 0;
		return (1);
	}
}

int		is_valid(char c)
{
	if (c == 'l' || c == 'r' || c == 't' || c == 'R' || c == 'a'
			|| c == '-' || c == '1')
		return (1);
	else
	{
		invalid_option(c);
	}
	return (1);
}

void	add_flags(char *from)
{
	int		index;

	index = 1;
	while (from[index])
	{
		if (is_valid(from[index]))
		{
			g_flags[(int)from[index]] = 1;
		}
		index += 1;
	}
}

int		check_flag(char flag)
{
	return (g_flags[(int)flag]);
}
