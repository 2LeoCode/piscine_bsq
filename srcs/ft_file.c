/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 11:22:44 by lsuardi           #+#    #+#             */
/*   Updated: 2020/02/25 15:06:29 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/tools.h"

int		ft_open_file(int *fd, char *arg)
{
	*fd = open(arg, O_RDONLY);
	if (*fd == -1)
		return (FAILURE);
	return (SUCCESS);
}

int		ft_close_file(int *file)
{
	if (close(*file) == -1)
		return (FAILURE);
	return (SUCCESS);
}

int		ft_check_file(char *buf)
{
	int i;
	int nb;

	i = 0;
	while (buf[i] >= '0' && buf[i] <= '9')
		i++;
	i += 3;
	if (buf[i] != '\n')
		return (FAILURE);
	i++;
	if (ft_check_lines(&buf[i]) == FAILURE)
		return (FAILURE);
	nb = ft_atoin(buf, i);
	return (nb);
}

int		ft_get_file(char *path, char *buf)
{
	int fd;
	int size;

	if (ft_open_file(&fd, path) == FAILURE)
		return (FAILURE);
	size = read(fd, buf, BUF_SIZE);
	buf[size] = 0;
	if (ft_check_file(buf) == FAILURE)
		return (FAILURE);
	if (ft_close_file(&fd) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

int		ft_read_file(int ac, char **av)
{
	char	buffer[BUF_SIZE + 1];
	t_file	*file;
	int		i;
	int		nb;

	i = 0;
	file = NULL;
	while (++i < ac)
		if (ft_get_file(av[i], buffer) == FAILURE)
			ft_putstr("map error\n");
		else if (!(file =
					ft_init_filelist(buffer, file, ft_check_file(buffer))))
			ft_putstr("memory error\n");
	ft_display_files(file);
	//ft_clean_chain(line);
	return (SUCCESS);
}
