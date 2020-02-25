/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 11:30:42 by lsuardi           #+#    #+#             */
/*   Updated: 2020/02/25 10:54:11 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef 	TOOLS_H

# define 	TOOLS_H
# define	SUCCESS		0
# define	FAILURE		-1
# define	BUF_SIZE	424242

# include				<sys/types.h>
# include				<sys/stat.h>
# include				<fcntl.h>
# include				<stdlib.h>
# include				<unistd.h>
# include				<stdio.h>
# include				"file.h"

void	ft_check_args(int ac, char **av);
int		ft_strlen(char *str);
void	ft_putstr(char *str);
char	*ft_strdup(char *str);
int		ft_atoin(char *str, int n);

#endif
