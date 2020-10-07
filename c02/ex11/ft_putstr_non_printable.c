/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 18:19:02 by rberthau          #+#    #+#             */
/*   Updated: 2020/09/16 12:18:44 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_hexaconverter(unsigned char b)
{
	char *b16;

	b16 = "0123456789abcdef";
	if (b < 16)
		ft_putchar(b16[b]);
	else
	{
		ft_hexaconverter(b / 16);
		ft_hexaconverter(b % 16);
	}
}

void	ft_putstr_non_printable(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 32 && str[i] <= 126)
			ft_putchar(str[i]);
		else
		{
			ft_putchar('\\');
			if ((unsigned char)str[i] < 16)
			{
				ft_putchar('0');
			}
			ft_hexaconverter((unsigned char)str[i]);
		}
		i++;
	}
}
