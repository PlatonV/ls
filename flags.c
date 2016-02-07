/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplaton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/20 10:11:26 by vplaton           #+#    #+#             */
/*   Updated: 2016/01/21 12:59:58 by vplaton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		is_valid(char c)
{
	if (c == 'l' || c == 'r' || c == 't' || c == 'R' || c == 'a')
		return (1);
	else
	{
		write(2, "Invalid option!", 15);
		exit(0);
	}
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
