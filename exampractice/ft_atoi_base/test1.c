/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 13:26:36 by rberthau          #+#    #+#             */
/*   Updated: 2020/10/01 16:26:07 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char *ft_strlowcase(const char *str)
{
	int i;
	char *str1;

	i = 0;
	str1 = (char*)str;
	while (str[i])
	{
		if (str1[i] >= 'A' && str1[i] <= 'F')
			str1[i] += 32;
		i++;
	}
	return (str1);
}

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

char *ft_createbase(int str_base)
{
	int i;
	char *base;
	char *dest;

	base = "0123456789abcdef";
	if (!(dest = malloc(sizeof(char) * str_base + 1)))
		return (NULL);
	i = 0;
	while (i < str_base)
	{
		dest[i] = base[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int ft_checkstr(char c, char *base)
{
	int i;
	int baselen;

	i = 0;
	baselen = ft_strlen(base);
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (0);
}

int ft_atoi_base(const char *str, int str_base)
{
	int size;
	int k;
	int nb;
	char *base;
	int baselen;
	int i;

	size = 0;
	k = 1;
	nb = 0;
	i = 0;
	ft_strlowcase(str);
	base = ft_createbase(str_base);
	baselen = ft_strlen(base);
	while (ft_isspace(*str))
			str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			k *= -1;
		str++;
	}
	while ((ft_checkstr(str[size], base)))
		size++;
	while (i < size)
	{
		nb = nb * baselen + ft_checkstr(str[i], base);
		i++;
	}
	return (nb * k);
}

int main(int ac, char **av)
{
	if (ac == 3)
	{
		printf("%d\n", ft_atoi_base((av[1]), atoi(av[2])));
	}
}
