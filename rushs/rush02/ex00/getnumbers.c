/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getnumbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 14:35:32 by rberthau          #+#    #+#             */
/*   Updated: 2020/09/27 20:33:25 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft.h"
#include "init_numbers.h"

int	ft_zero(char *str)
{
	int j;

	j = 0;
	if (ft_strlen(str) == 1 && str[0] == '0')
		return (0);
	return (1);
}

int	*ft_getnumbers(char *str)
{
	int		i;
	int		j;
	int		k;
	int		*tab;
	char	*dest;

	ft_strrev(str);
	if (!(dest = (char*)malloc(sizeof(char) * 3)))
		return (NULL);
	tab = ft_init_tab(str);
	i = 0;
	j = 0;
	k = 3;
	while (*str != '\0')
	{
		if (ft_zero(str) == 0)
		{
			tab[i] = 0;
			return (tab);
		}
		if (str[1] != '\0' && str[1] != '1')
		{
			i = 0;
			if (str[i] != '0')
				tab[j++] = str[i] - '0';
			if (str[i++] && str[i] != '0')
				tab[j++] = (str[i] - '0') * 10;
			str += 2;
		}
		else
		{
			if (str[0] != 0)
				tab[j++] = ft_atoi(ft_strrev(ft_strncpy(dest, str, 2)));
			str += 2;
		}
		if (*str != '\0' && str[0] != '0')
		{
			tab[j++] = 100;
			tab[j++] = *str - '0';
		}
		str++;
		if (*str != '\0' && (str[0] != '0' || str[1] != '0' || str[2] != '0'))
			tab[j++] = ft_power(10, k);
		k += 3;
	}
	return (tab);
}
