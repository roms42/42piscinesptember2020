/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 22:23:15 by rberthau          #+#    #+#             */
/*   Updated: 2020/09/30 17:19:55 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int i;
	int *tab2;

	if (!(tab2 = malloc(sizeof(int) * length)))
		return (NULL);
	i = 0;
	while (i < length)
	{
		tab2[i] = (*f)(tab[i]);
		i++;
	}
	return (tab2);
}
