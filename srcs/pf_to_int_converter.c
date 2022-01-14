/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_to_int_converter.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:24:46 by rodrodri          #+#    #+#             */
/*   Updated: 2022/01/14 12:27:07 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "bitwise.h"
#include "ft_printf.h"
#include "pf_converting.h"

static int	amount_of_digits(int n);
static int	align_left(int n, int width, t_spec *spec);
static int	align_right(int n, int width, t_spec *spec);
static int	align_right_pos(int n, int width, t_spec *spec);

/*
**	Prints an integer. Returns the amount of bytes written.
*/
int	to_int(va_list data_args, t_spec *spec)
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
			ret += align_left(n, width, spec);
		else
			ret += align_right(n, width, spec);
	}
	if (width <= 0)
	{
		n = va_arg(data_args, int);
		if (test_bit(SPACE, spec->flags) && n >= 0)
			ret += ft_putchar(' ');
		if (test_bit(PLUS, spec->flags) && n >= 0)
			ret += ft_putchar('+');
		ret += ft_putnbr(n);
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
static int	align_left(int n, int width, t_spec *spec)
{
	int		ret;

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
	ret += ft_putnbr(n);
	ret += putstr_repeat(" ", width - amount_of_digits(n));
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
static int	align_right(int n, int width, t_spec *spec)
{
	int		ret;

	ret = 0;
	if (n < 0)
	{
		n *= -1;
		if (test_bit(ZERO, spec->flags))
		{
			ret += ft_putchar('-');
			width--;
			ret += putstr_repeat("0", width - amount_of_digits(n));
		}
		else
		{
			ret += putstr_repeat(" ", width - amount_of_digits(n) - 1);
			ret += ft_putchar('-');
			width--;
		}
		ret += ft_putnbr(n);
	}
	else if (n >= 0)
		ret += align_right_pos(n, width, spec);
	return (ret);
}

static int	align_right_pos(int n, int width, t_spec *spec)
{
	int	ret;

	ret = 0;
	if (test_bit(ZERO, spec->flags))
	{
		if (test_bit(PLUS, spec->flags))
		{
			ret += ft_putchar('+');
			width--;
		}
		ret += putstr_repeat("0", width - amount_of_digits(n));
	}
	else
	{
		if (test_bit(PLUS, spec->flags))
		{
			ret += putstr_repeat(" ", width - amount_of_digits(n) - 1);
			ret += ft_putchar('+');
		}
		else
			ret += putstr_repeat(" ", width - amount_of_digits(n));
	}
	ret += ft_putnbr(n);
	return (ret);
}

/*
**	Returns the amount of digits in the number argument.
*/
static int	amount_of_digits(int n)
{
	int	ret;

	ret = 1;
	while (n >= 10)
	{
		n /= 10;
		ret++;
	}
	return (ret);
}
