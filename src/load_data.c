/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 18:05:59 by conoel            #+#    #+#             */
/*   Updated: 2019/01/11 20:13:27 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

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
			data[i][j] = data[i][j] == '#' ? (char)i + 65 : '.';
			j++;
		}
		i++;
	}
	return (data);
}

char		**load_data(char *path)
{
	char		**data;
	char		buffer[MAX_FILE + 1];
	int			fd;
	ssize_t		ret;

	if ((fd = open(path, O_RDONLY)) < 0)
		return (NULL);
	ret = read(fd, buffer, MAX_FILE + 1);
	buffer[ret] = '\0';
	if ((ft_strlen(buffer) % 20) - ((ft_strlen(buffer) / 20) - 1) != 0)
		return (NULL);
	if (!is_valid(buffer))
		return (NULL);
	if (!(data = load_tetris(buffer)))
		return (NULL);
	data = change_tetri(data);
	print_data(data);
	return (data);
}
