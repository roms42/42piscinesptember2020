/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchheang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 22:01:54 by dchheang          #+#    #+#             */
/*   Updated: 2020/09/20 22:38:50 by dchheang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "types.h"
#include "array.h"

int		**create_square_array(int size1, int size2)
{
	int **array;
	int i;

	i = 0;
	array = malloc(sizeof(int*) * size1);
	if (array == NULL)
		return (NULL);
	while (i < size1)
	{
		array[i] = malloc(sizeof(int) * size2);
		if (array[i] == NULL)
			return (NULL);
		i++;
	}
	return (array);
}

View	**create_view_array(int size1, int size2)
{
	int		i;
	View	**view;

	view = malloc(sizeof(View) * size1);
	if (view == NULL)
		return (NULL);
	i = 0;
	while (i < size1)
	{
		view[i] = malloc(sizeof(View) * size2);
		i++;
	}
	return (view);
}
