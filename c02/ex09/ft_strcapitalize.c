/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 11:22:34 by rberthau          #+#    #+#             */
/*   Updated: 2020/09/17 09:43:32 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strnumeric(char c)
{
	if (c < '0' || c > '9')
	{
		return (1);
	}
	return (0);
}

int		ft_stralpha(char c)
{
	if ((c < 'A' || c > 'Z') && (c < 'a' || c > 'z'))
	{
		return (1);
	}
	return (0);
}

char	*ft_strlowcase(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] + 32;
		}
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	ft_strlowcase(str);
	if (i == 0)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
	}
	while (str[i])
	{
		if (ft_strnumeric(str[i - 1]) == 1 && ft_stralpha(str[i - 1]) == 1)
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] -= 32;
		}
		i++;
	}
	return (str);
}
