/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsolis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 17:39:18 by gsolis            #+#    #+#             */
/*   Updated: 2017/02/14 17:39:20 by gsolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fillit.h"

int			last_check(int dest[4][2], char **d)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		if (dest[i][1] > g_size - 1 || dest[i][1] < 0)
			return (0);
		if (dest[i][0] > g_size - 1 || dest[i][0] < 0 ||
				d[dest[i][0]][dest[i][1]] != '.')
			return (0);
		i++;
	}
	return (1);
}

void		print_map(char **grind)
{
	int		i;
	int		j;

	i = -1;
	while (grind[++i] != 0)
	{
		j = -1;
		while (grind[i][++j] != '\0')
			write(1, &grind[i][j], 1);
		write(1, "\n", 1);
	}
}

void		free_map(char **grind)
{
	int		i;

	i = -1;
	while (grind[++i] != 0)
	{
		free(grind[i]);
		grind[i] = NULL;
	}
	free(grind);
	grind = NULL;
}

char		**ft_map(int size)
{
	char	**grind;
	int		i;
	int		j;

	j = -1;
	i = -1;
	grind = (char**)malloc(sizeof(char*) * (size + 1));
	while (++i < size)
	{
		grind[i] = (char*)malloc(sizeof(char) * (size + 1));
		while (++j < size)
			grind[i][j] = '.';
		grind[i][j] = '\0';
		j = -1;
	}
	grind[i] = NULL;
	return (grind);
}

void		fillit(char **pieces)
{
	char	**d;
	int		solved;

	solved = 0;
	g_size = 2;
	d = NULL;
	while (solved == 0)
	{
		d = ft_map(g_size);
		if (solve(pieces, d, 0) == 1)
		{
			solved = 1;
			print_map(d);
		}
		free_map(d);
		g_size++;
	}
}
