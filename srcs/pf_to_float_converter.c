/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_to_float_converter.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:56:24 by rodrodri          #+#    #+#             */
/*   Updated: 2022/01/26 18:46:27 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "bitwise.h"
#include "ft_printf.h"
#include "pf_numeric.h"

static int		no_precision_right(t_float *n, t_spec *spec);
static int		no_precision_left(t_float *n, t_spec *spec);
static int		add_spaces(t_float *n, t_spec *spec);
static int		handle_precision(t_float *n, t_spec *spec);

/*
**	Prints a floating point number. Returns the amount of bytes written.
*/
int	to_float(va_list data_args, t_spec *spec)
{
	int		ret;
	t_float	n;

	ret = 0;
	if (!test_bit(PREC, spec->flags))
		spec->prec = DEFAULT_PREC;
	if (test_bit(UPPELL, spec->flags))
		n = split_float(va_arg(data_args, long double), spec->prec);
	else
		n = split_float((long double)(va_arg(data_args, double)), spec->prec);
	if (spec->prec == 0)
	{
		if (test_bit(MINUS, spec->flags))
			ret += no_precision_left(&n, spec);
		else
			ret += no_precision_right(&n, spec);
	}
	else
		ret += handle_precision(&n, spec);
	return (ret);
}

/*
**	Handles the printing and alignment of a floating point number when the
**	precision directive is greater than zero.
**	Returns the amount of bytes written.
*/
static int	handle_precision(t_float *n, t_spec *spec)
{
	int		ret;

	ret = 0;
	spec->width -= spec->prec;
	spec->width -= 1;
	if (test_bit(MINUS, spec->flags))
		ret += no_precision_left(n, spec);
	else
		ret += no_precision_right(n, spec);
	ret += ft_putchar('.');
	ret += put_ull_base(n->decimal, DECDIGITS);
	if (amount_digits(n->decimal, spec) < spec->prec)
		ret += putstr_repeat("0", spec->prec - amount_digits(n->decimal, spec));
	if (test_bit(MINUS, spec->flags))
		ret += add_spaces(n, spec);
	return (ret);
}

/*
**	Adds spaces to pad a floating point number, aligned to the right or to the
**	left. It accounts for the sign (- or +) and for the ' ' flag.
**	Returns the amount of characters (bytes) written.
*/
static int	add_spaces(t_float *n, t_spec *spec)
{
	int	ret;
	int	amount;

	ret = 0;
	amount = spec->width - amount_digits(n->integer, spec);
	if (n->sign < 0 || test_bit(PLUS, spec->flags) || \
		test_bit(SPACE, spec->flags))
		ret += putstr_repeat(" ", amount - 1);
	else
		ret += putstr_repeat(" ", amount);
	return (ret);
}

/*
**	Prints a floating point number, aligned to the right, when the precision
**	is zero. Returns the amount of characters (bytes) written.
*/
static int	no_precision_right(t_float *n, t_spec *spec)
{
	int		ret;

	ret = 0;
	if (!test_bit(ZERO, spec->flags))
		ret += add_spaces(n, spec);
	if (n->sign < 0)
		ret += ft_putchar('-');
	else if (test_bit(PLUS, spec->flags))
		ret += ft_putchar('+');
	else if (test_bit(SPACE, spec->flags))
		ret += ft_putchar(' ');
	if (test_bit(ZERO, spec->flags))
	{
		if (n->sign < 0 || test_bit(PLUS, spec->flags) || \
			test_bit(SPACE, spec->flags))
			ret += putstr_repeat("0", spec->width - \
				amount_digits(n->integer, spec) - 1);
		else
			ret += putstr_repeat("0", spec->width - \
				amount_digits(n->integer, spec));
	}
	ret += put_ull_base(n->integer, DECDIGITS);
	return (ret);
}

/*
**	Prints a floating point number, aligned to the left, when the precision
**	is zero. Returns the amount of characters (bytes) written.
*/
static int	no_precision_left(t_float *n, t_spec *spec)
{
	int	ret;
	int	sign;

	sign = 1;
	ret = 0;
	if (n->sign < 0)
		ret += ft_putchar('-');
	else if (test_bit(PLUS, spec->flags))
		ret += ft_putchar('+');
	else if (test_bit(SPACE, spec->flags))
		ret += ft_putchar(' ');
	ret += put_ull_base(n->integer, DECDIGITS);
	if (spec->prec == 0)
		ret += add_spaces(n, spec);
	return (ret);
}
