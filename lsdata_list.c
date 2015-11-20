/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsdata_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplaton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/20 11:43:19 by vplaton           #+#    #+#             */
/*   Updated: 2015/11/20 12:35:55 by vplaton          ###   ########.fr       */
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
