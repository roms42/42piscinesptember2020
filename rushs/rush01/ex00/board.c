/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchheang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 20:48:20 by dchheang          #+#    #+#             */
/*   Updated: 2020/09/20 22:42:21 by dchheang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "types.h"
#include "array.h"
#include "params.h"

Board		init_square(Board b, int size1, int size2)
{
	int i;
	int j;

	i = 0;
	while (i < size1)
	{
		j = 0;
		while (j < size2)
		{
			b.square[i][j] = 0;
			j++;
		}
		i++;
	}
	return (b);
}

Board		init_views(Board b, int size1, int size2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < size1)
	{
		j = 0;
		while (j < size2)
		{
			b.colview[i][j].value = 0;
			b.colview[i][j].max = 0;
			b.rowview[i][j].value = 0;
			b.rowview[i][j].max = 0;
			j++;
		}
		i++;
	}
	return (b);
}

Board		init_board(int ncolumn, int nrow)
{
	int		i;
	int		j;
	Board	b;

	j = 0;
	i = 0;
	b.nrow = nrow;
	b.ncolumn = ncolumn;
	b.square = NULL;
	b.colview = NULL;
	b.rowview = NULL;
	b.colview = create_view_array(2, ncolumn);
	b.rowview = create_view_array(2, nrow);
	b.square = create_square_array(ncolumn, nrow);
	b = init_square(b, nrow, ncolumn);
	b = init_views(b, 2, ncolumn);
	return (b);
}

Board		boardcopy(Board src)
{
	int		i;
	int		j;
	Board	dest;

	dest = init_board(src.ncolumn, src.nrow);
	i = 0;
	while (i < src.ncolumn)
	{
		j = 0;
		while (j < src.nrow)
		{
			dest.square[i][j] = src.square[i][j];
			j++;
		}
		i++;
	}
	i = 0;
	while (i < 2)
	{
		j = 0;
		while (j < src.ncolumn)
		{
			dest.colview[i][j].value = src.colview[i][j].value;
			dest.colview[i][j].max = src.colview[i][j].max;
			j++;
		}
		i++;
	}
	i = 0;
	while (i < 2)
	{
		j = 0;
		while (j < src.nrow)
		{
			dest.rowview[i][j].value = src.rowview[i][j].value;
			dest.rowview[i][j].max = src.rowview[i][j].max;
			j++;
		}
		i++;
	}
	return (dest);
}

void		print_result(Board b)
{
	int c;
	int l;

	l = 3;
	if (b.square != NULL)
	{
		while (l >= 0)
		{
			c = 0;
			while (c < 4)
			{
				ft_putchar(b.square[c][l] + '0');
				if (c != 4)
					ft_putchar(' ');
				c++;
			}
			ft_putchar('\n');
			l--;
		}
	}
}
