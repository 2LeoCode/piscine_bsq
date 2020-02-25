
#include "../headers/tools.h"

void	ft_display_lines(t_line *lines)
{
	t_line *tmp;

	tmp = lines;
	if(tmp)
	{
		ft_display_lines(tmp->next);
		ft_putstr(tmp->line);
	}
	ft_putstr("\n");
}

/*void	ft_display_lines(t_line *lines)
{
	t_line *tmp;

	tmp = lines;
	while (tmp)
	{
		ft_putstr(tmp->line);
		ft_putstr("\n");
		tmp = tmp->next;
	}
	ft_putstr("\n");
}*/

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
