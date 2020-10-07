/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 17:32:02 by rberthau          #+#    #+#             */
/*   Updated: 2020/09/30 19:26:21 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int srclen;
	unsigned int destlen;

	destlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (srclen);
	if (size <= destlen)
		return (srclen + size);
	while (src[i] && (size - 1 - destlen) && size != 0)
	{
		dest[destlen + i] = src[i];
		i++;
		size--;
	}
	dest[destlen + i] = '\0';
	return (destlen + srclen);
}
