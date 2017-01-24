/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsolis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 19:35:23 by gsolis            #+#    #+#             */
/*   Updated: 2017/01/22 19:35:25 by gsolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fillit.h"

int		ft_comp3(char **str, int i, int j)
{
	write(1,"4",1);

	if (str[j][i + 1] == '#' && str[j][i + 2] == '#' && str[j]
		[i + 5] =='#')
		return (1);
	else if (str[j][i + 3] == '#' && str[j][i + 4] == '#' && str[j]
			[i + 5] == '#')
			return (1);
		else
			return (0);
}

int		ft_comp2(char **str, int i, int j)
{
	write(1,"3",1);

	if (str[j][i + 1] == '#' && str[j][i + 4] == '#' && str[j]
		[i + 5] =='#')
		return (1);
	else if (str[j][i + 4] == '#' && str[j][i + 8] == '#' && str[j]
			[i + 9] == '#')
			return (1);
		else if (str[j][i + 4] == '#' && str[j][i + 7] == '#' && str[j]
			[i + 8] == '#')
			return (1);
		else if (str[j][i + 4] == '#' && str[j][i + 4] == '#' && str[j]
			[i + 6] == '#')
			return (1);
		else if (str[j][i + 2] == '#' && str[j][i + 3] == '#' && str[j]
			[i + 4] == '#')
			return (1);
		else if (str[j][i + 3] == '#' && str[j][i + 4] == '#' && str[j]
			[i + 8] == '#')
			return (1);
		else if (str[j][i + 4] == '#' && str[j][i + 5] == '#' && str[j]
			[i + 8] == '#')
			return (1);
		else if (ft_comp3(str, j, i) ==  1)
			return (1);
		else
			return (0);
}

int		ft_comp(char **str, int i, int j)
{
	while (str[j][i])
	{
		//printf("imprime %s\n", str[0]);
		if (str[j][i + 1] == '#' && str[j][i + 5] == '#' && str[j]
			[i + 6] =='#')
			return (1);
		else if (str[j][i + 4] == '#' && str[j][i + 8] == '#' && str[j]
			[i + 12] == '#')
		{
				printf("imprime %s\n", str[0]);
				return (1);
		}
		else if (str[j][i + 1] == '#' && str[j][i + 2] == '#' && str[j][i + 3]\
			== '#')
			return (1);
		else if (str[j][i + 3] == '#' && str[j][i + 4] == '#' && str[j][i + 7]\
			== '#')
			return (1);
		else if (str[j][i + 1] == '#' && str[j][i + 3] == '#' && str[j][i + 4]\
			== '#')
			return (1);
		else if (str[j][i + 4] == '#' && str[j][i + 5] == '#' && str[j][i + 9]\
			== '#')
			return (1);
		else if (ft_comp2(str, j, i) == 1)
			return (1);
		i++;
	}
	return (0);
}

int		ft_check(char **str, int i, int j)
{
	printf("%d inicio de i\n", i);
	//printf("%s\n", str[i]);
	while (j--)
	{
		while (str[j][i] != '\0')
		{
			printf("%d\n", i);
			if (str[j][i] == '#')
				{
					//printf("se encontro %c\n", str[j][i]);
					i = ft_comp(str, 0, j);
					//printf("%d\n", i);
					if (i == 1)
					{
						j++;
						i = 0;
					}
					else
						return (0);
				}
			i++;
		}
		i = 0;
	}
	return (0);
}
