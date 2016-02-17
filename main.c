/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplaton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 14:43:04 by vplaton           #+#    #+#             */
/*   Updated: 2016/02/17 14:39:36 by vplaton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		g_first;

static void		print_target_files(t_lsdata **targets)
{
	t_lsdata	*lst;
	t_stat		s;

	g_ptargets = 1;
	while ((*targets) && !(opendir((*targets)->data)))
	{
		lstat((*targets)->data, &s);
		if (!errno || errno == ENOTDIR || S_ISLNK(s.st_mode))
		{
			g_first = 1;
			put_to_list((*targets)->data, &lst);
		}
		else
			ft_error((*targets)->data);
		(*targets) = (*targets)->next;
	}
	if (!lst)
		return ;
	lstsort(&lst, lstcmp_lexic);
	if (check_flag('t'))
		lstsort(&lst, lstcmp_time);
	print_files(lst);
	g_ptargets = 0;
}

static void		list_targets(t_lsdata *targets)
{
	DIR		*dir;

	g_first = 1;
	if (list_size(targets) == 1)
	{
		if ((dir = opendir(targets->data)))
			list(targets->data);
		else
			print_target_files(&targets);
		return ;
	}
	lstsort(&targets, lstcmp_lexic);
	lstsort(&targets, lstcmp_dir);
	while (targets)
	{
		if ((dir = opendir(targets->data)))
		{
			closedir(dir);
			if (!g_first)
			{
				ft_putchar('\n');
				g_first = 1;
			}
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
