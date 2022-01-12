/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_to_char_converter.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:24:46 by rodrodri          #+#    #+#             */
/*   Updated: 2022/01/12 22:38:20 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "pf_converting.h"

/*
**	Prints a character sign. Returns the amount of bytes written.
*/
int	to_char(va_list data_args, t_spec *spec)
{
	int		width;
	int		len;

	len = 0;
	set_width(spec, data_args, &width);
	if (width > 0 && !test_bit(MINUS, spec->flags))
		len += putstr_repeat(" ", width - 1);
	len += ft_putchar(va_arg(data_args, int));
	if (width > 0 && test_bit(MINUS, spec->flags))
		len += putstr_repeat(" ", width - 1);
	return (len);
}
