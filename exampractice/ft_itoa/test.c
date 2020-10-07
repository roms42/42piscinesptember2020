/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 16:49:14 by rberthau          #+#    #+#             */
/*   Updated: 2020/10/01 17:30:23 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char *ft_itoa(int nbr)
{
	int len;
	int i;
	long n;
	char *str;
	long n1;

	len = 0;
	i = 0;
	n = nbr;
	if (n < 0)
		n = -n;
	n1 = n;
	if (n == 0)
		len = 1;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	if (nbr < 0)
	{
		len += 1;
	}
	if (!(str = malloc(sizeof(char) * len + 1)))
		return (NULL);
	i = len - 1;
	if (nbr < 0)
	{
		while (i > 0)
		{
			str[i] = n1 % 10 + '0';
			n1 = n1 / 10;
			i--;
		}
		str[i] = '-';
	}
	else
	{
		while (i >= 0)
		{
			str[i] = n1 % 10 + '0';
			n1 = n1 / 10;
			i--;
		}
	}
	str[len] = '\0';
	return (str);
}


int main(int ac, char **av)
{
	if (ac == 2)
		printf("%s\n", ft_itoa(atoi(av[1])));
}
