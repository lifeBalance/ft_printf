/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_converter_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:24:46 by rodrodri          #+#    #+#             */
/*   Updated: 2022/01/15 19:07:18 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "bitwise.h"
#include "ft_printf.h"
#include "pf_converting.h"
#include "pf_parsing.h"

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
**	It sets the value of the number according to the length flags
**	extracted from the 'spec'; if converts the sign to positive and casts
**	to the appropriate types: 'h', 'hh', 'l', and 'll'.
*/
void	set_num(t_spec *spec, va_list data_args, long long *num)
{
	if (spec->specifier == INT)
	{
		if (test_bit(H, spec->length))
			*num = (short)va_arg(data_args, int);
		else if (test_bit(HH, spec->length))
			*num = (char)va_arg(data_args, int);
		else if (test_bit(ELL, spec->length))
			*num = va_arg(data_args, long);
		else if (test_bit(ELLELL, spec->length))
			*num = va_arg(data_args, long long);
		else
			*num = va_arg(data_args, int);
	}
	else if (spec->specifier == UINT || spec->specifier == OCTAL || \
	spec->specifier == UPPHEX || spec->specifier == LOWHEX)
	{
		if (test_bit(H, spec->length))
			*num = (unsigned short)va_arg(data_args, unsigned int);
		else if (test_bit(HH, spec->length))
			*num = (unsigned char)va_arg(data_args, unsigned int);
		else if (test_bit(ELL, spec->length))
			*num = va_arg(data_args, unsigned long);
		else if (test_bit(ELLELL, spec->length))
			*num = va_arg(data_args, unsigned long long);
		else
			*num = va_arg(data_args, unsigned int);
	}
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
	// while (n--)
	while (n > 0)
	{
		ret += ft_putstr(s);
		n--;
	}
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
