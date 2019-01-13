/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 16:43:55 by conoel            #+#    #+#             */
/*   Updated: 2019/01/13 16:33:26 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_putstr(char *str, int size)
{
	int i;
	int j;

	j = 0;
	i = size;
	while (i--)
	{
		write(1, &str[j], size);
		write(1, "\n", 1);
		j += size;
	}
	return ;
}

void		ft_putstrnor(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

static void	ft_puthead(int size)
{
	int i;

	i = 0;
	ft_putstrnor("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\
\n\n\n\n\n\n\n\n\n\n\n        /'-");
	while (i++ < size)
	{
		if (i == size / 2)
			ft_putstrnor("*FI");
		else if (i == size / 2 + 1)
			ft_putstrnor("L*L");
		else if (i == size / 2 + 2)
			ft_putstrnor("IT*");
		else
			ft_putstrnor("---");
	}
	ft_putstrnor("'\\\n");
}

static void	ft_putcolor(char c)
{
	ft_putstrnor("\033[30m");
	if (c % 6 == 0)
		ft_putstrnor("\033[41m ");
	else if (c % 6 == 1)
		ft_putstrnor("\033[42m ");
	else if (c % 6 == 2)
		ft_putstrnor("\033[43m ");
	else if (c % 6 == 3)
		ft_putstrnor("\033[44m ");
	else if (c % 6 == 4)
		ft_putstrnor("\033[45m ");
	else if (c % 6 == 5)
		ft_putstrnor("\033[46m ");
	write(1, &c, 1);
	ft_putstrnor(" \033[0m");
}

void		ft_putstr_visual(char *str, int size)
{
	int i;
	int j;

	ft_puthead(size);
	i = -1;
	while (++i < size)
	{
		j = -1;
		ft_putstrnor("        || ");
		while (++j < size)
		{
			if (str[j + (i * size)] != '.')
				ft_putcolor(str[j + (i * size)]);
			else
				ft_putstrnor("   ");
		}
		ft_putstrnor("||\n");
	}
	i = 0;
	ft_putstrnor("        \\.-");
	while (i++ < size)
		ft_putstrnor("---");
	ft_putstrnor("./\n");
	return ;
}
