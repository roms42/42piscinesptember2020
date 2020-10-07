/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 17:06:16 by rberthau          #+#    #+#             */
/*   Updated: 2020/09/27 20:22:07 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "getnumbers.h"
#include "read.h"
#include "init_numbers.h"
#include "struct_dict.h"

void	ft_display(char *str)
{
	t_dict	*numb;
	int		*tab;
	int		i;
	int		j;
	int		nb;

	i = ft_malloc_sizeoftab(str) - 1;
	nb = init_bufsize();
	numb = fill_dict_struct();
	tab = ft_getnumbers(str);
	while (i > 0)
	{
		j = 0;
		while (nb > 0)
		{
			if (!(ft_strcmp(ft_itoa(tab[i]), numb[j].nb)))
				ft_putstr(numb[j].lettres);
			j++;
			nb--;
		}
		i--;
	}
}
