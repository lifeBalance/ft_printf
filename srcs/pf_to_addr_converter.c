/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_to_addr_converter.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:24:46 by rodrodri          #+#    #+#             */
/*   Updated: 2022/01/25 13:50:44 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "bitwise.h"
#include "ft_printf.h"
#include "pf_numeric.h"

static int	print_address(unsigned long n, t_spec *spec);

/*
**	Prints the address of a variable in hexadecimal, as an 'unsigned long int'.
**	Returns the amount of bytes written.
*/
int	to_address(va_list args, t_spec *spec)
{
	unsigned long	n;
	int				ret;
	int				addr_width;

	n = va_arg(args, unsigned long int);
	ret = 0;
	addr_width = (int)ft_strlen("0x") + amount_digits(n, spec);
	if (spec->width > addr_width)
	{
		if (!test_bit(MINUS, spec->flags))
			ret += putstr_repeat(" ", spec->width - addr_width);
		ret += ft_putstr("0x");
		ret += print_address(n, spec);
		if (test_bit(MINUS, spec->flags))
			ret += putstr_repeat(" ", spec->width - addr_width);
	}
	else
	{
		ret += ft_putstr("0x");
		ret += print_address(n, spec);
	}
	return (ret);
}

static int	print_address(unsigned long n, t_spec *spec)
{
	int	ret;

	ret = 0;
	if (n == 0 && test_bit(DOT, spec->flags) && \
		(spec->prec == 0 || !test_bit(PREC, spec->flags)))
		return (ret);
	else if (n == 0 && test_bit(PREC, spec->flags) && spec->prec > 0)
		ret += putstr_repeat("0", spec->prec);
	else
	{
		ret += putstr_repeat("0", spec->prec - amount_digits(n, spec));
		ret += put_ull_base(n, HEXDIGITSLOW);
	}
	return (ret);
}
