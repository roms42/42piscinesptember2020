/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 16:58:05 by rberthau          #+#    #+#             */
/*   Updated: 2020/09/27 18:34:32 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_H
# define READ_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include "ft.h"
# include "init_struct.h"
# include "struct_dict.h"
# include <stdlib.h>

int		nb_return(char *str);
int		init_bufsize();
char	*ft_get_dict();
t_dict	*fill_dict_struct();

#endif
