/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_island.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdeniau <cdeniau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 14:19:25 by cdeniau           #+#    #+#             */
/*   Updated: 2015/01/30 15:45:57 by cdeniau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>

int		check_map(int fd, int *nb_line, int *size)
{
	int		size_line;
	int		verif;
	int		rd;
	char	buff[1];

	size_line = 0;
	verif = 0;
	while ((rd = read(fd, buff, 1)))
	{
		if (*buff && *buff != '\n' && *buff != 'X' && *buff != '.')
			return (0);
		if (*buff && *buff == '\n')
		{
			if (!verif)
				verif = size_line;
			if (verif != size_line)
				return (0);
			*nb_line += 1;
			size_line = 0;
		}
		else
			size_line++;
	}
	*size = verif;
	return (1);
}

void	scan(char *buff, int i, int size, int n)
{
	if (i < size && buff[i] == 'X')
	{
		buff[i] = n + '0';
		scan(buff, i + 1, size, n);
		scan(buff, i - 1, size, n);
		scan(buff, i + size_line, size, n);
		scan(buff, i - size_line, size, n);
	}
}

void	draw_map(int fd, int nb_line, int size_line)
{
	char	buff[nb_line * (size_line + 1)];
	int		i;
	int		size;
	int		n;

	size = nb_line * size_line + nb_line;
	i = -1;
	n = 0;
	read (fd, buff, size);
	while (++i < size)
		if (buff[i] == 'X')
			scan(buff, i, size, n++);
	write (1, buff, size);
}

int		main(int ac, char **av)
{
	int		fd;
	int		nb_line;
	int		size_line;

	nb_line = 0;
	size_line = 0;
	if (ac == 2)
	{
		if (!(fd = open(av[1], O_RDONLY)))
			return (0);
		if (!check_map(fd, &nb_line, &size_line))
			return (0);
		if (!(fd = open(av[1], O_RDONLY)))
			return (0);
		draw_map(fd, nb_line, size_line);
	}
	write (1, "\n", 1);
	return (0);
}
