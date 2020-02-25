/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:22:32 by lsuardi           #+#    #+#             */
/*   Updated: 2020/02/25 21:15:37 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CALC_H

# define CALC_H

typedef struct	s_coord		t_coord;
typedef struct	s_square	t_square;

struct s_coord
{
	int x;
	int y;
};

struct s_square
{
	int size;
	int x;
	int y;
};

void	ft_place_square(t_file *file);
void	ft_get_square(t_file *file, t_square square, t_square *stock_square, t_coord map);
int		ft_check_coords(t_square square, t_line *lines, t_coord map);
void	ft_putsquare(t_square square, t_line *lines, t_file *file);
void	ft_checknplace(t_file *file);

#endif
