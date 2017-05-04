/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsolis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 21:58:04 by gsolis            #+#    #+#             */
/*   Updated: 2017/02/08 21:58:06 by gsolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fillit.h"

int			main(int argc, char **argv)
{
	char	*buf;
	char	**pieces;

	g_size = 2;
	if (argc != 2)
	{
		ft_putstr("usage: fillit [file]\n");
		exit(1);
	}
	buf = reader(argv[1]);
	pieces = ft_pieces(buf);
	if ((ft_getval(pieces)) == 0)
		ft_error();
	if ((ft_getval2(pieces)) == 0)
		ft_error();
	fillit(pieces);
	return (0);
}
