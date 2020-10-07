/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 18:22:53 by rberthau          #+#    #+#             */
/*   Updated: 2020/09/26 10:36:56 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int					ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char				*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*stock;

	if (!(stock = (t_stock_str*)malloc(sizeof(t_stock_str) * (ac + 1))))
		return (NULL);
	i = 0;
	while (i < ac)
	{
		if (!(stock[i].size = (int)malloc(sizeof(int))))
			return (NULL);
		if (!(stock[i].str = (char*)malloc(sizeof(av[i]) * ft_strlen(av[i]))))
			return (NULL);
		if (!(stock[i].copy = (char*)malloc(sizeof(av[i]) * ft_strlen(av[i]))))
			return (NULL);
		stock[i].size = ft_strlen(av[i]);
		ft_strcpy(stock[i].str, av[i]);
		ft_strcpy(stock[i].copy, av[i]);
		i++;
	}
	stock[i].size = 0;
	stock[i].str = 0;
	stock[i].copy = 0;
	return (stock);
}
