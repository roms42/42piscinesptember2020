/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 16:55:15 by rberthau          #+#    #+#             */
/*   Updated: 2020/09/11 10:48:25 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char a, char b, char c)
{
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, &c, 1);
	if (a < '7')
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb(void)
{
	char a;
	char b;
	char c;

	a = '0';
	while (a <= '7')
	{
		b = a + 1;
		while (b <= '7')
		{
			c = b + 1;
			while (c <= '8')
			{
				ft_putchar(a, b, c);
				c++;
			}
			ft_putchar(a, b, c);
			b++;
		}
		ft_putchar(a, b, c);
		a++;
	}
}
