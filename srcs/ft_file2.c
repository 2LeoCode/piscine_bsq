/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 17:26:42 by lsuardi           #+#    #+#             */
/*   Updated: 2020/02/25 17:27:25 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/tools.h"

struct s_line	*ft_addlink_lines(t_line *lines,
		char *currentline, int index, t_file *list)
{
	t_line *tmp;

	if (!(tmp = malloc(sizeof(t_line))))
		return (NULL);
	if (tmp)
	{
		tmp->index = index - 1;
		if (!(tmp->line = ft_strdup(currentline)))
			return (NULL);
		tmp->nb_obs = ft_calc_obs(tmp->line, list);
		if (!(tmp->pos_obs = ft_pos_obs(tmp->line, list, tmp->nb_obs)))
			return (NULL);
		tmp->next = lines;
	}
	return (tmp);
}

struct s_line	*ft_addlines(char *buf, t_file *list)
{
	int		i;
	int		j;
	t_line	*lines;
	char	*curline;

	i = 0;
	j = 1;
	lines = NULL;
	while (buf[i])
	{
		curline = ft_get_line(&buf[i]);
		i += (ft_strlen(curline) + 1);
		lines = ft_addlink_lines(lines, curline, j, list);
		j++;
		if (lines == NULL)
			return (NULL);
	}
	return (lines);
}

struct s_file	*ft_addlink_file(t_file *list, int nb, char *params, char *buf)
{
	t_file	*tmp;

	if (!(tmp = malloc(sizeof(t_file))))
		return (NULL);
	if (tmp)
	{
		tmp->nb_line = nb;
		tmp->empty = params[0];
		tmp->obstacle = params[1];
		tmp->full = params[2];
		tmp->lines = ft_addlines(buf, tmp);
		if (tmp->lines == NULL)
			return (NULL);
		tmp->next = list;
	}
	return (tmp);
}

struct s_file	*ft_init_filelist(char *buf, t_file *filelist, int nb)
{
	int		i;
	char	params[3];
	int		j;

	i = 0;
	j = -1;
	while (buf[i] >= '0' && buf[i] <= '9')
		i++;
	while (++j < 3)
	{
		params[j] = buf[i];
		i++;
	}
	i++;
	filelist = ft_addlink_file(filelist, nb, params, &buf[i]);
	if (filelist == NULL)
		return (NULL);
	return (filelist);
}
