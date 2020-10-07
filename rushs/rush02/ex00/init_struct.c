/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 16:52:25 by rberthau          #+#    #+#             */
/*   Updated: 2020/09/27 20:23:11 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_dict.h"
#include <stdlib.h>

t_dict	*init_struct_tab(int size, int size2)
{
	t_dict	*dict;
	int		i;

	i = 0;
	if (!(dict = malloc(sizeof(dict) * size + 1)))
		return (NULL);
	while (i < size)
	{
		if (!(dict[i].nb = malloc(sizeof(char) * size2)))
			return (NULL);
		if (!(dict[i].lettres = malloc(sizeof(char) * size2)))
			return (NULL);
		i++;
	}
	return (dict);
}
