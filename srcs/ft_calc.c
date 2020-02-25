/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:14:20 by lsuardi           #+#    #+#             */
/*   Updated: 2020/02/25 22:23:13 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/tools.h"

int		ft_check_coords(t_square square, t_line *lines, t_coord map)
{
	t_line *tmp;
	int i;

	tmp = lines;
	i = 0;
	if (tmp)
	{
		ft_check_coords(square, tmp->next, map);
		if (lines->index >= square.y && lines->index < square.y + square.size)
		{
			if (lines->nb_obs)
				while (i < lines->nb_obs)
				{
					if (lines->pos_obs[i] >= square.x && tmp->pos_obs[i] < square.x + square.size)
						return (FAILURE);
				}
		}
	}
	return (SUCCESS);
}

void	ft_putsquare(t_square square, t_line *lines, t_file *file)
{
	t_line *tmp;
	int i;

	i = square.x;
	tmp = lines;
	if (tmp)
	{
		ft_putsquare(square, tmp->next, file);
		if (tmp->index >= square.y && tmp->index < square.y + square.size)
		{
			while (i < square.size + square.x)
			{
				tmp->line[i] = file->full;
				i++;
			}
		}
	}
}

void	ft_get_square(t_file *file, t_square square, t_square *stock_square, t_coord map)
{
	while (ft_check_coords(square, file->lines, map) != FAILURE)
		square.size++;
	if (square.size > stock_square->size)
		*stock_square = square;
}

void	ft_place_square(t_file *file)
{
	t_coord map;
	t_square square;
	t_square stock_square;

	map.x = ft_strlen(file->lines->line);
	map.y = file->nb_line;
	stock_square.size = 1;
	stock_square.x = 0;
	stock_square.y = 0;
	square.y = 0;
	while (square.y < map.y)
	{
		square.x = 0;
		while (square.x < map.x)
		{
			ft_get_square(file, square, &stock_square, map);
			square.x++;
			square.size = 1;
		}
		square.y++;
	}
	ft_putsquare(stock_square, file->lines, file);
}

void	ft_checknplace(t_file *file)
{
	t_file *tmp;

	tmp = file;
	if (tmp)
	{
		ft_checknplace(tmp->next);
		ft_place_square(tmp);
	}
}
