/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flanet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 15:52:35 by flanet            #+#    #+#             */
/*   Updated: 2020/09/27 16:06:53 by flanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_params(int argc, char **argv)
{
	if (argc < 2 || argc > 3)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (argc == 2)
	{
		if (argv[1] < 0)
		{
			write(1, "Error\n", 6);
			return (1);
		}
	}
	if (argc == 3)
	{
		if (argv[2] < 0)
		{
			write(1, "Error\n", 6);
			return (1);
		}
	}
	return (0);
}
