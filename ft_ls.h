/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplaton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 14:43:11 by vplaton           #+#    #+#             */
/*   Updated: 2016/02/17 14:21:34 by vplaton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# define MAJOR(dev) ((int)(((unsigned int) (dev) >> 8) & 0xff))
# define MINOR(dev) ((int)((dev) & 0xff))

# include <pwd.h>
# include <grp.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <time.h>
# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include "errno.h"

typedef struct stat		t_stat;
typedef struct dirent	t_dirstruct;

typedef struct			s_maxes
{
	unsigned int		size;
	unsigned int		link;
	unsigned int		owner;
	unsigned int		group;
	unsigned int		min;
	unsigned int		max;
}						t_maxes;

typedef struct			s_lsdata
{
	char				*data;
	struct s_lsdata		*next;
}						t_lsdata;

char			g_flags[200];
char			g_ptargets;

char			*get_filename(char *s);
unsigned int	ft_max(unsigned long a, unsigned long b);
unsigned int	ft_numsize(unsigned long n);
unsigned int	get_maxsize(t_lsdata *lst);
unsigned int	get_maxlink(t_lsdata *lst);
unsigned int	get_maxowner(t_lsdata *lst);
unsigned int	get_maxgroup(t_lsdata *lst);
unsigned int	get_maxmin(t_lsdata *lst);
unsigned int	get_maxmax(t_lsdata *lst);
int				get_blocks(t_lsdata *lst);
t_lsdata		*lstnew(char *data);
int				list_size(t_lsdata *lst);
void			lstadd(t_lsdata *node, t_lsdata **lst);
void			put_to_list(char *data, t_lsdata **lst);
int				lstcmp_lexic(t_lsdata* node1, t_lsdata* node2);
int				lstcmp_dir(t_lsdata* node1, t_lsdata* node2);
int				lstcmp_time(t_lsdata* node1, t_lsdata* node2);
void			lstdel(t_lsdata *node);
void			lstswap(t_lsdata *node1, t_lsdata *node2);
void			lstsort(t_lsdata **lst, int cmp(t_lsdata* nod1,
						t_lsdata* nod2));
void			add_flags(char *from);
int				check_flag(char flag);
void			print_long_file(char *file, t_maxes maxes);
void			print_size(t_stat st, t_maxes maxes);
void			print_lst(t_lsdata *lst);
void			print_files(t_lsdata *lst);
void			print_file2(char *file);
void			list(char *dir);
void			list_rec(t_lsdata *lst);
void			print_lst_rec(t_lsdata *lst);
void			ft_error(const char *str);
void			putslash(char *str);
void			invalid_option(char option);

#endif
