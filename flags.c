/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplaton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/20 10:11:26 by vplaton           #+#    #+#             */
/*   Updated: 2015/12/19 12:00:45 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		is_valid(char c)
{
	return (c == 'l' || c == 'r' || c == 't' || c == 'R' || c == 'a');
}

void	add_flags(char *from)
{
	int		index;

	index = 1;
	while (from[index])
	{
		if (is_valid(from[index]))
		{
			if (from[index] >= 'a' && from[index] <= 'z')
				g_flags[from[index] - 'a' - ('a' - 'Z')] = 1;
			else
				g_flags[from[index] - 'A'] = 0;
		}
		index += 1;
	}
}

int		check_flag(char flag)
{
	if (flag >= 'a' && flag <= 'z')
		return(g_flags[flag - 'a' - ('a' - 'Z')] == 1);
	else
		return(g_flags[flag - 'A'] == 0);
}
