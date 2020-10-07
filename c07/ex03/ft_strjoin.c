/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 09:43:43 by rberthau          #+#    #+#             */
/*   Updated: 2020/09/29 01:31:52 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_sizeofdest(int size, char **strs)
{
	int i;
	int j;
	int destlen;

	i = 0;
	destlen = 0;
	while (size-- > 0)
	{
		j = 0;
		while (strs[i][j])
		{
			j++;
			destlen++;
		}
		i++;
	}
	return (destlen);
}

char	*ft_assigndest(int size, char *dest, char **strs, char *sep)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	while (size-- > 0)
	{
		j = 0;
		while (strs[i][j])
			dest[k++] = strs[i][j++];
		j = 0;
		while (sep[j] && size > 0)
			dest[k++] = sep[j++];
		i++;
	}
	dest[k] = '\0';
	return (dest);
}

char	*ft_size_is_zero_one(int size, char **strs, int destlen)
{
	char	*dest;
	int		i;

	i = 0;
	if (size <= 0)
	{
		if (!(dest = malloc(sizeof(char))))
			return (NULL);
		dest[0] = '\0';
	}
	if (size == 1)
	{
		if (!(dest = (char*)malloc(sizeof(char) * (destlen + 1))))
			return (NULL);
		while (strs[0][i])
		{
			dest[i] = strs[0][i];
			i++;
		}
		dest[i] = '\0';
	}
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*dest;
	int		seplen;
	int		destlen;

	seplen = ft_strlen(sep);
	destlen = ft_sizeofdest(size, strs);
	if (size == 1 || size <= 0)
		dest = ft_size_is_zero_one(size, strs, destlen);
	else
	{
		dest = malloc(sizeof(char) * (destlen + seplen * (size - 1) + 1));
		if (!(dest))
			return (NULL);
		dest = ft_assigndest(size, dest, strs, sep);
	}
	return (dest);
}

#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
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
	char	*array[5] = {"Hello", "world", "", "!", "\n"};
	char	*sep = " ";
	char	*result = NULL;
	ft_putstr("0 = Hello, 1 = world, 2 = \"\", 3 = !, 4 = \\n, sep = \' \'\nResult : ");
	result = ft_strjoin(5, array, sep);
	if (result)
	{
		ft_putstr(result);
		free(result);
	}
/*	array[3] = NULL;
	ft_putstr("0 = Hello, 1 = world, 2 = !, 3 = NULL, 4 = \\n, sep = \' \'\nResult : ");
	result = ft_strjoin(5, array, sep);
	if (result)
	{
		ft_putstr(result);
		free(result);
	}
*/	ft_putstr("Now with size = 0\nResult : ");
	result = ft_strjoin(0, array, sep);
	if (result)
	{
		if (result[0] == '\0')
			ft_putstr("\"Empty string\"");
		free(result);
	}
	write(1, "\n", 1);
	ft_putstr("Now with size = -10\nResult : ");
	result = ft_strjoin(-10, array, sep);
	if (result)
	{
		if (result[0] == '\0')
			ft_putstr("\"Empty string\"");
		free(result);
	}
	write(1, "\n", 1);
	ft_putstr("Now with sep = \"\"\nResult : ");
	result = ft_strjoin(5, array, "");
	if (result)
	{
		ft_putstr(result);
		free(result);
	}
/*	ft_putstr("Now with sep = \"NULL\"\nResult : ");
	result = ft_strjoin(5, array, NULL);
	if (result)
	{
		ft_putstr(result);
		free(result);
	}
	ft_putstr("Now with strs = \"NULL\"\nResult : ");
	result = ft_strjoin(5, NULL, sep);
	if (result)
	{
		if (result[0] == '\0')
			ft_putstr("\"Empty string\"");
		free(result);
	}
*/	return (0);
}
