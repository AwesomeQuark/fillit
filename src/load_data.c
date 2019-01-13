/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 18:05:59 by conoel            #+#    #+#             */
/*   Updated: 2019/01/13 17:52:00 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	**load_tetris(char *buffer)
{
	int		data_len;
	char	**data;
	t_index	ind;

	data_len = (int)ft_strlen(buffer);
	if (!(data = malloc(sizeof(*data) * (unsigned long)((data_len + 1) / 21
) + 1)))
		return (NULL);
	ind.i = 0;
	ind.j = 0;
	while (ind.i < data_len)
	{
		if (!(data[ind.j] = ft_memdup(&buffer[ind.i], 20)))
			return (NULL);
		ind.j++;
		ind.i += 21;
	}
	data[ind.j] = NULL;
	return (data);
}

static void	decal_horizontal(char *tetri)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (tetri[i] != '.')
			break ;
		i++;
	}
	if (i == 4)
	{
		i = 0;
		while (i < 5)
		{
			tetri[i] = tetri[i + 5];
			tetri[i + 5] = tetri[i + 10];
			tetri[i + 10] = tetri[i + 15];
			tetri[i + 15] = '.';
			i++;
		}
		decal_horizontal(tetri);
	}
}

static void	decal_vertical(char *tetri)
{
	int i;

	i = 0;
	while (i < 20)
	{
		if (tetri[i] != '.')
			break ;
		i += 5;
	}
	if (i == 20)
	{
		i = 0;
		while (i < 20)
		{
			tetri[i] = tetri[i + 1];
			tetri[i + 1] = tetri[i + 2];
			tetri[i + 2] = tetri[i + 3];
			tetri[i + 3] = '.';
			i += 5;
		}
		decal_vertical(tetri);
	}
}

static char	**change_tetri(char **data)
{
	int i;
	int j;

	i = 0;
	while (data[i])
	{
		j = 0;
		while (data[i][j] != '\0')
		{
			if (data[i][j] == '#')
				data[i][j] = (char)i + 65;
			if (data[i][j] == '\n')
				data[i][j] = '.';
			j++;
		}
		decal_horizontal(data[i]);
		decal_vertical(data[i]);
		i++;
	}
	return (data);
}

char		**load_data(char *path)
{
	char		**data;
	char		buffer[MAX_FILE + 2];
	int			fd;
	ssize_t		ret;

	if ((fd = open(path, O_RDONLY)) < 0)
		return (NULL);
	ret = read(fd, buffer, MAX_FILE + 1);
	close(fd);
	buffer[ret] = '\0';
	buffer[ret + 1] = '\0';
	if (((ft_strlen(buffer) + 1) % 21) != 0)
		return (NULL);
	if (!is_valid(buffer))
		return (NULL);
	if (!(data = load_tetris(buffer)))
		return (NULL);
	data = change_tetri(data);
	return (data);
}
