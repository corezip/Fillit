/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsolis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 17:11:27 by gsolis            #+#    #+#             */
/*   Updated: 2017/02/09 17:11:28 by gsolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fillit.h"

int		ft_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		t_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_error(void)
{
	write(1, "error\n", 6);
	exit(0);
}

char	**tet_split(char *s)
{
	int		i;
	int		j;
	int		count;
	char	**new;
	int		k;

	i = 0;
	k = 0;
	count = (t_strlen(s) + 1) / 21;
	new = (char**)malloc(sizeof(char*) * (count + 1));
	while (s[i] != '\0')
	{
		j = 0;
		new[k] = (char *)malloc(sizeof(char) * 22);
		while (j < 21 && s[i] != '\0')
			new[k][j++] = s[i++];
		new[k][j] = '\0';
		k++;
	}
	if (k > 26)
		return (0);
	new[k] = NULL;
	return (new);
}

char	**ft_pieces(char *s)
{
	char **pieces;

	pieces = tet_split(s);
	return (pieces);
}
