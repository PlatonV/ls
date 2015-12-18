/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 23:55:31 by                   #+#    #+#             */
/*   Updated: 2015/12/18 01:52:37 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int argc, char **argv)
{
	int			arg_index;
	short		*flags;
	t_lsdata	*targets;

	init_flags(&flags);
	arg_index = 1;
	targets = NULL;
	while (arg_index < argc)
	{
		if (argv[arg_index][0] == '-')
			add_flags(flags, argv[arg_index]);
		else
			put_to_list(argv[arg_index], &targets);
		arg_index += 1;
	}
	if (!list_size(targets))
		put_to_list(ft_strdup("."), &targets);
	while (targets)
	{
		g_currentpath = ft_strdup(targets->data);
		list_dir(targets->data, flags);
		targets = targets->next;
	}
	return (0);
}
