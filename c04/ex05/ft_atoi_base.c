/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 17:23:44 by rberthau          #+#    #+#             */
/*   Updated: 2020/09/21 22:46:21 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_start(char *str, int *k)
{
	while (*str == 32 || (*str > 8 && *str < 14))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			*k *= -1;
		str++;
	}
	return (str);
}

int		ft_checkbase(char *str)
{
	int i;
	int j;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+' || str[i] < 33 || str[i] > 126)
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
	return (i);
}

int		ft_checkchar(char *str, char *base, int blen)
{
	int j;
	int i;

	i = 0;
	while (*str >= 32 && *str <= 126 && *str != '\0')
	{
		j = 0;
		while (base[j] != '\0' && *str != base[j])
			j++;
		if (j == blen)
			return (i);
		else
		{
			str++;
			i++;
		}
	}
	return (i);
}

int		ft_index(char c, char *base)
{
	int i;

	i = 0;
	while (base[i] != c && base[i])
	{
		i++;
	}
	return (i);
}

int		ft_atoi_base(char *str, char *base)
{
	int blen;
	int nb;
	int j;
	int k;

	nb = 0;
	k = 1;
	blen = ft_checkbase(base);
	if (blen != 0 && (base))
	{
		str = ft_start(str, &k);
		j = ft_checkchar(str, base, blen);
		while (j > 0)
		{
			nb = nb * blen + ft_index(*str, base);
			str++;
			j--;
		}
	}
	return (nb * k);
}
