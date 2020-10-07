/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchheang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 20:08:09 by dchheang          #+#    #+#             */
/*   Updated: 2020/09/27 13:19:10 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
#define TYPES_H

typedef struct view{
	int value;
	int max;
} View;

typedef struct board
{
	int ncolumn;
	int nrow;
	int **square;
	View **colview;
	View **rowview;
} Board;

#endif
