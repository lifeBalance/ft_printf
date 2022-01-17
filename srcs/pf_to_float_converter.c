/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_to_float_converter.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:24:46 by rodrodri          #+#    #+#             */
/*   Updated: 2022/01/17 19:44:16 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "bitwise.h"
#include "ft_printf.h"
#include "pf_converting.h"
#include "pf_parsing.h"

#define	DEFAULT_PREC 6

typedef struct s_part {
	unsigned long long	integer;
	unsigned long long	decimal;
}	t_float;

static t_float	split_float(double num, unsigned int pos);

/*
**	Prints a floating point number. Returns the amount of bytes written.
*/
int	to_float(va_list data_args, t_spec *spec)
{
	int		ret;
	double	d;
	t_float n;

	ret = 0;
	set_width_arg(spec, data_args);
	set_prec_arg(spec, data_args);
	if (spec->prec == NOT_SET)
		spec->prec = DEFAULT_PREC;
	d = va_arg(data_args, double);
	if (d < 0)
	{
		ret += ft_putchar('-');
		d = -d;
	}
	n = split_float(d, spec->prec);
	if (spec->prec == 0)
		ret += put_ull_base(n.integer, DECDIGITS);
	else
	{
		ret += put_ull_base(n.integer, DECDIGITS);
		ret += ft_putchar('.');
		ret += put_ull_base(n.decimal, DECDIGITS);
		if (amount_digits(n.decimal, 10) < spec->prec)
			ret += putstr_repeat("0", spec->prec - amount_digits(n.decimal, 10));
	}
	return (ret);
}

static t_float	split_float(double num, unsigned int pos)
{
	unsigned long long	amount;
	unsigned long long	biggie;
	unsigned long long	trunc;

	amount = 10;
	while (--pos)
		amount *= 10;
	biggie = num * amount;
	trunc = (unsigned long)num;
	return ((t_float){trunc, biggie - trunc * amount});
}
