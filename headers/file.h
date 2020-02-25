/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 13:15:01 by lsuardi           #+#    #+#             */
/*   Updated: 2020/02/25 13:54:01 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef 	FILE_H

# define	FILE_H

typedef struct 	s_file t_file;
typedef struct	s_line t_line;

struct			s_file
{
	int		nb_line;
	char	empty;
	char	obstacle;
	char	full;
	t_line	*lines;
	t_file	*next;
};

struct			s_line
{
	int		index;
	char	*line;
	int		nb_obs;
	int		*pos_obs;
	t_line	*next;
};

int				ft_open_file(int *fd, char *arg);
int				ft_close_file(int *file);
int				ft_get_file(char *path, char *buf);
int				ft_read_file(int ac, char **av);
int				ft_atoin(char *str, int n);
struct s_line	*ft_addlink_lines(t_line *lines, char *currentline, int index, t_file *list);
struct s_line	*ft_addlines(char *buf, t_file *list);
struct s_file	*ft_addlink_file(t_file *list, int nb, char *params, char *buf);
struct s_file	*ft_init_filelist(char *buf, t_file *filelist, int nb);
char			*ft_get_line(char *buf);
int				ft_calc_obs(char *line, t_file *list);
int				*ft_pos_obs(char *line, t_file *list, int nb_obs);
void			ft_display_lines(t_line *lines);
void			ft_display_files(t_file *files);
int				ft_check_files(char *buf);

#endif
