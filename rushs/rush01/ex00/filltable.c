/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcottet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 22:10:25 by pcottet           #+#    #+#             */
/*   Updated: 2020/09/20 22:10:38 by pcottet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "types.h"

void	fill_c_table(char *str, Board b)
{
	int i;
	int j;
	int index;

	i = 0;
	j = 0;
	index = 1;
	while (i <= 14)
	{
		if (j > 3)
		{
			index--;
			j = 0;
		}
		b.colview[index][j].max = str[i] - '0';
		j++;
		i = i + 2;
	}
}

void	fill_r_table(char *str, Board b)
{
	int i;
	int j;
	int index;

	i = 16;
	j = 3;
	index = 0;
	while (i <= 30)
	{
		if (j < 0)
		{
			index++;
			j = 3;
		}
		b.rowview[index][j].max = str[i] - '0';
		j--;
		i = i + 2;
	}
}

void	fill_rc_table(char *str, Board b)
{
	fill_r_table(str, b);
	fill_c_table(str, b);
}
