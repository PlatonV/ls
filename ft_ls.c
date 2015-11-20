/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplaton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/20 09:57:22 by vplaton           #+#    #+#             */
/*   Updated: 2015/11/20 13:39:34 by vplaton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char **argv)
{
	int		arg_index;
	short	*flags;

	if (argc == 1)
		return (0);
	init_flags(&flags);
	arg_index = 1;
	while (arg_index < argc)
	{
		if (argv[arg_index][0] == '-')
			add_flags(flags, argv[arg_index]);
		else
			if ((list_dir(argv[arg_index])) == -1)
				ft_putendl("Error");
		arg_index += 1;
	}
	return (0);
}
