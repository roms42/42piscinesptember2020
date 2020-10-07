/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 18:00:52 by rberthau          #+#    #+#             */
/*   Updated: 2020/09/27 20:31:26 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "display.h"
#include "ft.h"
#include "params.h"

int	main(int ac, char **av)
{
	check_params(ac, av);
	if (ac == 2)
		ft_display(av[1]);
	else if (ac == 3)
		ft_display(av[2]);
	return (0);
}
