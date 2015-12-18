/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 23:57:39 by                   #+#    #+#             */
/*   Updated: 2015/12/18 02:01:04 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		print_permissions(t_stat s)
{
	ft_putchar(S_ISDIR(s.st_mode) ? 'd' : '-');
	ft_putchar((s.st_mode & S_IRUSR) ? 'r' : '-');
	ft_putchar((s.st_mode & S_IWUSR) ? 'w' : '-');
	ft_putchar((s.st_mode & S_IXUSR) ? 'x' : '-');
	ft_putchar((s.st_mode & S_IRGRP) ? 'r' : '-');
	ft_putchar((s.st_mode & S_IWGRP) ? 'w' : '-');
	ft_putchar((s.st_mode & S_IXGRP) ? 'x' : '-');
	ft_putchar((s.st_mode & S_IROTH) ? 'r' : '-');
	ft_putchar((s.st_mode & S_IWOTH) ? 'w' : '-');
	ft_putchar((s.st_mode & S_IXOTH) ? 'x' : '-');
	ft_putchar(' ');
}

static void		print_nmax(int n, int maxsize)
{
	int		index;

	index = maxsize - ft_numsize(n);
	while (index-- > 0)
		ft_putchar(' ');
	ft_putnbr(n);
	ft_putchar(' ');
}

static void		print_date(t_stat s)
{
	char		**times;
	time_t		t;

	t = s.st_mtime;
	times = ft_strsplit(ctime(&t), ' ');
	ft_putstr(times[1]);
	ft_putstr(" ");
	ft_putstr(times[2]);
	ft_putstr(" ");
	times[3][5] = '\0';
	ft_putstr(times[3]);
	ft_putstr(" ");
}

void			print_long(t_lsdata *lst, short *flags)
{
	int		maxsize;
	int		maxlink;
	t_stat	sstat;

	maxsize = get_maxsize(lst);
	maxlink = get_maxlink(lst);
	while (lst)
	{
		if (check_flag(flags, 'a') || lst->data[0] != '.')
		{
			lstat(lst->data, &sstat);
			print_permissions(sstat);
			print_nmax(sstat.st_nlink, maxlink);
			ft_putstr(ft_strcat(getpwuid(sstat.st_uid)->pw_name, " "));
			ft_putstr(ft_strcat(getgrgid(sstat.st_gid)->gr_name, " "));
			print_nmax(sstat.st_size, maxsize);
			print_date(sstat);
			ft_putstr(ft_strcat(lst->data, " "));
			ft_putendl("");
		}
		lst = lst->next;
	}
}
