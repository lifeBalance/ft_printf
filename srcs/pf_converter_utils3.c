/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_converter_utils3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:24:46 by rodrodri          #+#    #+#             */
/*   Updated: 2022/01/15 16:53:55 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "bitwise.h"
#include "ft_printf.h"
#include "pf_converting.h"
#include "pf_parsing.h"

static int	align_left(int n, int width, t_spec *spec, char *digits);
static int	align_right(int n, int width, t_spec *spec, char *digits);
static int	align_right_pos(int n, int width, t_spec *spec, char *digits);
static int	print_split_sign(long long n, char *digits);

/*
**	Prints a number in any given base, according to some specifications
**	Returns the amount of written characters (bytes).
*/
int	to_numeric(va_list data_args, t_spec *spec, char *digits)
{
	int	n;
	int	ret;
	int	width;

	set_width(spec, data_args, &width);
	ret = 0;
	cancel_flags(spec);
	if (width > 0)
	{
		n = va_arg(data_args, int);
		if (test_bit(MINUS, spec->flags))
			ret += align_left(n, width, spec, digits);
		else
			ret += align_right(n, width, spec, digits);
	}
	if (width <= 0)
	{
		n = va_arg(data_args, int);
		if (test_bit(SPACE, spec->flags) && n >= 0)
			ret += ft_putchar(' ');
		if (test_bit(PLUS, spec->flags) && n >= 0)
			ret += ft_putchar('+');
		ret += print_split_sign(n, digits);
	}
	return (ret);
}

/*
**	Prints an integer aligned to the left, adding padding to the right.
**	(It also handles the flags:
**	 '+' which prefix positive integers with +.
**	 ' ' which appends spaces if the width requires it.)
**	Returns the amount of characters (bytes) written.
*/
static int	align_left(int n, int width, t_spec *spec, char *digits)
{
	int					ret;
	unsigned long long	base;

	set_base(&base, digits);
	ret = 0;
	if (n >= 0)
	{
		if (test_bit(PLUS, spec->flags))
			ret += ft_putchar('+');
		else if (test_bit(SPACE, spec->flags))
			ret += ft_putchar(' ');
		if (test_bit(PLUS, spec->flags) || test_bit(SPACE, spec->flags))
			width--;
	}
	else
	{
		n *= -1;
		ret += ft_putchar('-');
		width--;
	}
	ret += print_split_sign(n, digits);
	ret += putstr_repeat(" ", width - amount_of_digits(n, base));
	return (ret);
}

/*
**	Prints an integer aligned to the Right (default), adding padding to the
**	left. It also handles the flags:
**	 '0' pads with zeros instead of spaces if the width requires it.
**	 '+' which prefix positive integers with +.
**	 ' ' which appends spaces if the width requires it.
**	(The '+' flag overrides the ' ' flag. Also, this function assumes 
**	the '-' flag is not present)
**	Returns the amount of characters (bytes) written.
*/
static int	align_right(int n, int width, t_spec *spec, char *digits)
{
	unsigned long long	base;
	int					ret;

	set_base(&base, digits);
	ret = 0;
	if (n < 0)
	{
		n *= -1;
		if (test_bit(ZERO, spec->flags))
		{
			ret += ft_putchar('-');
			width--;
			ret += putstr_repeat("0", width - amount_of_digits(n, base));
		}
		else
		{
			ret += putstr_repeat(" ", width - amount_of_digits(n, base) - 1);
			ret += ft_putchar('-');
			width--;
		}
		ret += print_split_sign(n, digits);
	}
	else if (n >= 0)
		ret += align_right_pos(n, width, spec, digits);
	return (ret);
}

static int	align_right_pos(int n, int width, t_spec *spec, char *digits)
{
	unsigned long long	base;
	int					ret;

	set_base(&base, digits);
	ret = 0;
	if (test_bit(ZERO, spec->flags))
	{
		if (test_bit(PLUS, spec->flags))
		{
			ret += ft_putchar('+');
			width--;
		}
		ret += putstr_repeat("0", width - amount_of_digits(n, base));
	}
	else if (test_bit(PLUS, spec->flags))
	{
		ret += putstr_repeat(" ", width - amount_of_digits(n, base) - 1);
		ret += ft_putchar('+');
	}
	else
		ret += putstr_repeat(" ", width - amount_of_digits(n, base));
	ret += print_split_sign(n, digits);
	return (ret);
}

/*
**	Receives an 'long long int' argument and if it's negative, prints the '-'
**	before changing the number to positive; that's necessary since the
**	'put_ull_base' function only deals with UNSIGNED numbers.
**	Returns the amount of printed characters (bytes).
*/
static int	print_split_sign(long long n, char *digits)
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
