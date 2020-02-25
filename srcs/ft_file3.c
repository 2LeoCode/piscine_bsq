/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 22:16:50 by lsuardi           #+#    #+#             */
/*   Updated: 2020/02/25 15:09:04 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/tools.h"

char	*ft_get_line(char *buf)
{
	int		i;
	char	*line;

	i = 0;
	while (buf[i] != '\n')
		i++;
	if (!(line = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (buf[i] != '\n')
	{
		line[i] = buf[i];
		i++;
	}
	line[i] = 0;
	return (line);
}

int		ft_calc_obs(char *line, t_file *list)
{
	int i;
	int cptobs;

	i = 0;
	cptobs = 0;
	while (line[i])
	{
		if (line[i] == list->obstacle)
			cptobs++;
		i++;
	}
	return (cptobs);
}

int		*ft_pos_obs(char *line, t_file *list, int nb_obs)
{
	int i;
	int j;
	int *tab;

	i = 0;
	j = 0;
	tab = malloc(sizeof(int) * nb_obs);
	while (line[i])
	{
		if (line[i] == list->obstacle)
		{
			tab[j] = i;
			j++;
		}
		i++;
	}
	return (tab);
}
