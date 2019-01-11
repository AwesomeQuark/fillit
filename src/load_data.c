/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 18:05:59 by conoel            #+#    #+#             */
/*   Updated: 2019/01/11 13:33:01 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

static int	is_valid(char *buffer)
{
	int i;
	int j;
	int k;
	int count; //enregistre le nombre de "blocs" du tetrimino, si != 4 alors il est incorrect !

	i = -1;
	while (buffer[i + 1] != '\0')										// Tant que le fichier n'est pas fini
	{
		j = 0;
		count = 0;
		while (j++ < 4)													//tant que le tetrimino n'est pas fini
		{
			k = 0;
			while (k++ < 4)												//tant que la ligne du tetrimino n'est pas fini
			{
				i++;
				if (buffer[i] != '*' && buffer[i] != '#')				//si le caractere est invalide
					return (0);
				buffer[i] == '#' ? count++ : 0;
			}
			if (buffer[++i] != '\n')									//s'il n'y a pas de retour a la ligne a la fin de ma ligne
				return (0);
		}
		i++;															//s'il n'y a pas de retour a la ligne a la fin de mon tetrimino (on ne check si c'est le dernier tetri)
		if ((buffer[i] != '\n' && buffer[i + 1] != '\0') || (buffer[i] == '\n' 
&& buffer[i + 1] == '\0') || count != 4)
			return (0);
	}
	return (1);
}

static char	***load_tetris(char *buffer)
{
	int		data_len;
	char	***data;
	int i;
	int j;
	int k;


	data_len = ft_strlen(buffer);
	if (!(data = malloc(sizeof(*data) * (data_len / 21))))
		return (NULL);
	k = -1;
	i = 0;
	while (buffer[i + 1] != '\0')
	{
		k++;
		if (!(data[k] = malloc(sizeof(**data) * 4)))
			return (NULL);
		j = -1;
		while (j++ < 3)
		{
			if (!(data[k][j] = ft_memdup(&buffer[i], 5)))
				return (NULL);
			i += 5;
		}
		i++;
	}
	return (data);
}

char		***load_data(char *path)
{
	char		***data;
	char		buffer[MAX_FILE + 1];
	size_t		i;
	size_t		j;
	int			fd;

	i = 0;
	j = 0;
	if ((fd = open(path, O_RDONLY)) < 0)
	{
		write(2, "Wrong path !\n", 13);
		return (NULL);
	}
	buffer[read(fd, buffer, MAX_FILE)] = '\0';
	if ((ft_strlen(buffer) % 20) - ((ft_strlen(buffer) / 20) - 1) != 0)
	{
		write(2, "Incorrect file size\n", 20);
		return (NULL);
	}
	if (!is_valid(buffer))
	{
		write(2, "Wrong tetriminos formating\n", 27);
		return (NULL);
	}
	if (!(data = load_tetris(buffer)))
	{
		write(2, "Failed to memory allocate\n", 26);
		return (NULL);
	}
	return (data);
}
