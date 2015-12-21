/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsdata_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplaton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/20 11:43:19 by vplaton           #+#    #+#             */
/*   Updated: 2015/12/19 15:15:14 by                  ###   ########.fr       */
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

void		lstswap(t_lsdata *node1, t_lsdata *node2)
{
	char	*tmp;

	tmp = node1->data;
	node1->data = node2->data;
	node2->data = tmp;
}

int			lstcmp_lexic(t_lsdata* node1, t_lsdata* node2)
{
	return (ft_strcmp(node1->data, node2->data));
}

int			lstcmp_dir(t_lsdata* node1, t_lsdata* node2)
{
	if (opendir(node1->data) && !opendir(node2->data))
		return (1);
	return (0);
}

void		lstsort(t_lsdata **lst, int cmp(t_lsdata* nod1, t_lsdata* nod2))
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
