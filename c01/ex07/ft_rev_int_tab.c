/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 18:59:22 by rberthau          #+#    #+#             */
/*   Updated: 2020/09/14 10:08:38 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int tmp;
	int c;
	int d;

	c = size;
	d = size;
	while (c > (size / 2))
	{
		tmp = tab[c - 1];
		tab[c - 1] = tab[size - d];
		tab[size - c] = tmp;
		c--;
		d--;
	}
}
