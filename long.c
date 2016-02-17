/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplaton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 15:01:19 by vplaton           #+#    #+#             */
/*   Updated: 2016/02/17 14:05:24 by vplaton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		print_mode(t_stat s)
{
	if (S_ISDIR(s.st_mode))
		ft_putchar('d');
	else if (S_ISLNK(s.st_mode))
		ft_putchar('l');
	else if (S_ISSOCK(s.st_mode))
		ft_putchar('s');
	else if (S_ISCHR(s.st_mode))
		ft_putchar('c');
	else if (S_ISBLK(s.st_mode))
		ft_putchar('b');
	else
		ft_putchar('-');
}

static void		print_permissions(char *file)
{
	t_stat	s;

	lstat(file, &s);
	print_mode(s);
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
	ft_putchar(' ');
	while (index-- > 0)
		ft_putchar(' ');
	ft_putnbr(n);
}

static void		print_strmax_uid(t_stat sstat, int maxsize)
{
	int		index;
	char	*str;

	if (getpwuid(sstat.st_uid))
		str = getpwuid(sstat.st_uid)->pw_name;
	else
		str = ft_itoa(sstat.st_uid);
	ft_putstr(str);
	index = maxsize - ft_strlen(str);
	while (index-- > 0)
		ft_putchar(' ');
	ft_putchar(' ');
}

static void		print_strmax_gid(t_stat sstat, int maxsize)
{
	int		index;
	char	*str;

	ft_putchar(' ');
	if (getgrgid(sstat.st_gid))
		str = getgrgid(sstat.st_gid)->gr_name;
	else
		str = ft_itoa(sstat.st_gid);
	ft_putstr(str);
	index = maxsize - ft_strlen(str);
	while (index-- > 0)
		ft_putchar(' ');
	ft_putchar(' ');
}

static void		print_date(t_stat s)
{
	time_t		t;
	char		*str;

	t = s.st_mtime;
	if (s.st_mtime > time(NULL) || s.st_mtime < time(NULL) - 15768000)
	{
		ft_putstr(ft_strsub(ctime(&t), 4, 6));
		ft_putstr("  ");
		str = ft_strsub(ctime(&t), 20, 24);
		str[4] = '\0';
		ft_putstr(str);
	}
	else
		ft_putstr(ft_strsub(ctime(&t), 4, 12));
	ft_putchar(' ');
}

void			print_size(t_stat st, t_maxes maxes)
{
	int		aux;

	if (S_ISCHR(st.st_mode) || S_ISBLK(st.st_mode))
	{
		ft_putchar(' ');
		print_nmax(major(st.st_rdev), maxes.max);
		ft_putstr(",");
		print_nmax(minor(st.st_rdev), maxes.min);
		ft_putchar(' ');
	}
	else
	{
		aux = maxes.max;
		while (aux--)
			ft_putchar(' ');
		print_nmax(st.st_size, ft_max(maxes.min, maxes.size));
		ft_putchar(' ');
	}
}

void			print_long_file(char *file, t_maxes maxes)
{
	t_stat	sstat;

	if (check_flag('a') || !(get_filename(file)[0] == '.'))
	{
		lstat(file, &sstat);
		print_permissions(file);
		print_nmax(sstat.st_nlink, maxes.link);
		ft_putchar(' ');
		print_strmax_uid(sstat, maxes.owner);
		print_strmax_gid(sstat, maxes.group);
		print_size(sstat, maxes);
		print_date(sstat);
		print_file2(file);
		ft_putendl("");
	}
}
