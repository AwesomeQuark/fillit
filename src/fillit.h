/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 18:06:05 by conoel            #+#    #+#             */
/*   Updated: 2019/01/14 13:25:55 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# define MAX_FILE 546
# define MAX_CHAR_PROMT 80
# define MAX_LINE_PROMT 25

typedef struct	s_index
{
	int		i;
	int		j;
	int		k;
}				t_index;

typedef struct	s_data
{
	char	**data;
	char	*ret;
}				t_data;

void			ft_fillit(char **data, int size_min);
char			**load_data(char *path);
void			print_data(char **data);
void			ft_free(char **data);
int				is_valid(char *buffer);
void			ft_sleep(size_t time);
int				get_size(char **data);

size_t			ft_strlen(char *s);
char			*ft_memdup(char *str, size_t size);
void			ft_putstr(char *str, int size);
void			ft_putstr_visual(char *str, int size);
void			ft_memset(char *s, size_t size, char c);
void			ft_strcat(char *s1, char *s2);

#endif
