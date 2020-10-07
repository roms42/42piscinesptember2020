/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 13:14:27 by rberthau          #+#    #+#             */
/*   Updated: 2020/09/27 20:12:56 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "ft.h"
#include "init_struct.h"
#include "struct_dict.h"
#include <stdlib.h>
#include <stdio.h>

int		nb_return(char *str)
{
	int i;
	int nb_return;

	i = 0;
	nb_return = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			nb_return++;
		i++;
	}
	return (nb_return);
}

int		init_bufsize(void)
{
	int bufsize;

	bufsize = 4096;
	return (bufsize);
}

char	*ft_get_dict(void)
{
	int		fd;
	int		ret;
	char	*buf;
	int		bufsize;

	bufsize = init_bufsize();
	if (!(buf = malloc(sizeof(char) * bufsize)))
		return (NULL);
	fd = open("numbers.dict", O_RDONLY);
	while ((ret = read(fd, buf, bufsize)))
	{
		buf[ret] = '\0';
	}
	return (buf);
}

t_dict	*fill_dict_struct(void)
{
	t_dict	*tab;
	int		nb;
	int		i;
	int		j;
	int		k;
	char	*buf;

	buf = ft_get_dict();
	nb = nb_return(buf) + 1;
	tab = init_struct_tab(nb, 500);
	i = 0;
	k = 0;
	while (buf[i] != '\0')
	{
		while (buf[i] != '\0' && (buf[i] < '0' || buf[i] > '9'))
			i++;
		j = i;
		while (buf[j] != '\0' && buf[j] >= '0' && buf[j] <= '9')
			j++;
		j = j - i;
		ft_strncpy(tab[k].nb, &buf[i], j);
		tab[0].nb[1] = '\0';
		i = i + j;
		while (buf[i] != '\0' && (buf[i] < 33 || buf[i] > 126 || buf[i] == ':'))
			i++;
		j = i;
		while (buf[j] != '\0' && buf[j] > 32 && buf[j] <= 126)
			j++;
		j = j - i;
		ft_strncpy(tab[k].lettres, &buf[i], j);
		k++;
		i = i + j;
	}
	return (tab);
}
