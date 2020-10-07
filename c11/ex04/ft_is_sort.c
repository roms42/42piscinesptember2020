/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 15:20:36 by rberthau          #+#    #+#             */
/*   Updated: 2020/09/30 21:05:36 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_ascendant(int *tab, int length, int (*f)(int, int))
{
	int i;
	int cmp;
	int k;

	i = 0;
	k = 0;
	while (i < length - 1)
	{
		cmp = (*f)(tab[i], tab[i + 1]);
		if (cmp > 0 || cmp == 0)
			k++;
		i++;
	}
	if (k == length - 1)
		return (1);
	return (0);
}

int	ft_descendant(int *tab, int length, int (*f)(int, int))
{
	int i;
	int cmp;
	int k;

	i = 0;
	k = 0;
	while (i < length - 1)
	{
		cmp = (*f)(tab[i], tab[i + 1]);
		if (cmp < 0 || cmp == 0)
			k++;
		i++;
	}
	if (k == length - 1)
		return (1);
	return (0);
}

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	if (!tab)
		return (1);
	if (!length || length == 1 || length == 2)
		return (1);
	if (!f)
		return (0);
	if (ft_ascendant(tab, length, f) || ft_descendant(tab, length, f))
		return (1);
	return (0);
}
