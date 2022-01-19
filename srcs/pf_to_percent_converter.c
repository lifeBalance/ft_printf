/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_to_percent_converter.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:24:46 by rodrodri          #+#    #+#             */
/*   Updated: 2022/01/19 15:59:11 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "bitwise.h"
#include "ft_printf.h"
#include "pf_parsing.h"
#include "pf_converting.h"

/*
**	Prints a percent sign. Returns the amount of bytes written.
**	(Ignores all the flags and directives, hence the casting to void).
*/
int	to_percent(va_list args, t_spec *spec)
{
	int	ret;

	set_width_arg(spec, args);
	ret = 0;
	if (!test_bit(MINUS, spec->flags) && spec->width > 0)
	{
		if (test_bit(ZERO, spec->flags))
			ret += putstr_repeat("0", spec->width - 1);
		else
			ret += putstr_repeat(" ", spec->width - 1);
	}
	ret += ft_putchar('%');
	if (spec->width > 0 && test_bit(MINUS, spec->flags))
		ret += putstr_repeat(" ", spec->width - 1);
	return (ret);
}
