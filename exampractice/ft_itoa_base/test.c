/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 18:11:14 by rberthau          #+#    #+#             */
/*   Updated: 2020/10/01 19:15:37 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char *ft_create_base(int base)
{
	char *base1;
	char *dest;
	int i;

	i = 0;
	base1 = "0123456789ABCDEF";
	if (!(dest = malloc(sizeof(char) * base + 1)))
			return (NULL);
	while (i < base)
	{
		dest[i] = base1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_itoa_base(int value, int base)
{
	int long n;
	int long nb;
	int len;
	int i;
	char *base1;
	char *dest;


	base1 = ft_create_base(base);
	n = value;
	len = 0;
	i = 0;
	if (value < 0)
		n = -n;
	nb = n;
	while (nb > 0)
	{
		nb = nb / base;
		len ++;
	}
	if (value == 0)
		len = 1;
	if (value < 0 && base == 10)
		len += 1;
	if (!(dest = malloc(sizeof(char) * len + 1)))
		return (NULL);
	i = len - 1;
	if (value < 0 && base == 10)
	{
		while (i > 0)
		{
			dest[i] = base1[n % base];
			n = n / base;
			i--;
		}
		dest[i] = '-';
	}
	else
	{
		while (i >= 0)
		{
			dest[i] = base1[n % base];
			n = n / base;
			i--;
		}
	}
	dest[len] = '\0';
	return (dest);
}

int main(int ac, char **av)
{
	if (ac == 3)
		printf("%s\n", ft_itoa_base(atoi(av[1]), atoi(av[2])));
}
