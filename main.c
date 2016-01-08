/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 23:55:31 by                   #+#    #+#             */
/*   Updated: 2016/01/08 17:11:27 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		list_targets(t_lsdata *targets)
{
	if (list_size(targets) == 1)
	{
		list(targets->data);
		return;
	}
	lstsort(&targets, lstcmp_lexic);
	lstsort(&targets, lstcmp_dir);
	while (targets)
	{
		if (opendir(targets->data))
			ft_putendl(ft_strjoin(targets->data, ":"));
		list(targets->data);
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
