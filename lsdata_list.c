/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsdata_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplaton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 15:01:48 by vplaton           #+#    #+#             */
/*   Updated: 2016/02/17 14:06:55 by vplaton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_lsdata	*lstnew(char *data)
{
	t_lsdata	*lst;

	lst = (t_lsdata*)malloc(sizeof(t_lsdata));
	lst->data = ft_strdup(data);
	lst->next = NULL;
	return (lst);
}

void		lstadd(t_lsdata *node, t_lsdata **lst)
{
	if (node && *lst)
	{
		node->next = *lst;
		*lst = node;
	}
}

void		lstdel(t_lsdata *node)
{
	t_lsdata	*n;

	n = node->next;
	while (n)
	{
		n = node->next;
		free(node->data);
		free(node);
	}
}

void		lstswap(t_lsdata *node1, t_lsdata *node2)
{
	char	*tmp;

	tmp = node1->data;
	node1->data = node2->data;
	node2->data = tmp;
}

int			lstcmp_lexic(t_lsdata *node1, t_lsdata *node2)
{
	if (!check_flag('r'))
		return (ft_strcmp(node1->data, node2->data));
	else
		return (-ft_strcmp(node1->data, node2->data));
}

int			lstcmp_dir(t_lsdata *node1, t_lsdata *node2)
{
	if (opendir(node1->data) && !opendir(node2->data))
		return (check_flag('r') ? 0 : 1);
	return (check_flag('r') ? 1 : 0);
}

int			lstcmp_time(t_lsdata *node1, t_lsdata *node2)
{
	t_stat	stat1;
	t_stat	stat2;

	lstat(node1->data, &stat1);
	lstat(node2->data, &stat2);
	if (stat1.st_mtime < stat2.st_mtime)
		return (check_flag('r') ? 0 : 1);
	return (check_flag('r') ? 1 : 0);
}

void		lstsort(t_lsdata **lst, int cmp(t_lsdata *nod1, t_lsdata *nod2))
{
	int			done;
	t_lsdata	*p;

	done = 0;
	while (!done)
	{
		done = 1;
		p = *lst;
		while (p->next)
		{
			if (cmp(p, p->next) > 0)
			{
				lstswap(p, p->next);
				done = 0;
			}
			p = p->next;
		}
	}
}
