/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_to_char_converter.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:24:46 by rodrodri          #+#    #+#             */
/*   Updated: 2022/01/23 16:08:52 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "bitwise.h"
#include "ft_printf.h"
#include "pf_numeric.h"

/*
**	Prints a character sign. Returns the amount of bytes written.
*/
int	to_char(va_list args, t_spec *spec)
{
	int		len;

	len = 0;
	if (spec->width > 0 && !test_bit(MINUS, spec->flags))
		len += putstr_repeat(" ", spec->width - 1);
	len += ft_putchar(va_arg(args, int));
	if (spec->width > 0 && test_bit(MINUS, spec->flags))
		len += putstr_repeat(" ", spec->width - 1);
	return (len);
}
