/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 16:04:34 by rberthau          #+#    #+#             */
/*   Updated: 2020/09/30 20:54:57 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft.h>

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int		do_op(char c, char *s1, char *s2)
{
	int (*tabf[5])(int, int);

	tabf[0] = &ft_plus;
	tabf[1] = &ft_minus;
	tabf[2] = &ft_div;
	tabf[3] = &ft_mod;
	tabf[4] = &ft_times;
	if (c == '+')
		return (tabf[0](ft_atoi(s1), ft_atoi(s2)));
	if (c == '-')
		return (tabf[1](ft_atoi(s1), ft_atoi(s2)));
	if (c == '/')
		return (tabf[2](ft_atoi(s1), ft_atoi(s2)));
	if (c == '%')
		return (tabf[3](ft_atoi(s1), ft_atoi(s2)));
	if (c == '*')
		return (tabf[4](ft_atoi(s1), ft_atoi(s2)));
	return (0);
}

int		ft_check_op(char *s1)
{
	if (s1[0] != '+' && s1[0] != '-' && s1[0] != '/'
			&& s1[0] != '%' && s1[0] != '*')
		return (1);
	return (0);
}

int		ft_check_params(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i])
		i++;
	if (i > 1 || ft_check_op(s1))
	{
		ft_putstr("0\n");
		return (0);
	}
	if (s1[0] == '/' && s2[0] == '0')
	{
		ft_putstr("Stop : division by zero\n");
		return (0);
	}
	if (s1[0] == '%' && s2[0] == '0')
	{
		ft_putstr("Stop : modulo by zero\n");
		return (0);
	}
	return (1);
}

int		main(int ac, char **av)
{
	if (ac == 4)
	{
		if (!(ft_check_params(av[2], av[3])))
			return (0);
		if ((ft_check_op(av[2])))
			return (0);
		ft_putnbr(do_op(av[2][0], av[1], av[3]));
		ft_putstr("\n");
		return (0);
	}
	return (0);
}
