/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 09:20:52 by rberthau          #+#    #+#             */
/*   Updated: 2020/09/24 10:02:05 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putchar(char c);

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

/*void	ft_putchar(char c)
{
	write(1, &c, 1);
}*/

int		ft_checkbase(char *str)
{
	int i;
	int j;

	i = 0;
	if (str[0] == '\0' || str[1] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+' || str[i] < 32 || str[i] > 126)
			return (0);
		j = i + 1;
		while (str[j])
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		nbrnegative(int i)
{
	if (i < 0)
	{
		i *= -1;
		ft_putchar('-');
	}
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int i;
	unsigned int blen;

	i = nbr;
	blen = ft_strlen(base);
	if (ft_checkbase(base) && base != NULL)
	{
		i = nbrnegative(i);
		if (i < blen)
			ft_putchar(base[i]);
		else
		{
			ft_putnbr_base(i / blen, base);
			ft_putnbr_base(i % blen, base);
		}
	}
}
