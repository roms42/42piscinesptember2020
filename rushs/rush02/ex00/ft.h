/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 11:48:16 by rberthau          #+#    #+#             */
/*   Updated: 2020/09/27 18:23:38 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>

int		ft_atoi(char *str);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
int		ft_strlen(char *str);
char	*ft_strrev(char *dest);
int		ft_power(int nb, int power);
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_strcmp(char *s1, char *s2);
char	*ft_itoa(int nb);

#endif
