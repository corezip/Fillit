/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsolis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 18:03:27 by gsolis            #+#    #+#             */
/*   Updated: 2017/01/22 18:03:29 by gsolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h" 

int	ft_space(char *str)
{
	char **ret;
	int i;
	int j;

	ret = ft_strsplit(str, '\0');
	i = ft_check(ret, 0, 1);
	if (i == 0)
		return (-1);
	//else
	//	ft_solve(**str);
	return (1);
}

int	main(int args, char **argv)
{
	char *ret;
	int i = 0;
	int fd;
	char buff[1024];
	size_t bytes;

	i = i + args;
	if (args != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	bytes = read(fd,buff,1024);
	buff[bytes] = '\0';
	i = ft_space(buff);
	if (i == -1)
	{
		//write(1, "error", 5);
		return (0);
	}
	else
		write(1, "fine!", 5);
	return (0);
}
