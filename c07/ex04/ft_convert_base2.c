/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 18:08:51 by rberthau          #+#    #+#             */
/*   Updated: 2020/09/25 13:25:37 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		i++;
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
	blen = ft_strlen(base);
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
