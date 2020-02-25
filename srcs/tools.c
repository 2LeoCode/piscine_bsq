/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 12:58:46 by lsuardi           #+#    #+#             */
/*   Updated: 2020/02/25 15:10:59 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/tools.h"

int		ft_atoin(char *str, int n)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	while (str[i] && i < n)
	{
		nb *= 10;
		nb += str[i] - 48;
		i++;
	}
	return (nb);
}

void	ft_check_args(int ac, char **av)
{
	if (ac == 1)
		printf("wip\n");
		//ft_read_std();
	else
		ft_read_file(ac, av);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*point;

	i = 0;
	while (str[i])
		i++;
	if (!(point = (char*)malloc(i + 1)))
		return (NULL);
	i = -1;
	while (str[++i])
		point[i] = str[i];
	point[i] = 0;
	return (point);
}
