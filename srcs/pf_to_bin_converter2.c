/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_to_bin_converter2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:24:46 by rodrodri          #+#    #+#             */
/*   Updated: 2022/01/25 12:21:43 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "bitwise.h"
#include "ft_printf.h"
#include "pf_numeric.h"
#include "pf_binary.h"

int	to_bin_llong(va_list args, t_spec *spec)
{
	uint64_t	n;
	int8_t		pos;
	int			ret;

	ret = 0;
	n = (uint64_t)va_arg(args, long long int);
	pos = sizeof(uint64_t) * 8;
	pos--;
	while (pos >= 0)
	{
		ret += ft_putchar(((n & (1 << pos)) > 0) + '0');
		if (pos > 0 && pos % 4 == 0 && test_bit(SHARP, spec->flags))
			ret += ft_putchar(' ');
		pos--;
	}
	return (ret);
}
