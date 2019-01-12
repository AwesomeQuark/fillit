/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 18:06:05 by conoel            #+#    #+#             */
/*   Updated: 2019/01/12 19:55:24 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

# define MAX_FILE 546

typedef struct	s_index
{
	int		i;
	int		j;
	int		k;
}				t_index;

void			ft_fillit(char **data, int size_min);
char			**load_data(char *path);
void			print_data(char **data);
void			ft_free(char **data);
int				is_valid(char *buffer);

size_t			ft_strlen(char *s);
char			*ft_memdup(char *str, size_t size);
void			ft_putstr(char *str, int size);
void			ft_memset(char *s, size_t size, char c);
int				get_size(char **data);

#endif
