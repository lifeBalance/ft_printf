/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 00:07:55 by rodrodri          #+#    #+#             */
/*   Updated: 2022/01/10 12:23:40 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "bitwise.h"
#include "ft_printf.h"

static int	parse_specifier(char **fmt, t_spec *spec);
static int	parse_flags(char **fmt, t_spec *spec);
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
	int	i;

	i = 0;
	while (spec->specifier == NOT_SET)
	{
		if (i > 0 && ft_strchr("cspdiuxX", (*fmt)[i]))
			ret = parse_specifier(fmt, spec);
		else if (i > 0 && ft_strchr("#0-+ ", (*fmt)[i]))
			ret = parse_flags(fmt, spec);
		// else if (i > 0 && ft_strchr("hlL", (*fmt)[i]))
		// 	(*fmt) += parse_length((*fmt)[i], spec);
		// else if (i > 0 && ft_strchr("0123456789*", (*fmt)[i]))
		// 	(*fmt) += parse_digits(fmt, &i, spec);
		else
			i++;
	}
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
	else if (**fmt == 'x')
		spec->specifier = LOWHEX;
	else if (**fmt == 'X')
		spec->specifier = UPPHEX;
	(*fmt)++;
	return (1);
}

/*
**	Receives a character and set the proper flag field using bit twiddling.
**	Returns 1 (length of the specifier), that the caller 
**	can use to advance the format string.
*/
static int	parse_flags(char **fmt, t_spec *spec)
{
	if (**fmt == '#')
		set_bit(SHARP, &spec->flags);
	if (**fmt == '0')
		set_bit(ZERO, &spec->flags);
	if (**fmt == '-')
		set_bit(MINUS, &spec->flags);
	if (**fmt == '+')
		set_bit(PLUS, &spec->flags);
	if (**fmt == ' ')
		set_bit(SPACE, &spec->flags);
	(*fmt)++;
	return (1);
}

// static int	parse_digits(char ch, int *i, t_spec *spec)
// {
// 	while (ft_isdigit((*fmt_str)[*i]))
// {
// }
// }