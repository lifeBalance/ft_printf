/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_to_addr_converter.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:24:46 by rodrodri          #+#    #+#             */
/*   Updated: 2022/01/16 18:15:12 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "bitwise.h"
#include "ft_printf.h"
#include "pf_converting.h"
#include "pf_parsing.h"

/*
**	Prints the address of a variable in hexadecimal, as an 'unsigned long int'.
**	Returns the amount of bytes written.
*/
int	to_address(va_list data_args, t_spec *spec)
{
	unsigned long	n;
	int				ret;

	set_width_arg(spec, data_args);
	ret = 0;
	n = va_arg(data_args, unsigned long int);
	if (spec->width > amount_of_digits(n, 16) + (int)ft_strlen("0x"))
	{
		if (!test_bit(MINUS, spec->flags))
			ret += putstr_repeat(" ", spec->width - amount_of_digits(n, 16) - 2);
		ret += ft_putstr("0x");
		ret += put_ull_base(n, HEXDIGITSLOW);
		if (test_bit(MINUS, spec->flags))
			ret += putstr_repeat(" ", spec->width - amount_of_digits(n, 16) - 2);
	}
	else
	{
		ret += ft_putstr("0x");
		ret += put_ull_base(n, HEXDIGITSLOW);
	}
	return (ret);
}
