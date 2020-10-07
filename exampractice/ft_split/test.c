/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 20:06:32 by rberthau          #+#    #+#             */
/*   Updated: 2020/10/01 22:00:35 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int ft_is_charset(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

int	ft_countwords(char *str)
{
	int i;
	int word;

	word = 0;
	while (*str)
	{
		i = 0;
		while (*str && ft_is_charset(*str))
			str++;
		while (str[i] && (!(ft_is_charset(str[i]))))
			i++;
		if (i)
			word++;
		str = str + i;
	}
	return (word);
}

int ft_wordlen(char *str)
{
	int i;

	i = 0;
	while (*str && ft_is_charset(*str))
		str++;
	while (str[i] && (!(ft_is_charset(str[i]))))
		i++;
	return (i);
}

char *ft_wordcopy(char *str, int wordlen)
{
	int i;
	char *dest;

	i = 0;
	if (!(dest = malloc(sizeof(char) * wordlen + 1)))
		return (NULL);
	while (i < wordlen)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char    **ft_split(char *str)
{
	int wordlen;
	int word;
	char **tab;
	int i;

	i = 0;
	word = ft_countwords(str);
	if (!(tab = malloc(sizeof(char*) * word + 1)))
		return (NULL);
	tab[word] = NULL;
	while (word > 0)
	{
		wordlen = ft_wordlen(str);
		while (*str && ft_is_charset(*str))
			str++;
		tab[i] = ft_wordcopy(str, wordlen);
		i++;
		word--;
		str = str + wordlen;
	}
	return (tab);
}

int main(int ac, char **av)
{
	char **tab;
	int i;

	i = 0;
	if (ac == 2)
	{
		tab = ft_split(av[1]);
		while (tab[i])
		{
			printf("%s\n", tab[i]);
			i++;
		}
	}
}
