/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parsing2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:49:17 by rodrodri          #+#    #+#             */
/*   Updated: 2022/01/19 14:40:39 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "bitwise.h"
#include "ft_printf.h"
#include "pf_parsing.h"

/*
**	Receives a character and checks if the corresponding flag is already
**	set; in that case returns '-1', otherwise '0'.
*/
int	repeated_flag(char ch, t_spec *spec)
{
	if (ch == '#' && test_bit(SHARP, spec->flags))
		return (-1);
	if (ch == '0' && test_bit(ZERO, spec->flags))
		return (-1);
	if (ch == '+' && test_bit(PLUS, spec->flags))
		return (-1);
	if (ch == '-' && test_bit(MINUS, spec->flags))
		return (-1);
	if (ch == ' ' && test_bit(SPACE, spec->flags))
		return (-1);
	return (0);
}

/*
**	Receives either a '.' or a '*' character and checks if the width or
**	precision is already set. If not set, returns 0, otherwise -1.
*/
int	repeated_width_prec(char ch, t_spec *spec)
{
	if (ch == '.' && test_bit(DOT, spec->digits))
		return (-1);
	else if (ch == '*' && !test_bit(DOT, spec->digits) && \
		(test_bit(WIDTH_ARG, spec->digits) || test_bit(WIDTH, spec->digits)))
		return (-1);
	else if (ch == '*' && test_bit(DOT, spec->digits) && \
		(test_bit(PREC_ARG, spec->digits) || test_bit(PREC, spec->digits)))
		return (-1);
	return (0);
}
