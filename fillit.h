/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsolis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 18:47:41 by gsolis            #+#    #+#             */
/*   Updated: 2017/01/22 18:47:47 by gsolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "./libft/libft.h"

int				main(int args, char **argv);
int				ft_space(char *str);
int				ft_check(char **str, int i, int j);
int				ft_comp(char **str, int i, int j);
int				ft_comp2(char **str, int i, int j);
int				ft_comp3(char **str, int i, int j);

#endif