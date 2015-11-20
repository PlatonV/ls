/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsdata_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplaton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/20 11:43:40 by vplaton           #+#    #+#             */
/*   Updated: 2015/11/20 12:34:32 by vplaton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LSDATA_LIST_H
# define LSDATA_LIST_H

#include "ft_ls.h"

typedef struct			s_lsdata
{
	const char			*filename;
	struct s_lsdata		*next;
}						t_lsdata;

t_lsdata		*lstnew(t_dirstruct *data);
void			lstadd(t_lsdata *node, t_lsdata **lst);

#endif
