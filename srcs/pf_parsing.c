/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 00:07:55 by rodrodri          #+#    #+#             */
/*   Updated: 2022/01/23 15:51:23 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "bitwise.h"
#include "ft_printf.h"
#include "pf_parsing.h"

static int	parse_flags(char **fmt, t_spec *spec);
static int	parse_length(char **fmt, t_spec *spec);
static int	parse_width_prec(char **fmt, va_list args, t_spec *spec);
static int	parse_specifier(char **fmt, t_spec *spec);

/*
**	Parses the Conversion Specification, filling up the 'spec' structure
**	with the flags, and stuff that appear in the format string after the '%',
**	up to, and including, the specifier. It receives the address of the format
**	string so that, while traversing the specification, it moves forward the
**	Format String pointer.
**	Returns an integer with the status code of the parsing operation (0 for
**	no errors and -1 for error).
*/
int	parse_spec(char **fmt, va_list args, t_spec *spec)
{
	int	ret;

	ret = 0;
	(*fmt)++;
	while (**fmt)
	{
		if (ft_strchr("#0-+ ", **fmt))
			ret += parse_flags(fmt, spec);
		else if (ft_strchr("0123456789*.", **fmt))
			ret = parse_width_prec(fmt, args, spec);
		else if (ft_strchr("hlL", **fmt))
			ret += parse_length(fmt, spec);
		else if (ft_strchr("cspdiouxXf%", **fmt))
		{
			ret += parse_specifier(fmt, spec);
			break ;
		}
		else
			break ;
	}
	if (spec->specifier == NOT_SET)
		ret = -1;
	return (ret);
}

/*
**	Receives the format string and sets the proper flag field using bit
**	twiddling. It advances the format string.
**	A negative return value is used to send error notification up the pipeline.
*/
static int	parse_flags(char **fmt, t_spec *spec)
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
**	Receives the format string and sets the proper width and precision fields
**	using bit twiddling. It also set the numeric values for the width and
**	precision, and advances the format string while the parsing takes place.
*/
static int	parse_width_prec(char **fmt, va_list args, t_spec *spec)
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
**	Receives the format string and sets the proper length field using bit
**	twiddling. It advances the format string accordingly.
*/
static int	parse_length(char **fmt, t_spec *spec)
{
	while (**fmt && ft_strchr("hlL", **fmt))
	{
		if (**fmt == 'h')
			handle_double_flag(H, HH, spec);
		if (**fmt == 'l')
			handle_double_flag(ELL, DBLELL, spec);
		if (**fmt == 'L' && !test_bit(UPPELL, spec->flags))
			set_bit(UPPELL, &spec->flags);
		(*fmt)++;
	}
	return (0);
}

/*
**	Receives a specifier character and set the specifier field in the 'spec'
**	structure. Returns 1 (length of the specifier), that the caller can use
**	to advance the format string.
*/
static int	parse_specifier(char **fmt, t_spec *spec)
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
