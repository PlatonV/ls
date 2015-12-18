/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplaton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/20 09:43:12 by vplaton           #+#    #+#             */
/*   Updated: 2015/12/18 02:15:01 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <pwd.h>
# include <grp.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <time.h>
# include "libft.h"
# include <stdio.h>

typedef struct stat		t_stat;
typedef struct dirent	t_dirstruct;

typedef struct			s_lsdata
{
	char				*data;
	struct s_lsdata		*next;
}						t_lsdata;

char			*g_currentpath;

unsigned int	ft_numsize(unsigned long n);
unsigned int	get_maxsize(t_lsdata(*lst));
unsigned int	get_maxlink(t_lsdata(*lst));
t_lsdata		*lstnew(char *data);
int				list_size(t_lsdata *lst);
void			lstadd(t_lsdata *node, t_lsdata **lst);
void			put_to_list(char *data, t_lsdata **lst);
int				lstcmp_lexic(t_lsdata* node1, t_lsdata* node2);
void			lstswap(t_lsdata *node1, t_lsdata *node2);
void			lstsort(t_lsdata **lst, int cmp(t_lsdata* nod1,
						t_lsdata* nod2));
void			init_flags(short **flags);
void			add_flags(short *flags, char *from);
int				check_flag(short *flags, char flag);
void			print_long(t_lsdata *lst, short *flags);
void			print_all(t_lsdata *lst, short *flags);
int				list_dir(char *dir, short *flags);

#endif

/*
◦ write
◦ opendir - deschid director returneaza Dir*
◦ readdir - citesc Dir*
◦ closedir - dau Dir* si inchide
◦ stat - nu folosesc
◦ lstat - folosesc, imi da date, cu info despre link
◦ getpwuid - interpretez un stat
◦ getgrgid - al doilea stat
◦ listxattr - pt > 0: are extended, altfel nu
◦ getxattr - nu vrei
◦ time - nu conteaza
◦ ctime - interpretare stat
◦ readlink - numele de la ce arata lstat
◦ malloc 
◦ free
◦ perror - scrie eroarea in functie de errno
◦ strerror
◦ exit - return malefic
*/
