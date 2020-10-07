/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 15:42:24 by rberthau          #+#    #+#             */
/*   Updated: 2020/09/30 17:22:38 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_plus(int a, int b)
{
	int res;

	res = a + b;
	return (res);
}

int	ft_minus(int a, int b)
{
	int res;

	res = a - b;
	return (res);
}

int	ft_div(int a, int b)
{
	int res;

	res = a / b;
	return (res);
}

int	ft_mod(int a, int b)
{
	int res;

	res = a % b;
	return (res);
}

int	ft_times(int a, int b)
{
	int res;

	res = a * b;
	return (res);
}
