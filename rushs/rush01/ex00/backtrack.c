/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchheang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 17:33:11 by dchheang          #+#    #+#             */
/*   Updated: 2020/09/20 22:39:34 by dchheang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "board.h"
#include "view.h"

int	backtrack(int c, int l, Board b, int nb)
{
	Board btmp;

	btmp = init_board(4, 4);
	btmp = boardcopy(b);
	while (nb <= 4)
	{
		if (check_same_number(c, l, b, nb))
		{
			b.square[c][l] = nb;
			b = add_view(c, l, b);
			if (check_view(c, l, b))
			{
				if (c == 3 && l == 3)
				{
					print_result(b);
					return (1);
				}
				else if (l == 3)
				{
					if (backtrack(c + 1, 0, b, 1))
					{
						return (1);
					}
				}
				else
				{
					if (backtrack(c, l + 1, b, 1))
					{
						return (1);
					}
				}
			}
			b = boardcopy(btmp);
		}
		nb++;
	}
	return (0);
}
