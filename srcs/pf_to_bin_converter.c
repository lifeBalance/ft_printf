/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_to_bin_converter.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 12:24:46 by rodrodri          #+#    #+#             */
/*   Updated: 2022/01/25 12:22:51 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "bitwise.h"
#include "ft_printf.h"
#include "pf_numeric.h"
#include "pf_binary.h"

static int	print_padding(t_spec *spec);

/*
**	Prints an integer. Returns the amount of bytes written.
*/
int	to_bin(va_list args, t_spec *spec)
{
	int	ret;

	ret = 0;
	if (test_bit(MINUS, spec->flags))
		print_padding(spec);
	if (test_bit(HH, spec->flags))
		ret += to_bin_char(args, spec);
	else if (test_bit(H, spec->flags))
		ret += to_bin_int(args, spec);
	else if (test_bit(DBLELL, spec->flags))
		ret += to_bin_llong(args, spec);
	else if (test_bit(ELL, spec->flags))
		ret += to_bin_long(args, spec);
	else
		ret += to_bin_int(args, spec);
	if (!test_bit(MINUS, spec->flags))
		print_padding(spec);
	return (ret);
}

static int	print_padding(t_spec *spec)
{
	int		amount;
	int		ret;

	ret = 0;
	amount = 0;
	if (test_bit(HH, spec->flags))
		amount = 8;
	else if (test_bit(ELL, spec->flags))
		amount = 32;
	else if (test_bit(DBLELL, spec->flags))
		amount = 64;
	else
		amount = 16;
	if (test_bit(SHARP, spec->flags))
		amount += (amount / 4) - 1;
	ret += putstr_repeat(" ", spec->width - amount);
	return (ret);
}

int	to_bin_char(va_list args, t_spec *spec)
{
	uint8_t	n;
	int8_t	pos;
	int		ret;

	ret = 0;
	n = (uint8_t)va_arg(args, int);
	pos = sizeof(char) * 8;
	pos--;
	while (pos >= 0)
	{
		ret += ft_putchar(test_bit(pos, n) + '0');
		if (pos > 0 && pos % 4 == 0 && test_bit(SHARP, spec->flags))
			ret += ft_putchar(' ');
		pos--;
	}
	return (ret);
}

int	to_bin_int(va_list args, t_spec *spec)
{
	uint16_t	n;
	int8_t		pos;
	int			ret;

	ret = 0;
	n = (uint16_t)va_arg(args, int);
	pos = sizeof(int16_t) * 8;
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

int	to_bin_long(va_list args, t_spec *spec)
{
	uint32_t	n;
	int8_t		pos;
	int			ret;

	ret = 0;
	n = (uint32_t)va_arg(args, long int);
	pos = sizeof(int32_t) * 8;
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
