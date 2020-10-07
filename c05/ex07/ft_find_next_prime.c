/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 21:59:33 by rberthau          #+#    #+#             */
/*   Updated: 2020/09/22 14:16:00 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int i;

	if (nb == 0 || nb == 1)
		return (0);
	if (nb == 2)
		return (1);
	i = 3;
	if (!(nb % 2))
		return (0);
	while (i < nb / i + 1)
	{
		if (nb % i == 0)
			return (0);
		i = i + 2;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int i;

	if (nb <= 2)
		return (2);
	i = nb;
	if (ft_is_prime(nb) == 1)
		return (nb);
	if (!(nb % 2))
		nb++;
	while (!(ft_is_prime(nb)))
	{
		nb += 2;
	}
	return (nb);
}
