/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsolis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 21:59:57 by gsolis            #+#    #+#             */
/*   Updated: 2017/02/08 22:00:01 by gsolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/fillit.h"

int		ft_getval(char **str)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
		if ((ft_valchar(str[i], 0, 0, 0)) == 0)
			return (0);
	return (1);
}

int		ft_getval2(char **str)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
	{
		if ((ft_valpiece(str[i])) == 0)
			return (0);
	}
	return (1);
}

int		ft_valpiece(char *str)
{
	int	units;
	int	i;

	units = 0;
	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if ((i + 1) < 20 && str[i + 1] == '#')
				units++;
			if ((i - 1) >= 0 && str[i - 1] == '#')
				units++;
			if ((i + 5) < 20 && str[i + 5] == '#')
				units++;
			if ((i - 5) >= 0 && str[i - 5] == '#')
				units++;
		}
		i++;
	}
	return (units == 6 || units == 8);
}

int		ft_valchar(char *str, int n, int h, int d)
{
	int	i;

	i = -1;
	if (str[0] == '\n')
		return (0);
	while (str[++i] != '\0')
	{
		if (str[i] == '\n')
			n++;
		if (str[i] == '#')
			h++;
		if (str[i] == '.')
			d++;
	}
	if (h != 4 || d != 12 || (n <= 4 && n >= 5))
		return (0);
	return (1);
}

char	*reader(char *s)
{
	int		fd;
	char	*buf;
	int		byte_size;
	int		i;

	fd = open(s, O_RDONLY);
	if (!fd || !(buf = (char *)malloc(sizeof(char) * SIZE)))
		return (NULL);
	byte_size = read(fd, buf, SIZE);
	buf[byte_size] = '\0';
	i = ft_len(buf);
	if (i == 0)
		ft_error();
	if (buf[byte_size - 2] == '\n')
		ft_error();
	close(fd);
	return (buf);
}
