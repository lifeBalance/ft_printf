/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_converter_utils3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:24:46 by rodrodri          #+#    #+#             */
/*   Updated: 2022/01/17 12:15:18 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "bitwise.h"
#include "ft_printf.h"
#include "pf_converting.h"
#include "pf_parsing.h"

static int
handle_no_width(long long n, long long base, t_spec *spec, char *digits);

/*
**	Prints a number in any given base, according to some specifications
**	Returns the amount of written characters (bytes).
*/
int	to_numeric(va_list data_args, t_spec *spec, char *digits)
{
	long long	n;
	long long	base;
	int			ret;

	set_base(&base, digits);
	set_width_arg(spec, data_args);
	set_prec_arg(spec, data_args);
	set_num(spec, data_args, &n);
	ret = 0;
	cancel_flags(spec);
	if (spec->width > 0)
	{
		if (test_bit(MINUS, spec->flags))
			ret += align_left(n, base, spec, digits);
		else
			ret += align_right(n, base, spec, digits);
	}
	else
		ret += handle_no_width(n, base, spec, digits);
	return (ret);
}

/*
**	Prints an integer when there is no width, hence no need for padding,
**	or alineation. It also handles the flags:
**	 '+' which prefix positive integers with +.
**	 ' ' which appends spaces if the width requires it.
**	Returns the amount of characters (bytes) written.
*/
static int
	handle_no_width(long long n, long long base, t_spec *spec, char *digits)
{
	int	ret;

	ret = 0;
	if (spec->prec > amount_digits(n, base))
		ret += handle_prec(n, base, spec, digits);
	else
	{
		if (test_bit(SPACE, spec->flags) && n >= 0)
			ret += ft_putchar(' ');
		if (test_bit(PLUS, spec->flags) && n >= 0)
			ret += ft_putchar('+');
		ret += print_split_sign(n, digits);
	}
	return (ret);
}

/*
**	Receives an 'long long int' argument and if it's negative, prints the '-'
**	before changing the number to positive; that's necessary since the
**	'put_ull_base' function only deals with UNSIGNED numbers.
**	Returns the amount of printed characters (bytes).
*/
int	print_split_sign(long long n, char *digits)
{
	int	ret;

	ret = 0;
	if (n < 0)
	{
		ret += ft_putchar('-');
		n = -n;
	}
	ret += put_ull_base(n, digits);
	return (ret);
}

int	handle_prec(long long n, long long base, t_spec *spec, char *digits)
{
	int	ret;
	int	spaces;

	ret = 0;
	if (spec->width > spec->prec)
		spaces = spec->width - spec->prec;
	else
		spaces = 0;
	if (n < 0 || (n >= 0 && test_bit(PLUS, spec->flags)))
		spaces--;
	ret += putstr_repeat(" ", spaces);
	if (n >= 0 && test_bit(PLUS, spec->flags))
		ret += ft_putchar('+');
	if (n < 0)
	{
		ret += ft_putchar('-');
		n = -n;
	}
	ret += putstr_repeat("0", spec->prec - amount_digits(n, base));
	ret += put_ull_base(n, digits);
	return (ret);
}
