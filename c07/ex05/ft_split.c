/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 12:24:54 by rberthau          #+#    #+#             */
/*   Updated: 2020/09/28 16:38:36 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_charset(char c, char *charset)
{
	int i;

	i = -1;
	while (charset[++i])
	{
		if (c == charset[i])
			return (1);
	}
	return (0);
}

int		ft_countwords(char *str, char *charset)
{
	int i;
	int word;

	word = 0;
	while (*str)
	{
		i = 0;
		while (*str && ft_charset(*str, charset))
			str++;
		while (str[i] && !(ft_charset(str[i], charset)))
			i++;
		if (i)
			word++;
		str = str + i;
	}
	return (word);
}

int		ft_wordlen(char *str, char *charset)
{
	int i;

	i = 0;
	while (*str && ft_charset(*str, charset))
		str++;
	while (str[i] && !(ft_charset(str[i], charset)))
		i++;
	return (i);
}

char	*ft_stockword(int wordlen, char *str)
{
	int		j;
	char	*dest;

	j = 0;
	if (!(dest = malloc(sizeof(char) * (wordlen + 1))))
		return (NULL);
	while (wordlen-- > 0)
	{
		dest[j] = str[j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		word;
	int		wordlen;
	int		i;

	i = 0;
	word = ft_countwords(str, charset);
	if (!(tab = malloc(sizeof(char*) * word + 1)))
		return (NULL);
	tab[word] = 0;
	while (word-- > 0)
	{
		wordlen = ft_wordlen(str, charset);
		while (*str && ft_charset(*str, charset))
			str++;
		tab[i] = ft_stockword(wordlen, str);
		str += wordlen;
		i++;
	}
	return (tab);
}
