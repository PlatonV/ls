/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 23:55:31 by                   #+#    #+#             */
/*   Updated: 2015/12/19 15:15:20 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		list_targets(t_lsdata *targets)
{
	g_currentpath = ft_strdup(targets->data);
	if (list_size(targets) == 1)
	{
		list_dir(targets->data);
		return;
	}
	lstsort(&targets, lstcmp_lexic);
	lstsort(&targets, lstcmp_dir);
	while (targets)
	{
		if (opendir(targets->data))
			ft_putendl(ft_strcat(ft_strdup(targets->data), ":"));
		g_currentpath = ft_strdup(targets->data);
		list_dir(targets->data);
		if (targets->next)
			ft_putendl("");
		targets = targets->next;
	}
}

int		main(int argc, char **argv)
{
	int			arg_index;
	t_lsdata	*targets;

	arg_index = 1;
	targets = NULL;
	while (arg_index < argc)
	{
		if (argv[arg_index][0] == '-')
			add_flags(argv[arg_index]);
		else
			put_to_list(argv[arg_index], &targets);
		arg_index += 1;
	}
	if (!list_size(targets))
		put_to_list(ft_strdup("."), &targets);
	list_targets(targets);
	return (0);
}
