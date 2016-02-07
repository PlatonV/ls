/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplaton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 14:43:04 by vplaton           #+#    #+#             */
/*   Updated: 2016/01/21 13:27:06 by vplaton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		print_target_files(t_lsdata **targets)
{
	t_lsdata	*lst;

	g_ptargets = 1;
	while ((*targets) && !(opendir((*targets)->data)))
	{
		if (!errno || errno == ENOTDIR)
			put_to_list((*targets)->data, &lst);
		else
			ft_error((*targets)->data);
		(*targets) = (*targets)->next;
	}
	print_files(lst);
	g_ptargets = 0;
}

static void		list_targets(t_lsdata *targets)
{
	DIR		*dir;

	if (list_size(targets) == 1)
	{
		if ((dir = opendir(targets->data)))
			list(targets->data);
		else
			print_target_files(&targets);
		return;
	}
	lstsort(&targets, lstcmp_lexic);
	lstsort(&targets, lstcmp_dir);
	while (targets)
	{
		if ((dir = opendir(targets->data)))
		{
			closedir(dir);
			ft_putchar('\n');
			ft_putendl(ft_strjoin(targets->data, ":"));
			list(targets->data);
			targets = targets->next;
		}
		else
			print_target_files(&targets);
	}
}

int		main(int argc, char **argv)
{
	int			arg_index;
	t_lsdata	*targets;

	arg_index = 1;
	targets = NULL;
	while (arg_index < argc && argv[arg_index][0] == '-')
	{
		add_flags(argv[arg_index]);
		arg_index += 1;
	}
	while (arg_index < argc)
	{
		put_to_list(argv[arg_index], &targets);
		arg_index += 1;
	}
	if (!list_size(targets))
		put_to_list(ft_strdup("."), &targets);
	list_targets(targets);
	return (0);
}
