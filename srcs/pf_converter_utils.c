/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_converter_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:24:46 by rodrodri          #+#    #+#             */
/*   Updated: 2022/01/13 16:54:28 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "bitwise.h"
#include "ft_printf.h"
#include "pf_converting.h"

/*
**	It returns the value of the width directive extracted from the 'spec'; if
**	it's not set, it returns '0'.
*/
void	set_width(t_spec *spec, va_list data_args, int *width)
{
	if (test_bit(WIDTH_ARG, spec->digits))
		*width = va_arg(data_args, int);
	else if (test_bit(WIDTH, spec->digits))
		*width = spec->width;
	else
		*width = -1;
}

/*
**	If the precision directive is equal or greater than the string length,
**	it returns the length of the string. Otherwise returns the value of the
**	precision, which is stored in the 'spec' structure.
*/
void	set_precision(t_spec *spec, va_list data_args, int *prec)
{
	if (test_bit(PREC_ARG, spec->digits))
		*prec = va_arg(data_args, int);
	else if (test_bit(PREC, spec->digits))
		*prec = spec->precision;
	else
		*prec = -1;
}

/*
**	Prints a string argument 'n' times.
**	Returns the amount of characters (bytes) written.
*/
int	putstr_repeat(char *s, int n)
{
	int	ret;

	ret = 0;
	while (n--)
		ret += ft_putstr(s);
	return (ret);
}

/*
**	Cancels flags in the 'spec' structure:
**	- A - overrides a 0 if both are given.
**	- A + overrides a space if both are used.
*/
void	cancel_flags(t_spec *spec)
{
	if (test_bit(ZERO, spec->flags) && test_bit(MINUS, spec->flags))
		clear_bit(ZERO, &spec->flags);
	if (test_bit(PLUS, spec->flags) && test_bit(SPACE, spec->flags))
		clear_bit(SPACE, &spec->flags);
}