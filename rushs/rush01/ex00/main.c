/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchheang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 22:44:31 by dchheang          #+#    #+#             */
/*   Updated: 2020/09/20 22:47:16 by dchheang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "board.h"
#include "params.h"
#include "filltable.h"
#include "backtrack.h"

int	main(int argc, char **argv)
{
	Board b;

	b = init_board(4, 4);
	if (argc != 2 || !check_string(argv[1]))
	{
		ft_putstr("error\n");
		return (0);
	}
	fill_rc_table(argv[1], b);
	backtrack(0, 0, b, 1);

	return (0);
}
