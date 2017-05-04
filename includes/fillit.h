/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsolis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 21:53:29 by gsolis            #+#    #+#             */
/*   Updated: 2017/02/08 21:53:31 by gsolis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define SIZE 4096
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

int			g_size;

char		*reader(char *s);
void		ft_error(void);
int			ft_getval(char **str);
int			ft_getval2(char **str);
int			ft_valpiece(char *str);
int			ft_valchar(char *str, int n, int h, int d);
char		**ft_pieces(char *s);
char		**tet_split(char *s);
int			t_strlen(char *s);
int			ft_len(char *str);
char		**ft_map(int size);
void		free_map(char **grind);
void		print_map(char **grind);
void		fillit(char **pieces);
int			solve(char **tets, char **d, int piece);
void		clear_piece(int piece, char **d);
int			check(char *tets, int yx[2], char **d, int piece);
int			transfer(int dest[4][2], int raw_coord[4][2], char **d, int piece);
void		fill_grid(char **d, int coord[4][2], int piece);
int			last_check(int dest[4][2], char **d);
void		ft_putchar(char c);
void		ft_putstr(char const *s);

#endif
