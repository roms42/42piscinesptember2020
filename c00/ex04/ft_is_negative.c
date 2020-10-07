/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 15:52:22 by rberthau          #+#    #+#             */
/*   Updated: 2020/09/10 22:43:20 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_is_negative(int n)
{
	char c;

	if (n >= 0)
	{
		c = 'P';
		ft_putchar(c);
	}
	else
	{
		c = 'N';
		ft_putchar(c);
	}
}
