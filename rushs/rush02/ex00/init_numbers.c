/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 15:21:34 by rberthau          #+#    #+#             */
/*   Updated: 2020/09/27 20:24:03 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft.h"

int	ft_malloc_sizeoftab(char *str)
{
	int strlen;
	int malsize;
	int i;
	int j;
	int k;

	i = 2;
	j = 0;
	k = 1;
	malsize = 0;
	strlen = ft_strlen(str);
	if (strlen == 1)
	{
		malsize += 1;
		return (malsize);
	}
	if ((str[1] == '0' || str[1] == '1') && strlen == 2)
	{
		malsize += 1;
		return (malsize);
	}
	else
		malsize += 2;
	while (i < strlen)
	{
		if (i++ < strlen)
			malsize += 2;
		if (i++ < strlen)
			malsize += 1;
		if (i++ < strlen)
			malsize += 2;
	}
	i = 0;
	while (i < 3)
	{
		if (i++ < strlen && str[i - 1] == '0')
			j += 1;
		if (i++ < strlen && str[i - 1] == '0')
			j += 1;
		if (i++ < strlen && str[i - 1] == '0')
			j += 1;
	}
	i = 3;
	while (i < strlen)
	{
		if (i++ < strlen && str[i - 1] == '0')
			j += 2;
		if (i++ < strlen && str[i - 1] == '0')
			j += 1;
		if (i++ < strlen && str[i - 1] == '0')
			j += 2;
	}
	while (str[k])
	{
		if (str[k] == '1' && str[k - 1] != 0)
			j++;
		k += 3;
	}
	return (malsize - j);
}

int	*ft_init_tab(char *str)
{
	int malsize;
	int i;
	int *tab;

	i = 0;
	malsize = ft_malloc_sizeoftab(str);
	if (!(tab = (int*)malloc(sizeof(int) * malsize)))
		return (NULL);
	return (tab);
}
