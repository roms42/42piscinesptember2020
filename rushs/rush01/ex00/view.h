/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchheang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 22:19:49 by dchheang          #+#    #+#             */
/*   Updated: 2020/09/20 22:22:03 by dchheang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIEW_H
#define VIEW_H

int	check_same_number(int c, int l, Board b, int nb);
void add_rowview(int i, int c, int l, Board b);
void add_colview(int i, int c, int l, Board b);
Board add_view(int c, int l, Board b);
int check_view(int c, int l, Board b);

#endif
