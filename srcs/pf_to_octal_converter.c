/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_to_octal_converter.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:24:46 by rodrodri          #+#    #+#             */
/*   Updated: 2022/01/23 16:11:20 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "bitwise.h"
#include "ft_printf.h"

/*
**	Prints an integer. Returns the amount of bytes written.
*/
int	to_octal(va_list data_args, t_spec *spec)
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
