/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_converter_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:24:46 by rodrodri          #+#    #+#             */
/*   Updated: 2022/01/19 14:47:45 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "bitwise.h"
#include "ft_printf.h"
#include "pf_converting.h"
#include "pf_parsing.h"

static void	set_uint(t_spec *spec, va_list data_args, long long *num);

/*
**	It checks the 'digits' field of the 'spec' and ONLY if the WIDTH_ARG bit
**	is set, extracts a value from the data arguments, and assigns it to
**	the 'width' field.
*/
void	set_width_arg(t_spec *spec, va_list data_args)
{
	if (test_bit(WIDTH_ARG, spec->digits))
		spec->width = va_arg(data_args, int);
}

/*
**	It checks the 'digits' field of the 'spec' and ONLY if the PREC_ARG bit
**	is set, extracts a value from the data arguments, and assigns it to
**	the 'precision' field.
*/
void	set_prec_arg(t_spec *spec, va_list data_args)
{
	if (test_bit(PREC_ARG, spec->digits))
		spec->prec = va_arg(data_args, int);
}

/*
**	Receives a string argument with the set of allowed digits in a given
**	numeric base. Returns the base or radix of that numeric base.
*/
void	set_base(long long *base, char *digits)
{
	*base = 0;
	while (digits[*base])
		(*base)++;
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
		set_uint(spec, data_args, num);
}

/*
**	Continuation of the function above that had to be splitted to comply
**	with the Norm limitation of maximum 25 lines per function.
*/
static void	set_uint(t_spec *spec, va_list data_args, long long *num)
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
