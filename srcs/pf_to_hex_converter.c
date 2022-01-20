/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_to_hex_converter.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:24:46 by rodrodri          #+#    #+#             */
/*   Updated: 2022/01/20 17:28:32 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "bitwise.h"
#include "ft_printf.h"
#include "pf_converting.h"
#include "pf_parsing.h"

/*
**	Prints an unsiged integer in hexadecimal (base 16), with the letters in
**	lowercase. Returns the amount of bytes written.
*/
int	to_hex(va_list data_args, t_spec *spec)
{
	int	ret;

	ret = 0;
	if (test_bit(PLUS, spec->flags))
		clear_bit(PLUS, &spec->flags);
	if (test_bit(SPACE, spec->flags))
		clear_bit(SPACE, &spec->flags);
	ret += to_numeric(data_args, spec);
	return (ret);
}
