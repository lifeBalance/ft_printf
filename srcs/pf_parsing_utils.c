/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parsing_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 00:07:55 by rodrodri          #+#    #+#             */
/*   Updated: 2022/01/23 15:50:54 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "bitwise.h"
#include "ft_printf.h"
#include "pf_parsing.h"

/*
**	Receives the format string pointing to a digit, keeps traversing it while
**	so and set either the 'width' or 'precision' field of the 'spec' struct.
*/
int	parse_digits(char **fmt, t_spec *spec)
{
	int	n;

	n = 0;
	while (**fmt && ft_isdigit(**fmt))
	{
		n = n * 10 + (**fmt - '0');
		(*fmt)++;
	}
	if (!test_bit(DOT, spec->flags))
	{
		spec->width = n;
		return (0);
	}
	else if (test_bit(DOT, spec->flags))
	{
		spec->prec = n;
		set_bit(PREC, &spec->flags);
		return (0);
	}
	return (-1);
}

void	handle_star(char **fmt, va_list args, t_spec *spec)
{
	if (test_bit(DOT, spec->flags))
	{
		spec->prec = va_arg(args, int);
		set_bit(PREC, &spec->flags);
	}
	else
	{
		spec->width = va_arg(args, int);
		if (spec->width < 0)
		{
			spec->width *= -1;
			set_bit(MINUS, &spec->flags);
		}
	}
	(*fmt)++;
}

void	handle_double_flag(int flag, int dbl_flag, t_spec *spec)
{
	if (test_bit(flag, spec->flags) && !test_bit(dbl_flag, spec->flags))
		set_bit(dbl_flag, &(spec->flags));
	else if (!test_bit(flag, spec->flags))
		set_bit(flag, &(spec->flags));
}
