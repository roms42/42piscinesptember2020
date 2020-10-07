/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 13:02:26 by rberthau          #+#    #+#             */
/*   Updated: 2020/10/01 13:25:03 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int ft_atoi(char *str)
{
	int i;
	int k;
	int nb;

	i = 0;
	k = 1;
	nb = 0;
	while (ft_isspace(*str) && *str)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			k *= -1;
		str++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (nb * k);
}

#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	if (ac == 2)
	{
		printf("ft_atoi   = %d\n", ft_atoi(av[1]));
		printf("real atoi = %d\n", atoi(av[1]));
	}
}
