/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 19:56:21 by rberthau          #+#    #+#             */
/*   Updated: 2020/09/20 22:17:18 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

int		check_same_number(int c, int l, Board b, int nb)
{
	int i;

	i = c - 1;
	while (i >= 0)
	{
		if (nb == b.square[i][l])
			return (0);
		i--;
	}
	i = l - 1;
	while (i >= 0)
	{
		if (nb == b.square[c][i])
			return (0);
		i--;
	}
	return (1);
}

void	add_rowview(int i, int c, int l, Board b)
{
	if (i >= 0)
	{
		if (b.square[c][l] < b.square[i][l])
			b.rowview[1][l].value += 1;
		while ((b.square[c][l] > b.square[i][l]) && i > 0)
		{
			i--;
		}
		if (b.square[c][l] > b.square[i][l] && i == 0)
		{
			b.rowview[0][l].value += 1;
			b.rowview[1][l].value = 1;
		}
	}
}

void	add_colview(int i, int c, int l, Board b)
{
	if (i >= 0)
	{
		if (b.square[c][l] < b.square[c][i])
			b.colview[1][c].value += 1;
		while ((b.square[c][l] > b.square[c][i]) && i > 0)
		{
			i--;
		}
		if (b.square[c][l] > b.square[c][i] && i == 0)
		{
			b.colview[0][c].value += 1;
			b.colview[1][c].value = 1;
		}
	}
}

Board	add_view(int c, int l, Board b)
{
	int i;

	if (l == 0)
	{
		b.colview[0][c].value = 1;
		b.colview[1][c].value = 1;
	}
	if (c == 0)
	{
		b.rowview[0][l].value = 1;
		b.rowview[1][l].value = 1;
	}
	if (!c && !l)
	{
		return (b);
	}
	i = c - 1;
	add_rowview(i, c, l, b);
	i = l - 1;
	add_colview(i, c, l, b);
	return (b);
}

int		check_view(int c, int l, Board b)
{
	if (b.colview[0][c].value > b.colview[0][c].max
			|| b.rowview[0][l].value > b.rowview[0][l].max)
		return (0);
	if (l == 3)
	{
		if (b.colview[0][c].value > b.colview[0][c].max
			|| b.colview[1][c].value > b.colview[1][c].max)
			return (0);
	}
	if (c == 3)
	{
		if (b.rowview[0][l].value > b.rowview[0][l].max
				|| b.rowview[1][l].value > b.rowview[1][l].max)
			return (0);
	}
	return (1);
}
