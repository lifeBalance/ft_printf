/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_converter_utils3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:24:46 by rodrodri          #+#    #+#             */
/*   Updated: 2022/01/20 18:45:10 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "bitwise.h"
#include "ft_printf.h"
#include "pf_converting.h"
#include "pf_parsing.h"

static int	print_prefix(long long n, t_spec *spec);
static int	print_padding(long long n, t_spec *spec);
static int	print_number(long long n, t_spec *spec);
static int	assemble_num(long long n, t_spec *spec);

/*
**	Prints a number in any given base, according to some specifications
**	Returns the amount of written characters (bytes).
*/
int	to_numeric(va_list data_args, t_spec *spec)
{
	long long	n;
	int			ret;

	set_width_arg(spec, data_args);
	set_prec_arg(spec, data_args);
	set_num(spec, data_args, &n);
	ret = 0;
	cancel_flags(spec);
	ret += assemble_num(n, spec);
	return (ret);
}

static int	assemble_num(long long n, t_spec *spec)
{
	int	ret;

	ret = 0;
	if (test_bit(MINUS, spec->flags))
	{
		ret += print_prefix(n, spec);
		ret += print_number(n, spec);
		ret += print_padding(n, spec);
	}
	else
	{
		if (test_bit(ZERO, spec->flags) && spec->prec == NOT_SET)
		{
			ret += print_prefix(n, spec);
			ret += print_padding(n, spec);
		}
		else
		{
			ret += print_padding(n, spec);
			ret += print_prefix(n, spec);
		}
		ret += print_number(n, spec);
	}
	return (ret);
}

static int	print_padding(long long n, t_spec *spec)
{
	int		ret;
	int		amount;
	char	pad_char[2];

	ret = 0;
	if (test_bit(ZERO, spec->flags) && spec->prec == NOT_SET)
		ft_strcpy(pad_char, "0\0");
	else
		ft_strcpy(pad_char, " \0");
	if ((test_bit(SHARP, spec->flags) && n > 0) && \
		(spec->specifier == LOWHEX || spec->specifier == UPPHEX))
		spec->width -= 2;
	else if ((test_bit(SHARP, spec->flags) && \
		spec->specifier == OCTAL && n > 0) || \
		(test_bit(PLUS, spec->flags) && n >= 0) || \
		(test_bit(SPACE, spec->flags) && n >= 0) || \
		(test_bit(SPACE, spec->flags) && n >= 0) || n < 0)
		spec->width -= 1;
	if (spec->prec > 0 && spec->prec > amount_digits(n, spec))
		amount = spec->width - spec->prec;
	else
		amount = spec->width - amount_digits(n, spec);
	ret += putstr_repeat(pad_char, amount);
	return (ret);
}

static int	print_prefix(long long n, t_spec *spec)
{
	int	ret;

	ret = 0;
	if (n < 0)
		ret += ft_putchar('-');
	else if (test_bit(SHARP, spec->flags) && n > 0)
	{
		if (spec->specifier == LOWHEX)
			ret += ft_putstr("0x");
		else if (spec->specifier == UPPHEX)
			ret += ft_putstr("0X");
		else if (spec->specifier == OCTAL)
			ret += ft_putstr("0");
	}
	else if (test_bit(PLUS, spec->flags) && n >= 0)
		ret += ft_putchar('+');
	else if (test_bit(SPACE, spec->flags) && n >= 0)
		ret += ft_putchar(' ');
	return (ret);
}

static int	print_number(long long n, t_spec *spec)
{
	int	ret;
	int	sign;

	ret = 0;
	if (n < 0)
		sign = -1;
	else
		sign = 1;
	if (spec->prec != NOT_SET)
		ret += putstr_repeat("0", spec->prec - amount_digits(n, spec));
	if (spec->specifier == LOWHEX)
		ret += put_ull_base(n * sign, HEXDIGITSLOW);
	else if (spec->specifier == UPPHEX)
		ret += put_ull_base(n * sign, HEXDIGITSUPP);
	else if (spec->specifier == OCTAL)
		ret += put_ull_base(n * sign, OCTALDIGITS);
	else
		ret += put_ull_base(n * sign, DECDIGITS);
	return (ret);
}
