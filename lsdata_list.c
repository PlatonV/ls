/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsdata_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplaton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/20 11:43:19 by vplaton           #+#    #+#             */
/*   Updated: 2015/11/24 15:50:47 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lsdata_list.h"

t_lsdata	*lstnew(t_dirstruct *data)
{
	t_lsdata	*lst;

	lst = (t_lsdata*)malloc(sizeof(t_lsdata));
	lst->filename = ft_strdup(data->d_name);
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

	tmp = node1->filename;
	node1->filename = node2->filename;
	node2->filename = tmp;
}

int			lstcmp(t_lsdata* node1, t_lsdata* node2)
{
	return (ft_strcmp(node1->filename, node2->filename));
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
