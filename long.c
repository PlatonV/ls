/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 23:57:39 by                   #+#    #+#             */
/*   Updated: 2016/01/08 17:42:11 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		print_permissions(t_stat s)
{
	if (S_ISDIR(s.st_mode))
		ft_putchar('d');
	else if (S_ISLNK(s.st_mode))
		ft_putchar('l');
	else
		ft_putchar('-');
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

static void		print_strmax(char *str, int maxsize)
{
	int		index;

	index = maxsize - ft_strlen(str);
	while (index-- > 0)
		ft_putchar(' ');
	ft_putstr(str);
	ft_putchar(' ');
}

static void		print_date(t_stat s)
{
	char		**times;
	time_t		t;

	t = s.st_mtime;
	times = ft_strsplit(ctime(&t), ' ');
	times[1][0] = ft_tolower(times[1][0]);
	ft_putstr(times[1]);
	ft_putstr(" ");
	if (ft_atoi(times[2]) < 10)
		ft_putstr(" ");
	ft_putstr(times[2]);
	ft_putstr(" ");
	times[3][5] = '\0';
	ft_putstr(times[3]);
	ft_putstr(" ");
}

void			print_long_file(char *file, t_maxes maxes)
{
	t_stat	sstat;

	if (check_flag('a') || !(get_filename(file)[0] == '.'))
	{
		lstat(file, &sstat);
		print_permissions(sstat);
		print_nmax(sstat.st_nlink, maxes.link);
		print_strmax(getpwuid(sstat.st_uid)->pw_name, maxes.owner);
		print_strmax(getgrgid(sstat.st_gid)->gr_name, maxes.group);
		print_nmax(sstat.st_size, maxes.size);
		print_date(sstat);
		ft_putstr(get_filename(file));
		ft_putendl("");
	}
}
