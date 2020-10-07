/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 16:27:28 by rberthau          #+#    #+#             */
/*   Updated: 2020/10/01 16:40:00 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long int n;

	n = nb;
	if (n < 0)
	{
		n = -n;
		ft_putchar('-');
	}
	if (n > 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	if (n <= 10)
		ft_putchar(n + '0');
}

int main(int ac, char **av)
{
	if (ac == 2)
	ft_putnbr(atoi(av[1]));
}
