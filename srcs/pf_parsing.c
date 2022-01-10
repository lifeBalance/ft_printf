/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 00:07:55 by rodrodri          #+#    #+#             */
/*   Updated: 2022/01/10 22:31:30 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "bitwise.h"
#include "ft_printf.h"

static int	parse_specifier(char **fmt, t_spec *spec);
static int	parse_flags(char **fmt, t_spec *spec);
static int	parse_length(char **fmt, t_spec *spec);
static int	repeated_flag(char ch, t_spec *spec);
// static void	parse_digits(char **fmt_str, int *i, t_spec *spec);

/*
**	Parses the Conversion Specification, filling up the 'spec' structure
**	with the characters that appeared in the format string after the '%'.
**	Also, while traversing the specification, it moves forward the Format
**	String pointer.
**	Returns an integer with the status code of the parsing operation.
*/
int	parse_spec(char **fmt, t_spec *spec)
{
	int	ret;

	ret = 0;
	(*fmt)++;
	if (ft_strchr("#0-+ ", **fmt))
		ret += parse_flags(fmt, spec);
	// if (ft_strchr("0123456789*", **fmt))
	// 	ret = parse_digits(fmt, spec);
	if (ft_strchr("hlL", **fmt))
		ret += parse_length(fmt, spec);
	if (ft_strchr("cspdiuxX", **fmt))
		ret += parse_specifier(fmt, spec);
	if (spec->specifier == NOT_SET)
		ret = -1;
	return (ret);
}

/*
**	Receives a specifier character and set the specifier field in the 'spec'
**	structure. Returns 1 (length of the specifier), that the caller can use
**	to advance the format string.
*/
static int	parse_specifier(char **fmt, t_spec *spec)
{
	if (**fmt == 'c')
		spec->specifier = CHAR;
	else if (**fmt == 's')
		spec->specifier = STRING;
	else if (**fmt == 'p')
		spec->specifier = ADDRESS;
	else if (**fmt == 'd' || **fmt == 'i')
		spec->specifier = INT;
	else if (**fmt == 'u')
		spec->specifier = UINT;
	else if (**fmt == 'x')
		spec->specifier = LOWHEX;
	else if (**fmt == 'X')
		spec->specifier = UPPHEX;
	(*fmt)++;
	return (0);
}

/*
**	Receives the format string and sets the proper flag field using bit
**	twiddling. It advances the format string.
**	A negative return value is used to send error notification up the pipeline.
*/
static int	parse_flags(char **fmt, t_spec *spec)
{
	while(**fmt && ft_strchr("#0-+ ", **fmt))
	{
		if (repeated_flag(**fmt, spec) < 0)
			return (-1);
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
static int	parse_length(char **fmt, t_spec *spec)
{
	if ((*fmt)[1] && **fmt == 'h' && (*fmt)[1] == 'h')
		set_bit(HH, &spec->length);
	else if (**fmt == 'h')
		set_bit(H, &spec->length);
	if ((*fmt)[1] && **fmt == 'l' && (*fmt)[1] == 'l')
		set_bit(ELLELL, &spec->length);
	else if (**fmt == 'l')
		set_bit(ELL, &spec->length);
	if (**fmt == 'L')
		set_bit(UPPELL, &spec->length);
	if (test_bit(HH, spec->length) || test_bit(ELLELL, spec->length))
		(*fmt) += 2;
	else
		(*fmt)++;
	return (0);
}

/*
**	Receives a character and checks if the corresponding flag is already
**	set; in that case returns '-1', otherwise '0'.
*/
static int	repeated_flag(char ch, t_spec *spec)
{
	if (ch == '#' && test_bit(SHARP, spec->flags))
		return (-1);
	if (ch == '0' && test_bit(ZERO, spec->flags))
		return (-1);
	if (ch == '+' && test_bit(PLUS, spec->flags))
		return (-1);
	if (ch == '-' && test_bit(MINUS, spec->flags))
		return (-1);
	if (ch == ' ' && test_bit(SPACE, spec->flags))
		return (-1);
	return (0);
}

// static int	parse_digits(char ch, int *i, t_spec *spec)
// {
// 	while (ft_isdigit((*fmt_str)[*i]))
// {
// }
// }

// Parsing Validation ideas:
// if (**fmt == 'h' &&\
// 	(test_bit(H, spec->length) || test_bit(HH, spec->length)))
// 	return (0);
// if (**fmt == 'l' &&\
// 	(test_bit(ELL, spec->length) || test_bit(ELLELL, spec->length)))
// if (**fmt == 'L' &&\
// 	(test_bit(ELL, spec->length) ||\
// 	 test_bit(ELLELL, spec->length) ||\
// 	 test_bit(UPPELL, spec->length)))
	// return (0);