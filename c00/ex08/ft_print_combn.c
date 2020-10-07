/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 13:10:35 by rberthau          #+#    #+#             */
/*   Updated: 2020/09/12 18:56:27 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putnbr(int x)
{
	if (x >= 10)
	{
		ft_putnbr(x / 10);
		ft_putnbr(x % 10);
	}
	else
	{
		ft_putchar(x + '0');
	}
}

void	ft_assign(int *nb)
{
	nb[0] = 0;
	nb[1] = 1;
	nb[2] = 2;
	nb[3] = 3;
	nb[4] = 4;
	nb[5] = 5;
	nb[6] = 6;
	nb[7] = 7;
	nb[8] = 8;
	nb[9] = 9;
}

void	ft_print_combn(int n)
{
	int i;
	int k;
	int f;
	int nb[10];

	ft_assign(nb);
	k = 0;
	f = n - 1;
	i = nb[f];
	while (f >= 0)
	{
		while (nb[n - 1] <= 9)
		{
			while (k < n)
			{
				ft_putnbr(nb[k]);
				k++;
			}
			k = 0;
			nb[n - 1] = nb[n - 1] + 1;
		}
		nb[n - 1] = i;
		f = f - 1;
		nb[f] = nb[f] + 1;
	}
}

int	main(void)
{
	ft_print_combn(3);
}
