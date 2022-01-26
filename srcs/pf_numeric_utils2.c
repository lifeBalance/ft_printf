/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_numeric_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:24:46 by rodrodri          #+#    #+#             */
/*   Updated: 2022/01/26 11:44:03 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "bitwise.h"
#include "ft_printf.h"
#include "pf_numeric.h"

static void	set_uint(t_spec *spec, va_list data_args, long long *num);

/*
**	It sets the value of the number according to the length flags
**	extracted from the 'spec'; if converts the sign to positive and casts
**	to the appropriate types: 'h', 'hh', 'l', and 'll'.
*/
void	set_num(t_spec *spec, va_list data_args, long long *num)
{
	if (spec->specifier == INT)
	{
		if (test_bit(HH, spec->flags))
			*num = (char)va_arg(data_args, int);
		else if (test_bit(H, spec->flags))
			*num = (short)va_arg(data_args, int);
		else if (test_bit(DBLELL, spec->flags))
			*num = va_arg(data_args, long long);
		else if (test_bit(ELL, spec->flags))
			*num = va_arg(data_args, long);
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
	if (test_bit(HH, spec->flags))
		*num = (unsigned char)va_arg(data_args, unsigned int);
	else if (test_bit(H, spec->flags))
		*num = (unsigned short)va_arg(data_args, unsigned int);
	else if (test_bit(DBLELL, spec->flags))
		*num = va_arg(data_args, unsigned long long);
	else if (test_bit(ELL, spec->flags))
		*num = va_arg(data_args, unsigned long);
	else
		*num = va_arg(data_args, unsigned int);
}

void	set_pad_char(t_spec *spec, char *pad_char)
{
	if (test_bit(ZERO, spec->flags) && \
		(!test_bit(PREC, spec->flags) || spec->prec < 0))
		ft_strcpy(pad_char, "0\0");
	else
		ft_strcpy(pad_char, " \0");
}
