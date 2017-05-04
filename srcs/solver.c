/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsolis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 18:19:01 by gsolis            #+#    #+#             */
/*   Updated: 2017/02/14 18:19:07 by gsolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fillit.h"

void	fill_grid(char **d, int coord[4][2], int piece)
{
	int	i;
	int	x;
	int	y;

	i = -1;
	x = 0;
	y = 0;
	while (++i <= 3)
	{
		y = coord[i][0];
		x = coord[i][1];
		d[y][x] = 'A' + piece;
	}
}

int		transfer(int dest[4][2], int raw_coord[4][2], char **d, int piece)
{
	int i;
	int o_x;
	int o_y;

	i = -1;
	o_x = raw_coord[0][1];
	o_y = raw_coord[0][0];
	while (++i < 4)
	{
		raw_coord[i][0] = raw_coord[i][0] - o_y;
		raw_coord[i][1] = raw_coord[i][1] - o_x;
	}
	i = -1;
	while (++i < 4)
	{
		dest[i][0] = dest[0][0] + raw_coord[i][0];
		dest[i][1] = dest[0][1] + raw_coord[i][1];
	}
	if (last_check(dest, d) == 0)
		return (0);
	fill_grid(d, dest, piece);
	return (1);
}

int		check(char *tets, int yx[2], char **d, int piece)
{
	int		new_coord[4][2];
	int		coord[4][2];
	int		i;
	int		count;

	new_coord[0][0] = yx[0];
	new_coord[0][1] = yx[1];
	i = 0;
	count = 0;
	while (tets[i] != '\0' && count < 4)
	{
		if (tets[i] == '#')
		{
			coord[count][0] = i / 5;
			coord[count][1] = i % 5;
			count++;
		}
		i++;
	}
	if (transfer(new_coord, coord, d, piece) == 0)
		return (0);
	return (1);
}

void	clear_piece(int piece, char **d)
{
	int y;
	int x;

	y = 0;
	while (d[y] != '\0')
	{
		x = -1;
		while (d[y][++x] != '\0')
			if (d[y][x] == 'A' + piece)
				d[y][x] = '.';
		y++;
	}
}

int		solve(char **tets, char **d, int piece)
{
	int		yx[2];
	int		place;

	if (tets[piece] == NULL)
		return (1);
	place = -1;
	while (++place != g_size * g_size)
	{
		yx[0] = place / g_size;
		yx[1] = place % g_size;
		if (check(tets[piece], yx, d, piece))
		{
			if (solve(tets, d, piece + 1))
				return (1);
			clear_piece(piece, d);
		}
	}
	return (0);
}
