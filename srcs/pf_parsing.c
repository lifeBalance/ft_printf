/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 00:07:55 by rodrodri          #+#    #+#             */
/*   Updated: 2022/01/22 13:11:05 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "bitwise.h"
#include "ft_printf.h"
#include "pf_parsing.h"

static int	parse_digits(char **fmt, t_spec *spec);
static void	handle_star(char **fmt, va_list args, t_spec *spec);

/*
**	Receives the format string and sets the proper flag field using bit
**	twiddling. It advances the format string.
**	A negative return value is used to send error notification up the pipeline.
*/
int	parse_flags(char **fmt, t_spec *spec)
{
	while (**fmt && ft_strchr("#0-+ ", **fmt))
	{
		if (**fmt == '#')
			set_bit(SHARP, &spec->flags);
		else if (**fmt == '0')
			set_bit(ZERO, &spec->flags);
		else if (**fmt == '-')
			set_bit(MINUS, &spec->flags);
		else if (**fmt == '+')
			set_bit(PLUS, &spec->flags);
		else if (**fmt == ' ')
			set_bit(SPACE, &spec->flags);
		(*fmt)++;
	}
	return (0);
}

/*
**	Receives the format string and sets the proper length field using bit
**	twiddling. It advances the format string accordingly.
*/
int	parse_length(char **fmt, t_spec *spec)
{
	while (**fmt && ft_strchr("hlL", **fmt))
	{
		if ((*fmt)[1] && **fmt == 'h' && (*fmt)[1] == 'h')
			set_bit(HH, &spec->flags);
		else if (**fmt == 'h')
			set_bit(H, &spec->flags);
		if ((*fmt)[1] && **fmt == 'l' && (*fmt)[1] == 'l')
			set_bit(ELLELL, &spec->flags);
		else if (**fmt == 'l')
			set_bit(ELL, &spec->flags);
		if (**fmt == 'L')
			set_bit(UPPELL, &spec->flags);
		if (test_bit(HH, spec->flags) || test_bit(ELLELL, spec->flags))
			(*fmt) += 2;
		else
			(*fmt)++;
	}
	return (0);
}

/*
**	Receives the format string and sets the proper width and precision fields
**	using bit twiddling. It also set the numeric values for the width and
**	precision, and advances the format string while the parsing takes place.
*/
int	parse_width_prec(char **fmt, va_list args, t_spec *spec)
{
	int	ret;

	ret = 0;
	while (**fmt && ft_strchr("0123456789*.", **fmt))
	{
		if (**fmt == '.')
		{
			set_bit(DOT, &spec->flags);
			(*fmt)++;
		}
		else if (ft_isdigit(**fmt))
			ret += parse_digits(fmt, spec);
		else if (**fmt == '*')
			handle_star(fmt, args, spec);
	}
	return (ret);
}

/*
**	Receives the format string pointing to a digit, keeps traversing it while
**	so and set either the 'width' or 'precision' field of the 'spec' struct.
*/
static int	parse_digits(char **fmt, t_spec *spec)
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
		return (0);
	}
	return (-1);
}

/*
**	Receives a specifier character and set the specifier field in the 'spec'
**	structure. Returns 1 (length of the specifier), that the caller can use
**	to advance the format string.
*/
int	parse_specifier(char **fmt, t_spec *spec)
{
	if (**fmt == '%')
		spec->specifier = PERCENT;
	else if (**fmt == 'c')
		spec->specifier = CHAR;
	else if (**fmt == 's')
		spec->specifier = STRING;
	else if (**fmt == 'p')
		spec->specifier = ADDRESS;
	else if (**fmt == 'd' || **fmt == 'i')
		spec->specifier = INT;
	else if (**fmt == 'o')
		spec->specifier = OCTAL;
	else if (**fmt == 'u')
		spec->specifier = UINT;
	else if (**fmt == 'x')
		spec->specifier = LOWHEX;
	else if (**fmt == 'X')
		spec->specifier = UPPHEX;
	else if (**fmt == 'f')
		spec->specifier = FLOAT;
	(*fmt)++;
	return (0);
}

static void	handle_star(char **fmt, va_list args, t_spec *spec)
{
	if (test_bit(DOT, spec->flags))
		spec->prec = va_arg(args, int);
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
