/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 17:42:01 by rberthau          #+#    #+#             */
/*   Updated: 2020/09/27 20:20:24 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_len(int nb)
{
	int len;

	len = 0;
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int nb)
{
	int		len;
	char	*dest;

	len = ft_len(nb);
	if (!(dest = malloc(sizeof(char) * len + 1)))
		return (NULL);
	dest[len] = '\0';
	len--;
	while (len >= 0)
	{
		dest[len] = '0' + (nb % 10);
		nb = nb / 10;
		len--;
	}
	return (dest);
}
