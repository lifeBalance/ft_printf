/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrodri <rodrodri@student.hive.fi >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 00:07:55 by rodrodri          #+#    #+#             */
/*   Updated: 2022/01/09 19:43:35 by rodrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "bitwise.h"
#include "ft_printf.h"

static int	parse_specifier(char ch, t_spec *spec);
static int	parse_flags(char ch, t_spec *spec);
// static void	parse_digits(char **fmt_str, int *i, t_spec *spec);

/*
**	Parses the Conversion Specification, filling up the 'spec' structure
**	with the characters that appeared in the format string after the '%'.
**	Also, while traversing the specification, it moves forward the Format
**	String pointer.
**	Returns an integer with the status code of the parsing operation.
*/
int	parse_spec(char **fmt_str, t_spec *spec)
{
	int	i;

	i = 0;
	while (spec->specifier == NOT_SET)
	{
		if (i > 0 && ft_strchr("cspdiuxX%", (*fmt_str)[i]))
			i += parse_specifier((*fmt_str)[i], spec);
		else if (i > 0 && ft_strchr("#0-+ ", (*fmt_str)[i]))
			i += parse_flags((*fmt_str)[i], spec);
		// else if (i > 0 && ft_strchr("hlL", (*fmt_str)[i]))
		// 	(*fmt_str) += parse_length((*fmt_str)[i], spec);
		// else if (i > 0 && ft_strchr("0123456789", (*fmt_str)[i]))
		// 	(*fmt_str) += parse_digits(fmt_str, &i, spec);
		else
			i++;
	}
	(*fmt_str) += i;
	return (1);
}

/*
**	Receives a specifier character and set the specifier field in the 'spec'
**	structure. Returns 1 (length of the specifier), that the caller can use
**	to advance the format string.
*/
static int	parse_specifier(char ch, t_spec *spec)
{
	if (ch == '%')
		spec->specifier = PERCENT;
	else if (ch == 'c')
		spec->specifier = CHAR;
	else if (ch == 's')
		spec->specifier = STRING;
	else if (ch == 'p')
		spec->specifier = ADDRESS;
	else if (ch == 'd' || ch == 'i')
		spec->specifier = INT;
	else if (ch == 'x')
		spec->specifier = LOWHEX;
	else if (ch == 'X')
		spec->specifier = UPPHEX;
	return (1);
}

/*
**	Receives a character and set the proper flag field using bit twiddling.
**	Returns 1 (length of the specifier), that the caller 
**	can use to advance the format string.
*/
static int	parse_flags(char ch, t_spec *spec)
{
	if (ch == '#')
		set_bit(SHARP, &spec->flags);
	if (ch == '0')
		set_bit(ZERO, &spec->flags);
	if (ch == '-')
		set_bit(MINUS, &spec->flags);
	if (ch == '+')
		set_bit(PLUS, &spec->flags);
	if (ch == ' ')
		set_bit(SPACE, &spec->flags);
	return (1);
}

// static int	parse_digits(char ch, int *i, t_spec *spec)
// {
// 	while (ft_isdigit((*fmt_str)[*i]))
// {
// }
// }