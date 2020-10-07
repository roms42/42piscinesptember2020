/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 09:59:31 by rberthau          #+#    #+#             */
/*   Updated: 2020/09/21 18:54:26 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long lnb;

	lnb = nb;
	if (lnb < 0)
	{
		ft_putchar('-');
		lnb = -lnb;
	}
	if (lnb >= 10)
	{
		ft_putnbr(lnb / 10);
		ft_putnbr(lnb % 10);
	}
	else
		ft_putchar(lnb + '0');
}
