/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <romain.berthaud812@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 11:43:11 by rberthau          #+#    #+#             */
/*   Updated: 2020/09/13 22:09:02 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char x);

void	print_line(int x, int y, int i, int j)
{
	if (j == 0 || j == y - 1)
	{
		if ((i == 0 && j == 0) || (i == x - 1 && j == y - 1))
			ft_putchar('/');
		else if ((i == 0 && j == y - 1) || (i == x - 1 && j == 0))
			ft_putchar('\\');
		else
			ft_putchar('*');
	}
	else
	{
		if (i == 0 || i == x - 1)
			ft_putchar('*');
		else
			ft_putchar(' ');
	}
}

void	rush(int x, int y)
{
	int i;
	int j;

	if (x > 0 && y > 0)
	{
		i = 0;
		j = 0;
		while (j < y)
		{
			while (i < x)
			{
				print_line(x, y, i, j);
				i++;
			}
			ft_putchar('\n');
			j++;
			i = 0;
		}
	}
}
