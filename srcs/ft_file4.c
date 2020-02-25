/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:09:43 by lsuardi           #+#    #+#             */
/*   Updated: 2020/02/25 15:09:46 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/tools.h"

int		ft_check_lines(char *buf)
{
	int j;
	int i;
	int stock;

	j = 0;
	i = 0;
	stock = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			break ;
		while (buf[i] != '\n')
			i++;
		if (!stock)
			stock = i;
		j++;
		if (i / stock != j)
			return (FAILURE);
	}
	return (SUCCESS);
}

void	ft_display_lines(t_line *lines)
{
	t_line *tmp;

	tmp = lines;
	if (tmp)
	{
		ft_display_lines(tmp->next);
		ft_putstr(tmp->line);
	}
	ft_putstr("\n");
}

void	ft_display_files(t_file *files)
{
	t_file *tmp;

	tmp = files;
	if (tmp)
	{
		ft_display_files(tmp->next);
		ft_display_lines(tmp->lines);
	}
}
