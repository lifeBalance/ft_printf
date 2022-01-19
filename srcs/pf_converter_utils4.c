/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_converter_utils4.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:24:46 by rodrodri          #+#    #+#             */
/*   Updated: 2022/01/19 21:15:08 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "bitwise.h"
#include "ft_printf.h"
#include "pf_converting.h"
#include "pf_parsing.h"

static int
align_right_pos(long long n, long long base, t_spec *spec, char *digits);
static int
align_right_neg(long long n, long long base, t_spec *spec, char *digits);

/*
**	Prints an integer aligned to the left, adding padding to the right.
**	(It also handles the flags:
**	 '+' which prefix positive integers with +.
**	 ' ' which appends spaces if the width requires it.)
**	Returns the amount of characters (bytes) written.
*/
int	align_left(long long n, long long base, t_spec *spec, char *digits)
{
	int	ret;

	ret = 0;
	if (n >= 0)
	{
		if (test_bit(PLUS, spec->flags))
			ret += ft_putchar('+');
		else if (test_bit(SPACE, spec->flags))
			ret += ft_putchar(' ');
		if (test_bit(PLUS, spec->flags) || test_bit(SPACE, spec->flags))
			spec->width--;
	}
	else
		spec->width--;
	ret += print_split_sign(n, digits);
	ret += putstr_repeat(" ", spec->width - amount_digits(n, base));
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
int	align_right(long long n, long long base, t_spec *spec, char *digits)
{
	int	ret;

	ret = 0;
	if (spec->prec > amount_digits(n, base))
		ret += handle_prec(n, base, spec, digits);
	else if (n < 0)
		ret += align_right_neg(n, base, spec, digits);
	else if (n >= 0)
		ret += align_right_pos(n, base, spec, digits);
	return (ret);
}

/*
**	Prints a NEGATIVE integer aligned to the Right (default), adding padding
**	to the left. (It's basically the continuation of the function above, which
**	had to be splitted to comply with the Norm maximum limit of 25 lines
** 	per function.
*/
static int
	align_right_neg(long long n, long long base, t_spec *spec, char *digits)
{
	int	ret;

	ret = 0;
	n *= -1;
	if (test_bit(ZERO, spec->flags))
	{
		ret += ft_putchar('-');
		spec->width--;
		ret += putstr_repeat("0", spec->width - amount_digits(n, base));
		ret += print_split_sign(n, digits);
	}
	else
	{
		ret += putstr_repeat(" ", spec->width - amount_digits(n, base) - 1);
		ret += ft_putchar('-');
		spec->width--;
		ret += print_split_sign(n, digits);
	}
	return (ret);
}

/*
**	Prints a POSITIVE integer aligned to the Right (default), adding padding
**	to the left. (It's basically the continuation of the function above, which
**	had to be splitted to comply with the Norm maximum limit of 25 lines
** 	per function.
*/
static int
	align_right_pos(long long n, long long base, t_spec *spec, char *digits)
{
	int	ret;

	ret = 0;
	if (test_bit(ZERO, spec->flags) || spec->prec > amount_digits(n, base))
	{
		if (test_bit(PLUS, spec->flags))
		{
			ret += ft_putchar('+');
			spec->width--;
		}
		ret += putstr_repeat("0", spec->width - amount_digits(n, base));
	}
	else if (test_bit(PLUS, spec->flags))
	{
		ret += putstr_repeat(" ", spec->width - amount_digits(n, base) - 1);
		ret += ft_putchar('+');
	}
	else if (spec->width > amount_digits(n, base))
		ret += putstr_repeat(" ", spec->width - amount_digits(n, base));
	ret += print_split_sign(n, digits);
	return (ret);
}

/*
**	Splits a double argument into two parts:
**	- An integer part.
**	- A decimal part.
**	Returns both parts as a 't_float' (a struct with two members).
*/
t_float	split_float(double num, int pos)
{
	unsigned long long	amount;
	unsigned long long	biggie;
	unsigned long long	trunc;
	int					sign;

	sign = 1;
	if (num < 0)
		sign = -1;
	num *= sign;
	amount = 10;
	while (--pos > 0)
		amount *= 10;
	biggie = num * amount;
	trunc = (unsigned long long)num;
	return ((t_float){trunc * sign, biggie - trunc * amount});
}
