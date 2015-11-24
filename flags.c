/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplaton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/20 10:11:26 by vplaton           #+#    #+#             */
/*   Updated: 2015/11/24 16:20:58 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	init_flags(short **flags)
{
	*flags = (short*)malloc(56);
}

int		is_valid(char c)
{
	return (c == 'l' || c == 'r' || c == 't' || c == 'R' || c == 'a');
}

void	add_flags(short *flags, char *from)
{
	int		index;

	index = 1;
	while (from[index])
	{
		if (is_valid(from[index]))
		{
			if (from[index] >= 'a' && from[index] <= 'z')
				flags[from[index] - 'a' - ('a' - 'Z')] = 1;
			else
				flags[from[index] - 'A'] = 0;
		}
		index += 1;
	}
}

int		check_flag(short *flags, char flag)
{
	if (flag >= 'a' && flag <= 'z')
		return(flags[flag - 'a' - ('a' - 'Z')] == 1);
	else
		return(flags[flag - 'A'] == 0);
}
