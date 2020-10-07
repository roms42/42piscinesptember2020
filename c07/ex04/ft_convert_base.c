/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 12:33:16 by rberthau          #+#    #+#             */
/*   Updated: 2020/09/30 13:01:46 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str);
int		ft_atoi_base(char *str, char *base);

int		ft_checkbase(char *str)
{
	int i;
	int j;
	int strlen;

	strlen = ft_strlen(str);
	i = 0;
	if (strlen == 1)
		return (0);
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

void	ft_putnbr_base(long nbr, char *base, char *dest)
{
	int blen;
	int k;

	k = 0;
	blen = ft_strlen(base);
	if (nbr < 0)
		nbr = -nbr;
	if (nbr == 0)
		dest[k] = base[nbr];
	while (nbr > 0)
	{
		dest[k] = base[nbr % blen];
		nbr = nbr / blen;
		k++;
	}
}

void	ft_str_rev(char *dest)
{
	char	tmp;
	int		i;
	int		destlen;

	destlen = ft_strlen(dest);
	i = 0;
	if (destlen > 0)
	{
		while (i < destlen / 2)
		{
			tmp = dest[i];
			dest[i] = dest[destlen - 1 - i];
			dest[destlen - 1 - i] = tmp;
			i++;
		}
	}
}

int		ft_sizeofdest(int nb, int btolen)
{
	long	k;
	int		j;

	j = 0;
	k = nb;
	if (k < 0)
		k = -k;
	while (k > 0)
	{
		k = k / btolen;
		j++;
	}
	if (nb <= 0)
		j += 1;
	return (j);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*dest;
	int		j;
	int		btolen;
	long	nb;

	if (!(ft_checkbase(base_from)) || !(ft_checkbase(base_to)))
		return (NULL);
	nb = ft_atoi_base(nbr, base_from);
	btolen = ft_strlen(base_to);
	j = ft_sizeofdest(nb, btolen);
	if (!(dest = (char*)malloc(sizeof(char*) * (j + 1))))
		return (NULL);
	ft_putnbr_base(nb, base_to, dest);
	if (nb < 0)
		dest[j - 1] = '-';
	dest[j] = '\0';
	ft_str_rev(dest);
	return (dest);
}

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
void	ft_putchar(char c)
{
	write(1, &c, 1);
}
void	ft_putnbr(int nb)
{
	if (nb == INT_MIN)
	{
		ft_putnbr(INT_MIN / 10);
		ft_putchar(-(INT_MIN % 10) + '0');
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
}
void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}
int		main(void)
{
	char	*nb1 = "\n\t\v\f\r ---+--+1234ab567";
	char	*nb2 = "42";
	char	*nb3 = "01";
	char	*nb4 = "0";
	char	*nb5 = "";
	char	*nb6 = "\t-24a";
	char	*nb7 = "\t-204a";
	char	*nb8 = "\t-a24a";
	char	*nb9 = "33896823";
	char	*base0 = "";
	char	*base1 = "0";
	char	*base2 = "01";
	char	*base10 = "0123456789";
	char	*base10db = "01234567891";
	char	*base10sp = " 123456789";
	char	*base10p = "0123456+789";
	char	*base10m = "0123456-789";
	char	*base10nl = "0123456\n789";
	char	*base16 = "0123456789abcdef";
	char	*basep = "poneyvif";
	char	*nb10 = "-2147483648";
	char	*result = NULL;
	ft_putstr("nb1 = \\n\\t\\v\\f\\r ---+--+1234ab567\nnb2 = 42\nnb3 = 01\nnb4 = 0\nnb5 = \"\"\nnb6 = \\t-24a\nnb7 = \\t-204a\nnb8 = \\t-a24a\nnb9 = 33896823\n");
	ft_putstr("ft_convert_base(nb1, base10, base10), result = ");
	result = ft_convert_base(nb1, base10, base10);
	if (result)
	{
		ft_putstr(result);
		free(result);
	}
	write(1, "\n", 1);
	ft_putstr("ft_convert_base(nb1, base10, base0), result = ");
	result = ft_convert_base(nb1, base10, base0);
	if (result)
	{
		ft_putstr(result);
		free(result);
	}
	write(1, "\n", 1);
	ft_putstr("ft_convert_base(nb1, base1, base10), result = ");
	result = ft_convert_base(nb1, base1, base10);
	if (result)
	{
		ft_putstr(result);
		free(result);
	}
	write(1, "\n", 1);
	ft_putstr("ft_convert_base(nb5, base10sp, base10), result = ");
	result = ft_convert_base(NULL, base10sp, base10);
	if (result)
	{
		ft_putstr(result);
		free(result);
	}
	write(1, "\n", 1);
	ft_putstr("ft_convert_base(nb1, base10db, base10), result = ");
	result = ft_convert_base(nb1, base10db, base10);
	if (result)
	{
		ft_putstr(result);
		free(result);
	}
	write(1, "\n", 1);
	ft_putstr("ft_convert_base(nb1, base10sp, base10), result = ");
	result = ft_convert_base(nb1, base10sp, base10);
	if (result)
	{
		ft_putstr(result);
		free(result);
	}
	write(1, "\n", 1);
	ft_putstr("ft_convert_base(nb1, base10p, base10), result = ");
	result = ft_convert_base(nb1, base10p, base10);
	if (result)
	{
		ft_putstr(result);
		free(result);
	}
	write(1, "\n", 1);
	ft_putstr("ft_convert_base(nb1, base10m, base10), result = ");
	result = ft_convert_base(nb1, base10m, base10);
	if (result)
	{
		ft_putstr(result);
		free(result);
	}
	write(1, "\n", 1);
	ft_putstr("ft_convert_base(nb1, base10nl, base10), result = ");
	result = ft_convert_base(nb1, base10nl, base10);
	if (result)
	{
		ft_putstr(result);
		free(result);
	}
	write(1, "\n", 1);
	ft_putstr("ft_convert_base(nb1, base10, base16), result = ");
	result = ft_convert_base(nb1, base10, base16);
	if (result)
	{
		ft_putstr(result);
		free(result);
	}
	write(1, "\n", 1);
	ft_putstr("ft_convert_base(nb2, base10, base2), result = ");
	result = ft_convert_base(nb2, base10, base2);
	if (result)
	{
		ft_putstr(result);
		free(result);
	}
	write(1, "\n", 1);
	ft_putstr("ft_convert_base(nb3, base10, base2), result = ");
	result = ft_convert_base(nb3, base10, base2);
	if (result)
	{
		ft_putstr(result);
		free(result);
	}
	write(1, "\n", 1);
	ft_putstr("ft_convert_base(nb4, base10, base2), result = ");
	result = ft_convert_base(nb4, base10, base2);
	if (result)
	{
		ft_putstr(result);
		free(result);
	}
	write(1, "\n", 1);
	ft_putstr("ft_convert_base(nb5, base10, basep), result = ");
	result = ft_convert_base(nb5, base10, basep);
	if (result)
	{
		ft_putstr(result);
		free(result);
	}
	write(1, "\n", 1);
	ft_putstr("ft_convert_base(nb6, base10, base16), result = ");
	result = ft_convert_base(nb6, base10, base16);
	if (result)
	{
		ft_putstr(result);
		free(result);
	}
	write(1, "\n", 1);
	ft_putstr("ft_convert_base(nb7, base10, base2), result = ");
	result = ft_convert_base(nb7, base10, base2);
	if (result)
	{
		ft_putstr(result);
		free(result);
	}
	write(1, "\n", 1);
	ft_putstr("ft_convert_base(nb8, base10, base16), result = ");
	result = ft_convert_base(nb8, base10, base16);
	if (result)
	{
		ft_putstr(result);
		free(result);
	}
	write(1, "\n", 1);
	ft_putstr("ft_convert_base(nb9, base10, basep), result = ");
	result = ft_convert_base(nb9, base10, basep);
	if (result)
	{
		ft_putstr(result);
		free(result);
	}
	write(1, "\n", 1);
	ft_putstr("ft_convert_base(nb10, base10, base10), result = ");
	result = ft_convert_base(nb10, base10, base10);
	if (result)
	{
		ft_putstr(result);
		free(result);
	}
	return (0);
}
