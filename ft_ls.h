/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplaton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/20 09:43:12 by vplaton           #+#    #+#             */
/*   Updated: 2015/11/24 16:14:37 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <sys/types.h>
# include <dirent.h>
# include "libft.h"

typedef struct dirent	t_dirstruct;

# include "lsdata_list.h"

void	init_flags(short **flags);
void	add_flags(short *flags, char *from);
int		check_flag(short *flags, char flag);

int		list_dir(char *dir, short *flags);

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
