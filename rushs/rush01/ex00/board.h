/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchheang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 22:14:36 by dchheang          #+#    #+#             */
/*   Updated: 2020/09/20 22:16:44 by dchheang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOARD_H
#define BOARD_H

Board init_square(Board b, int size1, int size2);
Board init_views(Board b, int size1, int size2);
Board init_board(int ncolumn, int nrow);
Board boardcopy(Board src);
void print_result(Board b);

#endif
