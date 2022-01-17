/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_to_float_converter.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:24:46 by rodrodri          #+#    #+#             */
/*   Updated: 2022/01/17 23:14:18 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "bitwise.h"
#include "ft_printf.h"
#include "pf_converting.h"
#include "pf_parsing.h"

#define DEFAULT_PREC 6

typedef struct s_part {
	long long			integer;
	unsigned long long	decimal;
}	t_float;

static t_float	split_float(double num, int pos);
static int		no_precision(t_float *n, t_spec *spec);
// static int		print_posit_float(t_float *n, t_spec *spec);

/*
**	Prints a floating point number. Returns the amount of bytes written.
*/
int	to_float(va_list data_args, t_spec *spec)
{
	int		ret;
	t_float	n;

	ret = 0;
	set_width_arg(spec, data_args);
	set_prec_arg(spec, data_args);
	if (spec->prec == NOT_SET)
		spec->prec = DEFAULT_PREC;
	n = split_float(va_arg(data_args, double), spec->prec);
	if (spec->prec == 0)
		ret += no_precision(&n, spec);
	else
	{
		if (n.integer < 0)
		{
			ret += ft_putchar('-');
			n.integer *= -1;
		}
		ret += put_ull_base(n.integer, DECDIGITS);
		ret += ft_putchar('.');
		ret += put_ull_base(n.decimal, DECDIGITS);
		if (amount_digits(n.decimal, 10) < spec->prec)
			ret += putstr_repeat("0", spec->prec - amount_digits(n.decimal, 10));
	}
	return (ret);
}

static int	no_precision(t_float *n, t_spec *spec)
{
	int		ret;

	if (n->integer < 0 || test_bit(PLUS, spec->flags) || test_bit(SPACE, spec->flags))
		putstr_repeat(" ", spec->width - amount_digits(n->integer, 10) - 1);
	else
		putstr_repeat(" ", spec->width - amount_digits(n->integer, 10));
	ret = 0;
	if (n->integer < 0)
	{
		ret += ft_putchar('-');
		n->integer = n->integer *= -1;
	} else if (test_bit(PLUS, spec->flags))
		ret += ft_putchar('+');
	else if (test_bit(SPACE, spec->flags))
		ret += ft_putchar(' ');
	ret += put_ull_base(n->integer, DECDIGITS);
	return (ret);
}

static t_float	split_float(double num, int pos)
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

// static int	print_posit_float(t_float *n, t_spec *spec)
// {
// 	int	ret;

// 	ret = 0;
// 	ret += put_ull_base(n->integer, DECDIGITS);
// 	ret += ft_putchar('.');
// 	ret += put_ull_base(n->decimal, DECDIGITS);
// 	if (amount_digits(n->decimal, 10) < spec->prec)
// 		ret += putstr_repeat("0", spec->prec - amount_digits(n->decimal, 10));
// 	return (ret);
// }
