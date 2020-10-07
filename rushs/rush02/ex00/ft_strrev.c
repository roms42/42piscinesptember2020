/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 11:44:55 by rberthau          #+#    #+#             */
/*   Updated: 2020/09/27 20:19:56 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_strrev(char *dest)
{
	char	tmp;
	int		i;
	int		destlen;

	destlen = ft_strlen(dest);
	i = 0;
	destlen = destlen - 1;
	if (destlen > 0)
	{
		while (i < destlen)
		{
			tmp = dest[i];
			dest[i] = dest[destlen];
			dest[destlen] = tmp;
			i++;
			destlen--;
		}
	}
	return (dest);
}
