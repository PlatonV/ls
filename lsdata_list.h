/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsdata_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplaton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/20 11:43:40 by vplaton           #+#    #+#             */
/*   Updated: 2015/11/20 15:17:23 by vplaton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LSDATA_LIST_H
# define LSDATA_LIST_H

#include "ft_ls.h"

typedef struct			s_lsdata
{
	char				*filename;
	struct s_lsdata		*next;
}						t_lsdata;

t_lsdata		*lstnew(t_dirstruct *data);
void			lstadd(t_lsdata *node, t_lsdata **lst);
void			lstswap(t_lsdata *node1, t_lsdata *node2);

#endif
