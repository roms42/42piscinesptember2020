/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgrondin <sg9031@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 12:53:11 by sgrondin          #+#    #+#             */
/*   Updated: 2020/09/13 22:10:20 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char x);

void	print_line(int x, int y, int i, int j)
{
	if (i == 0 || i == x - 1)
	{
		if (j == 0)
			ft_putchar('A');
		else if (j == y - 1)
			ft_putchar('C');
		else
			ft_putchar('B');
	}
	else
	{
		if (j == 0 || j == y - 1)
			ft_putchar('B');
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
